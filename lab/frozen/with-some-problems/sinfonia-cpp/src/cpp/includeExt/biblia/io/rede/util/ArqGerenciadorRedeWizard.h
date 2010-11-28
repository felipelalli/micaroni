/*
 * $RCSfile: ArqGerenciadorRedeWizard.h,v $
 * $Date: 2004/06/09 12:31:43 $
 * $Revision: 1.10 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef ARQ_GERENCIADOR_REDE_WIZARD
#define ARQ_GERENCIADOR_REDE_WIZARD



#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/io/disco/ArquivoBasico.h"
using namespace biblia::io::disco;

#include "biblia/fluxo/Semaforo.h"
using namespace biblia::fluxo;

#include "biblia/armazenamento/volatil/ListaInt.h"
#include "biblia/armazenamento/volatil/ListaString.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/seguranca/ChaveSeguranca.h"
using namespace biblia::seguranca;

#include "biblia/util/StrToken.h"
#include "biblia/util/Debug.h"
using namespace biblia::util;

#include "biblia/io/rede/RedeUtil.h"
using namespace biblia::io::rede;

#include "biblia/armazenamento/volatil/primitivos/Inteiro.h"
using namespace biblia::armazenamento::volatil::primitivos;

namespace biblia{

	namespace io{

		namespace rede{

			namespace util{

				class ArqGerenciadorRedeWizard : public Objeto{

					private:

						char pArquivoBasico[100];
						ChaveSeguranca* pChaveSeguranca;

						Semaforo* pSemaforo;

						char pIP [20];
						int pPorta;
						bool pLocal;

						ListaString* pLstIP;
						ListaInt* pLstHub;
						ListaInt* pLstLigado;


						void ArqGerenciadorRedeWizard::pGeraLocal();
						void ArqGerenciadorRedeWizard::pGeraEmRede();


						void ArqGerenciadorRedeWizard::pOrdenarListas();

					public:
						static int ArqGerenciadorRedeWizard::finalDoIp (char* ip);

						ArqGerenciadorRedeWizard::ArqGerenciadorRedeWizard(const char* arquivo, ChaveSeguranca* chave);
						ArqGerenciadorRedeWizard::~ArqGerenciadorRedeWizard();

						void ArqGerenciadorRedeWizard::carregar();
						void ArqGerenciadorRedeWizard::salvar();

						char* ArqGerenciadorRedeWizard::getIPLocal();
						void  ArqGerenciadorRedeWizard::setIPLocal(const char* ipLocal);

						int   ArqGerenciadorRedeWizard::getPorta();
						void  ArqGerenciadorRedeWizard::setPorta(int porta);

						ListaString* ArqGerenciadorRedeWizard::getListaIP();
						ListaInt* ArqGerenciadorRedeWizard::getListaHub();						
						ListaInt* ArqGerenciadorRedeWizard::getListaLigado();						

						void ArqGerenciadorRedeWizard::setListaIP(ListaString* lstIP){};
						void ArqGerenciadorRedeWizard::setListaHub(ListaInt* lstIP){};						
						void ArqGerenciadorRedeWizard::setListaLigado(ListaInt* lstIP){};						

						void ArqGerenciadorRedeWizard::setRedeLocal (bool local);
						bool ArqGerenciadorRedeWizard::getRedeLocal();
				};
			}
		}
	}
}

#endif