/**
 * $RCSfile: CondicaoModificadora.cpp,v $
 * $Date: 2005/02/23 22:32:51 $
 * $Revision: 1.3 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/CondicaoModificadora.h"
using namespace biblia::dinamicas::sinfonia;

CondicaoModificadora::CondicaoModificadora(const Condicao& c)
		:pCondicao((Condicao*) c.geraCopia())
{}

CondicaoModificadora::~CondicaoModificadora() {
	delete this->pCondicao;
}

bool CondicaoModificadora::verdadeira() const {
	return !this->pCondicao->verdadeira();
}

Objeto* CondicaoModificadora::geraCopia() const {
	return new CondicaoModificadora(*(this->pCondicao));
}

Copiavel& CondicaoModificadora::copiaEmSi(const Copiavel& alheio) {
	const CondicaoModificadora& cm = dynamic_cast<const CondicaoModificadora&>(alheio);

	delete this->pCondicao;
	this->pCondicao = (Condicao*) cm.pCondicao->geraCopia();

	return *this;
}

string CondicaoModificadora::emString() const {
	return "!(" + this->pCondicao->emString() + ")";
}
