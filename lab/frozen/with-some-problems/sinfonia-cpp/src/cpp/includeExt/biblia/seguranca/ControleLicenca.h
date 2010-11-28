/*
 * $RCSfile: ControleLicenca.h,v $
 * $Date: 2005/02/03 00:55:28 $
 * $Revision: 1.13 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: cvsroot $)
 */

#ifndef CONTROLE_LICENCA_H
#define CONTROLE_LICENCA_H

#include <time.h>

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/util/Versao.h"
#include "biblia/util/Debug.h"
using namespace biblia::util;

#include "biblia/io/rede/RedeUtil.h"
using namespace biblia::io::rede;

#include "biblia/seguranca/DigestMD5.h"
#include "biblia/seguranca/ChaveSeguranca.h"
#include "biblia/seguranca/SecureMessage.h"
#include "biblia/seguranca/CadastroLicenca.h"
#include "biblia/seguranca/VerificadorDeDispositivoComLicenca.h"
using namespace biblia::seguranca;

#include "biblia/seguranca/util/Licenca.h"
#include "biblia/seguranca/util/ArqLicenca.h"
using namespace biblia::seguranca::util;

#include "biblia/io/disco/ArquivoBasico.h"
using namespace biblia::io::disco;

#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Semaforo.h"
#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Segundo.h"
#include "biblia/tempo/unidades/Milissegundo.h"
using namespace biblia::tempo::unidades;

#include "biblia/armazenamento/eterno/Contador.h"
using namespace biblia::armazenamento::eterno;

#include "biblia/sorte/Sorteio.h"
using namespace biblia::sorte;

#define NUMEROS_DE_LICENCAS_DEFAULT 100

#define CODIGO_ENTRADA "87594"

/******************INFORMACOES PARA LICENCA**************************/
/*CAMPOS   : serial | tipo | atualizacao | entrada |  saida  | dias */
/*TAMANHO  :   15   |   4  |     15      |    20   |    20   |  8   */
/*TAMANHO B:    2   |   1  |      2      |     4   |     4   |  1   */
/*VALOR MAX: 32.768 |  16  |   32.768    |1.048.576|1.048.576| 256  */
/*TOTAL    : 82 bits (10 bytes e 2 bits)                            */
/*TOTAL B  : 14 bytes (112 bits)                                    */
/********************************************************************/



namespace biblia{

	namespace seguranca{

		class VerificadorDeDispositivoComLicenca;

		class ControleLicenca: public Executavel,
								  public Objeto{
			private:

				Versao pVersao;
				ArqLicenca* pArqLicenca;

				Contador* pContador;

				VerificadorDeDispositivoComLicenca* pVerificador;

				bool pMudarData;
				bool pMudandoData;

				Semaforo* pSema;
				Thread* pMinhaThread;
				
				ChaveSeguranca* pChaveSeguranca;

				bool pTerminar;
				bool pTerminou;

				unsigned short pAtualizacaoInicial;

				void ControleLicenca::pVerificarData();

				static int ControleLicenca::pCalcularDiferenca(time_t ultimaLeitura, time_t leituraAtual);

			public:
				ControleLicenca::ControleLicenca(ChaveSeguranca* chaveSeguranca,Contador* contador);
				ControleLicenca::~ControleLicenca();

				Executavel& ControleLicenca::executa ();				

				bool ControleLicenca::cadastrada();
				bool ControleLicenca::habilitado();
				unsigned int  ControleLicenca::tempoRestante();
				unsigned int  ControleLicenca::segundosRestantes();

				bool ControleLicenca::licencaAtual (char** buffer,int* tamanho);
				bool ControleLicenca::entrarLicenca(char* licenca,int tamanho);

				bool ControleLicenca::codigoInicial (char** buffer, int* tamanho);
				bool ControleLicenca::entrarLicencaInicial(char* licenca,int tamanho);				

				void ControleLicenca::iniciarMudancaData();
				void ControleLicenca::terminarMudancaData();

				void ControleLicenca::gerouLicenca();

				static void ControleLicenca::getVariables (char* buffer,int qtsElementos,...);
				static void ControleLicenca::setVariables (char* buffer,int qtsElementos,...);
		};
	}
}
#endif


/*
void main(){	

	char buffer[100];

	GerenciadorLicenca* licenca = new GerenciadorLicenca(Constantes::chaveJogo);

	while (true){

		printf ("Dias restantes: %d\n",licenca->tempoRestante());

		if (licenca->cadastrada()){
			int tamLic;
			char* bufferLic;
			licenca->licencaAtual (&bufferLic,&tamLic);
			printf ("Licenca atual: %s\n",bufferLic);
		}

		printf ("Digite a licenca: ");
		scanf ("%s",buffer);
		printf ("\n");

		if (licenca->cadastrada()){
			if (licenca->entrarLicenca(buffer,strlen(buffer))){
				printf ("Licenca cadastrada com sucesso!!!\n");
			}else{
				printf ("Licenca invalida!!!\n");
			}
		}else{
			if (licenca->entrarLicencaInicial(buffer,strlen(buffer))){
				printf ("Licenca cadastrada com sucesso!!!\n");
			}else{
				printf ("Licenca invalida!!!\n");
			}
		}
	}

	delete licenca;
}
*/