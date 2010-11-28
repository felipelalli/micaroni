/*
 * $RCSfile: DispositivoDeSaida.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_DISPOSITIVODESAIDA_H__B512D77D_B8EB_4FCE_BC27_E0A1ACB108B3__INCLUDED_)
#define AFX_DISPOSITIVODESAIDA_H__B512D77D_B8EB_4FCE_BC27_E0A1ACB108B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/fluxo/Executavel.h"
#include "biblia/armazenamento/volatil/GerenciadorDeEventos.h"

using namespace biblia::basico;
using namespace biblia::fluxo;
using namespace biblia::armazenamento::volatil;

namespace biblia {
  namespace io {

	class DispositivoDeSaida:
			public Objeto, public Executavel
	{
		private:
			GerenciadorDeEventos DispositivoDeSaida::pEventos;

		protected:
			DispositivoDeSaida::DispositivoDeSaida();

		public:
			virtual DispositivoDeSaida::~DispositivoDeSaida();
			GerenciadorDeEventos& DispositivoDeSaida::eventos();

			// Executavel:

			/**
			 * Processa os eventos e os transforma ou
			 * envia para o dispositivo de saída.
			 */
			virtual Executavel& DispositivoDeSaida::executa() = 0;
	};
  }
}

#endif // !defined(AFX_DISPOSITIVODEENTRADA_H__B512D77D_B8EB_4FCE_BC27_E0A1ACB108B3__INCLUDED_)
