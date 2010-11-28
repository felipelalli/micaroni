/*
 * $RCSfile: Simulador.h,v $
 * $Date: 2005/01/13 17:09:48 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: fernandofernandes $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AGES_SPECIAL_UPGRADE_AFX_SIMULADOR_H__4342B284_3276_45C4_9C75_6D16E3A4EC76__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_AFX_SIMULADOR_H__4342B284_3276_45C4_9C75_6D16E3A4EC76__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

namespace biblia {
 namespace jogos {
  namespace specialUpgrade {
   namespace estados {
	class Simulador: public Objeto {
		private:
			int Simulador::pGanho;
			int Simulador::pApostado;
			int Simulador::pCreditos;
			int Simulador::pJogadas;
			double Simulador::pAcumulado;
			bool Simulador::pAutomatico;

		public:
			Simulador::Simulador();
			virtual Simulador::~Simulador();

			virtual Simulador& Simulador::creditos(const int&);
			virtual const int& Simulador::creditos() const;

			virtual Simulador& Simulador::ganho(const int&);
			virtual const int& Simulador::ganho() const;

			virtual Simulador& Simulador::apostado(const int&);
			virtual const int& Simulador::apostado() const;

			virtual Simulador& Simulador::jogadas(const int&);
			virtual const int& Simulador::jogadas() const;

			virtual Simulador& Simulador::acumulado(const double&);
			virtual const double& Simulador::acumulado() const;

			virtual Simulador& Simulador::automatico(const bool&);
			virtual const bool& Simulador::automatico() const;
	};
   }
  }
 }
}

#endif // !defined(AFX_SIMULADOR_H__4342B284_3276_45C4_9C75_6D16E3A4EC76__INCLUDED_)
