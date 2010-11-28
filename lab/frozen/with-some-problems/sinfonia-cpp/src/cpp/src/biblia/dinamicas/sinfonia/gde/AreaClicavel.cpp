/**
 * $RCSfile: AreaClicavel.cpp,v $
 * $Date: 2005/03/30 01:23:46 $
 * $Revision: 1.6 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/gde/AreaClicavel.h"
using namespace biblia::dinamicas::sinfonia::gde;

AreaClicavel::AreaClicavel(const MediadorDeEstados& mde,
		 const UniversoDeTempo& tempo, Estado* e)
	:GeradorDeEventosEspecial(mde),
	 pTempo(tempo), pEstado(e)
{
	this->modificaEventosQueTrata()
				.adiciona(this->pEstado->valor().emString());
	// ver executa
}

AreaClicavel::~AreaClicavel() {}

GeradorDeEventos& AreaClicavel::captaEGeraEmLoop() {
	const MediadorDeEstados& mde = this->mediadorDeEstados();
	Valor nomeEstado(this->pEstado->valor());

	if (!mde.existeEstado(nomeEstado)) {
		Debug::msg(WARN, "AreaClicavel: aguardando"
				" Estado '" + nomeEstado + "'"
				" ser criado...");
	}
	
	while (!mde.existeEstado(nomeEstado) && !this->encerrou()) {
		Thread::sleep(Intervalo(100, Milissegundo()));
	}

	try {
		this->pEstado->atribui(false, this->pTempo, "mouse sobre");
		this->pEstado->atribui(false, this->pTempo, "clicado sobre");

		this->modificaEventosQueTrata()
				.adiciona(mde.estado(this->pEstado->valor()).valor().emString());

	} catch(const Excecao& ex) {
		ImpossivelCriarAreaClicavelExcecao icace;
		icace << "Erro ao criar AreaClicavel! Campo principal deve"
				" existir e deve existir tamb�m um Estado da classe"
				" Mouse v�lido relacionado."
				" Lembre-se que � o nome completo. Excecao: " + ex;

		throw icace;
	}

	while (!this->encerrou()) {
		const Evento* e = this->esperaAteQueVenhaEvento();

		if (e != NULL) {
			try {
				if (e->modificaEstadoDiretamente()) {
					Valor campo = e->modificador().campo();

					if (e->nomeCompleto() == this->pEstado->valor() // clicou
						|| e->nomeCompleto() == this->mediadorDeEstados()
						  .estado(this->pEstado->valor()).valor()) // moveu
					{
						Lista<Evento*> aDisparar;

						if (this->pEstado->valor("habilitado").emBool()) {
							const Estado& mousePos
								= this->mediadorDeEstados().estado(
									this->mediadorDeEstados()
								    .estado(this->pEstado->valor()).valor());

							int xMouse = mousePos.valor("x").emInt();
							int yMouse = mousePos.valor("y").emInt();

							const Estado& mouse
								= this->mediadorDeEstados()
								    .estado(this->pEstado->valor());

							bool clicado = mouse.valor("bot�o esquerdo pressionado").emBool();

							int xArea = this->pEstado->valor("x").emInt();
							int yArea = this->pEstado->valor("y").emInt();
							int largura = this->pEstado->valor("largura").emInt();
							int altura = this->pEstado->valor("altura").emInt();
							bool clicadoSobre = this->pEstado->valor(
									"clicado sobre").emBool();

							bool mouseSobre = this->pEstado->valor(
									"mouse sobre").emBool();

							if (xMouse >= xArea
								&& xMouse < xArea + largura
								&& yMouse >= yArea
								&& yMouse < yArea + altura)
							{
								if (!mouseSobre) {
									// lan�a mouse sobre
									ModificadorDeEstado mde(this->pEstado->nomeCompleto());
									mde.adicionaParametro(Valor(true));
									mde.defineCampo("mouse sobre");
									Evento evento(this->pEstado->nome(), mde);
									evento.grupo(this->pEstado->grupo());
									Evento* disparado = evento.dispara(this->pTempo);
									disparado->especial(true);
									aDisparar.adiciona(disparado);
									this->pEstado->atribui(true, "mouse sobre");
								}

								if (clicado && !clicadoSobre) {
									// lan�a evento clicado sobre
									ModificadorDeEstado mde(this->pEstado->nomeCompleto());
									mde.adicionaParametro(Valor(true));
									mde.defineCampo("clicado sobre");
									Evento evento(this->pEstado->nome(), mde);
									evento.grupo(this->pEstado->grupo());
									Evento* disparado = evento.dispara(this->pTempo);
									disparado->especial(true);
									aDisparar.adiciona(disparado);
									this->pEstado->atribui(true, "clicado sobre");
								}

								if (!clicado && clicadoSobre) {
									// lan�a evento desclicando
									ModificadorDeEstado mde(this->pEstado->nomeCompleto());
									mde.adicionaParametro(Valor(false));
									mde.defineCampo("clicado sobre");
									Evento evento(this->pEstado->nome(), mde);
									evento.grupo(this->pEstado->grupo());
									Evento* disparado = evento.dispara(this->pTempo);
									disparado->especial(true);
									aDisparar.adiciona(disparado);
									this->pEstado->atribui(false, "clicado sobre");
								}

							} else { // est� fora da �rea
								if (mouseSobre) {
									// lan�a pra tirar o mouse sobre
									ModificadorDeEstado mde(this->pEstado->nomeCompleto());
									mde.adicionaParametro(Valor(false));
									mde.defineCampo("mouse sobre");
									Evento evento(this->pEstado->nome(), mde);
									evento.grupo(this->pEstado->grupo());
									Evento* disparado = evento.dispara(this->pTempo);
									disparado->especial(true);
									aDisparar.adiciona(disparado);
									this->pEstado->atribui(false, "mouse sobre");
								}

								if (clicadoSobre) {
									// lan�a pra desclicar
									ModificadorDeEstado mde(this->pEstado->nomeCompleto());
									mde.adicionaParametro(Valor(false));
									mde.defineCampo("clicado sobre");
									Evento evento(this->pEstado->nome(), mde);
									evento.grupo(this->pEstado->grupo());
									Evento* disparado = evento.dispara(this->pTempo);
									disparado->especial(true);
									aDisparar.adiciona(disparado);
									this->pEstado->atribui(false, "clicado sobre");
								}
							}
						}

						for (int i = 0; i < aDisparar.tamanho(); i++) {
							this->gera(aDisparar[i]);
						}
					}
				}
			} catch(const Excecao& e) {
				Debug::msg(WARN, "AreaClicavel::executa():: ignorando"
						" a exce��o " + e + "! Corrija o mais r�pido"
						" poss�vel.");
			}

			delete e;
		}
	}

	return *this;
}

string AreaClicavel::emString() const {
	return "AreaClicavel(" + *(this->pEstado) + ")x="
			+ Inteiro(this->pEstado->valor("x").emInt())
			+ ", y=" + Inteiro(this->pEstado->valor("y").emInt())
			+ ", largura=" + Inteiro(this->pEstado->valor("largura").emInt())
			+ ", altura=" + Inteiro(this->pEstado->valor("altura").emInt());
}
