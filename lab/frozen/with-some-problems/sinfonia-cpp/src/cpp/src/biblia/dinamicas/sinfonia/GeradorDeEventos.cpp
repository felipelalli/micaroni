/**
 * $RCSfile: GeradorDeEventos.cpp,v $
 * $Date: 2005/03/30 01:23:45 $
 * $Revision: 1.23 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/GeradorDeEventos.h"
using namespace biblia::dinamicas::sinfonia;

GeradorDeEventos::GeradorDeEventos(
		const MediadorDeEstados& mde, bool desabilitaAviso)
	:pMediadorDeEstados(mde), pSemaforo(0),
	 pSemaforo2(0), pEventosGerados(), pEventosCapturados(),
	 pEventosQueTrata(), pEncerrou(false),
	 pSynchronized1(1), pSynchronized2(1),
	 pSynchronized3(1), pSynchronized4(1),
	 pApenasGerador(false), pEncerrouDeFato(false),
	 pExecutou(false)
{
	if (!desabilitaAviso) {
		Debug::msg(WARN, "GeradorDeEventos:: esta classe"
				" não deve ser sobrescrita diretamente. Para"
				" implementar um GeradorDeEventos específico"
				" use GeradorDeEventosEspecial. Caso você tenha"
				" certeza que deseja sobrescrever esta diretamente,"
				" passe 'true' ao construtor desta ao invés de utilizar"
				" o construtor padrão. this: " + Objeto::emString());
	}
}

// Para captar eventos:

GeradorDeEventos& GeradorDeEventos::naoDeveReceberNenhumEvento() {
	this->pApenasGerador = true;
	return *this;
}

GeradorDeEventos& GeradorDeEventos::terminaLoopPrincipal() {
	this->pEncerrouDeFato = true;
	return *this;
}

GeradorDeEventos& GeradorDeEventos::iniciaLoopPrincipal() {
	this->pExecutou = true;
	return *this;
}

const bool& GeradorDeEventos::naoRecebeNenhumEvento() const {
	return this->pApenasGerador;
}

GeradorDeEventos& GeradorDeEventos::aconteceu(const Evento* e) {
//	this->pProtecao1.esperar();
	Lock lock(this->pSynchronized3);

	if (e == NULL) {
#ifdef _DEBUG
//		Debug::msg(INFO, *this + " - GeradorDeEventos::aconteceu:: Ignorando Evento NULL...");
#endif
	} else {
		if (!e->disparado()) {
			EventoNaoDisparadoExcecao ende;
			ende << "GeradorDeEventos::aconteceu:: o Evento "
					"passado deve estar disparado!! Evento: " + *e;

			Debug::msg(ERRO, ende.emString());
			throw ende;

//			Debug::sair("GeradorDeEventos::aconteceu:: o Evento "
//					"passado deve estar disparado!! Evento: " + *e);
		} else {
//			Debug::msg(INFO, "--- GeradorDeEventos::aconteceu: " + *e);
			this->pEventosCapturados.adiciona(e);
			this->pSemaforo2.liberar();
		}
	}

//	this->pProtecao1.liberar();
	return *this;
}

const Evento* GeradorDeEventos::esperaAteQueVenhaEvento() {
//	Debug::msg(INFO, "--- GeradorDeEventos:: esperando evento... " + *this);
	this->pSemaforo2.esperar();
	Lock lock(this->pSynchronized4);

//	this->pProtecao2.esperar();
	const Evento* retorno = NULL;

	if (!this->encerrou()) {
		try {
			retorno = this->pEventosCapturados[0];
			this->pEventosCapturados.remove(0);
		} catch (IndiceForaDeIntervaloListaExcecao& e) {
			Debug::msg(ERRO, "GeradorDeEventos::esperaAteQueVenhaEvento:: "
					"ERRO GRAVE: o semáforo foi liberado sem autorização! " + e);

			retorno = NULL;
		}
	}

//	Debug::msg(INFO, string("--- GeradorDeEventos:: vai retornar: ") + (!retorno?"NULL":""+ *retorno));

//	this->pProtecao2.liberar();
	return retorno;
}

const int GeradorDeEventos::quantosEventosEmEsperaParaVir() const {
	return this->pEventosCapturados.tamanho();
}

const Lista<Identificacao>& GeradorDeEventos::eventosQueTrata() const {
	return this->pEventosQueTrata;
}

Lista<Identificacao>& GeradorDeEventos::modificaEventosQueTrata() {
	return this->pEventosQueTrata;
}

// Geração de eventos:

GeradorDeEventos& GeradorDeEventos::gera(const Evento* e) {
//	this->pProtecao1.esperar();
	Lock lock(this->pSynchronized1);

	if (e == NULL) {
#ifdef _DEBUG
//		Debug::msg(INFO, *this + " - GeradorDeEventos::gera::"
//				" Ignorando Evento NULL...");
#endif
	} else {
		if (!e->disparado()) {
			EventoNaoDisparadoExcecao ende;
			ende << "GeradorDeEventos::gera:: o Evento "
					"passado deve estar disparado!! Evento: " + *e;

			Debug::msg(ERRO, ende.emString());
			throw ende;

//			Debug::sair("GeradorDeEventos::gera:: o Evento "
//					"passado deve estar disparado!! Evento: " + *e);
		} else {
			this->pEventosGerados.adiciona(e);
			this->pSemaforo.liberar();
		}
	}

//	this->pProtecao1.liberar();
	return *this;
}

GeradorDeEventos& GeradorDeEventos
		::lancaIntermediario(const Valor& nomeCompletoDoEvento)
{
	Evento evento(nomeCompletoDoEvento);
	Evento* disparado = evento.dispara(this->mediadorDeEstados().universo());
	this->gera(disparado);

	return *this;
}

GeradorDeEventos& GeradorDeEventos::lanca(
		const Valor& valor, const Valor& nomeCompletoDoEstado,
		const Valor& campo, const Identificacao& operacao)
{
	ModificadorDeEstado mde(nomeCompletoDoEstado, operacao);
	mde.defineCampo(campo);
	mde.adicionaParametro(valor);

	Evento evento(nomeCompletoDoEstado, mde);
	Evento* disparado = evento.dispara(this->mediadorDeEstados().universo());
	this->gera(disparado);

	return *this;
}

GeradorDeEventos::~GeradorDeEventos() {
	//	Debug::msg(INFO, "--- vai deletar (encerrar) gerador de eventos");

	if (this->pExecutou) {

		if (!this->encerrou()) {
			this->encerra();
		}

		if (!this->pEncerrouDeFato) {
			Debug::msg(INFO, "O GeradorDeEventos: '" + *this + "' ainda não"
					" encerrou, aguardando que ele se encerre...");

			int timeOut = 0;
			while (!this->pEncerrouDeFato && timeOut < 1000) {
				Thread::sleep(Intervalo(10, Milissegundo()));
				timeOut++;
			}

			if (timeOut >= 1000) {
				Debug::msg(ERRO, "Timeout de 10 segundos!"
					" Tentando sair... this: " + *this);
			}
		}
	}

//	Debug::msg(INFO, "--- deletou gerador de eventos");
}

const MediadorDeEstados& GeradorDeEventos::mediadorDeEstados() const {
	return this->pMediadorDeEstados;
}

const Evento* GeradorDeEventos::esperaAteQueHajaEvento() {
//	Debug::msg(INFO, "--- GeradorDeEventos::esperaAteQueHajaEvento... " + *this);
	this->pSemaforo.esperar();
	Lock lock(this->pSynchronized2);

//	this->pProtecao2.esperar();
	const Evento* retorno = NULL;

	if (!this->encerrou()) {
		try {
			retorno = this->pEventosGerados[0];
			this->pEventosGerados.remove(0);
		} catch (IndiceForaDeIntervaloListaExcecao& e) {
			Debug::sair("GeradorDeEventos::esperaAteQueHajaEvento:: "
					"o semáforo foi liberado sem autorização! " + e);
		}
	}

//	Debug::msg(INFO, string(*this + "--- GeradorDeEventos:: vai retornar: ") + (!retorno?"NULL":""+ *retorno));

//	this->pProtecao2.liberar();
	return retorno;
}

const int GeradorDeEventos::quantosEventosEmEspera() const {
	return this->pEventosGerados.tamanho();
}

const bool GeradorDeEventos::encerrou() const {
	return this->pEncerrou;
}

GeradorDeEventos& GeradorDeEventos::encerra() {
//	Debug::msg(INFO, "--- GeradorDeEventos::encerra...");

	this->pEncerrou = true;

	while (!this->pSemaforo.esperar(false)) {
		this->pSemaforo.liberar();
	}

	while (!this->pSemaforo2.esperar(false)) {
		this->pSemaforo2.liberar();
	}

//	Debug::msg(INFO, "--- Fim de GeradorDeEventos::encerra...");

	return *this;
}

Executavel& GeradorDeEventos::executa() {
	this->iniciaLoopPrincipal();
	this->captaEGeraEmLoop();
	this->terminaLoopPrincipal();

	return *this;
}
