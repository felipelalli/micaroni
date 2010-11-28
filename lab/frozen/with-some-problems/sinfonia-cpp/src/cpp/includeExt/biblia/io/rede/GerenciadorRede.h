/*
 * $RCSfile: GerenciadorRede.h,v $
 * $Date: 2005/03/16 20:24:19 $
 * $Revision: 1.18 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: cvsroot $)
 */

#ifndef GERENCIADOR_REDE_SW
#define GERENCIADOR_REDE_SW

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/util/Debug.h"
using namespace biblia::util;

#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Semaforo.h"
#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

#include "biblia/io/rede/ComunicadorRede.h"
#include "biblia/io/rede/MaquinaNaRede.h"
#include "biblia/io/rede/GerenciadorMaquinaNaRede.h"
using namespace biblia::io::rede;

#include "biblia/io/rede/interfaces/interfacesServidor/InterServGerenciadorRede.h"
using namespace biblia::io::rede::interfaces::interfacesServidor;

#include "biblia/tempo/Intervalo.h"
#include "biblia/tempo/Cronometro.h"
#include "biblia/tempo/UniversoDeTempo.h"
using namespace biblia::tempo;

#include "biblia/sorte/Sorteio.h"
using namespace biblia::sorte;

#include "biblia/tempo/unidades/Milissegundo.h"
#include "biblia/tempo/unidades/Segundo.h"
using namespace biblia::tempo::unidades;

#include "biblia/io/rede/RedeUtil.h"
using namespace biblia::io::rede;

namespace biblia{

	namespace io{

		namespace rede{

			class GerenciadorRede:	public Objeto,
									public ComunicadorRede,
									public Executavel{

				private:

					UniversoDeTempo& pUniverso;

					Sorteio pSorteio;

					bool pTerminar;

					int pPorta;
					char pIpLocal [16];

					bool pServidorEleito;
					int pIndiceServidor;

					InterServGerenciadorRede* pInterServGerenciadorRede;

					ChaveSeguranca* pChaveSeguranca;

					GerenciadorMaquinaNaRede* pLstMaquinas;

					void GerenciadorRede::pLimpa();
					void GerenciadorRede::pElegerServidor();

					Thread* pThreadEleicao;
					Semaforo* pSemaEleicao;

					Semaforo* pSemaUso;

					enum Constantes{
						TIMEOUT_INICIALIZACAO = 60,
						TIMEOUT_FALHA = 180
					};

					Cronometro* pCronometroErro;
					bool pErroDeRede;

				public:

					GerenciadorRede::GerenciadorRede(UniversoDeTempo& universo, char* ipLocal, int porta,
													 InterServGerenciadorRede* interServGerenciadorRede,
													 ChaveSeguranca* chave);

					virtual GerenciadorRede::~GerenciadorRede();

					void GerenciadorRede::limpar();
					void GerenciadorRede::addMaquina (char* ip, int hub);
					void GerenciadorRede::iniciar();

					void GerenciadorRede::reiniciar (char* ipLocal, int porta);

					bool GerenciadorRede::disponivel();

					int GerenciadorRede::makeComm(char* buffer,int tamanho);
					int GerenciadorRede::makeComm(int maquina,char* buffer,int tamanho);

					bool GerenciadorRede::conectado();
					bool GerenciadorRede::conectado(int maquina);

					int GerenciadorRede::qtsMaquinas();
					bool GerenciadorRede::ehServidor();
					int GerenciadorRede::indiceLocal();

					Executavel& GerenciadorRede::executa();

			};
		}
	}
}

#endif