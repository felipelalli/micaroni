/**
 * $RCSfile: Som.cpp,v $
 * $Date: 2005/03/30 01:23:46 $
 * $Revision: 1.4 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/gde/Som.h"
using namespace biblia::dinamicas::sinfonia::gde;

SomBiblia::SomBiblia(const MediadorDeEstados& mde,
		 ResultadoSonoro& resultadoSonoro,
		 CarregadorDeSom& carregadorDeSom,
		 const UniversoDeTempo& tempo,
		 Estado* e)

	:GeradorDeEventosEspecial(mde), 
	 pCarregadorDeSom (carregadorDeSom),
	 pResultadoSonoro(resultadoSonoro),
	 pTempo (tempo),
	 pEstado(e), pSomRelacionado("???"),
	 pGeradorDeEventosParaSomEmThread(pGeradorDeEventosParaSom)

{
	this->pGeradorDeEventosParaSom.defineThis(this);

	bool impossivelCriar = false;
	ImpossivelCriarSomBibliaExcecao icabe;

	try {
		if (e->valor().indefinida()) {
			impossivelCriar = true;
			icabe << "Valor Indefinido! ";
		} else {
			this->pSomRelacionado = e->valor().emString();

			if (!this->pCarregadorDeSom.jaCarregado(this->pSomRelacionado))
			{
				impossivelCriar = true;
				icabe << "Som não existe!";
			}
		}
	} catch (const Excecao& cie) {
		impossivelCriar = true;
		icabe << cie + " - ";
	}

	if (impossivelCriar) {
		icabe << "Erro na criação da SomBiblia relativa ao Estado '" + *e
				+ "'. Campo PRINCIPAL obrigatório / o som "
				+ "'" + this->pSomRelacionado + "' deve estar"
				+ " previamente criado. This: " + *this;

		throw icabe;
	} else {
		
		bool tocando = false;
		int  volume = 100;
		int  prioridade = -1;
		bool emLoop = false;
		bool paralelo = true;

		try {
			tocando = e->valor("tocando").emBool();
		} catch (const Excecao&) {				
			this->pEstado->atribui(tocando,this->tempo(), "tocando");
		}

		try {
			volume = e->valor("volume").emInt();
		} catch (const Excecao&) {				
			this->pEstado->atribui(volume,this->tempo(), "volume");
		}

		try {
			prioridade = e->valor("prioridade").emInt();
		} catch (const Excecao&) {				
			this->pEstado->atribui(prioridade,this->tempo(), "prioridade");
		}

		try {
			emLoop = e->valor("loop").emBool();
		} catch (const Excecao&) {				
			this->pEstado->atribui(emLoop,this->tempo(), "loop");
		}

		try {
			paralelo = e->valor("paralelo").emBool();
		} catch (const Excecao&) {				
			this->pEstado->atribui(paralelo,this->tempo(), "paralelo");
		}
		
		
		if (tocando){

			this->pResultadoSonoro.toca(
				ComponenteSonoro(
					this->pCarregadorDeSom.som(this->pSomRelacionado),
					volume,
					prioridade,
					emLoop,
					paralelo
				)
			);		
		}
	}

	this->pGeradorDeEventosParaSomEmThread.start();
	this->modificaEventosQueTrata().adiciona(
			this->pEstado->nomeCompleto().valor());
}

SomBiblia::~SomBiblia() {
	this->pGeradorDeEventosParaSom.termina();

	while (!this->pGeradorDeEventosParaSom.terminou()) {
		Thread::sleep(Intervalo(10, Milissegundo()));
	}
}

Som& SomBiblia::somRelacionado() const {
	return this->pCarregadorDeSom.som (this->pSomRelacionado);
}

const string& SomBiblia::nomeDoSomRelacionado() const {
	return this->pSomRelacionado;
}

const UniversoDeTempo& SomBiblia::tempo(){
	return this->pTempo;
}

string SomBiblia::emString() const {
	return "Som(" + this->nomeDoSomRelacionado() + ")("
			+ this->somRelacionado() + ")";
}

GeradorDeEventos& SomBiblia::captaEGeraEmLoop() {
	while (!this->encerrou()) {
		const Evento* e = this->esperaAteQueVenhaEvento();

		if (e != NULL) {
			if (e->modificaEstadoDiretamente()
				&& (e->nomeCompleto() == this->pEstado->nomeCompleto()))
			{
				Valor campo = e->modificador().campo();

				if (campo == Multifuncional::CAMPO_PRINCIPAL) {

					Debug::msg(WARN, "SomBiblia::executa::"
							" Ao tentar mudar de '"
							+ this->nomeDoSomRelacionado()
							+ "' para '"
							+ this->pEstado->valor()
							+ " não é possível mudar o nome do"
							" som relacionada! Corrija isto"
							" o mais rápido possível porque"
							" o nome do Estado ficou desatualizado!");

				} else if (campo == Valor("tocando")) {
					
					if (e->modificador().parametros()[0].valorAlvo() == Valor(true)){

						this->pResultadoSonoro.toca(
							ComponenteSonoro(
								this->pCarregadorDeSom.som(this->pSomRelacionado),
								this->pEstado->valor("volume").emInt(),
								this->pEstado->valor("prioridade").emInt(),
								this->pEstado->valor("loop").emBool(),
								this->pEstado->valor("paralelo").emBool()
							)
						);	
					}
				}
			}

			delete e;
		}
	}

	return *this;
}

SomBiblia::GeraEventosParaSom
		::GeraEventosParaSom()
	:pSomBiblia(NULL), pTerminou(false),
	 pTermina(false), pTocandoAnterior(false)
{}

Executavel& SomBiblia::GeraEventosParaSom::executa() {

	this->pTocandoAnterior = this->pSomBiblia->somRelacionado().tocando();

	while (!this->pTermina) {

		bool tocandoAtual = this->pSomBiblia->somRelacionado().tocando();
		
		if ((tocandoAtual==false) && (this->pTocandoAnterior==true)) {

			// Lança evento que terminou
			SomBiblia& a = *(this->pSomBiblia);

			ModificadorDeEstado mde(a.pEstado->nomeCompleto());
			mde.adicionaParametro(Valor(false));

			mde.defineCampo("tocando");
			Evento deixaDeEstarIniciado(a.pEstado->nome(), mde);
			deixaDeEstarIniciado.grupo(a.pEstado->grupo());
			Evento* disparado = deixaDeEstarIniciado.dispara(a.tempo());
			disparado->especial(true);
			a.gera(disparado);
		}

		Thread::sleep(Intervalo(10, Milissegundo()));

		this->pTocandoAnterior = tocandoAtual;
	}

	this->pTerminou = true;
	return *this;
}

SomBiblia::GeraEventosParaSom& SomBiblia
		::GeraEventosParaSom::termina()
{
	this->pTermina = true;
	return *this;
}

const bool& SomBiblia::GeraEventosParaSom::terminou() {
	return this->pTerminou;
}

void SomBiblia::GeraEventosParaSom::defineThis(SomBiblia* ab) {
	this->pSomBiblia = ab;
}
