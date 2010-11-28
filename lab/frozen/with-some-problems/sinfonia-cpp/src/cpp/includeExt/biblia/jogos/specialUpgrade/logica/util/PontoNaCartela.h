#ifndef AGES_SPECIAL_UPGRADE_PONTO_NA_CARTELA_H
#define AGES_SPECIAL_UPGRADE_PONTO_NA_CARTELA_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace logica{

				namespace util{

					class PontoNaCartela : public Objeto{

						private:
							int pLinha;
							int pColuna;
							int pCartela;

						public:
							PontoNaCartela::PontoNaCartela (int linha, int coluna);
							PontoNaCartela::PontoNaCartela (int cartela, int linha, int coluna);
							PontoNaCartela::PontoNaCartela (const PontoNaCartela& ponto);
							PontoNaCartela::~PontoNaCartela();

							virtual const int& PontoNaCartela::getLinha () const;
							virtual const int& PontoNaCartela::getColuna() const;
							virtual const int& PontoNaCartela::getCartela() const;

							virtual void PontoNaCartela::setLinha   (int linha);
							virtual void PontoNaCartela::setColuna  (int coluna);
							virtual void PontoNaCartela::setCartela (int cartela);

							virtual bool PontoNaCartela::operator==(const PontoNaCartela& ponto) const;
							virtual bool PontoNaCartela::operator!=(const PontoNaCartela& ponto) const;
							virtual PontoNaCartela& PontoNaCartela::operator=(const PontoNaCartela& p);
					};
				}
			}
		}
	}
}

#endif