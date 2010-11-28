/**
 * $RCSfile: EstadoAlvo.cpp,v $
 * $Date: 2005/03/04 06:34:49 $
 * $Revision: 1.8 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/EstadoAlvo.h"
using namespace biblia::dinamicas::sinfonia;

EstadoAlvo::EstadoAlvo(const Valor& valorConstante)
		:pEstado(NULL), pCampo(valorConstante)
{
	// detalhe de implementação: quando o EstadoAlvo é constante
	// ele é guardado na variável pCampo porque o campo sempre
	// será o mesmo: Principal.
}

EstadoAlvo::EstadoAlvo(const Estado* estado, const Valor& campoAlvo)
		:pEstado(estado), pCampo(campoAlvo)
{}

EstadoAlvo::EstadoAlvo(const Estado* estado)
		:pEstado(estado), pCampo(Multifuncional::CAMPO_PRINCIPAL)
{}

EstadoAlvo::~EstadoAlvo() {}

const bool EstadoAlvo::constante() const {
	return this->pEstado == NULL;
}

const Valor& EstadoAlvo::campoAlvo() const {
	if (this->constante()) {
		return Multifuncional::CAMPO_PRINCIPAL;
	} else {
		return this->pCampo;
	}
}

const Estado& EstadoAlvo::estado() const {
	if (this->constante()) {
		Debug::sair("EstadoAlvo::estado():: Não é possível"
				" resgatar um Estado de um EstadoAlvo constante."
				" Use a função 'constante()' para verificar.");
	}

	return *(this->pEstado);
}

const Valor EstadoAlvo::valorAlvo() const {
	if (this->constante()) {
		return this->pCampo;
	} else {
		return this->estado().valor(this->campoAlvo());
	}
}

Objeto* EstadoAlvo::geraCopia() const {
	return new EstadoAlvo(*this);
}

Copiavel& EstadoAlvo::copiaEmSi(const Copiavel& alheio) {
	const EstadoAlvo& ea = dynamic_cast<const EstadoAlvo&>(alheio);
	this->pCampo = ea.pCampo;
	this->pEstado = ea.pEstado;
	return *this;
}

string EstadoAlvo::emString() const {
	Valor va(this->valorAlvo());
	string retorno;

	// se o EstadoAlvo é constante ou o Estado apontado é constante
	if (this->pEstado == NULL?true:this->estado().constante()) {
		retorno = string(va.indefinida()
			?"<<indefinido>>":va.emString());
	} else {
		retorno = ">>" + this->estado()
				.emString(this->campoAlvo());
	}

	return retorno;
}

const bool EstadoAlvo::igual(const Igualavel& alheio) const {
	const EstadoAlvo& ea = dynamic_cast<const EstadoAlvo&>(alheio);
	bool retorno = false;

	if (this->pEstado == ea.pEstado) {
		if (ea.campoAlvo() == this->campoAlvo()) {
			retorno = true;
		}
	}

	return retorno;
}
