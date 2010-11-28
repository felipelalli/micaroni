/*
 * $RCSfile: UnidadeDeTempo.h,v $
 * $Date: 2005/01/20 21:29:26 $
 * $Revision: 1.8 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_UNIDADEDETEMPO_H__1B319516_1091_4043_BCA1_8F8D5EBFAED7__INCLUDED_)
#define AFX_UNIDADEDETEMPO_H__1B319516_1091_4043_BCA1_8F8D5EBFAED7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "biblia/basico/Objeto.h"

using namespace std;
using namespace biblia::basico;

namespace biblia {
  namespace tempo {

	/**
	 * Representa uma unidade de tempo
	 * que tem milionésimos de segundo como base
	 * e ponto comum entre todas as unidades
	 * possíveis.
	 * <p>
	 * <i>Uma UnidadeDeTempo não pode ser
	 * mensurável por si própria. Use
	 * {@link biblia::tempo::Intervalo} para
	 * medir o tempo.</i>
	 *
	 * @see biblia::tempo::unidades
	 * @see biblia::tempo::Intervalo
	 */
	class UnidadeDeTempo: public Objeto {
		private:
			double UnidadeDeTempo::pRelacao;
			std::string UnidadeDeTempo::pString;

		protected:
			UnidadeDeTempo::UnidadeDeTempo(
					double milionesimosDeSegundo,
					std::string representacao = std::string(""));

		public:
			virtual UnidadeDeTempo::~UnidadeDeTempo();

			/**
			 * Retorna a relação desta unidade
			 * de tempo à milionésimos de segundo
			 * (1 / 1.000.000) segundo.
			 */
			virtual const double& UnidadeDeTempo
					::relacaoParaMilionesimosDeSegundo() const;

			/**
			 * Multiplica esta UnidadeDeTempo
			 * gerando uma outra UnidadeDeTempo
			 * a princípio 'desconhecida'.
			 *
			 * @see #emString()
			 */
			virtual UnidadeDeTempo UnidadeDeTempo
					::operator*(const double&) const;

			/**
			 * Verifica se tem a mesma relação
			 * para milionésimos de segundo, e. g.,
			 * Segundo() é igual a Milissegundo() * 1000
			 */
			virtual bool UnidadeDeTempo
					::operator==(const UnidadeDeTempo&) const;

			/**
			 * Representação em std::string do nome desta unidade.
			 */
			virtual std::string UnidadeDeTempo::emString() const;
	};

	inline UnidadeDeTempo operator*(const double&, const UnidadeDeTempo&);
  }
}

#endif // !defined(AFX_UNIDADEDETEMPO_H__1B319516_1091_4043_BCA1_8F8D5EBFAED7__INCLUDED_)
