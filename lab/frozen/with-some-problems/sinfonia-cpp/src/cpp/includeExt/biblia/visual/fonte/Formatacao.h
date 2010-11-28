/*
 * $RCSfile: Formatacao.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_FORMATACAO_H__93ECB361_8447_4C26_903F_EB03611D512A__INCLUDED_)
#define AFX_FORMATACAO_H__93ECB361_8447_4C26_903F_EB03611D512A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

namespace biblia {
  namespace visual {
 	namespace fonte {

		/**
		 * Representa uma formatação simples
		 * de <b>caracteres</b>, tais como
		 * <b>negrito</b>, <i>itálico</i>, <s>sublinhado</s>,
		 * tamanho, espaçamento entre os caracteres etc.
		 * <p>
		 * Esta formatação nada tem a ver com
		 * parágrafo, alinhamento etc.
		 */
		class Formatacao: public Objeto {
			private:
				double Formatacao::pTamanho;
				bool Formatacao::pNegrito;
				bool Formatacao::pItalico;
				bool Formatacao::pSublinhado;
				bool Formatacao::pSobrescrito;
				bool Formatacao::pSubscrito;
				bool Formatacao::pCaixaAlta;
				bool Formatacao::pTodasMaiusculas;
				bool Formatacao::pTodasMinusculas;
				double Formatacao::pEspacamentoEntrePalavras;
				double Formatacao::pEspacamentoEntreCaracteres;

			public:
				static double TAMANHO_PADRAO;

				Formatacao::Formatacao(
						double tamanho = Formatacao::TAMANHO_PADRAO,
						bool negrito = false, bool italico = false,
						bool sublinhado = false, bool sobrescrito = false,
						bool subscrito = false, bool caixaAlta = false,
						bool todasMaiusculas = false,
						bool todasMinusculas = false,
						double espacamentoEntrePalavras = -1,
						double espacamentoEntreCaracteres = 0.0);

				virtual Formatacao::~Formatacao();

				virtual Formatacao& Formatacao::tamanho(double tamanho);
				virtual Formatacao& Formatacao::negrito(bool sim);
				virtual Formatacao& Formatacao::italico(bool sim);
				virtual Formatacao& Formatacao::sublinhado(bool sim);
				virtual Formatacao& Formatacao::sobrescrito(bool sim);
				virtual Formatacao& Formatacao::subscrito(bool sim);
				virtual Formatacao& Formatacao::caixaAlta(bool sim);
				virtual Formatacao& Formatacao::todasMaiusculas(bool sim);
				virtual Formatacao& Formatacao::todasMinusculas(bool sim);
				virtual Formatacao& Formatacao
						::espacamentoEntrePalavras(double tamanho);

				virtual Formatacao& Formatacao
						::espacamentoEntreCaracteres(double tamanho);

				virtual const double& Formatacao::tamanho() const;
				virtual const bool& Formatacao::negrito() const;
				virtual const bool& Formatacao::italico() const;
				virtual const bool& Formatacao::sublinhado() const;
				virtual const bool& Formatacao::sobrescrito() const;
				virtual const bool& Formatacao::subscrito() const;
				virtual const bool& Formatacao::caixaAlta() const;
				virtual const bool& Formatacao::todasMaiusculas() const;
				virtual const bool& Formatacao::todasMinusculas() const;
				virtual const double& Formatacao
						::espacamentoEntrePalavras() const;

				virtual const double& Formatacao
						::espacamentoEntreCaracteres() const;
		};
	}
  }
}

#endif // !defined(AFX_FORMATACAO_H__93ECB361_8447_4C26_903F_EB03611D512A__INCLUDED_)
