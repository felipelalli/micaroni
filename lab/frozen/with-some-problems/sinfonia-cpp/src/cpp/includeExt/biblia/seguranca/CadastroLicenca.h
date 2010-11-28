#ifndef CADLICENCA_H_SW
#define CADLICENCA_H_SW

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/seguranca/ControleLicenca.h"
#include "biblia/seguranca/SecureMessage.h"
#include "biblia/seguranca/DigestMD5.h"
#include "biblia/seguranca/ChaveSeguranca.h"
using namespace biblia::seguranca;

namespace biblia{

	namespace seguranca{

		class CadastroLicenca: public Objeto {
			private:		
				
				bool pInicial;
				bool pFuncionamento;

				unsigned short pSerial;
				unsigned char  pTipo;
				unsigned short pAtualizacao;
				unsigned int   pHashMacAddress;
				unsigned char  pDiasRestantes;
				unsigned int   pEntrada;
				unsigned int   pSaida;
				unsigned int   pIdVersao;

				ChaveSeguranca& pChaveSeguranca;

			public:

				CadastroLicenca::CadastroLicenca(ChaveSeguranca& chave);
				CadastroLicenca::~CadastroLicenca();

				bool  CadastroLicenca::carregarLicenca (char* buffer);

				char* CadastroLicenca::gerarLicencaInicial (unsigned short serial,
															unsigned short atualizacao,
															unsigned int   hashMacAddress,															
															unsigned char  diasRestantes);
				
				char* CadastroLicenca::gerarLicencaFuncionamento (unsigned short serial,
																  unsigned short atualizacao,
																  unsigned int   apostado,
																  unsigned int   ganho,
																  unsigned char  diasRestantes);

				bool CadastroLicenca::inicial(){return this->pInicial;};
				bool CadastroLicenca::funcionamento(){return this->pFuncionamento;};

				unsigned short CadastroLicenca::getSerial()        {return pSerial;};
				unsigned char  CadastroLicenca::getTipo()          {return pTipo;};
				unsigned short CadastroLicenca::getAtualizacao()   {return pAtualizacao;};
				unsigned int   CadastroLicenca::getIdVersao()      {return pIdVersao;};
				unsigned int   CadastroLicenca::getHashMacAddress(){return pHashMacAddress;};
				unsigned char  CadastroLicenca::getDiasRestantes() {return pDiasRestantes;};
				unsigned int   CadastroLicenca::getApostado()      {return pEntrada;};
				unsigned int   CadastroLicenca::getGanho()         {return pSaida;};
				
				static unsigned short CadastroLicenca::proximaAtualizacao (unsigned short atualizacao);
		};
	}
}

#endif