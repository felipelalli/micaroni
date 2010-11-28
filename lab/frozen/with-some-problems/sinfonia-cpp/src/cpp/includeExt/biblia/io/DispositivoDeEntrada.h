/*
 * $RCSfile: DispositivoDeEntrada.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_DISPOSITIVODEENTRADA_H__B512D77D_B8EB_4FCE_BC27_E0A1ACB108B3__INCLUDED_)
#define AFX_DISPOSITIVODEENTRADA_H__B512D77D_B8EB_4FCE_BC27_E0A1ACB108B3__INCLUDED_

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

	class DispositivoDeEntrada:
			public Objeto, public Executavel
	{
		private:
			GerenciadorDeEventos DispositivoDeEntrada::pEventos;

		protected:
			DispositivoDeEntrada::DispositivoDeEntrada();

		public:
			virtual DispositivoDeEntrada::~DispositivoDeEntrada();
			GerenciadorDeEventos& DispositivoDeEntrada::eventos();

			// Executavel:

			/**
			 * Monitora o dispositivo de entrada e gera
			 * os eventos relativos.
			 */
			virtual Executavel& DispositivoDeEntrada::executa() = 0;
	};
  }
}

#endif // !defined(AFX_DISPOSITIVODEENTRADA_H__B512D77D_B8EB_4FCE_BC27_E0A1ACB108B3__INCLUDED_)
