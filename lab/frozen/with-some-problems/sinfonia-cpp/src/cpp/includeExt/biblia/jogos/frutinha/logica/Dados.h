#ifndef DADOS_FRUTINHA_H
#define DADOS_FRUTINHA_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/io/disco/Arquivo.h"
using namespace biblia::io::disco;

#include "biblia/util/StrToken.h"
using namespace biblia::util;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

#include "biblia/jogos/frutinha/estados/EstadosTropical.h"
using namespace biblia::jogos::frutinha::estados;

#include "biblia/seguranca/ChaveSeguranca.h"
using namespace biblia::seguranca;


namespace biblia{
	namespace jogos{
		namespace frutinha{
			namespace logica{

				class DadosTropical: public Objeto{

					private:
						char   pVetNome                [100][100];
						double pVetProb_1_2            [100];
						double pVetProb_1_2_acumulado  [100];
						double pVetProb_3_4_5          [100];
						double pVetProb_3_4_5_acumulado[100];
						int    pVetValor               [100];						
						double pPercentualPagamento;
						double pPercentualRetencao;

						EstadosTropical& pEstados;

						void DadosTropical::pEscreveProbs (char* nome,double* prob,bool concorre);

					public:
						DadosTropical::DadosTropical(EstadosTropical& estados);
						DadosTropical::~DadosTropical();

						int DadosTropical::qtsProbabilidades();
						double DadosTropical::getProbabilidade(int indProb, int qtsLinhas, int aposta, bool demonstracao);
						int DadosTropical::getValor (int premio, int aposta);
						int DadosTropical::qtsCelulas (int premio);
						
						double DadosTropical::percentualDeRetencao();

						int DadosTropical::qtsFrutas ();
						int DadosTropical::qualFruta (int premio);

						int DadosTropical::mesmoPremio (int premio, int premioComp);
						int DadosTropical::qualPremio (int fruta, int repeticoes);

						bool DadosTropical::ehAcumulado (int premio, int aposta);
						bool DadosTropical::ehBonus (int premio);
				};

			}
		}
	}
}

#endif