/*
 * $RCSfile: CriaComposto.h,v $
 * $Date: 2004/02/11 23:28:52 $
 * $Revision: 1.3 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_CRIACOMPOSTO_H__202431F4_0D0A_4177_B2FA_C740086E6ABE__INCLUDED_)
#define AFX_CRIACOMPOSTO_H__202431F4_0D0A_4177_B2FA_C740086E6ABE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/util/instrucoes/Instrucao.h"
#include "biblia/armazenamento/volatil/carcacas/MapaHash.h"

using namespace biblia::util::instrucoes;
using namespace biblia::armazenamento::volatil::carcacas;

namespace biblia {
 namespace armazenamento {
  namespace volatil {
   namespace carcacas { 
    namespace composto {
	 namespace instrucoes {
		class CriaComposto: public Instrucao {
			private:
				mutable MapaHash<Informacao*>
						CriaComposto::pInformacoes;
		
			public:
				static Identificacao CriaComposto::COMANDO;
				
				CriaComposto::CriaComposto(
						const Identificacao&
							qualDefinicaoDeComposto);

				CriaComposto::CriaComposto(const Instrucao& instrucao);
				virtual CriaComposto::~CriaComposto();

				virtual const Identificacao CriaComposto
						::qualDefinicaoDeComposto() const;

				/**
				 * Retorna uma informação previamente
				 * preenchida e retira deste comando.
				 * <p>
				 * Ela é retirada por questão de segurança,
				 * para que ela não seja deletada duas vezes.
				 * Portanto, se você quiser usar o mesmo
				 * comando para criar diversos compostos
				 * em série é importante preenchê-lo cada
				 * vez que for usá-lo novamente.
				 */
				virtual Informacao* CriaComposto
						::retiraNovaInformacao(
								const Identificacao&
								campo) const;

				/**
				 * Indica se este composto foi previamente
				 * preenchido por novas informações.
				 */
				virtual const bool CriaComposto
						::preenchido(const Identificacao& campo) const;

				/**
				 * Indica as novas informações
				 * que preencherão o composto inicial.
				 * <p>
				 * Um Composto quando criado pegará para
				 * si a responsabilidade de deletar esta
				 * nova informação, portanto pode passar
				 * uma nova instância para esta classe
				 * sem ter que deletá-la. Esta informação
				 * permanece dentro desta instrução até
				 * que essa instrução seja "executada".
				 */
				virtual CriaComposto& CriaComposto
						::preenche(const Identificacao& campo,
								   Informacao* novaInformacao);
		};
	 }
	}
   }
  }
 }
}

#endif // !defined(AFX_CRIACOMPOSTO_H__202431F4_0D0A_4177_B2FA_C740086E6ABE__INCLUDED_)
