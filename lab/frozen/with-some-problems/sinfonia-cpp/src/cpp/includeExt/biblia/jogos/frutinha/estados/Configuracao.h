/*
 * $RCSfile: Configuracao.h,v $
 * $Date: 2005/01/20 21:28:48 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(SBS_AFX_CONFIGURACAO_F_H__60E6A4FB_7749_4E8A_BA73_D8A4BBBDC992__INCLUDED_)
#define SBS_AFX_CONFIGURACAO_F_H__60E6A4FB_7749_4E8A_BA73_D8A4BBBDC992__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include <deque>
#include "biblia/basico/Objeto.h"
#include "biblia/visual/formulario/ControladorDeComponentesPorAcao.h"

using namespace std;
using namespace biblia::basico;
using namespace biblia::visual::formulario;

namespace biblia {
  namespace jogos {
	namespace frutinha {
      namespace estados {
		class Configuracao : public Objeto {
			private:
				std::deque<int> Configuracao::pAcoes;
				ControladorDeComponentesPorAcao
						Configuracao::pControlador;

				bool pUsuarioLogado;

			public:
				Configuracao::Configuracao();
				virtual Configuracao::~Configuracao();

				virtual const std::deque<int>& Configuracao::acoes() const;
				virtual std::deque<int>& Configuracao::acoes();
				virtual const ControladorDeComponentesPorAcao&
						Configuracao::controlador() const;

				virtual ControladorDeComponentesPorAcao&
						Configuracao::controlador();

				virtual void Configuracao::setUsuarioLogado(bool logado){
					this->pUsuarioLogado = logado;
				}

				virtual bool Configuracao::usuarioLogado(){
					return this->pUsuarioLogado;
				}
		};
	  }
	}
  }
}

#endif // !defined(SBS_AFX_CONFIGURACAO_F_H__60E6A4FB_7749_4E8A_BA73_D8A4BBBDC992__INCLUDED_)
