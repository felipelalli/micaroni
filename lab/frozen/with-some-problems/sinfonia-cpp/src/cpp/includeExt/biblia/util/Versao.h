#ifndef VERSAO_H
#define VERSAO_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/io/disco/Arquivo.h"
#include "biblia/io/disco/ArquivoBasico.h"
using namespace biblia::io::disco;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

#include "biblia/seguranca/DigestMD5.h"
using namespace biblia::seguranca;

#include <string>
using namespace std;




namespace biblia{

	namespace util{

		class Versao: public Objeto{

			private:
				std::string pNomeAplicacao;
				std::string pVersao;
				int    pIdVersao;
				std::string pData;

			public:
				Versao::Versao();
				Versao::Versao(const char* arquivo,
							   const char* nomeAplicacao,
							   const char* versao,
							   int idVersao,
							   const char* data);

				Versao::~Versao();

				std::string Versao::nomeAplicacao();

				std::string Versao::versao();
				int    Versao::idVersao();

				std::string Versao::data();

				std::string Versao::emString ();
		};

	}
}

#endif