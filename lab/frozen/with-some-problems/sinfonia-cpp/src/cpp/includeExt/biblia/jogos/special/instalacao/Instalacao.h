/*
 * $RCSfile: Instalacao.h,v $
 * $Date: 2003/11/27 20:31:54 $
 * $Revision: 1.6 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_INSTALACAO_H__5B13330E_F3B1_4F03_BF2D_807F29FB9001__INCLUDED_)
#define AFX_INSTALACAO_H__5B13330E_F3B1_4F03_BF2D_807F29FB9001__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include "biblia/basico/Objeto.h"
#include "biblia/basico/Excecao.h"
#include "biblia/sorte/Sorteio.h"
#include "biblia/fluxo/Executavel.h"
#include "biblia/io/disco/Arquivo.h"
#include "biblia/visual/dinamica/BasicoVisual.h"
#include "biblia/visual/dinamica/DesenhistaDeResultadoGraficoNaTela.h"
#include "biblia/jogos/special/io/botoes/Botoes.h"
#include "biblia/io/script/RodadorScript.h"

using namespace biblia::basico;
using namespace biblia::fluxo;
using namespace biblia::sorte;
using namespace biblia::io::script;
using namespace biblia::io::disco;
using namespace biblia::visual::dinamica;
using namespace biblia::jogos::special::io::botoes;

namespace biblia {
  namespace jogos {
    namespace special {
	  namespace instalacao {

 	   /**
 	    * � a instala��o completa,
		* j� com o visual embutido.
	    */
		class Instalacao: public Executavel, public Objeto {
			private:
				Sorteio Instalacao::sorte;
				int Instalacao::pModo;
				int Instalacao::passo;
				int Instalacao::botaoSorteado;
				bool Instalacao::pAcabou;
				BasicoVisual& Instalacao::pVisual;
				Botoes& Instalacao::pBotoes;
				DesenhistaDeResultadoGraficoNaTela* Instalacao::pDesenhista;
				RodadorScript* Instalacao::rs;

			protected:
				virtual DesenhistaDeResultadoGraficoNaTela&
						Instalacao::desenhista();

				virtual BasicoVisual& Instalacao::visual();
				virtual const BasicoVisual& Instalacao::visual() const;
				virtual const int& Instalacao::modo() const;
				virtual const bool& Instalacao::acabou() const;
				virtual Instalacao& Instalacao::termina();
				virtual Botoes& Instalacao::botoes();
				virtual const Botoes& Instalacao::botoes() const;

				// etapas:
				virtual Instalacao& Instalacao::ambos();
				virtual Instalacao& Instalacao::instalacao();
				virtual Instalacao& Instalacao::atualizacao();
				virtual Instalacao& Instalacao::leBotoesEFazOQueDeveFazer();

				// extras:
				virtual bool Instalacao::deuCerto() const;

			public:
				class ModoInvalido: public Excecao {};

				static const int Instalacao::INSTALACAO;
				static const int Instalacao::ATUALIZACAO;
				static const int Instalacao::AMBOS;

				/**
				 * @param modo Pode ser instanciado para INSTALACAO,
				 *             ATUALIZACAO ou AMBOS.
				 *
				 * @param b � importante que o bot�o sobreviva
				 *          at� o fim deste.
				 *
				 * @param bv � importante que o BasicoVisual
				 *           sobreviva enquanto esta instala��o
				 *           se manter viva.
				 */
				Instalacao::Instalacao(
						BasicoVisual& bv, Botoes& b,
						int modo = AMBOS);

				virtual Instalacao::~Instalacao();

				/**
				 * Inicia o processo.
				 */
				virtual Executavel& Instalacao::executa();


		};
	  }
	}
  }
}

#endif // !defined(AFX_INSTALACAO_H__5B13330E_F3B1_4F03_BF2D_807F29FB9001__INCLUDED_)
