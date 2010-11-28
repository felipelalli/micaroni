/**
 * $RCSfile: OuvidorDosGeradoresDeEventos.cpp,v $
 * $Date: 2005/03/15 21:59:01 $
 * $Revision: 1.6 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/OuvidorDosGeradoresDeEventos.h"
using namespace biblia::dinamicas::sinfonia;

OuvidorDosGeradoresDeEventos
		::OuvidorDosGeradoresDeEventos(
		GeradorDeEventos* receptor,
		GeradorDeEventos* doador)
	:pGeradorReceptor(receptor),
	 pGeradorDoador(doador), pEsperaAcabar(1),
	 pEsperaExecutar(0), pAcabou(false), pExecutou(false)
{}

OuvidorDosGeradoresDeEventos::~OuvidorDosGeradoresDeEventos() {
	this->pAcabou = true;
//	Debug::msg(INFO, "--- manda encerrar gerador: " + *(this->pGerador));
	this->pGeradorDoador->encerra(); // Encerra o Gerador doador associado

	if (!this->pExecutou) {
#ifdef _DEBUG
		Debug::msg(INFO, "Esperando OuvidorDosGeradoresDeEventos executar... this: " + *this);
#endif
		this->pEsperaExecutar.esperar();
	}

	if (this->pExecutou) {
//		Debug::msg(INFO, "--- Esperando OuvidorDosGeradoresDeEventos acabar...");
		this->pEsperaAcabar.esperar();
	}

//	Debug::msg(INFO, "--- OuvidorDosGeradoresDeEventos acabou!");
}

Executavel& OuvidorDosGeradoresDeEventos::executa() {
	if (this->pExecutou) {
		Debug::sair("Concretizador::executa:: só pode ser executado uma vez! "
				+ *this);
	} else {
		this->pEsperaAcabar.esperar();
		this->pExecutou = true;

//		Debug::msg(INFO, "--- vai executar um ouvidor!");

		while (!this->pAcabou) {
			const Evento* novoEvento
					= this->pGeradorDoador->esperaAteQueHajaEvento();

			this->pGeradorReceptor->gera(novoEvento);
		}

		this->pEsperaAcabar.liberar();
		this->pEsperaExecutar.liberar();
	}

	return *this;
}

string OuvidorDosGeradoresDeEventos::emString() const {
	return Objeto::emString()
			+ " de {" + this->pGeradorReceptor->emString() + "}"
			+ " recebendo eventos de {"
			+ this->pGeradorDoador->emString() + "}";
}
