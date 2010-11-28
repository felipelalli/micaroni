/*
 * $RCSfile: LeitorNotasSmiles.h,v $
 * $Date: 2004/05/17 21:10:20 $
 * $Revision: 1.12 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef LEITOR_NOTAS_SMILES_H
#define LEITOR_NOTAS_SMILES_H


#include "biblia/io/noteiro/LeitorNotas.h"
using namespace biblia::io::noteiro;

#include "biblia/io/noteiro/smiley/ComandosSmiley.h"
#include "biblia/io/noteiro/smiley/EventosSmiley.h"
#include "biblia/io/noteiro/smiley/SmileyControlLayer.h"
using namespace biblia::io::noteiro::smiley;

namespace biblia{

	namespace io{

		namespace noteiro{

			class LeitorNotasSmiles : public LeitorNotas {

				private:
					int pNotasHabilitadas;					
					int pNota;
					
					void LeitorNotasSmiles::pHabilitar();
					int  LeitorNotasSmiles::pQtsReais (int canal);

					SmileyControlLayer pControlLayer;

					enum Constantes{

						REAIS_CANAL1	=   1,
						REAIS_CANAL2	=   2,
						REAIS_CANAL3	=   5,
						REAIS_CANAL4	=  10,
						REAIS_CANAL5	=  50,
						REAIS_CANAL6	= 100,
					};


				public:
					LeitorNotasSmiles::LeitorNotasSmiles (UniversoDeTempo& universoDeTempo,const char* porta);
					LeitorNotasSmiles::~LeitorNotasSmiles ();

					Executavel& LeitorNotasSmiles::executa ();					

					void LeitorNotasSmiles::ligar(const char* porta);
					void LeitorNotasSmiles::desligar();

					void LeitorNotasSmiles::habilitarNotas (int notas);
			};
		}
	}
}
#endif