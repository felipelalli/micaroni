/*
 * $RCSfile: Ajuda.h,v $
 * $Date: 2005/01/13 17:09:48 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_AJUDA_H__EA4D1ECA_347F_4B73_8436_1C74A68A175B__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_AJUDA_H__EA4D1ECA_347F_4B73_8436_1C74A68A175B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

namespace biblia {
    namespace jogos {
        namespace specialUpgrade {
            namespace estados {
                class Ajuda : public Objeto   {
                    private:
                        int  Ajuda::pQualTela;
                        bool Ajuda::pEstaNaAjuda;
                        bool Ajuda::pBotaoEsquerdoAceso;
                        bool Ajuda::pBotaoCentralAceso;
                        bool Ajuda::pBotaoDireiroAceso;
						int Ajuda::pVelocidade;
                        bool Ajuda::pSomAjuda;

                    public:

                        virtual Ajuda& Ajuda::deveConsumirAjuda(bool sim);
                        virtual bool Ajuda::consomeAjuda();

	                    Ajuda::Ajuda();
	                    virtual Ajuda::~Ajuda();

                        Ajuda& Ajuda::proximaTela();
                        Ajuda& Ajuda::telaAnterior();
                        int Ajuda::qualTela() const;

                        Ajuda& Ajuda::botaoDireitoAceso(bool aceso);
                        Ajuda& Ajuda::botaoEsquerdoAceso(bool aceso);
                        Ajuda& Ajuda::botaoCentralAceso(bool aceso);
                        bool Ajuda::botaoDireitoAceso() const;
                        bool Ajuda::botaoEsquerdoAceso() const;
                        bool Ajuda::botaoCentralAceso() const;
                        Ajuda& Ajuda::estahNela(bool sim);
                        bool Ajuda::estahNela() const;

						virtual int Ajuda::velocidade() const;
						virtual double Ajuda::velocidadeReal() const;
						virtual Ajuda& Ajuda::aumentaVelocidade();
						virtual Ajuda& Ajuda::diminuiVelocidade();
                };
            }
        }
    }
}
#endif // !defined(SBS_AFX_AJUDA_H__EA4D1ECA_347F_4B73_8436_1C74A68A175B__INCLUDED_)
