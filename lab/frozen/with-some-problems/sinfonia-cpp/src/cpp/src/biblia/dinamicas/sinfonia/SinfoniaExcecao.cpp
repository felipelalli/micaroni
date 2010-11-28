/**
 * $RCSfile: SinfoniaExcecao.cpp,v $
 * $Date: 2005/01/05 23:30:36 $
 * $Revision: 1.2 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/SinfoniaExcecao.h"
using namespace biblia::dinamicas::sinfonia; 

/* UniversoSequencial */

UniversoSequencial::Vezes::Vezes():UnidadeDeTempo(0, "impossível determinar tempo") {}
UniversoSequencial::Vezes::~Vezes() {}

int UniversoSequencial::pVezes = 0;
UniversoSequencial::Vezes UniversoSequencial::pPasso = UniversoSequencial::Vezes();

Momento UniversoSequencial::agora() const {
	return Momento(++UniversoSequencial::pVezes, *this);
}

const UnidadeDeTempo& UniversoSequencial::cadaPasso() const {
	return UniversoSequencial::pPasso;
}

bool UniversoSequencial::mesmoUniversoDeTempo(const UniversoDeTempo& u) const {
	return typeid(*this) == typeid(u)?true:false;
}
