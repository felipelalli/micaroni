#ifndef CARREGADOR_DE_PROBABILIDADES_H
#define CARREGADOR_DE_PROBABILIDADES_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/io/disco/Arquivo.h"
using namespace biblia::io::disco;

#include "biblia/armazenamento/volatil/Lista.h"
#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/jogos/bingo/logica/util/Premio.h"
using namespace biblia::jogos::bingo::logica::util;

#include "biblia/jogos/bingo/logica/GerenciadorDePremios.h"
using namespace biblia::jogos::bingo::logica;

#include "biblia/util/StrToken.h"
using namespace biblia::util;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

namespace biblia{

	namespace jogos{

		namespace bingo{
		
			namespace logica{

				namespace util{

					class CarregadorDeProbabilidades : public Objeto{

						private:
							GerenciadorDePremios& pGerenciador;
							Arquivo*  pArquivo;
							biblia::armazenamento::volatil::Lista    pLstPremios;
							biblia::armazenamento::volatil::Lista    pLstProbabilidades;
							biblia::armazenamento::volatil::Lista    pLstProbabilidadesDobro;
							double   pProbAcumulado;

							static unsigned long pKey[4];
							ChaveSeguranca pChaveSeguranca;

							double pPercentualPagamento;
							double pPercentualPagamentoDobro;							
				
							void CarregadorDeProbabilidades::pLimpar();
							void CarregadorDeProbabilidades::pCarregar();

						public:
							CarregadorDeProbabilidades::CarregadorDeProbabilidades (GerenciadorDePremios& gerenciador);
							CarregadorDeProbabilidades::~CarregadorDeProbabilidades();

							int     CarregadorDeProbabilidades::qtsPremios();
							Premio& CarregadorDeProbabilidades::getPremio (int indice);
							double  CarregadorDeProbabilidades::getProbabilidade (int indice,bool dobro,int cartelas);
							double  CarregadorDeProbabilidades::getProbAcumulado ();

							double CarregadorDeProbabilidades::getPercentualPagamento (bool dobro);
					};
				}
			}
		}
	}
}

#endif

