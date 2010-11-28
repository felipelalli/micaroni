/*
 * $RCSfile: GerenciadorDeProbabilidades.h,v $
 * $Date: 2004/06/16 00:31:26 $
 * $Revision: 1.15 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef GERENCIADOR_DE_PROBABILIDADES_H
#define GERENCIADOR_DE_PROBABILIDADES_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/jogos/bingo/logica/util/CarregadorDeProbabilidades.h"
#include "biblia/jogos/bingo/logica/util/CalculadorDeProbabilidades.h"
using namespace biblia::jogos::bingo::logica::util;

#include "biblia/jogos/bingo/logica/LogicaBolaExtra.h"
using namespace biblia::jogos::bingo::logica;

//FIXME: Nao deveria chamar nada do special
#include "biblia/jogos/special/logica/SorteioBolas.h"
using namespace biblia::jogos::special::logica;

//FIXME: Nao deveria chamar nada do special, usa o configuracao apenas para pegar o valor do acumulado
#include "biblia/jogos/special/dados/DConfiguracao.h"
using namespace biblia::jogos::special::dados;


namespace biblia{
	
	namespace jogos{

		namespace bingo{
		
			namespace logica{	

				class GerenciadorDeProbabilidades: public Objeto{
					
					private:
						
						Sorteio pSorteioPremios;
						biblia::jogos::special::logica::SorteioBolas pSorteioBolas;

						GerenciadorDePremios& pGerenciador;
						CarregadorDeProbabilidades pCarregador;
						CalculadorDeProbabilidades pCalculador;
						biblia::jogos::bingo::logica::LogicaBolaExtra& pLBolaExtra;
						biblia::jogos::special::dados::DConfiguracao& pConfiguracao;

						bool GerenciadorDeProbabilidades::pMudaPremio (biblia::jogos::bingo::logica::util::Premio& premioAtual,
							                                           biblia::jogos::bingo::logica::util::Premio& novoPremio);

						int GerenciadorDeProbabilidades::pSorteioPremioBolaExtra (ListaInt& lstPremios, double valorBolaExtra);

					public:
						GerenciadorDeProbabilidades::GerenciadorDeProbabilidades(GerenciadorDePremios& gerenciador, biblia::jogos::special::dados::DConfiguracao& configuracao,biblia::jogos::bingo::logica::LogicaBolaExtra& lBolaExtra);
						GerenciadorDeProbabilidades::~GerenciadorDeProbabilidades();

						CarregadorDeProbabilidades& GerenciadorDeProbabilidades::getCarregador();
						
						int GerenciadorDeProbabilidades::sortearPremio (bool concorreAcumulado, bool dobro, int cartelas);

						void GerenciadorDeProbabilidades::gerarNumerosDisponiveis (int indCartela,Cartela& cartela, biblia::jogos::bingo::logica::util::Premio& premio,ListaInt& lstNumerosDisponiveis, biblia::armazenamento::volatil::Lista& lstPontosDisponiveis);

						PontoNaCartela* GerenciadorDeProbabilidades::sortearBolasExtras (biblia::armazenamento::volatil::Lista& lstPremios);

						static void GerenciadorDeProbabilidades::geraListaDePremiosSozinhos(int iPremio,ListaInt& lstPremios);

						bool   GerenciadorDeProbabilidades::deuAcumulado();
						double GerenciadorDeProbabilidades::valorInicialAcumuladoAtual();
						void   GerenciadorDeProbabilidades::premiouAcumulado();
				};
			}
		}
	}
}
#endif

