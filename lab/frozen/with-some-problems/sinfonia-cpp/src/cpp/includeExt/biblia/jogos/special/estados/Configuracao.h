/*
 * $RCSfile: Configuracao.h,v $
 * $Date: 2005/01/20 21:28:54 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(SBS_AFX_CONFIGURACAO_H__60E6A4FB_7749_4E8A_BA73_D8A4BBBDC992__INCLUDED_)
#define SBS_AFX_CONFIGURACAO_H__60E6A4FB_7749_4E8A_BA73_D8A4BBBDC992__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include <deque>
#include "biblia/jogos/special/logica/Logicas.h"
#include "biblia/visual/imagem2d/FabricaDeImagens.h"
#include "biblia/visual/formulario/ControladorDeComponentesPorAcao.h"
#include "biblia/jogos/special/io/botoes/Botoes.h"
#include "biblia/jogos/special/io/botoes/Piscador.h"
#include "biblia/basico/Objeto.h"

using namespace std;
using namespace biblia::visual::imagem2d;
using namespace biblia::visual::formulario;
using namespace biblia::jogos::special::logica;
using namespace biblia::jogos::special::io::botoes;
using namespace biblia::basico;

namespace biblia {
	namespace jogos {
		namespace special {
			namespace estados {
				class Configuracao : public Objeto {
					private:
						std::deque<int> Configuracao::pAcoes;
						ControladorDeComponentesPorAcao
								Configuracao::pControlador;

						bool pUsuarioLogado;

						// Histórico:
						bool pJogadaExibida;
						int pQualJogada;

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

						// Histórico:
						// (ver também estado da BolaExtra
						// que faz a jogada sozinho)
						virtual const bool& jogadaExibida() const;
						virtual const int& qualJogada() const;
						virtual Configuracao& exibeJogada(const int&);
						virtual Configuracao& ocultaJogada();
				};
			}
		}
	}
}

#endif // !defined(AFX_CONFIGURACAO_H__60E6A4FB_7749_4E8A_BA73_D8A4BBBDC992__INCLUDED_)
