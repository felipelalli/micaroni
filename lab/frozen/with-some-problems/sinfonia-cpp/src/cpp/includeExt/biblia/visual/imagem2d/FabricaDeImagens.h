/*
 * $RCSfile: FabricaDeImagens.h,v $
 * $Date: 2005/03/16 20:24:19 $
 * $Revision: 1.8 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: cvsroot $)
 */

#if !defined(AFX_FABRICADEIMAGENS_H__5C3B8B62_7C42_40EB_8BAB_35502609897A__INCLUDED_)
#define AFX_FABRICADEIMAGENS_H__5C3B8B62_7C42_40EB_8BAB_35502609897A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Interface.h"
#include "biblia/visual/imagem2d/Imagem.h"
#include <string>

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

using namespace std;
using namespace biblia::basico;

namespace biblia {
  namespace visual {
	namespace imagem2d {

		/**
		 * � respons�vel por gerar uma {@link
		 * biblia::visual::imagem2d::Imagem}.
		 */
		class FabricaDeImagens: public Interface {
			protected:

				AGES_INT_64 pTamanhoCarregado;

				FabricaDeImagens::FabricaDeImagens();

			public:
				virtual FabricaDeImagens::~FabricaDeImagens();

				/**
				 * @throws ErroNaLeituraDoArquivoBasico
				 *         � invocado quando o arquivo
				 *         n�o � encontrado ou n�o � poss�vel
				 *         ler por algum motivo.
				 */
				virtual Imagem* FabricaDeImagens
						::carregaDeArquivoBasico
							(const std::string& nomeDoArquivoBasico) = 0;

				/**
				 * As propriedades s�o 'novas'
				 * mas a regi�o de mem�ria onde a imagem
				 * est� armazenada � comum �s duas.
				 */
				virtual Imagem* FabricaDeImagens
						::fazClone(const Imagem*) = 0;

				virtual Imagem* FabricaDeImagens::criaVazio(
						 const Tamanho&) = 0;

				AGES_INT_64 FabricaDeImagens::tamanhoCarregado(){
					return this->pTamanhoCarregado;
				}

				void FabricaDeImagens::zera(){
					this->pTamanhoCarregado=0;
				}
		};
	}
  }
}

#endif // !defined(AFX_FABRICADEIMAGENS_H__5C3B8B62_7C42_40EB_8BAB_35502609897A__INCLUDED_)
