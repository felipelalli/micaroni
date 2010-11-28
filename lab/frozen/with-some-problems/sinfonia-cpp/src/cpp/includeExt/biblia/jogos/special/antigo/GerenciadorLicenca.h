/*
 * $RCSfile: GerenciadorLicenca.h,v $
 * $Date: 2004/08/10 15:13:39 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include "biblia/jogos/special/antigo/Marcacao.h"
#include "biblia/jogos/special/antigo/MensagemBmp.h"
#include "biblia/jogos/special/antigo/Relatorio.h"
#include "biblia/jogos/special/antigo/ExibidorDeRelatorio.h"
#include "biblia/jogos/special/io/botoes/Botoes.h"
#include "biblia/jogos/special/antigo/Sistema.h"
#include "biblia/seguranca/ControleLicenca.h"

#include "biblia/util/Versao.h"
using namespace biblia::util;

using namespace biblia::seguranca;
using namespace biblia::jogos::special::io::botoes;

#ifndef SBS_GERENCIADOR_LICENSA_H_SW
#define SBS_GERENCIADOR_LICENSA_H_SW

namespace biblia {
	namespace jogos {
		namespace special {
			namespace antigo {

				class GerenciadorLicenca {
					private:
						Versao& pVersao;
						ControleLicenca& pControleLicenca;
						Botoes& pBotoes;
						/*fontes usadas para o input*/
						MensagemBmp* pFonteSelecionada;
						MensagemBmp* pFonteConvencional;
						MensagemBmp* pFonteNegrito;
						MensagemBmp* pFonteTitulo;
						MensagemBmp* pFontePequena;

						Marcacao* pFundo;

						biblia::armazenamento::volatil::Lista* pListaInput;
						biblia::armazenamento::volatil::Lista* pListaLabel;

						int pQuantosCaracteres;
						int pInputAtual;

						ExibidorDeRelatorio* pExibidor;
						char* pMontaString();

						void pAdicionaLabelNaTabela(int l, int c,Tabela&, Label*);
						void pAdicionaInputNaTabela(int l, int c,Tabela&, Input*);

						void  pProximoInput(bool pedeSenhaAntiga);
						void  pInputAnterior(bool pedeSenhaAntiga);

						void  pProximoCaracter(bool pedeSenhaAntiga);
						void  pCaracterAnterior(bool pedeSenhaAntiga);

						bool pTeclado;
						bool segundaTela;
						TelaCompleta& pTela;

					protected:
						GerenciadorLicenca& GerenciadorLicenca::limpa();

					public:
						GerenciadorLicenca(TelaCompleta& tela,
								Versao& versao,
								ControleLicenca& controle,
								Botoes& botoes);

						~GerenciadorLicenca();
						//cada caracter eh representador por dois inputs
						void GerenciadorLicenca::verificacaoDeLicencaValida(
									int qtsCaracteres, bool pedeSenhaAntiga);

						bool GerenciadorLicenca::aviso(
								int dias);

						ControleLicenca& controle() {
							return this->pControleLicenca;
						}
				};
			}
		}
	}
}
#endif
