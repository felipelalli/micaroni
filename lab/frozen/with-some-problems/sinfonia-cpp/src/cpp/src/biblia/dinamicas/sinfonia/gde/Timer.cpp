/**
 * $RCSfile: Timer.cpp,v $
 * $Date: 2005/03/30 01:23:46 $
 * $Revision: 1.20 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/gde/Timer.h"
using namespace biblia::dinamicas::sinfonia::gde;

/* CPPDOC_BEGIN_EXCLUDE */

void biblia::dinamicas::sinfonia::gde::timer(void* tim) {
	static Semaforo s(1);
	Lock lock(s);
	
	try {
		Timer& t = *((Timer*) tim);

		if (!t.lancaEvento()) {
			t.pEstado->atribui(t.pEstado->valor().emDouble() + 1, t.pUniverso);
		} else {
			// lança evento que incrementa um no principal
			ModificadorDeEstado mde(t.pEstado->nomeCompleto(), Multifuncional::MAIS);
			mde.adicionaParametro(Valor(1));
			Evento incrementaUmNoPrincipal(t.pEstado->nome(), mde);
			incrementaUmNoPrincipal.grupo(t.pEstado->grupo());
			Evento* disparado = incrementaUmNoPrincipal.dispara(t.pUniverso);
			disparado->especial(true);
			t.gera(disparado);
		}

		if (!t.emLoop()) {
			if (!t.lancaEvento()) {
				t.pEstado->atribui(false, t.pUniverso, "iniciado");
			} else {
				// lança evento que pára
				ModificadorDeEstado mde(t.pEstado->nomeCompleto());
				mde.defineCampo("iniciado");
				mde.adicionaParametro(Valor(false));

				Evento para(t.pEstado->nome(), mde);
				para.grupo(t.pEstado->grupo());
				Evento* disparado = para.dispara(t.pUniverso);
				disparado->especial(true);
				t.gera(disparado);
			}
		}
	} catch(exception& e) {
		throw e;
	} catch(...) {
		Debug::msg(ERRO, "biblia::dinamicas::sinfonia::gde::timer::"
				" Ocorreu um erro desconhecido no timer."
				" Provavelmente ocorreu porque a função não terminou"
				" enquanto o Timer era deletado.");
	}

} END_OF_FUNCTION(timer);

/* CPPDOC_END_EXCLUDE */

Timer::Timer(const UniversoDeTempo& u, const MediadorDeEstados& mde, Estado* e)
		:GeradorDeEventosEspecial(mde), pSemaTimer(1),
		 pUniverso(u), pEstado(e), pIntervalo(0, Segundo()),
		 pQuantasVezes(0)
{
//	Debug::msg(INFO, "--- vai criar timer, puxando informações...");

	try {
		// captura os dados do Estado
		double relacao = e->valor("em milionésimos de segundo").emDouble();
		double intervalo = e->valor("intervalo").emDouble();

		try {
			Identificacao nome(e->valor("unidade").emString());
			this->pIntervalo = Intervalo(intervalo, UnidadeGenerica(relacao, nome));
		} catch (const CampoInexistenteExcecao&) {
			this->pIntervalo = Intervalo(intervalo, UnidadeGenerica(relacao));
		}

		if (!e->valor().indefinida()) {
			this->pQuantasVezes = (int) e->valor().emDouble();
		} else {
			this->pQuantasVezes = 0;
			//e->atribui(Valor(0), u);

			{
				// lança evento que zera cronometro
				ModificadorDeEstado mde(this->pEstado->nomeCompleto());
				mde.defineCampo();
				mde.adicionaParametro(Valor(0));

				Evento zera(this->pEstado->nome(), mde);
				zera.grupo(this->pEstado->grupo());
				Evento* disparado = zera.dispara(this->pUniverso);
				disparado->especial(true);
				this->gera(disparado);
			}
		}

		this->pLancaEvento = e->valor("lança evento").emBool();

		e->externo(!this->pLancaEvento);

		this->pEmLoop = e->valor("loop").emBool();
		this->pIniciado = false;

		if (e->valor("iniciado").emBool()) {
			this->pIniciaParado = false;
//			Debug::msg(INFO, "--- timer já começa iniciado, olha só...");
		} else {
			this->pIniciaParado = true;
		}
	} catch (const CampoInexistenteExcecao& cie) {
		ImpossivelCriarTimerExcecao icte;
		icte << "Erro na criação do Timer relativo ao Estado '" + *e
				+ "'. Falta algum campo: " + cie;

		throw icte;
	} catch (const InformacaoNaoDefinidaExcecao& inde) {
		ImpossivelCriarTimerExcecao icte;
		icte << "Erro na criação do Timer relativo ao Estado '" + *e
				+ "'. Informação indefinida: " + inde;

		throw icte;
	}

	this->pEstado->atribui(false, this->pUniverso, "iniciado");
	this->pPausado = e->valor("pausado").emBool();

	static bool passou = false;
	if (!passou) {
		passou = true;
		Allegro::inicializa();
		LOCK_FUNCTION(timer);
	}

	this->defineEventosQueTrata();

	if (this->pIniciado) {
		this->pIniciado = false;
		this->inicia();
	}
}

Timer::Timer(const UniversoDeTempo& u, const MediadorDeEstados& mde, Estado* e,
		const Intervalo& i, const bool& lancaEvento,
		const bool& emLoop, const bool& iniciaParado)
	:GeradorDeEventosEspecial(mde), pSemaTimer(1),
	 pUniverso(u), pEstado(e), pIntervalo(i),
	 pLancaEvento(lancaEvento), pEmLoop(emLoop), pIniciado(false),
	 pPausado(false), pIniciaParado(iniciaParado),
	 pQuantasVezes(0)
{
	e->externo(!lancaEvento);

	// atualiza os campos no Estado

	e->atribui(0, u);
	e->atribui((double) i.emMilionesimosDeSegundo().emLong(), u, "em milionésimos de segundo");
	e->atribui((double) i().emLong(), u, "intervalo");
	e->atribui(i.unidadeDeTempo().emString(), u, "unidade");
	e->atribui(lancaEvento, u, "lança evento");
	e->atribui(emLoop, u, "loop");
	e->atribui(false, u, "iniciado");
	e->atribui(false, u, "pausado");

	this->defineEventosQueTrata();
}

Timer::~Timer() {
	if (this->iniciado()) {
		this->para();
		Thread::sleep(this->intervalo());
		Thread::sleep(Intervalo(50, Milissegundo()));
	}
}

Timer& Timer::defineEventosQueTrata() {
	this->modificaEventosQueTrata().adiciona(this->pEstado->nomeCompleto().valor());
	return *this;
}

Timer& Timer::para() {
	if (!this->iniciado()) {
		Debug::msg(WARN, "Timer::para():: este timer já"
				" estava parado! this: " + *this);
	} else {
		this->pIniciado = false;
		Lock lock(this->pSemaTimer);
		remove_param_int(timer, this);
	}

	return *this;
}

Timer& Timer::inicia() {
	Lock lock(this->pSemaTimer);

	if (this->iniciado()) {
		Debug::msg(WARN, "Timer::inicia():: este timer já"
				" estava iniciado! this: " + *this);
	} else {
		this->pIniciado = true;
		double milionesimos = (double) this->intervalo()
				.emMilionesimosDeSegundo().emLong();

		if (milionesimos / 1000.0 < 10.0) {
			if (this->lancaEvento()) {
				Debug::msg(WARN, "Timer::inicia():: informação de otimização:"
						" talvez não seja adequado criar um timer que tenha"
						" menos que 10 milissegundos e que lance eventos pois"
						" isso pode sobrecarregar a Sinfonia.");
			}
		}

		if (milionesimos >= 1000.0) {
			install_param_int(timer, this, (int) (milionesimos / 1000.0));
		} else {
			install_param_int_ex(timer, this, (int) (milionesimos * 1.193181));
		}
	}

	return *this;
}

const Intervalo& Timer::intervalo() const {
	return this->pIntervalo;
}

const bool& Timer::lancaEvento() const {
	return this->pLancaEvento;
}

const bool& Timer::emLoop() const {
	return this->pEmLoop;
}

const bool& Timer::iniciado() const {
	return this->pIniciado;
}

const bool Timer::parado() const {
	return !this->pIniciado || this->pPausado;
}

const bool Timer::emAndamento() const {
	return !this->parado();
}

const bool& Timer::pausado() const {
	return this->pPausado;
}

const int& Timer::quantasVezes() const {
	return this->pQuantasVezes;
}

GeradorDeEventos& Timer::captaEGeraEmLoop() {
	if (this->pausado()) {
		Debug::sair("Timer::executa():: FIXME: pausar ainda não está"
				" implementado! :(");
	}

	if (!this->pIniciaParado) {
		this->pEstado->atribui(true, this->pUniverso, "iniciado");
		this->inicia();
	}

	while (!this->encerrou()) {
		const Evento* e = this->esperaAteQueVenhaEvento();

		if (e != NULL) {
			if (e->modificaEstadoDiretamente()
				&& (e->nomeCompleto() == this->pEstado->nomeCompleto()))
			{
				Valor campo = e->modificador().campo();

				if (campo == Valor("pausado")) {
					this->pPausado = this->pEstado->valor("pausado").emBool();
					Debug::sair("Timer::executa():: FIXME: pausar ainda não está"
							" implementado! :(");
				} else if (campo == Multifuncional::CAMPO_PRINCIPAL) {
					this->pQuantasVezes = (int) this->pEstado->valor().emDouble();
				} else if (campo == Valor("em milionésimos de segundo")) {
					this->pIntervalo = Intervalo(
							this->pIntervalo(),
							UnidadeGenerica(this->pEstado->valor(
											"em milionésimos de segundo").emDouble(),
											this->pIntervalo.unidadeDeTempo()
											.emString()));
				} else if (campo == Valor("intervalo")) {
					this->pIntervalo = Intervalo(
							this->pEstado->valor("intervalo").emDouble(),
							UnidadeGenerica((double) this->pIntervalo
										    .emMilionesimosDeSegundo().emLong(),
											this->pIntervalo.unidadeDeTempo()
											.emString()));	
				} else if (campo == Valor("unidade")) {
					this->pIntervalo = Intervalo(
							this->pIntervalo(),
							UnidadeGenerica((double) this->pIntervalo
										    .emMilionesimosDeSegundo().emLong(),
											this->pEstado->valor("unidade").emString()));
				} else if (campo == Valor("loop")) {
					this->pEmLoop = this->pEstado->valor("loop").emBool();
				} else if (campo == Valor("iniciado")) {
					if (!this->pEstado->valor("iniciado").pareceSerBoleano()) {
						Debug::msg(WARN, "Timer::executa():: o valor iniciado"
								" possui um valor que não é verdadeiro nem falso: "
								+ this->pEstado->valor("iniciado") + " this: "
								+ *this);
					} else {
						if (this->pEstado->valor("iniciado").emBool()) {
//							Debug::msg(INFO, "--- Timer:: iniciando! " + *this);
							this->inicia();
						} else {
//							Debug::msg(INFO, "--- Timer:: parando! " + *this);
							this->para();
						}	
					}
				} else if (campo == Valor("lança evento")) {
					this->pEmLoop = this->pEstado->valor("lança evento").emBool();
				}
			}

//			Debug::msg(INFO, "--- Timer (" + *this
//					+ ") recebeu evento: " + *e);

			delete e;
		}
	}

	return *this;
}

const Estado& Timer::estadoRelacionado() const {
	return *(this->pEstado);
}

string Timer::emString() const {
	return "Estado: " + this->pEstado->emString()
			+ ", Vezes: " + Inteiro(this->quantasVezes())+ ", Intervalo: "
			+ this->intervalo() + ", Em andamento? " + string(
			  this->emAndamento()?"sim":"não") + ".";
}
