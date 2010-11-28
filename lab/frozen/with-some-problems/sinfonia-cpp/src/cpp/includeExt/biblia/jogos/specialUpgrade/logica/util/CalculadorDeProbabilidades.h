#ifndef AGES_SPECIAL_UPGRADE_CALCULADOR_DE_PROBABILIDADES_H
#define AGES_SPECIAL_UPGRADE_CALCULADOR_DE_PROBABILIDADES_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/jogos/specialUpgrade/logica/util/CarregadorDeProbabilidades.h"
using namespace biblia::jogos::specialUpgrade::logica::util;

#include "biblia/armazenamento/volatil/Lista.h"
using namespace biblia::armazenamento::volatil;

//FIXME: Nao deveria chamar nada do specialUpgrade, usa o configuracao apenas para pegar o valor do acumulado
#include "biblia/jogos/specialUpgrade/dados/DConfiguracao.h"
using namespace biblia::jogos::specialUpgrade::dados;

#include "biblia/jogos/specialUpgrade/logica/LogicaCredito.h"
using namespace biblia::jogos::specialUpgrade::logica;

#include "biblia/fluxo/Semaforo.h"
using namespace biblia::fluxo;

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace logica{

				namespace util{

					class CalculadorDeProbabilidades: public Objeto{

						private:
							CarregadorDeProbabilidades& pCarregador;
							biblia::jogos::specialUpgrade::dados::DConfiguracao& pConfiguracao;

							bool pConcorreAcumulado;
							bool pDobro;
							int  pCartelas;
							biblia::armazenamento::volatil::Lista pLstProbabilidades;

							Semaforo* pSemaAcumulado;
							double pProbAcumulado;

							void CalculadorDeProbabilidades::pLimpa();

						public:
							CalculadorDeProbabilidades::CalculadorDeProbabilidades(CarregadorDeProbabilidades& carregador, biblia::jogos::specialUpgrade::dados::DConfiguracao& configuracao);
							CalculadorDeProbabilidades::~CalculadorDeProbabilidades();

							void CalculadorDeProbabilidades::geraProbabilidades (bool concorreAcumulado, bool dobro,int cartelas);
							int CalculadorDeProbabilidades::qtsProbabilidades();
							double CalculadorDeProbabilidades::getProbabilidade (int qualPremio);
							double CalculadorDeProbabilidades::getProbAcumulado();

							double CalculadorDeProbabilidades::getProbPremioSozinho (int qualPremio, bool dobro, int qtsCartelas);

							static bool CalculadorDeProbabilidades::ehLinhaDupla(int iPremio);
					};
				}
			}
		}
	}
}
#endif
