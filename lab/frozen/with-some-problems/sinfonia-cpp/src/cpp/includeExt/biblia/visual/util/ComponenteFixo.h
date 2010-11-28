/*
 * $RCSfile: ComponenteFixo.h,v $
 * $Date: 2005/01/20 21:29:47 $
 * $Revision: 1.3 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_COMPONENTEFIXO_H__623D5021_CFE7_4826_9A28_1DA8C49D9F8C__INCLUDED_)
#define AFX_COMPONENTEFIXO_H__623D5021_CFE7_4826_9A28_1DA8C49D9F8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/visual/Ponto.h"
using namespace biblia::visual;

#include "biblia/util/StrToken.h"
using namespace biblia::util;

namespace biblia {
 namespace visual {
  namespace util {
	class ComponenteFixo: public Objeto {
		private:
			int pTipo;
			std::string pNome;
			Ponto pPosicao;
			bool pVisivel;
			int pQuadro;
			std::string pTexto;

		public:
			ComponenteFixo(const std::string& emString);

			/**
			 * Se o quadro é < 0 é porque está animando.
			 */
			ComponenteFixo(const int& tipo, const std::string& nome,
				           const Ponto& posicao, const bool& visivel,
						   const int& quadro = 0, const std::string& texto = "");

			virtual ~ComponenteFixo();

			virtual const int& tipo() const;
			virtual const std::string& nome() const;
			virtual const Ponto& posicao() const;
			virtual const bool& visivel() const;
			virtual const int& quadro() const;
			virtual const std::string& texto() const;

			// Objeto:
			virtual std::string emString() const;
	};
  }
 }
}

#endif // !defined(AFX_COMPONENTEFIXO_H__623D5021_CFE7_4826_9A28_1DA8C49D9F8C__INCLUDED_)
