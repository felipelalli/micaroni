/*
 * $RCSfile: BarraDeMensagens.h,v $
 * $Date: 2004/06/28 19:17:46 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef BARRA_DE_MENSAGENS_H
#define BARRA_DE_MENSAGENS_H



#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/armazenamento/eterno/VariavelEmArquivo.h"
using namespace biblia::armazenamento::eterno;

#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

#include "biblia/tempo/Cronometro.h"
#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Milissegundo.h"
#include "biblia/tempo/unidades/Segundo.h"
using namespace biblia::tempo::unidades;




namespace biblia{

	namespace jogos{

		namespace frutinha{

			namespace estados{

				class BarraDeMensagens: public Executavel{

					private:					
						
						Cronometro pCronometro;
						Intervalo pIntervaloPiscada;
						Intervalo pIntervaloPiscaInsiraCreditos;
						Intervalo pIntervaloTempoQueInsiraCreditosPermaneceAcesso;

						int pQualMensagem;
						bool pPiscaInsiraCreditos;
						bool pInsiraCreditosAcesso;						

					public:
						BarraDeMensagens::BarraDeMensagens(UniversoDeTempo& universo);
						BarraDeMensagens::~BarraDeMensagens();

						void BarraDeMensagens::demonstracao();
						void BarraDeMensagens::boaSorte();
						void BarraDeMensagens::insiraCreditos();
						void BarraDeMensagens::piscaInsiraCreditos();

						int BarraDeMensagens::qualMensagem();

						Executavel& BarraDeMensagens::executa();

						enum Mensagens{

							NENHUMA        =-1,
							DEMONSTRACAO   = 1,
							BOA_SORTE      = 2,
							INSIRA_CREDITOS= 3
						};
				};
			}
		}
	}
}

#endif