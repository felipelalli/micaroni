#ifndef VERIFICADOR_DE_DESLIGAMENTO_SW_H
#define VERIFICADOR_DE_DESLIGAMENTO_SW_H

#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Segundo.h"
#include "biblia/tempo/unidades/Milissegundo.h"
using namespace biblia::tempo::unidades;

#include "biblia/io/disco/Arquivo.h"
using namespace biblia::io::disco;

#include "biblia/util/CData.h"
using namespace biblia::util;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;


namespace biblia{

	namespace util{

		class VerificadorDeDesligamento: public Executavel{

			private:

				bool pTerminar;
				bool pTerminou;
				Thread* pThread;

				std::string pUltimoDesligamento;

				void VerificadorDeDesligamento::pLeArquivo();
				void VerificadorDeDesligamento::pAtualizaArquivo();


			public:

				VerificadorDeDesligamento::VerificadorDeDesligamento();
				VerificadorDeDesligamento::~VerificadorDeDesligamento();

				std::string VerificadorDeDesligamento::ultimoDesligamento();

				Executavel& VerificadorDeDesligamento::executa();
		};
	}
}

#endif