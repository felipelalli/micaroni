/**
 * $RCSfile: GenesisTeste.h,v $
 * $Date: 2004/12/23 21:04:56 $
 * $Revision: 1.2 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_GENESISTESTE_H__C4D2ED10_30C7_4E69_8E87_EDD7FA0A6654__INCLUDED_)
#define AFX_GENESISTESTE_H__C4D2ED10_30C7_4E69_8E87_EDD7FA0A6654__INCLUDED_

#include <biblia/visual/dinamica/BasicoVisual.h>
using namespace biblia::visual::dinamica;

#include "biblia/dinamicas/sinfonia/Genesis.h"
#include "biblia/dinamicas/sinfonia/CondicaoComposta.h"
#include "biblia/dinamicas/sinfonia/CondicaoDeComparacao.h"
using namespace biblia::dinamicas::sinfonia;

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
   namespace miniaplicacao {
	/**
	 * Cria uma Sinfonia para testes gerais.
	 *
	 * @Genesis
	 */
	class GenesisTeste: public Genesis {
		private:
			const BasicoVisual& pVisual;

		public:
			GenesisTeste(const BasicoVisual&);
			virtual ~GenesisTeste();

			// Genesis:
			virtual Sinfonia* geraSinfonia();
	};
   }
  }
 }
}

#endif // !defined(AFX_GENESISTESTE_H__C4D2ED10_30C7_4E69_8E87_EDD7FA0A6654__INCLUDED_)
