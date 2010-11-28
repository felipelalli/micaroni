/*
 * $RCSfile: Texto.h,v $
 * $Date: 2005/01/20 21:29:45 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_TEXTO_H__54CC8A1C_9FA0_43BB_9DDB_C799BA88DA7D__INCLUDED_)
#define AFX_TEXTO_H__54CC8A1C_9FA0_43BB_9DDB_C799BA88DA7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "biblia/basico/Objeto.h"
#include "biblia/visual/fonte/Formatacao.h"

using namespace std;
using namespace biblia::basico;

namespace biblia {
  namespace visual {
    namespace fonte {

		/**
		 * Representa um texto puro (sem fonte)
		 * {@link biblia::visual::fonte::Formatacao formatado}.
		 */
		class Texto: public Objeto {
			private:
				std::string Texto::pTexto;
				Formatacao Texto::pFormatacao;

			public:
				Texto::Texto(const std::string&, Formatacao = Formatacao());
				virtual Texto::~Texto();

				std::string Texto::emString() const;
				virtual std::string& Texto::operator()();
				virtual Texto& Texto::muda(const Texto& novoTexto);
				virtual Texto& Texto::muda(const std::string& novoTexto);
				virtual const std::string& Texto::operator()() const;
				virtual Formatacao& Texto::formatacao();
				virtual const Formatacao& Texto::formatacao() const;
		};
	}
  }
}

#endif // !defined(AFX_TEXTO_H__54CC8A1C_9FA0_43BB_9DDB_C799BA88DA7D__INCLUDED_)
