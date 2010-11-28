/**
 * $RCSfile: MouseBiblia.cpp,v $
 * $Date: 2005/03/31 23:45:29 $
 * $Revision: 1.11 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/gde/MouseBiblia.h"
using namespace biblia::dinamicas::sinfonia::gde;

MouseBiblia::MouseBiblia(const MediadorDeEstados& mde,
						 const UniversoDeTempo& u,
					 Estado* e)
	:GeradorDeEventosEspecial(mde), pEstado(e),
	 pGeradorDeEventosParaMouseEmThread(NULL),
	 pTempo(u), pNomeDoEstadoRelacionado("???")
{
	this->modificaEventosQueTrata().adiciona(
			this->pEstado->nomeCompleto().valor());
}

MouseBiblia::~MouseBiblia() {
	this->pGeradorDeEventosParaMouse.termina();

	while (!this->pGeradorDeEventosParaMouse.terminou()) {
		Thread::sleep(Intervalo(10, Milissegundo()));
	}

	if (this->pGeradorDeEventosParaMouseEmThread) {
		delete this->pGeradorDeEventosParaMouseEmThread;
	}
}

string MouseBiblia::emString() const {
	return "MouseBiblia(" + this->pNomeDoEstadoRelacionado + ")";
}

GeradorDeEventos& MouseBiblia::captaEGeraEmLoop() {
	this->pNomeDoEstadoRelacionado
			= Valor(this->pEstado->valor().emString()).emString();

	if (!this->mediadorDeEstados()
		.existeEstado(this->pNomeDoEstadoRelacionado))
	{
		Debug::msg(WARN, "MouseBiblia: aguardando"
				" Estado '" + this->pNomeDoEstadoRelacionado + "'"
				" ser criado...");
	}

	while (!this->encerrou() && !this->mediadorDeEstados()
			.existeEstado(this->pNomeDoEstadoRelacionado))
	{
		Thread::sleep(Intervalo(100, Milissegundo()));
	}

	try {
		this->pEstado->atribui(this->pNomeDoEstadoRelacionado, this->pTempo);
		Estado* alvo = (Estado*) & this->mediadorDeEstados()
				.estado(this->pNomeDoEstadoRelacionado);

		int x = this->pMa.posX();
		int y = this->pMa.posY();

		// evento X
		{
			ModificadorDeEstado mde(this->pEstado->valor()); // valor do campo principal
			mde.adicionaParametro(Valor(x));

			mde.defineCampo("x");
			Evento moveX(this->pEstado->valor(), mde);
			Evento* disparado = moveX.dispara(this->pTempo);
			disparado->especial(true);
			this->gera(disparado);
		}

		// evento Y
		{
			ModificadorDeEstado mde(this->pEstado->valor()); // valor do campo principal
			mde.adicionaParametro(Valor(y));

			mde.defineCampo("y");
			Evento moveY(this->pEstado->valor(), mde);
			Evento* disparado = moveY.dispara(this->pTempo);
			disparado->especial(true);
			this->gera(disparado);
		}

		// torna visível
		{
			ModificadorDeEstado mde(this->pEstado->valor()); // valor do campo principal
			mde.adicionaParametro(Valor(true));

			mde.defineCampo("visível");
			Evento visivel(this->pEstado->valor(), mde);
			Evento* disparado = visivel.dispara(this->pTempo);
			disparado->especial(true);
			this->gera(disparado);
		}
	} catch(const Excecao& ex) {
		ImpossivelCriarMouseBibliaExcecao icmbe;
		icmbe << "Erro ao criar MouseBiblia! Campo principal deve"
				" existir e deve existir também um Estado relacionado."
				" Lembre-se que é o nome completo. Excecao: " + ex;

		throw icmbe;
	}

	this->pGeradorDeEventosParaMouse.defineThis(this);

	this->pGeradorDeEventosParaMouseEmThread
			= new Thread(this->pGeradorDeEventosParaMouse,
				"gerador de eventos para mouse em thread: " + *this);

	this->pGeradorDeEventosParaMouseEmThread->start();

	while (!this->encerrou()) {
		const Evento* e = this->esperaAteQueVenhaEvento();

		if (e != NULL) {
			if (e->modificaEstadoDiretamente()
				&& (e->nomeCompleto() == this->pEstado->nomeCompleto()))
			{
				Valor campo = e->modificador().campo();

				if (campo == Multifuncional::CAMPO_PRINCIPAL) {
					Lista<Evento*> aDisparar;

					string nomeDoEstadoRelacionado
							= this->pEstado->valor().emString();

					// retira o visível do Estado anterior
					{
						ModificadorDeEstado mde(this->pNomeDoEstadoRelacionado);
						mde.adicionaParametro(Valor(false));

						mde.defineCampo("visível");
						Evento retiraVisivelDoEstadoAnterior(
								this->pNomeDoEstadoRelacionado, mde);

						Evento* disparado = retiraVisivelDoEstadoAnterior
								.dispara(this->pTempo);

						disparado->especial(true);
						aDisparar.adiciona(disparado);
					}

					this->pNomeDoEstadoRelacionado
							= this->pEstado->valor().emString();

					// move X
					{
						ModificadorDeEstado mde(nomeDoEstadoRelacionado);
						mde.adicionaParametro(Valor(this->pMa.posX()));

						mde.defineCampo("x");
						Evento moveX(nomeDoEstadoRelacionado, mde);

						Evento* disparado = moveX.dispara(this->pTempo);

						disparado->especial(true);
						aDisparar.adiciona(disparado);
					}

					// move Y
					{
						ModificadorDeEstado mde(nomeDoEstadoRelacionado);
						mde.adicionaParametro(Valor(this->pMa.posY()));

						mde.defineCampo("y");
						Evento moveY(nomeDoEstadoRelacionado, mde);

						Evento* disparado = moveY.dispara(this->pTempo);

						disparado->especial(true);
						aDisparar.adiciona(disparado);
					}

					// coloca visível no Estado atual
					{
						ModificadorDeEstado mde(nomeDoEstadoRelacionado);
						mde.adicionaParametro(Valor(true));

						mde.defineCampo("visível");
						Evento colocaVisivelNoEstado(
								nomeDoEstadoRelacionado, mde);

						Evento* disparado = colocaVisivelNoEstado
								.dispara(this->pTempo);

						disparado->especial(true);
						aDisparar.adiciona(disparado);
					}

					for (int i = 0; i < aDisparar.tamanho(); i++) {
//						Debug::msg(WARN, "--- vai disparar: " + *(aDisparar[i]));
						this->gera(aDisparar[i]);
					}
				}
			}

			delete e;
		}
	}

	return *this;
}

MouseBiblia::GeraEventosParaMouse
		::GeraEventosParaMouse()
	:pMouseBiblia(NULL), pTerminou(false),
	 pTermina(false)
{}

MouseBiblia::GeraEventosParaMouse& MouseBiblia
		::GeraEventosParaMouse::termina()
{
	this->pTermina = true;
	return *this;
}

const bool& MouseBiblia::GeraEventosParaMouse::terminou() {
	return this->pTerminou;
}

Executavel& MouseBiblia::GeraEventosParaMouse::executa() {
	Mouse& m = this->pMouseBiblia->pMa;
	MouseBiblia& mb = *(this->pMouseBiblia);
	
	while (!this->pTermina) {
		m.executa();
		Lista<Evento*> aDisparar;

		if (m.moveuMouse()) {
//			Debug::msg(INFO, "--- moveu mouse!!");

			int x = m.posX();
			int y = m.posY();

			string estadoRelacionado = mb.pEstado->valor().valor();

			// evento X
			{
				ModificadorDeEstado mde(estadoRelacionado); // valor do campo principal
				mde.adicionaParametro(Valor(x));
				mde.defineCampo("x");
				Evento moveX(estadoRelacionado, mde);
				Evento* disparado = moveX.dispara(mb.pTempo);
				disparado->especial(true);

				aDisparar.adiciona(disparado);
			}

			// evento Y
			{
				ModificadorDeEstado mde(estadoRelacionado); // valor do campo principal
				mde.adicionaParametro(Valor(y));

				mde.defineCampo("y");
				Evento moveY(estadoRelacionado, mde);
				Evento* disparado = moveY.dispara(mb.pTempo);
				disparado->especial(true);
				aDisparar.adiciona(disparado);
			}
		}

		if (m.pressionouBotaoEsquerdo()
			|| m.liberouBotaoEsquerdo())
		{
			bool valor = m.botaoEsquerdoPressionado();

			ModificadorDeEstado mde(mb.pEstado->nomeCompleto());
			mde.adicionaParametro(Valor(valor));

			mde.defineCampo("botão esquerdo pressionado");
			Evento evento(mb.pEstado->nome(), mde);
			evento.grupo(mb.pEstado->grupo());
			Evento* disparado = evento.dispara(mb.pTempo);
			disparado->especial(true);
			aDisparar.adiciona(disparado);
		}

		if (m.pressionouBotaoDireito()
			|| m.liberouBotaoDireito())
		{
			bool valor = m.botaoDireitoPressionado();

			ModificadorDeEstado mde(mb.pEstado->nomeCompleto());
			mde.adicionaParametro(Valor(valor));

			mde.defineCampo("botão direito pressionado");
			Evento evento(mb.pEstado->nome(), mde);
			evento.grupo(mb.pEstado->grupo());
			Evento* disparado = evento.dispara(mb.pTempo);
			disparado->especial(true);
			aDisparar.adiciona(disparado);
		}

		if (m.pressionouBotaoCentral()
			|| m.liberouBotaoCentral())
		{
			bool valor = m.botaoCentralPressionado();

			ModificadorDeEstado mde(mb.pEstado->nomeCompleto());
			mde.adicionaParametro(Valor(valor));

			mde.defineCampo("botão central pressionado");
			Evento evento(mb.pEstado->nome(), mde);
			evento.grupo(mb.pEstado->grupo());
			Evento* disparado = evento.dispara(mb.pTempo);
			disparado->especial(true);
			aDisparar.adiciona(disparado);
		}

		m.limpa();

		for (int i = 0; i < aDisparar.tamanho(); i++) {
//			Debug::msg(WARN, "--- disparando: " + *(aDisparar[i]));
			mb.gera(aDisparar[i]);
		}

		Thread::sleep(Intervalo(10, Milissegundo()));
	}

	this->pTerminou = true;

	return *this;
}

void MouseBiblia::GeraEventosParaMouse::defineThis(MouseBiblia* mb) {
	this->pMouseBiblia = mb;
}

