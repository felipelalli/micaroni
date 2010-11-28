/*
 * $RCSfile: RodilhoAnimado.h,v $
 * $Date: 2004/03/31 18:57:09 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#ifndef RODILHO_TROPCIAL_H___
#define RODILHO_TROPCIAL_H___

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/jogos/frutinha/estados/Rodilho.h"
using namespace biblia::jogos::frutinha::estados;

#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

#include "biblia/tempo/Cronometro.h"
#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Milissegundo.h"
using namespace biblia::tempo::unidades;

/** MILISSEGUNDOS */
#define INTERVALO_PARAR_DE_RODAR 1000
#define INTERVALO_ENTRE_RODILHOS 300

#define INTERVALO_ENTRE_PISCADAS 100
#define INTERVALO_EM_QUE_FICA_ACESO 100
#define QTS_PISCADAS 5

namespace biblia{

	namespace jogos{

		namespace frutinha{

			namespace estados{
				
				class RodilhoAnimado: public Executavel{

					private:
						Rodilho pRodilho;

						bool pRodando;
						bool pTotalmenteParado;
						int pDeveParar;
						int pParaQualRodilho;

						Cronometro pCronometroParadaRodilho;
						Intervalo pIntervaloPararDeRodar;
						Intervalo pIntervaloEntreRodilhos;


						bool pDevePiscar;
						bool pEhAcumuladoOuBonus;
						bool pPiscadaAcesa;
						int  pQtsPiscadas;
						bool pVetMarcadosAcumuladoEBonus [5][5];
						Cronometro pCronometroPiscadaAcumuladoEBonus;
						Intervalo pIntervaloEntrePiscadas;
						Intervalo pIntervaloEmQueFicaAceso;

					public:
						RodilhoAnimado::RodilhoAnimado(UniversoDeTempo&);
						virtual RodilhoAnimado::~RodilhoAnimado();
						
						RodilhoAnimado& RodilhoAnimado::visivel(bool visivel);
						bool RodilhoAnimado::visivel();

						RodilhoAnimado& RodilhoAnimado::rodaRodilho ();
						bool RodilhoAnimado::rodando ();
						bool RodilhoAnimado::totalmenteParado();
						RodilhoAnimado& RodilhoAnimado::totalmenteParado(bool estado);
						
						RodilhoAnimado& RodilhoAnimado::defineFigura (int linha, int coluna, int figura);						
												

						RodilhoAnimado& RodilhoAnimado::mudaAposta (int linha, int aposta);
																		
						int RodilhoAnimado::apostaPremio (int linha);

						Rodilho& RodilhoAnimado::getRodilho();

						Executavel& RodilhoAnimado::executa();

						RodilhoAnimado& RodilhoAnimado::limpaEventos();

						RodilhoAnimado& RodilhoAnimado::ehAcumuladoOuBonus(bool eh);

						RodilhoAnimado& RodilhoAnimado::marcaPosicaoAcumuladoOuBonus (int iPremio, int iColuna, bool marcado);
						bool RodilhoAnimado::posicaoDeAcumuladoOuBonus (int iPremio, int iColuna);
						bool RodilhoAnimado::piscadaAcesa();
				};
			}
		}
	}
}

#endif