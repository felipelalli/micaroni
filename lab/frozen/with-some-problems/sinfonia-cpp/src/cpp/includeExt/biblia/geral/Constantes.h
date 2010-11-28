#ifndef CONTANTES_GERAL_H
#define CONTANTES_GERAL_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include <string>
using namespace std;

#ifdef WIN32
#define AGES_INT_64 __int64
#else
#define AGES_INT_64 long
#endif

namespace biblia{

	namespace geral{

		class Constantes : public Objeto{

			public:

				static bool demonstracao;

				static int valorMinimoDoAcumulado;

				static std::string diretorioBase;

				static std::string diretorioDat;

				static std::string diretorioSom;

				static std::string diretorioXML;

				static std::string arqInfoGerenciadorRede;
				static std::string arqConfGerenciadorRede;

				static std::string arqAcumulado;
				static std::string arqAcumuladoCliente;

				static std::string arqLeitorNotas;

				static std::string arqContador;

				static std::string arqLicenca;

				static std::string arqUsuario;

				static std::string arqVersao;

				static std::string arqDesligamento;
				static std::string arqEventos;

				static std::string arqCartelas;
				static std::string arqCreditoAtual;
				static std::string arqDobro;
				static std::string arqUltimasJogadas;
				static std::string arqPremiosDevidos;
				static std::string arqCobranca;
				static std::string arqBolaExtra;

				static std::string arqPremiacao;
				static std::string arqProbabilidades;

				static std::string arqCamadasSimulacao;
				static std::string arqCamadasConfiguracao;
				static std::string arqCamadas;

				static std::string arqHistorico;
				static std::string arqDicionario;
				static std::string arqConfiguracao;

				static std::string arqSimulacao;

				static std::string scriptSalvarHistorico;
				static std::string scriptRestaurarHistorico;
				static std::string scriptMudarData;
				static std::string scriptRede;

				static std::string arqMacAddress;

				static std::string arqDebug;

				static std::string arqLock;

				static std::string diretorioArqEterno;
				static std::string diretorioEstatistica;

				static std::string diretorioJogo;
				static std::string diretorioPics;
				static unsigned long chaveUsuario [4];
				static unsigned long chaveJogos   [4];
				static unsigned long chaveSistema [4];

				enum{

					SLEEP_THREAD_ACUMULADO =10,
					CANTOS_ID =1,
					LINHA_ID =2,
					CRUZ_PEQUENA_ID =3,
					T_ID =4,
					CRUZ_GRANDE_ID =5,
					QUADRADO_ID =6,
					LINHA_DUPLA_ID =7,
					U_ID =8,
					PERIMETRO_ID =9,
					BINGO_ID =10,
					ACUMULADO_ID =11
				};
		};

	}
}

#endif