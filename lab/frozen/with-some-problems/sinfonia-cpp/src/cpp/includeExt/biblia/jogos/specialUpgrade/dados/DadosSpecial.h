#ifndef DADOS_SPECIAL_H_UPGRADE_DOUBLE
#define DADOS_SPECIAL_H_UPGRADE_DOUBLE

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using namespace std;

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/armazenamento/volatil/primitivos/Inteiro.h"
using namespace biblia::armazenamento::volatil::primitivos;

#include "biblia/io/disco/Arquivo.h"
using namespace biblia::io::disco;

#include "biblia/jogos/specialUpgrade/logica/util/CarregadorDePremios.h"
using namespace biblia::jogos::specialUpgrade::logica::util;



namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace dados{

				class DadosSpecial : public Objeto{

					private:
						string pNomeArquivo;
						CarregadorDePremios& pCarregador;
						
						void DadosSpecial::carregar  ();
						void DadosSpecial::salvar    ();
						void DadosSpecial::pZerar    ();

						int  apostado           [2];
						int  ganho              [3];
						int* qtdPremios         [3];
						int  jogadas            [3];
						int  jogadasPremiadas   [3];
						int  cartelasJogadas    [3];
						int  cartelasPremiadas  [3];
						int  premioSurpresa     [3];
						int  pagoPremioSurpresa [3];
						int  distribuicaoBolaExtra [12];
						int  pedidosDeBolaExtra;
						int  acumulados;

					public:	

						DadosSpecial::DadosSpecial(string nomeArquivo, CarregadorDePremios& carregador);
						virtual DadosSpecial::~DadosSpecial();

						enum TipoJogada{
							NORMAL     = 0,
							BOLA_EXTRA = 1,
							BONUS      = 2
						};

						void DadosSpecial::jogou  (int valor, int qtsCartelas, TipoJogada tipoJogada);
						void DadosSpecial::ganhou (int valor, TipoJogada tipoJogada);				
						
						void DadosSpecial::premiouJogada (TipoJogada tipoJogada);
						void DadosSpecial::premiouCartela (TipoJogada tipoJogada);

						void DadosSpecial::deuPremio (int premio, TipoJogada tipoJogada);
						
						void DadosSpecial::pediuBolaExtra ();
						void DadosSpecial::parouDeComprarBolaExtra (int qual);
						
						void DadosSpecial::deuAcumulado ();	
						
						void DadosSpecial::deuPremioSurpresa (int valor, TipoJogada tipoJogada);
				};
			}
		}
	}
}

#endif