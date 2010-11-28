/*
 * $RCSfile: BotoesAllegro.h,v $
 * $Date: 2005/01/20 17:44:47 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(SBS_AFX_BOTOESALLEGRO_H__18B9EFC5_E1DF_48BD_A4D2_59E4BE212742__INCLUDED_FRUTINHA)
#define SBS_AFX_BOTOESALLEGRO_H__18B9EFC5_E1DF_48BD_A4D2_59E4BE212742__INCLUDED_FRUTINHA

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/jogos/frutinha/io/botoes/Botoes.h"
using namespace biblia::jogos::frutinha::io::botoes;

namespace biblia {
	namespace jogos {
		namespace frutinha {
			namespace io {
				namespace botoes {
					class BotoesAllegro : public Botoes {
						private:
							static int BotoesAllegro::TECLA_AJUDA;							
							static int BotoesAllegro::TECLA_MUDA_APOSTA1;							
							static int BotoesAllegro::TECLA_MUDA_APOSTA2;							
							static int BotoesAllegro::TECLA_MUDA_APOSTA3;							
							static int BotoesAllegro::TECLA_MUDA_APOSTA4;							
							static int BotoesAllegro::TECLA_MUDA_APOSTA5;
							static int BotoesAllegro::TECLA_APOSTA_MAXIMA;
							static int BotoesAllegro::TECLA_COBRAR;
							static int BotoesAllegro::TECLA_JOGAR;
							static int BotoesAllegro::TECLA_SAIR;
							static int BotoesAllegro::TECLA_AUTOMATICO;
							static int BotoesAllegro::TECLA_CHAVE_CONFIGURACAO;
							static int BotoesAllegro::TECLA_CHAVE_COBRANCA;
                            
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
