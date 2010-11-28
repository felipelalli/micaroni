#ifndef AGES_SPECIAL_UPGRADE_PREMIO_LOGICA_BASE_H
#define AGES_SPECIAL_UPGRADE_PREMIO_LOGICA_BASE_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/armazenamento/volatil/Lista.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/jogos/specialUpgrade/logica/util/PontoNaCartela.h"
using namespace biblia::jogos::specialUpgrade::logica::util;

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace logica{

				namespace util{

					class Premio : public Objeto{

						private:
							string pNome;
							int    pId;
							int    pValor;
							bool   pPodeBolaExtra;
							bool   pGeradoNaBolaExtra;
							biblia::armazenamento::volatil::Lista* pLstPossibilidadesDePremios;
							PontoNaCartela pFaltaUm;

						public:
							Premio::Premio ();
							Premio::Premio (const Premio& premio);
							Premio::Premio (const Premio& premio,int possibilidade);
							Premio::~Premio();

							int                   Premio::valor            () const;
							string                Premio::nome             () const;
							int                   Premio::id               () const;
							bool                  Premio::podeBolaExtra    () const;
							int                   Premio::qtsPossibilidades() const;
							int                   Premio::qtsPontos        (int possibilidade) const;
							const PontoNaCartela& Premio::getPonto         (int possibilidade, int indice) const;
							const PontoNaCartela& Premio::getFaltaUm       () const;
							bool                  Premio::geradoNaBolaExtra() const;

							void Premio::zerar                 ();
							void Premio::setNome               (string nome);
							void Premio::setId                 (int id);
							void Premio::setValor              (int valor);
							void Premio::setPodeBolaExtra      (bool podeBolaExtra);
							void Premio::adicionaPossibilidade ();
							void Premio::adicionaPonto         (const PontoNaCartela& ponto);
							void Premio::setFaltaUm            (const PontoNaCartela& ponto);
							void Premio::setGeradoNaBolaExtra  (bool geradoNaBolaExtra);

							virtual bool Premio::operator==(const Premio& premio) const;
							virtual bool Premio::operator!=(const Premio& premio) const;
					};
				}
			}
		}
	}
}

#endif