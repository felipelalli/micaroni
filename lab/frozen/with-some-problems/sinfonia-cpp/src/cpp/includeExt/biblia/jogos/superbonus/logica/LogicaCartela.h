/*
 * $RCSfile: LogicaCartela.h,v $
 * $Date: 2004/07/13 21:13:35 $
 * $Revision: 1.14 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#include <stdlib.h>
#include <stdio.h>
#include "biblia/basico/Objeto.h"
#include "biblia/util/Debug.h"
#include "biblia/jogos/superbonus/logica/SorteioBolas.h"
#include "biblia/jogos/superbonus/logica/Premio.h"
#include "biblia/jogos/superbonus/logica/LogicaPremio.h"
#include "biblia/jogos/superbonus/logica/PremioNaCartela.h"
#include "biblia/util/StrToken.h"
#include "biblia/io/disco/Arquivo.h"

#ifdef WIN32
#include <io.h>
#else
#include <unistd.h>
#include <errno.h>
#endif

#ifndef LOGICACARTELA_SW_H
#define LOGICACARTELA_SW_H

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

#include "biblia/jogos/superbonus/logica/PosicaoNasCartelas.h"

using namespace biblia::basico;
using namespace biblia::util;
using namespace biblia::io::disco;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace logica {

		class LogicaCartela : public Objeto
		{

			private:
				Arquivo LogicaCartela::arquivo;
				unsigned int pCartelasAtivas;
				unsigned int*** pCartelas;
				bool***		 pCartelasMarc;

				unsigned int* pPremiosDados;

				unsigned int pQtsCartelas;
				unsigned int pQtsColunas;
				unsigned int pQtsLinhas;
				unsigned int pQtsNumSorteados;
				Premio** pPremios;
				SorteioBolas* pSorteio;
				bool* pJogandoSozinho;
				LogicaPremio * logicaPremio;

				int pBolaAtual;
				bool pSimulacao, pDeveLimpar;

				//fixme: converter para alocacao
				//dinamica
				int pQuantosFaltaUm[4];

				//esta listas foram criadas para melhorar o desempenho
				//do redenrizador gráfico
				biblia::armazenamento::volatil::Lista pBufferPremios, pBufferLinhas, pBufferFaltaUm, pBufferNumerosMarcados, pBufferCantos;

				void adicionaPremioNoBuffer(const PremioNaCartela&);
				void adicionaCantosNoBuffer(const PosicaoNasCartelas&);
				void adicionaLinhaNoBuffer(const PosicaoNasCartelas&);
				void adicionaFaltaUmNoBuffer(const PosicaoNasCartelas&);
				void adicionaNumeroMarcadoNoBuffer(const PosicaoNasCartelas&);

				void limpaBufferes();

				void ordenar (unsigned int* numeros, unsigned int inicio, unsigned int fim);
				void pVerificarPremiosInvalidos();

				//Verifica se saiu algum premio para essa linha (ou 4 cantos)
				const unsigned int verificarLinha (const unsigned int& iCartela,
												   const unsigned int& iLinha,
												   const unsigned int& iColuna);



			protected:
				const bool& jogandoSozinho() const
						{ return *(this->pJogandoSozinho); }

			protected:
				void LogicaCartela::leCartelas();

			public:
				//construtor
				LogicaCartela::LogicaCartela(bool* jogandoSozinho,bool Simulacao,
											 LogicaPremio* logicaPremio=NULL,
											 const unsigned int& qtsCartelas =4,
											 const unsigned int& qtsNumX = 5,
											 const unsigned int& qtsNumY = 3,
											 const unsigned int& qtsNumSorteados=90);

				//destrutor
				LogicaCartela::~LogicaCartela();



				bool LogicaCartela::simulacao(){
					return this->pSimulacao;
				}

				//Sorteia os numeros para as cartelas de 1 a qtsNumSorteados
				void LogicaCartela::sortearCartelas(bool repertirNumCart = false);

				void LogicaCartela::trocaNumeros(const biblia::armazenamento::volatil::Lista&);

				//Zera os resultados da cartela
				void LogicaCartela::zerarCartelas();

				//Altera os resultados do jogo conforme a bola jogada
				void LogicaCartela::colocarBola(const unsigned int& bola,bool concorreAcumulado);

				//Retorna o Premio para a cartela
				Premio* LogicaCartela::premio(const unsigned int& iCartela);

				//Retorna Matriz de numeros sortiados no formato [CARTELAS][LINHAS][COLUNAS]
				unsigned int LogicaCartela::getNumero(
						unsigned int cartela, unsigned int linha,
						unsigned int coluna);

				bool LogicaCartela::numeroMarcado(unsigned int cartela, unsigned int linha,
						unsigned int coluna)
				{
					return this->pCartelasMarc[cartela][linha][coluna];
				}

				//Retorna o numero de cartelas
				unsigned int LogicaCartela::qtsCartelas();

				//Retorna o numero de linhas
				unsigned int LogicaCartela::qtsLinhas();

				//Retorna o numero de colunas
				unsigned int LogicaCartela::qtsColunas();

				//Muda o numero de cartelas ativas
				void LogicaCartela::proxCartelaAtiva();

				//Retorna o numero de cartelas ativas
				unsigned int LogicaCartela::qtsCartelasAtivas();

				bool LogicaCartela::podeBolaExtra();
				int LogicaCartela::qualPremioBolaExtra(int qualCartela);
				int LogicaCartela::quantosFaltaUm(int qualCartela);
				int LogicaCartela::cartelaIdeal();
				void LogicaCartela::gravaCartelas();

				bool fezLinha(unsigned int cartela, unsigned int linha);

				void LogicaCartela::restauraCartelas(){
					this->leCartelas();
				}

				LogicaCartela& LogicaCartela::atualizaBufferDePremios();
				bool LogicaCartela::haPremiosNoBuffer() const;
				const PremioNaCartela LogicaCartela::consomePremioDoBuffer();

				bool LogicaCartela::haLinha() const;
				PosicaoNasCartelas LogicaCartela::consomeLinha();

				bool LogicaCartela::haFaltaUm() const;
				PosicaoNasCartelas LogicaCartela::consomeFaltaUm();

				bool LogicaCartela::haNumeroMarcado() const;
				PosicaoNasCartelas LogicaCartela::consomeNumeroMarcado();

				bool LogicaCartela::haCantos() const;
				PosicaoNasCartelas LogicaCartela::consomeCantos();

				void LogicaCartela::deveLimpar(bool);
				bool LogicaCartela::deveLimpar() const;
				void LogicaCartela::limpou();

				int LogicaCartela::quantidadeDeFaltaUm(int);
		};
	  }
	}
  }
}

#endif
