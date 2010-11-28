/*
 * $RCSfile: Jogada.h,v $
 * $Date: 2004/07/01 14:39:16 $
 * $Revision: 1.8 $
 * $Name:  $
 * $Author: fernandofernandes $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#ifndef JOGADA_TROPICAL_H
#define JOGADA_TROPICAL_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/armazenamento/eterno/VariavelEmArquivo.h"
using namespace biblia::armazenamento::eterno;

#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

#include "biblia/tempo/Cronometro.h"
#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Segundo.h"
using namespace biblia::tempo::unidades;


namespace biblia {
  namespace jogos {
    namespace frutinha {
      namespace estados {
		class Jogada: public Executavel,Objeto {
			private:
				bool Jogada::pPodeJogar;
				bool Jogada::pTelaDeCarregamento;
				bool Jogada::pTelaDeConfiguracao;
				bool Jogada::pAutomatico;
				bool Jogada::pDeveEsperar;
				int Jogada::pVezes;
				VariavelEmArquivo<double> Jogada::pMedia;

				Cronometro pCronometroDemonstracao;
				Intervalo pIntervaloDemonstracao;
				Intervalo pIntervaloAjuda;
				Intervalo pIntervaloJogo;
				Intervalo pIntervaloAcumulado;

				bool pDemonstracao;
				bool pDemonstracaoDeFato;
				int  pTela;
				bool pMudouTela;
				bool pFlash;

			public:
				Jogada::Jogada(UniversoDeTempo& universo);
				virtual Jogada::~Jogada();

				virtual const int& Jogada::vezes() const;
				virtual Jogada& Jogada::incaVezes();
				virtual const bool Jogada::telaDeCarregamento() const;
				virtual Jogada& Jogada::telaDeCarregamento(bool);
				virtual const bool Jogada::telaDeConfiguracao() const;
				virtual Jogada& Jogada::telaDeConfiguracao(bool);

				/**
				 * Para esperar no mínimo x segundos depois
				 * que aparece o "pago".
				 */
				virtual const bool& Jogada::deveEsperar() const;
				virtual Jogada& Jogada::deveEsperar(const bool&);
				virtual const double& Jogada::media() const;
				virtual Jogada& Jogada::novaMedia(const double&);

				/**
				 * Consome, colocando true de volta.
				 */
				virtual const bool Jogada::podeJogar();
				virtual Jogada& Jogada::podeJogar(const bool& sim);

				virtual const bool Jogada::automatico();
				virtual Jogada& Jogada::automatico (const bool& sim);

				virtual const bool Jogada::demonstracao();
				virtual const bool Jogada::mudouTela();
				virtual const int  Jogada::qualTela();
				virtual void       Jogada::setDemonstracao (bool estaNaDemonstracao);
				virtual void       Jogada::pressionouAlgoNaDemonstracao();

				virtual bool       Jogada::consomeFlash();
				virtual void       Jogada::lancaFlash();

				Executavel& Jogada::executa();

				enum Telas{
					TELA_NENHUMA   = -1,
					TELA_JOGO      =  1,
					TELA_AJUDA1    =  2,
					TELA_AJUDA2    =  3,
					TELA_ACUMULADO =  4
				};
		};
	  }
	}
  }
}

#endif