/*
 * $RCSfile: UltimasJogadas.h,v $
 * $Date: 2005/01/19 17:21:57 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_ULTIMAS_JOGADAS_H
#define AGES_SPECIAL_UPGRADE_SBS_ULTIMAS_JOGADAS_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/util/StrToken.h"
using namespace biblia::util;

#include "biblia/armazenamento/volatil/ListaInt.h"
#include "biblia/armazenamento/volatil/ListaString.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/armazenamento/volatil/carcacas/Lista.h"
using namespace biblia::armazenamento::volatil::carcacas;

#include "biblia/io/disco/Arquivo.h"
using namespace biblia::io::disco;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

#include "biblia/jogos/specialUpgrade/dados/util/DadosJogada.h"
using namespace biblia::jogos::specialUpgrade::dados::util;

#include "biblia/visual/util/VariavelEmArquivoResultadoGrafico.h"
using namespace biblia::armazenamento::eterno;

#include "biblia/visual/util/ResultadoGraficoFixo.h"
using namespace biblia::visual::util;

#define MAX_JOGADAS 10

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace dados{
				class JogadaSalva: public Objeto {
					private:
						biblia::armazenamento::volatil::carcacas::Lista<int> pBolas;
						biblia::armazenamento::volatil::carcacas::Lista<
								biblia::armazenamento::volatil::carcacas::Lista<
									biblia::armazenamento::volatil::carcacas::Lista<
										int> > > pCartelas;
						int pAposta;
						int pCreditosAtual;
						int pCreditosGanhos;
						bool pDobro;

					public:
						JogadaSalva(const string& dados);
						virtual ~JogadaSalva();
						virtual const int& creditosAtual() const;
						virtual const int& creditosGanhos() const;
						virtual const int& aposta() const;
						virtual const bool& estavaNoDobro() const;
						virtual const int quantasBolas() const;
						virtual const int bola(const int& qual) const;
						virtual const int quantasCartelas() const;
						virtual const int numeroDaCartela(
								const int& cartela, const int& linha,
								const int& coluna) const;

						// Objeto:
						virtual std::string emString() const;
				};

				class UltimasJogadas : public Objeto{

					private:

						void UltimasJogadas::salvar();
						void UltimasJogadas::carregar();

						void UltimasJogadas::concatenaListaEmString (ListaInt* lista, char* str);

						ListaString* pLstJogadas;
						Arquivo arquivo;

						// Resultado Gráfico:
						biblia::armazenamento::volatil::carcacas
								::Lista<VariavelEmArquivo<
									biblia::armazenamento::volatil::carcacas
										::Lista<ComponenteFixo> >* > pResultados;

						VariavelEmArquivo<int> pPosicaoFinalDosResultados;

					public:
						UltimasJogadas::UltimasJogadas ();
						UltimasJogadas::~UltimasJogadas();

						int UltimasJogadas::qtsJogadas();
						virtual UltimasJogadas& UltimasJogadas::zera();

						/**
						 * @param qual de 1 a 10, sendo 1 a última.
						 */
						virtual const biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo>&
								componentesFixos(const int& qual) const;

						/**
						 * @deprecated Use resgataJogada(const int& qual)
						 */
						void UltimasJogadas::getJogada
								(int qualJogada,char* jogada) const;

						virtual const JogadaSalva resgataJogada(
								const int& qual) const;

						void UltimasJogadas::addJogada(
							ListaInt* bolas,
							ListaInt* cartela1,
							ListaInt* cartela2,
							ListaInt* cartela3,
							ListaInt* cartela4,
							int creditoAtual,
							int aposta,
							int creditosGanhos,
							bool dobro);

						/**
						 * Tira uma "foto" da última jogada. Salva
						 * os elementos da tela.
						 */
						UltimasJogadas& tiraFoto(ResultadoGrafico& rg);
				};
			}
		}
	}
}

#endif