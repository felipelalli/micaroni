/*
 * $RCSfile: Dados.h,v $
 * $Date: 2005/01/20 21:28:48 $
 * $Revision: 1.8 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef DADOS_TROPCIAL_H
#define DADOS_TROPCIAL_H

#include <string>
using namespace std;

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/util/CData.h"
#include "biblia/util/NumeroUtilOld.h"
using namespace biblia::util;

#include "biblia/armazenamento/volatil/carcacas/Lista.h"
using namespace biblia::armazenamento::volatil::carcacas;

#include "biblia/armazenamento/eterno/Contador.h"
#include "biblia/armazenamento/eterno/VariavelEmArquivo.h"
using namespace biblia::armazenamento::eterno;

namespace biblia{

	namespace jogos{

		namespace frutinha{

			namespace estados{

				class Dados: public Objeto{
					private:
						Contador* pContador;

						/*INFORMAÇÕES GERAIS SOBRE O JOGO*/
						/*TOTAIS*/
						VariavelEmArquivo<int> pQtsJogadasTotal;
						VariavelEmArquivo<int> pQtsJogadasGanhasTotal;
						VariavelEmArquivo<int> pQtsLinhasJogadasTotal;
						VariavelEmArquivo<int> pQtsLinhasGanhasTotal;
						VariavelEmArquivo<int> pApostadoTotal;
						VariavelEmArquivo<int> pGanhoTotal;
						VariavelEmArquivo<int> pEntradaTotal;
						VariavelEmArquivo<int> pSaidaTotal;
						VariavelEmArquivo<string> pDataTotal;

						/*PARCIAIS*/
						VariavelEmArquivo<int> pQtsJogadasParcial;
						VariavelEmArquivo<int> pQtsJogadasGanhasParcial;
						VariavelEmArquivo<int> pQtsLinhasJogadasParcial;
						VariavelEmArquivo<int> pQtsLinhasGanhasParcial;
						VariavelEmArquivo<int> pApostadoParcial;
						VariavelEmArquivo<int> pGanhoParcial;
						VariavelEmArquivo<int> pEntradaParcial;
						VariavelEmArquivo<int> pSaidaParcial;
						VariavelEmArquivo<string> pDataParcial;

						/* Volume */
						Lista<VariavelEmArquivo<double>*> pVolume;

						bool pDemonstracao;

						/* Créditos x Jogada
						   usado somente no simulador
						*/
						//Lista<int> pCreditosPorJogada;

					public:
						Dados::Dados(Contador*);
						virtual Dados::~Dados();

						Dados& Dados::adicionaJogada        ();
						Dados& Dados::adicionaJogadaGanha   ();
						Dados& Dados::adicionaLinhasJogadas (int qtsLinhasJogadas);
						Dados& Dados::adicionaLinhasGanhas  (int qtsLinhasGanhas);
						Dados& Dados::adicionaApostado      (int quantoApostado);
						Dados& Dados::adicionaGanho         (int quantoGanho);
						Dados& Dados::adicionaEntrada       (int quantoEntrada);
						Dados& Dados::adicionaSaida         (int quantoSaida);
						Dados& Dados::adicionaPremio        (int qualPremio);
						Dados& Dados::adicionaAcumulado     ();
						Dados& Dados::mudaVolume            (const int& qual,const double& novoVolume);

						int Dados::qtsJogadas      (bool total=true);
						int Dados::qtsJogadasGanhas(bool total=true);
						int Dados::qtsLinhasJogadas(bool total=true);
						int Dados::qtsLinhasGanhas (bool total=true);
						int Dados::apostado        (bool total=true);
						int Dados::ganho           (bool total=true);
						int Dados::entrada         (bool total=true);
						int Dados::saida           (bool total=true);
						int Dados::qtsPremios      (int qualPremio, bool total=true);
						int Dados::qtsAcumulados   (bool total=true);
						std::string Dados::data         (bool total=true);
						const double Dados::volume (const int& qual) const;

						Dados& Dados::zeraTotal  ();
						Dados& Dados::zeraParcial();

						Contador& Dados::contador      ();
						const Contador& Dados::contador() const;

						Dados& Dados::setDemonstracao  (bool demonstracao);
				};
			}
		}
	}
}

#endif