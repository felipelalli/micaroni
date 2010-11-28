/*
 * $RCSfile: ResgataDefinicaoDeComposto.h,v $
 * $Date: 2004/02/11 23:28:52 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_RESGATADEFINICAODECOMPOSTO_H__6B0D5B5A_D708_4766_A810_9DD4791E6456__INCLUDED_)
#define AFX_RESGATADEFINICAODECOMPOSTO_H__6B0D5B5A_D708_4766_A810_9DD4791E6456__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/util/instrucoes/Instrucao.h"
using namespace biblia::util::instrucoes;

namespace biblia {
 namespace armazenamento {
  namespace volatil {
   namespace carcacas { 
    namespace composto {
	 namespace instrucoes {
		class ResgataDefinicaoDeComposto: public Instrucao {
			public:
				static Identificacao ResgataDefinicaoDeComposto::COMANDO;
				
				ResgataDefinicaoDeComposto
						::ResgataDefinicaoDeComposto(
							const Identificacao& nome);

				ResgataDefinicaoDeComposto
						::ResgataDefinicaoDeComposto(
							const Instrucao& instrucao);

				virtual ResgataDefinicaoDeComposto
						::~ResgataDefinicaoDeComposto();

				virtual const Identificacao
						ResgataDefinicaoDeComposto
							::nome() const;
		};
	 }
	}
   }
  }
 }
}

#endif // !defined(AFX_RESGATADEFINICAODECOMPOSTO_H__6B0D5B5A_D708_4766_A810_9DD4791E6456__INCLUDED_)
