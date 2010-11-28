/**
 * $RCSfile: Lock.cpp,v $
 * $Date: 2004/12/30 20:01:22 $
 * $Revision: 1.1 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/util/Lock.h"
using namespace biblia::dinamicas::sinfonia::util;

Lock::Lock(Semaforo& s):semaforo(s) {
	this->semaforo.esperar();
}

Lock::~Lock() {
	this->semaforo.liberar();
}
