#ifndef MATEMATICA_TROPICAL_FRUTINHA_H
#define MATEMATICA_TROPICAL_FRUTINHA_H




#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/sorte/Sorteio.h"
using namespace biblia::sorte;

#include "biblia/jogos/frutinha/logica/Dados.h"
using namespace biblia::jogos::frutinha::logica;

#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/armazenamento/volatil/primitivos/Inteiro.h"
using namespace biblia::armazenamento::volatil::primitivos;

#include "biblia/jogos/frutinha/estados/EstadosTropical.h"
using namespace biblia::jogos::frutinha::estados;

#include "biblia/jogos/special/logica/SorteioBolas.h"
using namespace biblia::jogos::special::logica;

#include "biblia/jogos/frutinha/logica/util/ArqFilaDePremiacao.h"
using namespace biblia::jogos::frutinha::logica::util;



#define TAMANHO_FILA 1000
#define VALOR_MINIMO_PARA_ENTRAR_NO_CONTROLE_DE_RETENCAO 100

namespace biblia{
	namespace jogos{
		namespace frutinha{
			namespace logica{

				class MatematicaTropical: public Objeto{

					private:

						DadosTropical pDados;
						Sorteio pSorteio;
						SorteioBolas pSorteBolas;
						EstadosTropical& pEstados;
						ArqFilaDePremiacao pArqFilaDePremiacao;

						int pVetAposta[5];
						int  pRodilho[3][5];
						bool pRodilhoMarcado[5][5];
						int  vetPremiosRodilho[5];

						ListaInt vetPremiosDevidos_1_2;
						ListaInt vetPremiosDevidos_1_2_Acumulado;
						ListaInt vetPremiosDevidos_3_4_5;
						ListaInt vetPremiosDevidos_3_4_5_Acumulado;

						ListaInt vetQualLinha_PremiosDevidos_1_2;
						ListaInt vetQualLinha_PremiosDevidos_1_2_Acumulado;
						ListaInt vetQualLinha_PremiosDevidos_3_4_5;
						ListaInt vetQualLinha_PremiosDevidos_3_4_5_Acumulado;

						int indVetPremios_1_2;
						int vetPremios_1_2 [TAMANHO_FILA];

						int indVetPremios_1_2_Acumulado;
						int vetPremios_1_2_Acumulado [TAMANHO_FILA];

						int indVetPremios_3_4_5;
						int vetPremios_3_4_5 [TAMANHO_FILA];

						int indVetPremios_3_4_5_Acumulado;
						int vetPremios_3_4_5_Acumulado [TAMANHO_FILA];

						void MatematicaTropical::pExibirFila (char* msg,int qtsLinhas, int aposta, bool demonstracao);

						void MatematicaTropical::pZeraRodilho();
						void MatematicaTropical::pCopiaRodilho (int rodilhoOrigem[3][5], int rodilhoDestino[3][5]);
						void MatematicaTropical::pVerificaPremios (int* vetPremios,int rodilho[3][5]);

						int  MatematicaTropical::pValorPremio (int premio, int aposta);
						bool MatematicaTropical::pEfetuaControleDeRetencaoNessePremio (int premio, int aposta);
						int  MatematicaTropical::pValorMaximoDePremioQuePodeSerPago ();
						bool MatematicaTropical::pPassaNoControleDeRetencao (int premio, int aposta);
						bool MatematicaTropical::pColocaPremio (int iLinha,int premio, int* vetAposta);
						void MatematicaTropical::pCompletarRodilho ();

						int MatematicaTropical::pSortearPremio (int qtsLinhas, int aposta, bool demonstracao);
						void MatematicaTropical::pGerarPremiacao(int qtsLinhas, int aposta, bool demonstracao);
						void MatematicaTropical::pArranjarPremiacao(int* vetPremios, int qtsPremios);

						int MatematicaTropical::pGetPremio(int qtsLinhas, int aposta, bool demonstracao);

						void MatematicaTropical::pModificaPosicaoNaFila (int premio,int qtsLinhas, int aposta, bool demonstracao);
						int* MatematicaTropical::pQualLista (int qtsLinhas,int aposta, bool demonstracao, int** indice);
						std::string MatematicaTropical::pQualNomeLista (int qtsLinhas,int aposta, bool demonstracao);
						ListaInt& MatematicaTropical::qualListaPremiosDevidos(const int& qtsLinhas, const int& apostaAtual, bool demonstracao);
						ListaInt& MatematicaTropical::qualLinhaListaPremiosDevidos(const int& qtsLinhas, const int& apostaAtual, bool demonstracao);

					public:
						MatematicaTropical::MatematicaTropical (EstadosTropical& estados);
						MatematicaTropical::~MatematicaTropical ();

						void MatematicaTropical::sortearRodilho (int* vetAposta, bool demonstracao);
						int MatematicaTropical::getFrutaRodilho (int linha, int coluna);
						bool MatematicaTropical::estaMarcado (int linha, int coluna);

						int MatematicaTropical::getPremio (int linha);
						int MatematicaTropical::getFrutaPremio (int linha);
						int MatematicaTropical::valorPremio (int premio, int aposta);

						bool MatematicaTropical::ehAcumulado (int premio, int aposta);
						bool MatematicaTropical::ehBonus (int premio);

						int MatematicaTropical::getLinhaPremio (int iPremio, int iColuna);
						int MatematicaTropical::qtsCelulas (int iPremio);
				};

			}
		}
	}
}

#endif