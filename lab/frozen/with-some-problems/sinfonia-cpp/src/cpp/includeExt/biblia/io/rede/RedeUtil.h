/*
 * $RCSfile: RedeUtil.h,v $
 * $Date: 2004/06/01 00:51:34 $
 * $Revision: 1.8 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef REDEUTIL_H
#define REDEUTIL_H

#include "biblia/io/disco/ArquivoBasico.h"
using namespace biblia::io::disco;

#include "biblia/seguranca/DigestMD5.h"
using namespace biblia::seguranca;

#include "biblia/io/script/RodadorScript.h"
using namespace biblia::io::script;

#ifndef WIN32
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#endif

#ifdef WIN32
#include <snmp.h>
#endif

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

namespace biblia{

	namespace io{

		namespace rede{

			class RedeUtil: public Objeto{
				private:
					static char RedeUtil::buffer[200];
					static bool RedeUtil::inicializado;

				public:
					static bool RedeUtil::mudarIP (char* novoIP);
					static void RedeUtil::getMacAddress(char* retorno);
					static void RedeUtil::getIPLocal (char* retorno);
					static int  RedeUtil::hashMacAddres();
					static void RedeUtil::reset();
			};
		}
	}
}

#endif
