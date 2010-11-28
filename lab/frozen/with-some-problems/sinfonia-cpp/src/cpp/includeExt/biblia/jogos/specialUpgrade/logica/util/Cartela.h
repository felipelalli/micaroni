#ifndef AGES_SPECIAL_UPGRADE_CARTELA_H
#define AGES_SPECIAL_UPGRADE_CARTELA_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/armazenamento/volatil/Lista.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/jogos/specialUpgrade/logica/util/Premio.h"
#include "biblia/jogos/specialUpgrade/logica/util/EventosCartela.h"
#include "biblia/jogos/specialUpgrade/logica/util/PontoNaCartela.h"
using namespace biblia::jogos::specialUpgrade::logica::util;

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace logica{

				namespace util{

					class Cartela : public Objeto{

						private:
							int** pVetCartela;

							//Listas que guardam o estado atual das cartelas
							biblia::armazenamento::volatil::Lista pLstPontosMarcados;
							biblia::armazenamento::volatil::Lista pLstFaltaUm;
							biblia::armazenamento::volatil::Lista pLstPremios;
							biblia::armazenamento::volatil::Lista pLstPremiosSubstituidos;

							//Lista de eventos na cartela
							biblia::armazenamento::volatil::Lista pLstEventos;

							int  pQtsLinhas;
							int  pQtsColunas;
							bool pAtiva;

							bool pMarcou;

						public:
							Cartela::Cartela(int qtsLinhas=3, int qtsColunas=5);
							Cartela::Cartela(Cartela& cartela);
							Cartela::~Cartela();

							void Cartela::setNumero (int linha, int coluna, int numero);

							bool Cartela::ativa     ();
							int  Cartela::qtsLinhas ();
							int  Cartela::qtsColunas();

							bool Cartela::haEvento();
							EventoID* Cartela::consomeEvento();
							void Cartela::adicionaEvento (EventoID* evento);
							int Cartela::qtsEventos();
							EventoID& Cartela::getEvento(int qual);

							void Cartela::ativar (bool ativa);
							void Cartela::marca  (int numero);
							bool Cartela::marcou ();

							int Cartela::getNumero (int linha, int coluna);

							void Cartela::zera();

							int Cartela::qtsPontosMarcados();
							PontoNaCartela& Cartela::getPontoMarcado(int qual);
							void Cartela::zerarPontosMarcados();
							void Cartela::adicionaPontoMarcado (PontoNaCartela& ponto);

							int Cartela::qtsFaltaUm();
							Premio& Cartela::getFaltaUm(int qual);
							void Cartela::zerarFaltaUm();
							void Cartela::adicionaFaltaUm (Premio& premio);

							int Cartela::qtsPremios();
							Premio& Cartela::getPremio(int qual);
							void Cartela::zerarPremios();
							void Cartela::adicionaPremio (Premio& premio);

							int Cartela::qtsPremiosSubstituidos();
							Premio& Cartela::getPremioSubstituido(int qual);
							void Cartela::zerarPremiosSubstituidos();
							void Cartela::adicionaPremioSubstituido (Premio& premio);
					};
				}
			}
		}
	}
}

#endif