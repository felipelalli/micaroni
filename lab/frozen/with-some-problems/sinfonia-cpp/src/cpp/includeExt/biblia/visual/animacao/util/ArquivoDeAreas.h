/*
 * $RCSfile: ArquivoDeAreas.h,v $
 * $Date: 2005/03/22 02:14:36 $
 * $Revision: 1.8 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_ARQUIVODEAREAS_H__7C020BC3_E3CC_4D9D_A5DF_40D38B88DCFC__INCLUDED_)
#define AFX_ARQUIVODEAREAS_H__7C020BC3_E3CC_4D9D_A5DF_40D38B88DCFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <deque>
#include "biblia/basico/Objeto.h"
#include "biblia/util/StrToken.h"
#include "biblia/io/disco/ArquivoBasico.h"
#include "biblia/visual/Area.h"
#include "biblia/visual/animacao/util/AnimacaoUtilExcecao.h"

using namespace std;
using namespace biblia::basico;
using namespace biblia::util;
using namespace biblia::io::disco;
using namespace biblia::visual;

namespace biblia {
  namespace visual {
 	namespace animacao {
	  namespace util {

		/**
		 * x-y-tamX-tamY-transparencia(opcional)
		 * 
		 * Formato:
		 * <pre>
		 *   0-0-176-27
		 *   176-0-176-27-99
		 *   352-0-176-27-50
		 *   528-0-176-27-21
		 *   704-0-176-27-89
		 *   880-0-176-27
		 *   1056-0-176-27
		 *   (... etc.)
		 * </pre>
		 */
		class ArquivoDeAreas: public Objeto {
			private:
				ArquivoBasico ArquivoDeAreas::pArquivoBasico;
				std::string ArquivoDeAreas::pNomeArquivoBasico;
				std::deque<Area> ArquivoDeAreas::pAreas;
				std::deque<int> pTransparencias;

			public:
				/**
				 * @param aPartirDaLinha Número da linha do arquivo
				 *                       que se iniciará
				 *                       as áreas.
				 *
				 * @throws biblia::visual::animacao::util::ArquivoDeAreasInvalidoExcecao
				 */
				ArquivoDeAreas::ArquivoDeAreas(
						const std::string& nomeDoArquivoBasico,
						bool somenteTransparencias = false,
						int aPartirDaLinha = 1);

				virtual const std::deque<Area>& ArquivoDeAreas::emLista() const;
				virtual const std::deque<int>& ArquivoDeAreas::transparencias() const;
				virtual ArquivoDeAreas::~ArquivoDeAreas();
		};
	  }
	}
  }
}

#endif // !defined(AFX_ARQUIVODEAREAS_H__7C020BC3_E3CC_4D9D_A5DF_40D38B88DCFC__INCLUDED_)
