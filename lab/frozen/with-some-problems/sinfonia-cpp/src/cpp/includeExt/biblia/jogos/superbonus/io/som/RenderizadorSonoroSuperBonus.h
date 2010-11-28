/*
 * $RCSfile: RenderizadorSonoroSuperBonus.h,v $
 * $Date: 2005/01/20 21:29:00 $
 * $Revision: 1.11 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */


#if !defined(AFX_RENDERIZADORSONOROSUPERBONUS_H__CDF08B08_F3E5_415A_BFD6_678C1DE8E8ED__INCLUDED_)
#define AFX_RENDERIZADORSONOROSUPERBONUS_H__CDF08B08_F3E5_415A_BFD6_678C1DE8E8ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/jogos/superbonus/EstadosSuperBonus.h"
#include "biblia/jogos/superbonus/dados/DConfiguracao.h"
#include "biblia/logica/Renderizador.h"
#include "biblia/io/som/ResultadoSonoro.h"
#include "biblia/io/som/CarregadorDeSom.h"

using namespace biblia::logica;
using namespace biblia::io::som;
using namespace biblia::jogos::superbonus;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace io {
	    namespace som {

			class RenderizadorSonoroSuperBonus: public Renderizador {
				private:
					CarregadorDeSom* RenderizadorSonoroSuperBonus
							::pCarregadorDeSom;

					ResultadoSonoro* RenderizadorSonoroSuperBonus
							::pResultadoSonoro;

					EstadosSuperBonus* RenderizadorSonoroSuperBonus
							::pEstadosSuperBonus;

					// Bola:
					int RenderizadorSonoroSuperBonus::pUltimaBolona;

					// Cartela e Números:
					// int RenderizadorSonoroSuperBonus::pUltimaCartela;
					// this->jogo().logicas().cartelas().deveLimpar()
					bool RenderizadorSonoroSuperBonus::pUltimoDeveZerar;

					// Aposta:
					int RenderizadorSonoroSuperBonus::pUltimaAposta;

					// Premio:
					int RenderizadorSonoroSuperBonus::pUltimoPremio;

					// Créditos:
					int RenderizadorSonoroSuperBonus::pUltimoCredito;

					// fazer créditos insuficientes

					// Dobro:
					bool RenderizadorSonoroSuperBonus::pUltimoAceso;

					// Falta-um:
					int RenderizadorSonoroSuperBonus::pFaltaUm[4];

					// BolaExtra:
					bool RenderizadorSonoroSuperBonus::pDeuBolaExtra;

					// Acumulado:
					bool RenderizadorSonoroSuperBonus::pDeuAcumulado;

					// fazer algum temporizador para a trilha

				protected:
					CarregadorDeSom& RenderizadorSonoroSuperBonus
							::carregador();

					ResultadoSonoro& RenderizadorSonoroSuperBonus
							::resultado();

					EstadosSuperBonus& RenderizadorSonoroSuperBonus
							::jogo();

					double RenderizadorSonoroSuperBonus::volume(std::string);

				public:
					RenderizadorSonoroSuperBonus
							::RenderizadorSonoroSuperBonus();

					virtual RenderizadorSonoroSuperBonus
							::~RenderizadorSonoroSuperBonus();

					virtual RenderizadorSonoroSuperBonus&
							RenderizadorSonoroSuperBonus
								::defineCarregadorDeSom(
									CarregadorDeSom&);

					virtual RenderizadorSonoroSuperBonus&
							RenderizadorSonoroSuperBonus
								::defineResultadoSonoro(
									ResultadoSonoro&);

					virtual RenderizadorSonoroSuperBonus&
							RenderizadorSonoroSuperBonus
								::defineEstados(
									EstadosSuperBonus&);

					// Renderizador:
					/**
					 * Transforma os estados em resultados sonoros
					 * propriamente ditos.
					 */
					virtual Executavel&
							RenderizadorSonoroSuperBonus
								::executa();
			};
		}
	  }
	}
  }
}

#endif // !defined(AFX_RENDERIZADORSONOROSUPERBONUS_H__CDF08B08_F3E5_415A_BFD6_678C1DE8E8ED__INCLUDED_)
