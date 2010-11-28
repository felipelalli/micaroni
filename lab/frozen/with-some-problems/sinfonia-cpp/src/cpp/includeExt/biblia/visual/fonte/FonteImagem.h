/*
 * $RCSfile: FonteImagem.h,v $
 * $Date: 2005/01/20 21:29:34 $
 * $Revision: 1.7 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_FONTEIMAGEM_H__C94C8FFD_F32F_4959_B58F_5B927DAAD8B6__INCLUDED_)
#define AFX_FONTEIMAGEM_H__C94C8FFD_F32F_4959_B58F_5B927DAAD8B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#endif

#include <map>
#include <string>
#include "biblia/basico/Objeto.h"
#include "biblia/visual/imagem2d/Imagem.h"
#include "biblia/visual/fonte/FonteExcecao.h"

using namespace std;
using namespace biblia::basico;
using namespace biblia::visual::imagem2d;

namespace biblia {
  namespace visual {
    namespace fonte {

		/**
		 * Cont�m as informa��es necess�rias para
		 * se renderizar um caracter a partir de imagens.
		 * <p>
		 * Este tipo de fonte � muito <s>est�tico</s>; solu��o
		 * simples por�m n�o elegante.
		 * <p>
		 * <i>Obs.: N�o � fun��o desta classe a formata��o
		 * espec�fica da fonte, i. e., se houver necessidade
		 * de formata��o de fonte e suas origens forem diferentes,
		 * deve-se criar mais de uma FonteImagem com cada formata��o
		 * ou modificar a imagem 'por fora'.</i>
		 *
		 * @see biblia::visual::fonte::FonteImagemWizard
		 */
		class FonteImagem: public Objeto {
			private:
				std::string FonteImagem::pNome;
				std::deque<string> FonteImagem::pLetras;
				map<std::string, const Imagem*> FonteImagem::pImagens;

			public:
				FonteImagem::FonteImagem(std::string nome = "");
				virtual FonteImagem::~FonteImagem();

				/**
				 * Associa uma letra a uma imagem.
				 */
				virtual FonteImagem& FonteImagem::associa(
						const std::string& letra, const Imagem&);

				/**
				 * @see #associa(const std::string& letra, const Imagem&)
				 */
				virtual FonteImagem& FonteImagem::associa(
						const char& letra, const Imagem& i)
				{
					return this->associa(string() + letra, i);
				}

				/**
				 * Retorna o nome desta fonte.
				 */
				virtual const std::string& FonteImagem::nome() const;

				/**
				 * Captura uma imagem relativa a uma letra.
				 *
				 * @bug n�o sei por que o map[x] n�o � fun��o
				 *         const. Desconfio: porque � poss�vel
				 *         fazer map[x]=y, mas n�o seria motivo
				 *         para n�o ter um operator[] const.
				 *         - Verificar isso com calma depois.
				 *         - Isso � motivo pelo qual em muitos
				 *           outros lugares n�o se usou 'const'.
				 *           :-o Efeito em cascata!
				 */
				virtual const Imagem& FonteImagem::letra(
						const std::string& qual);

				/**
				 * @see #letra(const std::string& qual)
				 */
				virtual const Imagem& FonteImagem::letra(
						const char& qual)
				{
					return this->letra(string() + qual);
				}

				/**
				 * Retorna todas as letras que esta
				 * fonte cont�m.
				 */
				virtual const std::deque<string>& FonteImagem
						::letras() const;

				/**
				 * Concatena todas as letras desta fonte numa
				 * s� std::string. Esta fun��o n�o � otimizada e deve
				 * ser evitada ser chamada dentro de loops.
				 */
				virtual std::string FonteImagem::letrasConcatenadas() const;

				// Objeto:
				virtual std::string FonteImagem::emString() const;
		};
	}
  }
}

#endif // !defined(AFX_FONTEIMAGEM_H__C94C8FFD_F32F_4959_B58F_5B927DAAD8B6__INCLUDED_)
