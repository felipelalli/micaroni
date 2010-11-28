/*
 * $RCSfile: Excecao.h,v $
 * $Date: 2005/01/20 21:28:40 $
 * $Revision: 1.11 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_EXCECAO_H__8A05724C_4EA5_4579_9C51_F4542DFE2C07__INCLUDED_)
#define AFX_EXCECAO_H__8A05724C_4EA5_4579_9C51_F4542DFE2C07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include <exception>
#include "biblia/basico/Objeto.h"

using namespace std;

namespace biblia {
  namespace basico {

		class Excecao:
#ifdef WIN32
				public exception,
#endif
				public Objeto
		 {
			private:
				std::string Excecao::pMensagem;

			protected:
				Excecao::Excecao();

			public:
				virtual Excecao::~Excecao();

				/**
				 * Retorna a mensagem de erro
				 * descrevendo a causa da exceção.
				 */
				std::string Excecao::emString() const;

				/**
				 * Define a mensagem de erro
				 * que descreve a causa desta exceção.
				 */
				Excecao& Excecao::operator<<(
						const std::string& mensagem);
		};

		class ReferenciaNulaExcecao: public Excecao {};
		class IncompatibilidadeDeTiposExcecao: public Excecao {};
		class FuncaoNaoImplementadaExcecao: public Excecao {};
		class ForaDeIntervaloExcecao: public Excecao {};
		class ExcecaoDesconhecida: public Excecao {};
  }
}

#endif // !defined(AFX_EXCECAO_H__8A05724C_4EA5_4579_9C51_F4542DFE2C07__INCLUDED_)
