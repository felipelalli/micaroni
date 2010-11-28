/*
 * $RCSfile: RenderizadorSonoroSpecial.h,v $
 * $Date: 2005/01/20 21:28:54 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */


#if !defined(SBS_AFX_RENDERIZADORSONOROSUPERBONUS_H__CDF08B08_F3E5_415A_BFD6_678C1DE8E8ED__INCLUDED_)
#define SBS_AFX_RENDERIZADORSONOROSUPERBONUS_H__CDF08B08_F3E5_415A_BFD6_678C1DE8E8ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/jogos/special/EstadosSpecial.h"
#include "biblia/jogos/special/dados/DConfiguracao.h"
#include "biblia/logica/Renderizador.h"
#include "biblia/io/som/ResultadoSonoro.h"
#include "biblia/io/som/CarregadorDeSom.h"
#include "biblia/tempo/Cronometro.h"
#include "biblia/tempo/unidades/Segundo.h"

using namespace biblia::tempo;
using namespace biblia::logica;
using namespace biblia::io::som;
using namespace biblia::jogos::special;
using namespace biblia::tempo::unidades;

namespace biblia {
  namespace jogos {
    namespace special {
	  namespace io {
	    namespace som {

			class RenderizadorSonoroSpecial: public Renderizador {
				private:
					CarregadorDeSom* RenderizadorSonoroSpecial
							::pCarregadorDeSom;

					ResultadoSonoro* RenderizadorSonoroSpecial
							::pResultadoSonoro;

					EstadosSpecial* RenderizadorSonoroSpecial
							::pEstadosSpecial;

					UniversoDeTempo* RenderizadorSonoroSpecial
							::pTempo;

					Cronometro* RenderizadorSonoroSpecial::pTrilha;

					// Segundos para a trilha:
					int RenderizadorSonoroSpecial::pQuantosSegundosPraTrilha;

					// Bola:
					int RenderizadorSonoroSpecial::pUltimaBolona;

					// Cartela e Números:
					// int RenderizadorSonoroSpecial::pUltimaCartela;
					// this->jogo().logicas().cartelas().deveLimpar()
					bool RenderizadorSonoroSpecial::pUltimoDeveZerar;

					// Aposta:
					int RenderizadorSonoroSpecial::pUltimaAposta;

					// Créditos:
					int RenderizadorSonoroSpecial::pUltimoCredito;

					// Dobro:
					bool RenderizadorSonoroSpecial::pUltimoAceso;

					// Falta-um:
					int RenderizadorSonoroSpecial::pFaltaUm[4];

					// BolaExtra:
					bool RenderizadorSonoroSpecial::pDeuBolaExtra;

					// Acumulado:
					bool RenderizadorSonoroSpecial::pDeuAcumulado;

					// fazer algum temporizador para a trilha

					Skin skin;

				protected:
					CarregadorDeSom& RenderizadorSonoroSpecial
							::carregador();

					ResultadoSonoro& RenderizadorSonoroSpecial
							::resultado();

					UniversoDeTempo& RenderizadorSonoroSpecial
							::tempo();

					EstadosSpecial& RenderizadorSonoroSpecial
							::jogo();

					double RenderizadorSonoroSpecial::volume(std::string);

				public:
					RenderizadorSonoroSpecial
							::RenderizadorSonoroSpecial(const Skin&);

					virtual RenderizadorSonoroSpecial
							::~RenderizadorSonoroSpecial();

					virtual RenderizadorSonoroSpecial&
							RenderizadorSonoroSpecial
								::defineCarregadorDeSom(
									CarregadorDeSom&);

					virtual RenderizadorSonoroSpecial&
							RenderizadorSonoroSpecial
								::defineResultadoSonoro(
									ResultadoSonoro&);

					virtual RenderizadorSonoroSpecial&
							RenderizadorSonoroSpecial
								::defineTempo(
									UniversoDeTempo&);

					virtual RenderizadorSonoroSpecial&
							RenderizadorSonoroSpecial
								::defineEstados(
									EstadosSpecial&);

					// Renderizador:
					/**
					 * Transforma os estados em resultados sonoros
					 * propriamente ditos.
					 */
					virtual Executavel&
							RenderizadorSonoroSpecial
								::executa();
			};
		}
	  }
	}
  }
}

#endif // !defined(AFX_RENDERIZADORSONOROSUPERBONUS_H__CDF08B08_F3E5_415A_BFD6_678C1DE8E8ED__INCLUDED_)
