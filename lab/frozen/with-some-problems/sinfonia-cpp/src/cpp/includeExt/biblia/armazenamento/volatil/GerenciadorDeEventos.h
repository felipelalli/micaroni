/*
 * $RCSfile: GerenciadorDeEventos.h,v $
 * $Date: 2005/01/20 21:28:34 $
 * $Revision: 1.9 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_GERENCIADORDEEVENTOS_H__A2072211_C9D8_4928_8CDD_11D99792448F__INCLUDED_)
#define AFX_GERENCIADORDEEVENTOS_H__A2072211_C9D8_4928_8CDD_11D99792448F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <deque>
#include "biblia/basico/Objeto.h"
#include "biblia/armazenamento/volatil/Evento.h"

namespace biblia {
  namespace armazenamento {
 	namespace volatil {

		class GerenciadorDeEventos: public Objeto {
			private:
				std::deque<Evento*> GerenciadorDeEventos::pEventos;

			public:
				GerenciadorDeEventos::GerenciadorDeEventos();

				virtual GerenciadorDeEventos::~GerenciadorDeEventos();

				virtual GerenciadorDeEventos& GerenciadorDeEventos::gera(Evento*);

				/**
				 * O retorno deve ser deletado por
				 * quem o captura.
				 */
				virtual Evento* GerenciadorDeEventos::consomeEvento();

				//Esse não deve ser deletado
				virtual const Evento& GerenciadorDeEventos::getEvento (int indice);

				virtual GerenciadorDeEventos& GerenciadorDeEventos::limpa();

				virtual bool GerenciadorDeEventos::possui(const Evento&) const;

				virtual bool GerenciadorDeEventos::haEvento() const;

				virtual int GerenciadorDeEventos::quantosEventos() const;

		};
	}
  }
}

#endif // !defined(AFX_GERENCIADORDEEVENTOS_H__A2072211_C9D8_4928_8CDD_11D99792448F__INCLUDED_)
