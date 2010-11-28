/*
 * $RCSfile: BotoesAllegro.h,v $
 * $Date: 2003/05/29 21:03:14 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_BOTOESALLEGRO_H__18B9EFC5_E1DF_48BD_A4D2_59E4BE212742__INCLUDED_)
#define AFX_BOTOESALLEGRO_H__18B9EFC5_E1DF_48BD_A4D2_59E4BE212742__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/jogos/superbonus/io/botoes/Botoes.h"
using namespace biblia::jogos::superbonus::io::botoes;

namespace biblia {
	namespace jogos {
		namespace superbonus {
			namespace io {
				namespace botoes {
					class BotoesAllegro : public Botoes {
						private:
							static int BotoesAllegro::TECLA_AJUDA;
							static int BotoesAllegro::TECLA_APOSTA;
							static int BotoesAllegro::TECLA_BOLA_EXTRA;
							static int BotoesAllegro::TECLA_CARTELAS;
							static int BotoesAllegro::TECLA_COBRAR;
							static int BotoesAllegro::TECLA_JOGAR;
							static int BotoesAllegro::TECLA_NUMEROS;
							static int BotoesAllegro::TECLA_SUPER_TURBO;
							static int BotoesAllegro::TECLA_SAIR;
                            static int BotoesAllegro::TECLA_CHAVE_PAG;
							static int BotoesAllegro::TECLA_CHAVE_CONF;

							int BotoesAllegro::converteBotaoEmTecla(const Botao&) const;
							Botao BotoesAllegro::converteTeclaEmBotao(int tecla) const;

						public:
							BotoesAllegro::BotoesAllegro();
							BotoesAllegro::~BotoesAllegro();

							virtual Executavel& BotoesAllegro::executa();
							virtual bool BotoesAllegro::pressionado(const Botao&);
					};
				}
			}
		}
	}
}
#endif // !defined(AFX_BOTOESALLEGRO_H__18B9EFC5_E1DF_48BD_A4D2_59E4BE212742__INCLUDED_)
