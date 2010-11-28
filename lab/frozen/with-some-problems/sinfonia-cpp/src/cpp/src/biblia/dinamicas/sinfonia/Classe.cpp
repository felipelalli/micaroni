/**
 * $RCSfile: Classe.cpp,v $
 * $Date: 2005/01/11 23:41:25 $
 * $Revision: 1.6 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/Classe.h"
using namespace biblia::dinamicas::sinfonia;

Classe::Classe(const Valor& nome):Rotulado(nome), pAcoesPossiveis(), pCampos() {}
Classe::~Classe() {}

const Lista<Identificacao>& Classe::acoesPossiveis() const {
	return this->pAcoesPossiveis;
}

Lista<Identificacao>& Classe::acoes() {
	return this->pAcoesPossiveis;
}

Lista<Identificacao>& Classe::camposParaModificar() {
	return this->pCampos;
}

const Lista<Identificacao>& Classe::campos() const {
	return this->pCampos;
}
