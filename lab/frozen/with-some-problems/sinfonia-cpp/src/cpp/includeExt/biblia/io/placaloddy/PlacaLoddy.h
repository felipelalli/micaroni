/*
 * $RCSfile: PlacaLoddy.h,v $
 * $Date: 2003/11/13 15:50:00 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#ifndef PLACALODDY_H
#define PLACALODDY_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/fluxo/Executavel.h"
#include "biblia/fluxo/Semaforo.h"
#include "biblia/fluxo/Thread.h"
using namespace biblia::fluxo;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Milissegundo.h"
#include "biblia/tempo/unidades/Segundo.h"
using namespace biblia::tempo::unidades;

#include "biblia/io/teclado/Teclado.h"
using namespace biblia::io::teclado;

#include "biblia/util/Debug.h"
using namespace biblia::util;


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef WIN32
	#include <unistd.h>
	#include <fcntl.h>
#endif

#define QTS_BOTOES   20

namespace biblia{

	namespace io{
	
		namespace placaloddy{

			class PlacaLoddy: public Objeto,Executavel{

				public:
					enum EstadoLampada{
						APAGADO,
						ACESO,
						PISCANDO
					};

				private:
					int pArquivo;
					EstadoLampada pEstados [QTS_BOTOES];
					bool pEstadoBotoes [QTS_BOTOES];

					Thread* pThread;
					bool pTerminar;
					bool pTerminou;
					Semaforo* pSema;

					Teclado* pTeclado;

					bool PlacaLoddy::pEscrever (char* buffer,int tamanho);
					void PlacaLoddy::pAtualizaBotoes (char botao);


				public:
					
					PlacaLoddy::PlacaLoddy();
					PlacaLoddy::~PlacaLoddy();
					
					bool PlacaLoddy::acenderLampada (int lampada);
					bool PlacaLoddy::apagarLampada (int lampada);
					bool PlacaLoddy::piscarLampada (int lampada);
					EstadoLampada PlacaLoddy::getEstadoLampada (int lampada);
					bool PlacaLoddy::getEstadoBotao (int botao);
					bool PlacaLoddy::escreverDisplay (double valor);

					bool PlacaLoddy::pulsarContador (int contador, int vezes);
					
					Executavel& PlacaLoddy::executa ();
			};
		}
	}
}

#endif
