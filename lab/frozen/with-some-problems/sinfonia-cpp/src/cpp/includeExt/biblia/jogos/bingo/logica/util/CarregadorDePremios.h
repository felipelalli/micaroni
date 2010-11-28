#ifndef CARREGADOR_DE_PREMIOS_H
#define CARREGADOR_DE_PREMIOS_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/io/disco/Arquivo.h"
using namespace biblia::io::disco;

#include "biblia/armazenamento/volatil/Lista.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/jogos/bingo/logica/util/Premio.h"
using namespace biblia::jogos::bingo::logica::util;

#include "biblia/util/StrToken.h"
using namespace biblia::util;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

namespace biblia{

	namespace jogos{

		namespace bingo{
		
			namespace logica{

				namespace util{

					class CarregadorDePremios : public Objeto{

						private:
							Arquivo* pArquivo;
							biblia::armazenamento::volatil::Lista* pLstPremios;

							int  pQtsCartelas;
							int  pQtsLinhas;
							int  pQtsColunas;
							int  pQtsNumeros;
							bool pPagaMaisAlto;
							int  pApostaMaxima;
							static unsigned long pKey[4];
							ChaveSeguranca pChaveSeguranca;
				
							void CarregadorDePremios::pLimpar();
							void CarregadorDePremios::pCarregar();

						public:
							CarregadorDePremios::CarregadorDePremios ();
							CarregadorDePremios::~CarregadorDePremios();

							int     CarregadorDePremios::qtsPremios();
							Premio& CarregadorDePremios::getPremio (int indice);

							int CarregadorDePremios::qtsCartelas();
							int CarregadorDePremios::qtsLinhas();
							int CarregadorDePremios::qtsColunas();
							int CarregadorDePremios::qtsNumeros();
							int CarregadorDePremios::apostaMaxima();
							bool CarregadorDePremios::pagaMaisAlto();
					};
				}
			}
		}
	}
}

#endif