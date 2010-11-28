/*
 * $RCSfile: FMod.h,v $
 * $Date: 2004/05/14 19:59:16 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#include <fmod.h>
#include <fmod_errors.h>

#ifndef FMOD_H
#define FMOD_H

#include <stdio.h>
#include <stdlib.h>
#ifdef WIN32
    #include <windows.h>
    #include <conio.h>
#else
	#undef stricmp
	#include "wincompat.h"
#endif

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/util/Debug.h"
using namespace biblia::util;

namespace biblia{

	namespace mais{

		namespace fmod{

			class FMod: public Objeto {

				private:

					bool pPrioridade;

					biblia::armazenamento::volatil::Lista* pLstSons;

					class CSom{

						protected:
							ListaInt pLstCanais;
							char pNomeArquivo [200];

						public:
							CSom& CSom::toca(int novoCanal);
							CSom& CSom::limpaLista();
							CSom& CSom::paraTudo();
							bool  CSom::estaTocando();
					
							char* CSom::nomeArquivo(){
								return pNomeArquivo;
							}

							//int canal;
							int volume;
							int prioridade;
							FSOUND_SAMPLE* mod;

							CSom::CSom(const char* musica,int pVolume = 125, int pPrioridade=0);
							CSom::~CSom();

							//bool tocando();
					};

				public:

					FMod::FMod(bool prioridade);
					FMod::~FMod();

					/* Toca um som. O padrão é não tocar ao mesmo tempo. */
					void FMod::tocar(int musica);

					void FMod::prioridade(bool usar = false);

					bool FMod::tocando (int musica);
					void FMod::para(int musica);

					//Volume varia de 0 (mudo) a 100 (maximo)
					void FMod::mudarVolume(int musica, int pVolume);

					void FMod::mudarPrioridade(int musica, int pPrioridade);

					int FMod::add(const char* musica,int pVolume = 50, int pPrioridade = -1);

					void FMod::paraTudo();
					bool FMod::temSomTocandoMaiorQue(int prioridade);
					unsigned int FMod::quantosSonsTocando() {
						return this->pLstSons->size() + 1;
					}
			};
		}
	}
}

#endif
