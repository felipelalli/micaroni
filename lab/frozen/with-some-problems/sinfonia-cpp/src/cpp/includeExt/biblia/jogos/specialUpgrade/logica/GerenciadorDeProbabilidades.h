/*
 * $RCSfile: GerenciadorDeProbabilidades.h,v $
 * $Date: 2005/01/19 17:22:12 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#ifndef AGES_SPECIAL_UPGRADE_GERENCIADOR_DE_PROBABILIDADES_H
#define AGES_SPECIAL_UPGRADE_GERENCIADOR_DE_PROBABILIDADES_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/jogos/specialUpgrade/logica/util/CarregadorDeProbabilidades.h"
#include "biblia/jogos/specialUpgrade/logica/util/CalculadorDeProbabilidades.h"
using namespace biblia::jogos::specialUpgrade::logica::util;

#include "biblia/jogos/specialUpgrade/logica/LogicaBolaExtra.h"
#include "biblia/jogos/specialUpgrade/logica/LogicaCartelas.h"
using namespace biblia::jogos::specialUpgrade::logica;

//FIXME: Nao deveria chamar nada do specialUpgrade
#include "biblia/jogos/specialUpgrade/logica/SorteioBolas.h"
using namespace biblia::jogos::specialUpgrade::logica;

//FIXME: Nao deveria chamar nada do specialUpgrade, usa o configuracao apenas para pegar o valor do acumulado
#include "biblia/jogos/specialUpgrade/dados/DConfiguracao.h"
using namespace biblia::jogos::specialUpgrade::dados;


namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace logica{

				class GerenciadorDeProbabilidades: public Objeto{

					private:

						Sorteio pSorteioPremios;
						biblia::jogos::specialUpgrade::logica::SorteioBolas pSorteioBolas;

						GerenciadorDePremios& pGerenciador;
						CarregadorDeProbabilidades pCarregador;
						CalculadorDeProbabilidades pCalculador;
						biblia::jogos::specialUpgrade::logica::LogicaBolaExtra& pLBolaExtra;
						biblia::jogos::specialUpgrade::dados::DConfiguracao& pConfiguracao;

						bool GerenciadorDeProbabilidades::pMudaPremio (biblia::jogos::specialUpgrade::logica::util::Premio& premioAtual,
							                                           biblia::jogos::specialUpgrade::logica::util::Premio& novoPremio);

						int GerenciadorDeProbabilidades::pSorteioPremioBolaExtra (ListaInt& lstPremios, double valorBolaExtra, int qtsCartelas);

					public:
						GerenciadorDeProbabilidades::GerenciadorDeProbabilidades(GerenciadorDePremios& gerenciador, biblia::jogos::specialUpgrade::dados::DConfiguracao& configuracao,biblia::jogos::specialUpgrade::logica::LogicaBolaExtra& lBolaExtra);
						GerenciadorDeProbabilidades::~GerenciadorDeProbabilidades();

						CarregadorDeProbabilidades& GerenciadorDeProbabilidades::getCarregador();

						int GerenciadorDeProbabilidades::sortearPremio (bool concorreAcumulado, bool dobro, int cartelas);

						void GerenciadorDeProbabilidades::gerarNumerosDisponiveis (int indCartela,Cartela& cartela, biblia::jogos::specialUpgrade::logica::util::Premio& premio,ListaInt& lstNumerosDisponiveis, biblia::armazenamento::volatil::Lista& lstPontosDisponiveis);

						PontoNaCartela* GerenciadorDeProbabilidades::sortearBolasExtras (biblia::armazenamento::volatil::Lista& lstPremios, LogicaCartelas& cartelas);

						int GerenciadorDeProbabilidades::valorPremio (int premio,bool considerarValorTotalDaLinhaDupla=false, int qtsCartelas=0);

						static void GerenciadorDeProbabilidades::geraListaDePremiosSozinhos(int iPremio,ListaInt& lstPremios);

						bool   GerenciadorDeProbabilidades::deuAcumulado();
						double GerenciadorDeProbabilidades::valorInicialAcumuladoAtual();
						void   GerenciadorDeProbabilidades::premiouAcumulado();

						int GerenciadorDeProbabilidades::idPremioGerenciadorDePremios (int idPremio);
				};
			}
		}
	}
}
#endif

