/*
 * $RCSfile: Licenca.h,v $
 * $Date: 2004/12/01 15:01:02 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef LICENCA_H
#define LICENCA_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/util/Debug.h"
using namespace biblia::util;

#include "biblia/io/rede/RedeUtil.h"
using namespace biblia::io::rede;

#include "biblia/seguranca/ChaveSeguranca.h"
#include "biblia/seguranca/DigestMD5.h"
#include "biblia/seguranca/SecureMessage.h"
using namespace biblia::seguranca;




#define TAM_SERIAL      2
#define TAM_TIPO        1
#define TAM_ATUALIZACAO 2
#define TAM_SEGUNDOS    4
#define TAM_DIAS        1
#define TAM_HORA        4
#define TAM_MAC_ADDR    4
#define TAM_VERSAO      4
#define TAM_ENTRADA     4
#define TAM_SAIDA       4
#define TAM_LIC_GERADAS 4


namespace biblia{

	namespace seguranca{

		namespace util{

			class Licenca : public Objeto{

				private:

					ChaveSeguranca* pChaveSeguranca;

					unsigned short pSerial;
					unsigned char  pTipo;
					unsigned short pAtualizacao;
					unsigned int   pSegundosRestantes;
					unsigned int   pMac_address_hash;
					long           pData;
					unsigned int   pLicencasGeradas;

					void Licenca::pGetVariables (char* buffer,int qtsElementos,...);
					void Licenca::pSetVariables (char* buffer,int qtsElementos,...);

				public:
					Licenca::Licenca (ChaveSeguranca* chave);
					Licenca::~Licenca();

					bool Licenca::setLicenca(char* licenca);
					void Licenca::getLicenca(char* licenca);

					unsigned short Licenca::getSerial();
					unsigned char  Licenca::getTipo();
					unsigned short Licenca::getAtualizacao();
					unsigned int   Licenca::getSegundosRestantes();
					unsigned char  Licenca::getDiasRestantes();
					unsigned int   Licenca::getMacAddressHash();
					long           Licenca::getData();
					unsigned int   Licenca::getLicencasGeradas();

					void Licenca::setSerial(unsigned short serial);
					void Licenca::setTipo(unsigned char tipo);
					void Licenca::setAtualizacao(unsigned short atualizacao);
					void Licenca::setSegundosRestantes(unsigned int segundosRestantes);
					void Licenca::setMacAddressHash(unsigned int macAddressHash);
					void Licenca::setData(long data);
					void Licenca::setLicencasGeradas (unsigned int licencasGeradas);
			};
		}
	}
}

#endif