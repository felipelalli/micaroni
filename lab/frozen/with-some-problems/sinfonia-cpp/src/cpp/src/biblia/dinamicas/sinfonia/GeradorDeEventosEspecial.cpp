/**
 * $RCSfile: GeradorDeEventosEspecial.cpp,v $
 * $Date: 2005/02/16 23:52:59 $
 * $Revision: 1.6 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/GeradorDeEventosEspecial.h"
using namespace biblia::dinamicas::sinfonia;

GeradorDeEventosEspecial::GeradorDeEventosEspecial(const MediadorDeEstados& mde)
		:GeradorDeEventos(mde, true)
{}

GeradorDeEventosEspecial::~GeradorDeEventosEspecial() {}


