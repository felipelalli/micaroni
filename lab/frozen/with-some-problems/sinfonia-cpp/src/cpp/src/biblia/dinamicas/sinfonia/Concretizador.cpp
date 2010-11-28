/**
 * $RCSfile: Concretizador.cpp,v $
 * $Date: 2005/03/30 01:23:45 $
 * $Revision: 1.16 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/Concretizador.h"
using namespace biblia::dinamicas::sinfonia;

Concretizador::Concretizador(const MediadorDeEstados& mde)
		:GeradorDeEventos(mde, true), pResultados(),
		 pLixo(), pAcabou(false),
		 pEsperaAcabar(1), pExecutou(false),
		 pEsperaExecutar(0)
{
//	Debug::msg(INFO, "--- criou concretizador!");
}

Concretizador::~Concretizador() {
	this->pAcabou = true;
	this->encerra();

	if (!this->pExecutou) {
#ifdef _DEBUG
		Debug::msg(INFO, "Esperando Concretizador executar... this: " + *this);
#endif
		this->pEsperaExecutar.esperar();
	}

	if (this->pExecutou) {
		this->pEsperaAcabar.esperar();
	}

//	Debug::msg(INFO, "--- destruiu concretizador");
}

Concretizador& Concretizador::adiciona(Resultado* r) {
	const Lista<const Evento*>& relacionados
			= r->situacao().seAcontecerUmDessesEventos();

	r->define(this->mediadorDeEstados(), this);

	for (int i = 0; i < relacionados.tamanho(); i++) {
		string id = relacionados[i]->nomeCompleto().valor();

		if (this->pResultados.existe(id)) {
			this->pResultados[id]->adiciona(r);
//			Debug::msg(INFO, "--- Concretizador::adiciona:: ja existia "
//					+ id + "... Adicionando na lista! ;)");
		} else {
			Lista<Resultado*>* novaLista = new Lista<Resultado*>();
			this->pLixo.adiciona(novaLista);
			novaLista->adiciona(r);
			this->pResultados.insere(id, novaLista);
		}
	}

	return *this;
}

GeradorDeEventos& Concretizador::captaEGeraEmLoop() {
	if (this->pExecutou) {
		Debug::sair("Concretizador::executa:: só pode ser executado uma vez! "
				+ *this);
	} else {
		this->pEsperaAcabar.esperar();
		this->pExecutou = true;

//		Debug::msg(INFO, "--- vai executar concretizador!");

		while (!this->pAcabou) {
			const Evento* evento = this->esperaAteQueVenhaEvento();

			if (evento != NULL) {
				const Evento& e = *evento;
				const string id = e.nomeCompleto().valor();
				const UniversoDeTempo& tempo = e.momentoDoDisparo().universo();

				if (!this->pResultados.existe(id)) {
/*#ifdef _DEBUG
					if (!this->pJaExibiuEsteErro.existe(id)) {
						Debug::msg(INFO, "Concretizador::executa()::"
								" ignorando evento: " + e);

						this->pJaExibiuEsteErro.insere(id, true);
					}
#endif*/
				} else {
				//if (this->pResultados.existe(id)) {
					const Lista<Resultado*>& resultados = *(this->pResultados[id]);

					for (int j = 0; j < resultados.tamanho(); j++) {
						Resultado& resultado = *(resultados[j]);

//						Debug::msg(INFO, "--- resultado atual: " + resultado);

						if (resultado.situacao().aconteceu(e)) {
							resultado.executa();

							/*
							 * O resultado já se encarrega de adicionar
							 * os eventos gerados a este Concretizador
							 */
						}
					}
				}

				delete evento;
			}
		}

//		Debug::msg(INFO, "--- executou concretizador!");
		this->pEsperaAcabar.liberar();
		this->pEsperaExecutar.liberar();
	}

	return *this;
}
