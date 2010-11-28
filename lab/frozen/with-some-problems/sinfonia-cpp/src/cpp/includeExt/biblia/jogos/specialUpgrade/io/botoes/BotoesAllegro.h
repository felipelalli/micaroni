/*
 * $RCSfile: BotoesAllegro.h,v $
 * $Date: 2005/01/19 17:22:03 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_BOTOESALLEGRO_H__18B9EFC5_E1DF_48BD_A4D2_59E4BE212742__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_BOTOESALLEGRO_H__18B9EFC5_E1DF_48BD_A4D2_59E4BE212742__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/jogos/specialUpgrade/io/botoes/Botoes.h"
using namespace biblia::jogos::specialUpgrade::io::botoes;

namespace biblia {
	namespace jogos {
		namespace specialUpgrade {
			namespace io {
				namespace botoes {
					class BotoesAllegro : public Botoes {
						private:
							static int BotoesAllegro::TECLA_APOSTA;
							static int BotoesAllegro::TECLA_BOLA_EXTRA;
							static int BotoesAllegro::TECLA_CARTELAS;
							static int BotoesAllegro::TECLA_NUMEROS;
							static int BotoesAllegro::TECLA_SUPER_TURBO;
							static int BotoesAllegro::TECLA_CHAVE_PAG;
							static int BotoesAllegro::TECLA_CHAVE_CONF;
							static int BotoesAllegro::TECLA_AJUDA;
							static int BotoesAllegro::TECLA_COBRAR;
							static int BotoesAllegro::TECLA_JOGAR;
							static int BotoesAllegro::TECLA_SAIR;

							int BotoesAllegro::converteBotaoEmTecla(const Botao&) const;
							Botao BotoesAllegro::converteTeclaEmBotao(int tecla) const;

						public:
							BotoesAllegro::BotoesAllegro();
							BotoesAllegro::~BotoesAllegro();

							virtual Executavel& BotoesAllegro::executa();
							virtual bool BotoesAllegro::pressionado(const Botao&);

							virtual bool BotoesAllegro::pressionado(int tecla);
					};
				}
			}
		}
	}
}
#endif // !defined(AFX_BOTOESALLEGRO_H__18B9EFC5_E1DF_48BD_A4D2_59E4BE212742__INCLUDED_)
