/*
 * $RCSfile: CriaDefinicaoDeComposto.h,v $
 * $Date: 2004/02/11 23:28:52 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_CRIADEFINICAODECOMPOSTOINSTRUCAO_H__B2A88CE2_BA76_4674_A730_FA29B4EFA7DB__INCLUDED_)
#define AFX_CRIADEFINICAODECOMPOSTOINSTRUCAO_H__B2A88CE2_BA76_4674_A730_FA29B4EFA7DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Excecao.h"
#include "biblia/util/UtilExcecao.h"
#include "biblia/util/instrucoes/Instrucao.h"
#include "biblia/armazenamento/volatil/primitivos/Inteiro.h"
#include "biblia/armazenamento/volatil/carcacas/composto/TipoIdentificado.h"

using namespace biblia::basico;
using namespace biblia::util::instrucoes;
using namespace biblia::armazenamento::volatil::primitivos;
using namespace biblia::armazenamento::volatil::carcacas::composto;

namespace biblia {
 namespace armazenamento {
  namespace volatil {
   namespace carcacas { 
    namespace composto {
	 namespace instrucoes {
		/**
 		 * Instrução para criar uma DefinicaoDeComposto.
		 * @see biblia::armazenamento::volatil::primitivos::composto::ConhecedorDeCompostos
		 */
		class CriaDefinicaoDeComposto: public Instrucao {
			public:
				static Identificacao CriaDefinicaoDeComposto::COMANDO;

				CriaDefinicaoDeComposto
						::CriaDefinicaoDeComposto(
							const Identificacao& nome);

				CriaDefinicaoDeComposto
						::CriaDefinicaoDeComposto(
							const Instrucao& instrucao);

				virtual CriaDefinicaoDeComposto
						::~CriaDefinicaoDeComposto();

//				virtual CriaDefinicaoDeComposto&
//						CriaDefinicaoDeComposto
//							::herdaDe(const Identificacao& quem);

				virtual CriaDefinicaoDeComposto&
						CriaDefinicaoDeComposto
							::criaCampo(const Tipo& tipo,
										const Identificacao& id);

				virtual const Identificacao
						CriaDefinicaoDeComposto
							::nome() const;

//				virtual const Identificacao
//						CriaDefinicaoDeComposto
//							::herdaDe() const;

				/**
				 * @throws biblia::basico::ForaDeIntervaloExcecao
				 * @see #quantosCampos()
				 */
				virtual const TipoIdentificado
						CriaDefinicaoDeComposto
							::campo(const Inteiro&) const;

				virtual const int CriaDefinicaoDeComposto
						::quantosCampos() const;
		};
	 }
	}
   }
  }
 }
}

#endif // !defined(AFX_CRIADEFINICAODECOMPOSTOINSTRUCAO_H__B2A88CE2_BA76_4674_A730_FA29B4EFA7DB__INCLUDED_)
