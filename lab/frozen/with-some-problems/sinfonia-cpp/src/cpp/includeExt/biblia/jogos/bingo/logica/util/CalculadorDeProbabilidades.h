#ifndef CALCULADOR_DE_PROBABILIDADES_H
#define CALCULADOR_DE_PROBABILIDADES_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/jogos/bingo/logica/util/CarregadorDeProbabilidades.h"
using namespace biblia::jogos::bingo::logica::util;

#include "biblia/armazenamento/volatil/Lista.h"
using namespace biblia::armazenamento::volatil;

//FIXME: Nao deveria chamar nada do special, usa o configuracao apenas para pegar o valor do acumulado
#include "biblia/jogos/special/dados/DConfiguracao.h"
using namespace biblia::jogos::special::dados;

#include "biblia/jogos/special/logica/LogicaCredito.h"
using namespace biblia::jogos::special::logica;

#include "biblia/fluxo/Semaforo.h"
using namespace biblia::fluxo;

namespace biblia{
	
	namespace jogos{

		namespace bingo{
		
			namespace logica{
				
				namespace util{

					class CalculadorDeProbabilidades: public Objeto{
						
						private:
							CarregadorDeProbabilidades& pCarregador;
							biblia::jogos::special::dados::DConfiguracao& pConfiguracao;

							bool pConcorreAcumulado;
							bool pDobro;
							int  pCartelas;
							biblia::armazenamento::volatil::Lista pLstProbabilidades;

							Semaforo* pSemaAcumulado;
							double pProbAcumulado;

							void CalculadorDeProbabilidades::pLimpa();							

						public:
							CalculadorDeProbabilidades::CalculadorDeProbabilidades(CarregadorDeProbabilidades& carregador, biblia::jogos::special::dados::DConfiguracao& configuracao);
							CalculadorDeProbabilidades::~CalculadorDeProbabilidades();

							void CalculadorDeProbabilidades::geraProbabilidades (bool concorreAcumulado, bool dobro,int cartelas);
							int CalculadorDeProbabilidades::qtsProbabilidades();							
							double CalculadorDeProbabilidades::getProbabilidade (int qualPremio);
							double CalculadorDeProbabilidades::getProbAcumulado();

							double CalculadorDeProbabilidades::getProbPremioSozinho (int qualPremio, bool dobro=false);

							static bool CalculadorDeProbabilidades::ehLinhaDupla(int iPremio);
					};
				}
			}
		}
	}
}
#endif
