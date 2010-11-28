/*
 * $RCSfile: DadosXMLFixo.h,v $
 * $Date: 2005/01/20 21:28:53 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#include <string>
#include "biblia/jogos/special/dados/Dados.h"
#include "biblia/jogos/special/dados/DConfiguracao.h"

#ifndef SBS_DADOS_XML_FIXO_SW_H
#define SBS_DADOS_XML_FIXO_SW_H

#define IP_FIXO_SW "10.0.0.3"

namespace biblia {
  namespace jogos {
    namespace special {
	  namespace dados {

		class DadosXMLFixo: public Dados {

			public:
				DadosXMLFixo::DadosXMLFixo();
				virtual DadosXMLFixo::~DadosXMLFixo();

				/*
				 * Abre os arquivos para leitura e para escrita.
				 * Na verdade, apenas os marca para usa-los quando
				 * necessario.
				 *
				 * Deve criar se o arquivo nao existir.
				 */
				virtual Dados& DadosXMLFixo::abrirArquivo(const char* arquivo);

				/*
				 * Le de um certo caminho especificado por:
				 * TagPai->Tag->ultimaTag
				 *
				 * Retorna true se o caminho existe e falso caso contrario.
				 */
				virtual bool DadosXMLFixo::ler(const char* caminho, char* buffer);
				virtual bool DadosXMLFixo::ler(const char* caminho, Lista*);

				/*
				 * Sobrescreve uma lista em um certo caminho definido por:
				 * TagPai->Tag->ultimaTag
				 */
				virtual Dados& DadosXMLFixo::escrever(const char* caminho, char* oQue) ;
				virtual Dados& DadosXMLFixo::escrever(const char* caminho, Lista*);
		};
	  }
	}
  }
}

#endif
