/**
 * $RCSfile: Resultado.cpp,v $
 * $Date: 2005/03/15 21:59:01 $
 * $Revision: 1.2 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/Resultado.h"
using namespace biblia::dinamicas::sinfonia;

Resultado::Resultado(const Situacao* s):pSituacao(s), pMediador(NULL) {}
Resultado::~Resultado() {}

GeradorDeEventos& Resultado::gerador() {
	if (this->pGerador == NULL) {
		Debug::sair("Resultado::gerador():: o Gerador precisa ser definido!");
	}

	return *(this->pGerador);
}

const MediadorDeEstados& Resultado::mediador() const {
	if (this->pMediador == NULL) {
		Debug::sair("Resultado::mediador():: o Mediador precisa ser definido!");
	}

	return *(this->pMediador);
}

const Situacao& Resultado::situacao() const {
	if (this->pSituacao == NULL) {
		Debug::sair("Resultado::situacao():: a Situacao precisa ser definida!");
	}

	return *(this->pSituacao);
}

Resultado& Resultado::define(const MediadorDeEstados& mde, GeradorDeEventos* gde) {
	if (this->pMediador) {
		Debug::sair("Resultado::define:: este Resultado ja foi definido!");
	}

	this->pMediador = (const MediadorDeEstados*) &mde;
	this->pGerador = gde;
	return *this;
}
