/*
 * $RCSfile: Rodilho.h,v $
 * $Date: 2005/01/20 21:28:49 $
 * $Revision: 1.16 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef RODILHO_TROPCIAL_H
#define RODILHO_TROPCIAL_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/armazenamento/volatil/GerenciadorDeEventos.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/jogos/frutinha/estados/eventos/EventosRodilho.h"
using namespace biblia::jogos::frutinha::estados::eventos;

#include "biblia/sorte/Sorteio.h"
using namespace biblia::sorte;

#include "biblia/armazenamento/eterno/VariavelEmArquivo.h"
using namespace biblia::armazenamento::eterno;

#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

#include "biblia/tempo/Cronometro.h"
#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Milissegundo.h"
using namespace biblia::tempo::unidades;

#include "biblia/armazenamento/volatil/carcacas/MapaHash.h"
using namespace biblia::armazenamento::volatil::carcacas;

#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;



#define INTERVALO_PARA_APAGAR_LINHA_PREMIO 100

namespace biblia{

	namespace jogos{

		namespace frutinha{

			namespace estados{

				class Rodilho: public Executavel{

					private:

						Intervalo pIntervaloParaApagarLinhaPremio;
						Cronometro* pVetCronometroPremio[5];
						bool pVetLinhaPremioAcesa[5];

						/* Se a linha for -1 está invisível */
						int pLinhaAposta;

						int  pVetApostaPremio[5];
						bool pVetPremioMarcado[5];

						int  pVetEstadoRodilho[3][5];
						int  pVetFiguraRodilho[3][5];
						bool pVetRodilhoAceso [5][5];

						GerenciadorDeEventos pGerenciadorEventos;
						/*
						bool pVisivel;
						int pUltimoPremio;
						*/
						VariavelEmArquivo<bool> pVisivel;
						VariavelEmArquivo<int> pQuantasCelulas;

						ListaInt pLstFrutas;

						Rodilho& Rodilho::pSomeMarcacaoDePremios();

					public:
						Rodilho::Rodilho(UniversoDeTempo& universoDeTempo);
						virtual Rodilho::~Rodilho();

						virtual const int& Rodilho::quantasCelulas() const;
						virtual Rodilho& Rodilho::quantasCelulas(
								const int& quantas);

						/** Indica se o rodilho deve ou não aparece na tela */
						Rodilho& Rodilho::visivel(bool visivel);
						bool Rodilho::visivel();


//---------------------->
						/** FUNCOES DE CONTROLE DO RODILHO */

						/** Inicia giro do rodilho especificado */
						Rodilho& Rodilho::rodaRodilho (int linha, int coluna);

						/** Para giro do rodilho especificado na figura escolhida */
						Rodilho& Rodilho::paraRodilho (int linha, int coluna);

						/** Coloca figura no rodilho especificado */
						Rodilho& Rodilho::defineFigura (int linha, int coluna, int figura);

						/** Acende e apaga o rodilho */
						Rodilho& Rodilho::acendeRodilho (int linha, int coluna, bool aceso);

						/** Retorna os estados do rodilho */
						int Rodilho::estadoRodilho (int linha, int coluna);
						int Rodilho::figuraRodilho (int linha, int coluna);
						bool Rodilho::rodilhoAceso (int linha, int coluna);
//---------------------->


//---------------------->
						/** FUNCOES DE CONTROLE DO INDICADOR DE PREMIAÇÃO */

						/** Coloca marcacao na linha especificada */
						Rodilho& Rodilho::marcaPremio (int linha);

						/** Some com a marcadao da linha especificada */
						Rodilho& Rodilho::tiraMarcacao (int linha);

						Rodilho& Rodilho::mudaLinhaAposta(int linha);
						Rodilho& Rodilho::tiraLinhaAposta();

						/** Muda valor da aposta para a linha */
						Rodilho& Rodilho::mudaAposta (int linha, int aposta);

						/** Retorna o estado do premio */
						bool Rodilho::premioMarcado (int linha);
						int Rodilho::apostaPremio (int linha);
						bool Rodilho::linhaPremioAcesa(int linha);
						int Rodilho::linhaAposta ();
//---------------------->


						Executavel& Rodilho::executa();


						GerenciadorDeEventos& Rodilho::gerenciadorEventos();

						enum EstadoRodilho{
							PARADO  = 0,
							RODANDO = 1
						};

						static std::string Rodilho::nomeFigura(int figura);

						int Rodilho::getLinhaRodilho (int iLinha, int iColuna);

						/**
						 * De 0 a 6
						 */
						virtual int Rodilho::consomeUltimaFruta();
						virtual Rodilho& Rodilho::deuFruta(const int& premio);

						Rodilho& Rodilho::someMarcacaoDePremios();
				};
			}
		}
	}
}

#endif