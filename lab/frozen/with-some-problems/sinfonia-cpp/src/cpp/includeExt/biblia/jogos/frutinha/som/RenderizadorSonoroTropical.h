/*
 * $RCSfile: RenderizadorSonoroTropical.h,v $
 * $Date: 2004/04/24 04:54:10 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_RENDERIZADORSONOROTROPICAL_H__C526AA33_9A10_40D2_A384_9F4A0ECE282F__INCLUDED_)
#define AFX_RENDERIZADORSONOROTROPICAL_H__C526AA33_9A10_40D2_A384_9F4A0ECE282F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/tempo/Cronometro.h"
#include "biblia/logica/Renderizador.h"
#include "biblia/io/som/ResultadoSonoro.h"
#include "biblia/io/som/CarregadorDeSom.h"
#include "biblia/tempo/unidades/Segundo.h"
#include "biblia/jogos/frutinha/estados/EstadosTropical.h"

using namespace biblia::tempo;
using namespace biblia::logica;
using namespace biblia::io::som;
using namespace biblia::tempo::unidades;
using namespace biblia::jogos::frutinha::estados;

namespace biblia {
  namespace jogos {
	namespace frutinha {
	  namespace som {
		class RenderizadorSonoroTropical: public Renderizador {
			private:
				CarregadorDeSom* pCarregadorDeSom;
				ResultadoSonoro* pResultadoSonoro;
				EstadosTropical* pEstadosTropical;
				UniversoDeTempo* pTempo;

				// Estados:
				bool pPrimeiraVez;
				bool pRodilhoParadoAntigo;
				bool pAcumuladoAntigo;
				bool pAcumuladoTocandoAntigo;
				int pApostaAntiga;
				int pCreditosAntigos;
				bool pBonusAntigo;
				bool pBonusTocandoAntigo;
				bool pAjudaAntiga;
				int pLinhaApostaAntiga;

			protected:
				CarregadorDeSom& RenderizadorSonoroTropical::carregador();
				ResultadoSonoro& RenderizadorSonoroTropical::resultado();
				UniversoDeTempo& RenderizadorSonoroTropical::tempo();
				EstadosTropical& RenderizadorSonoroTropical::jogo();
				double RenderizadorSonoroTropical::volume(int qual);

			public:
				RenderizadorSonoroTropical
						::RenderizadorSonoroTropical();

				virtual RenderizadorSonoroTropical
						::~RenderizadorSonoroTropical();

				virtual RenderizadorSonoroTropical&
						RenderizadorSonoroTropical
							::defineCarregadorDeSom(
								CarregadorDeSom&);

				virtual RenderizadorSonoroTropical&
						RenderizadorSonoroTropical
							::defineResultadoSonoro(
								ResultadoSonoro&);
				
				virtual RenderizadorSonoroTropical&
						RenderizadorSonoroTropical
							::defineTempo(
								UniversoDeTempo&);

				virtual RenderizadorSonoroTropical&
						RenderizadorSonoroTropical
							::defineEstados(
								EstadosTropical&);

				// Renderizador:
				/**
				 * Transforma os estados em resultados sonoros.
				 */
				virtual Executavel&
						RenderizadorSonoroTropical
							::executa();
		};
	  }
	}
  }
}

#endif // !defined(AFX_RENDERIZADORSONOROTROPICAL_H__C526AA33_9A10_40D2_A384_9F4A0ECE282F__INCLUDED_)
