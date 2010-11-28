/*
 * $RCSfile: ArquivoBasico.h,v $
 * $Date: 2005/02/03 00:52:22 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: cvsroot $)
 */

#ifndef ARQUIVO_H_SW
#define ARQUIVO_H_SW

#ifdef WIN32
#include <io.h>
#endif

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifdef WIN32
	#include <direct.h>
	#include <dos.h>
	#include <direct.h>
	#include <stdio.h>
	#include <windows.h>
	#include <stdlib.h>
#else
	#include <dirent.h>
	#include <unistd.h>
	#include <fcntl.h>
#endif

#define PERMICOES_SW (S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH|S_IWOTH|S_IXOTH)

//#ifdef WIN32
#define SEPARADOR_DIR_SW '/'
//#else
//  #define SEPARADOR_DIR_SW '/'
//#endif

/* MODOS DE ABERTURA DO ARQUIVO */
#define SOMENTE_LEITURA   O_RDONLY
#define SOMENTE_ESCRITA   O_WRONLY
#define LEITURA_E_ESCRITA O_RDWR
#define CRIAR             O_CREAT
#define CRIAR_EXCLUSIVO   (O_CREAT | O_EXCL)
#define CRIAR_TRUNCADO    (O_CREAT | O_TRUNC)

/* MODOS DE CRIACAO DO ARQUIVO */
#define CRIAR_SOMENTE_LEITURA   S_IREAD
#define CRIAR_SOMENTE_ESCRITA   S_IWRITE
#define CRIAR_LEITURA_E_ESCRITA (S_IREAD | S_IWRITE)

/* EXTENCAO DO ARQUIVO TEMPORARIO */
#define ARQUIVO_TEMPORARIO_EXTENCAO ".backup.old.temp"

/* Tempo máximo de tentativas para verificar se um arquivo existe. */
#define TEMPO_MAXIMO_ARQUIVO_MB 10


#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/util/Debug.h"
using namespace biblia::util;

#include "biblia/seguranca/ChaveSeguranca.h"
#include "biblia/seguranca/Criptografia.h"
using namespace biblia::seguranca;

#include "biblia/fluxo/Thread.h"
using namespace biblia::fluxo;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

#include "biblia/fluxo/Semaforo.h"
using namespace biblia::fluxo;


namespace biblia {
 namespace io {
  namespace disco {

	enum TipoOperacao {CRIPTOGRAFAR,DECRIPTOGRAFAR};
	enum TipoDataArquivoBasico{DATA_CRIACAO,DATA_MODIFICACAO,DATA_ACESSO};

	class ArquivoBasico: public Objeto {

		private:

			static int qtsAbertos;
			static Semaforo pSemaAberto;			


			int pArq;
			int pILinha;
			int pTamanho;
			bool pEscrita;
			char pRestoLinha [1000];
			char nomeArq[400];


		public:
			ArquivoBasico();
			virtual ~ArquivoBasico();

			/*
			 * Verifica se o diretório existe.
			 */
			static int ArquivoBasico::existeDiretorio(
					const char* endereco);

			static bool ArquivoBasico::existeArquivoBasico(
					const char* arquivo,
					bool esperarTempoMaximo = false);

			/*
			 * Verifica se o caminho é um diretório.
			 */
			static bool ArquivoBasico::diretorio(const char* caminho);

			static void ArquivoBasico::destroiDiretorio(const char* diretorio);
			static int  ArquivoBasico::criaDiretorio(const char* diretorio);
			static int  ArquivoBasico::removeDiretorio(const char* diretorio);
			static int  ArquivoBasico::removeArquivoBasico(const char* arquivo);
			static bool ArquivoBasico::apaga(const char* arquivo);

			static bool ArquivoBasico::renomeia(
					const char* arquivoAntigo,
					const char* novoArquivoBasico);

			static void ArquivoBasico::temporario(
					char* destino, const char* nome);

			/* Uma forma mais simples: */
			virtual bool ArquivoBasico::abre(const char* arquivo,
						bool escrita = false);

			virtual void  ArquivoBasico::fecha();
			virtual bool  ArquivoBasico::lerLinha(char* linha);
			virtual int   ArquivoBasico::ler(char* buffer,int tamanho);
			virtual bool  ArquivoBasico::escrever(const char* linha,int tamanho = -1);
			virtual bool  ArquivoBasico::sincronizar();

			static bool ArquivoBasico::secureFile(ChaveSeguranca* chaveSeguranca,
					const char* arqOrigem,
					const char* arqDestino,
					TipoOperacao operacao);

			virtual long ArquivoBasico::dataArquivoBasico(
					const char* arquivo, TipoDataArquivoBasico tipoData);

			static void ArquivoBasico::sincronizarTudo();
	};
  }
 }
}

#endif

