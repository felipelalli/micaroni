/**
 * $RCSfile: Condicao.cpp,v $
 * $Date: 2005/01/13 02:18:10 $
 * $Revision: 1.2 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/Condicao.h"
using namespace biblia::dinamicas::sinfonia;

string Condicao::emString() const {
	if (this->verdadeira()) {
		return "V";
	} else {
		return "F";
	}
}
