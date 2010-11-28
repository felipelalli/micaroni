/*
 * $RCSfile: DEstatistica.h,v $
 * $Date: 2005/01/10 20:30:46 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include <stdio.h>

#include "biblia/io/disco/ArquivoBasico.h"
#include "biblia/util/StrToken.h"
#include "biblia/util/CData.h"
#include "biblia/jogos/special/dados/Dados.h"
#include "biblia/jogos/special/dados/DadosXML.h"
//#include "DadosXMLFixo.h"
															// para a criação do xml vazio.
#include "biblia/jogos/special/dados/DadosArqText.h"
#include "biblia/jogos/special/dados/Estatistica.h"
#include "biblia/jogos/special/util/NumeroUtil.h"

using namespace biblia::util;
using namespace biblia::io::disco;
using namespace biblia::jogos::special::util;

#ifndef SBS_DESTATISTICA_SW_H
#define SBS_DESTATISTICA_SW_H





namespace biblia {
  namespace jogos {
    namespace special {
	  namespace dados {

		class DEstatistica: public Estatistica {

			private:
				Dados* DEstatistica::pDados;
				char DEstatistica::pDiretorioRaiz[2000];
				bool DEstatistica::pEstatistica;
				bool DEstatistica::pContabilidade;
				bool DEstatistica::pAcumulado;

			protected:
				const char* DEstatistica::montaNomeArquivoBasicoOuDiretorio(
						int ano, int mes = 0, int dia = 0);

				DEstatistica& DEstatistica::criaSeNaoExiste(
						int ano, int mes = 0, int dia = 0);

				double DEstatistica::somatoria(const char* caminho,
				   				   const char* diretorioBase);

				void DEstatistica::valores(const char* caminho,
							   const char* diretorioBase,
							   biblia::armazenamento::volatil::Lista* lista);

			public:
				/*
				 * @param diretorioRaiz Base do diretorio que esta' organizado em:
				 * 			printf(%s%d%c%s%d%c%s%d%s,
 				 *                             ANO_EST, ano, SEPARADOR_DIR_SW,
				 *                             MES_EST, mes, SEPARADOR_DIR_SW,
				 *                             DIA_EST, dia, ARQUIVO_EST);
				 *                      e.g.:
				 *                      "ano-2002/mes-2/dia-3-estatistica.xml"
				 */
				DEstatistica::DEstatistica(
						const char* diretorioRaiz = ".",
						const bool simulacao=false);

				DEstatistica::~DEstatistica();

				/* Monta um caminho a partir das contantes _EST */
				static const char* DEstatistica::montaCaminhoEstatistica(
					const char* modo, const char* jogadasOuPremios,
					const char* premio = "");

				/* Monta um caminho a partir das contantes _CONT */
				static const char* DEstatistica::montaCaminhoContabilidade(
					const char* notasOuTotal, const char* oQue);

				/*
				 * Abre algum dia para que se possa ler atraves do leLong(caminho).
				 * Cuidado: esta funcao cria o arquivo caso ele nao exista.
				 */
				virtual Estatistica& DEstatistica::abreDia(int ano, int mes, int dia);


				/*
				 * Abre o arquivo parcial o geral para poder atualizar as
				 * configurações que são apresentadas nas telas de  configuração
				 */
				virtual Estatistica& DEstatistica::abreParcialOuGeral(const char* oQue);
				virtual Estatistica& DEstatistica::apagaGeral();
				virtual Estatistica& DEstatistica::apagaParcial();

				/*
				 * Zera tudo. Apaga o diretorio raiz e o cria de novo.
				 * --> MUITO CUIDADO AO CHAMAR ESSA FUNCAO. <--
				 */
				virtual Estatistica& DEstatistica::zeraTudo();

				/* Soma um ou mais dias, de um certo mes ou ano */
				long DEstatistica::somatoria(const char* caminho,
								 int ano, int mes = 0,
								 int dia = 0);

				double DEstatistica::somatoriaDouble(const char* caminho,
								 int ano, int mes = 0,
								 int dia = 0);

				biblia::armazenamento::volatil::Lista* DEstatistica::valores(const char* caminho,
								 int ano, int mes = 0,
								 int dia = 0);

				DEstatistica& DEstatistica::setEstatistica() {
					this->pEstatistica = true;
					this->pContabilidade = false;
					this->pAcumulado = false;
					return *this;
				}

				DEstatistica& DEstatistica::setContabilidade() {
					this->pContabilidade = true;
					this->pEstatistica = false;
					this->pAcumulado = false;
					return *this;
				}

				DEstatistica& DEstatistica::setAcumulado() {
					this->pAcumulado = true;
					this->pContabilidade = false;
					this->pEstatistica = false;
					return *this;
				}

				bool DEstatistica::estatistica() const { return this->pEstatistica; }
				bool DEstatistica::contabilidade() const { return this->pContabilidade; }
				bool DEstatistica::acumulado() const { return this->pAcumulado; }

				/*
				 * Transforma uma lista (a, b, c) em token: a->b->c .
				 * Essa função é engraçada porque além dela transformar
				 * uma lista em token, ela já apaga todos os elementos
				 * e destrói a lista; literalmente consome!
				 */
				static const char* DEstatistica::consomeListaEmToken(biblia::armazenamento::volatil::Lista*);
				static const char* DEstatistica::criaStringValor (double valor,int tamanhoMax);
		};
	  }
	}
  }
}

#endif