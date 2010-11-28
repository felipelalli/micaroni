/*
 * $RCSfile: Conclusivo.h,v $
 * $Date: 2005/03/16 20:24:19 $
 * $Revision: 1.8 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: cvsroot $)
 */

#if !defined(AFX_CONCLUSIVO_H__EB2C6DC6_5FA3_4C25_B8AA_162A2CBFE7D2__INCLUDED_)
#define AFX_CONCLUSIVO_H__EB2C6DC6_5FA3_4C25_B8AA_162A2CBFE7D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/util/Debug.h"
#include "biblia/fluxo/FluxoExcecao.h"

using namespace biblia::basico;
using namespace biblia::util;

namespace biblia {
  namespace fluxo {

    /**
     * � Conclusivo tudo aquilo que pode ser
	 * "conclu�do". Em outras palavras, um Conclusivo
	 * � o que tem in�cio, meio e fim; necessariamente
	 * nessa ordem.
	 * <p>
	 * Esta classe possui um progresso, uma indica��o
	 * se iniciou e se foi conclu�do.
	 */
	class Conclusivo: public Objeto {
		protected:
			bool Conclusivo::pAcabou;
			bool Conclusivo::pIniciou;
			double Conclusivo::pProgresso;			

		public:
			Conclusivo::Conclusivo();
			Conclusivo::Conclusivo(const Conclusivo&);
			virtual Conclusivo::~Conclusivo();

			/**
			 * Como se estivesse come�ado agora.
			 * <del>Serve para quando algum Conclusivo
			 * pode ser executado v�rias vezes
			 * evitando a exce��o ConclusivoJaIniciadoConclusivoExcecao
			 * na fun��o {@link #inicia()}</del>
			 */
			virtual Conclusivo& Conclusivo::zera();

			/**
			 * Deve ser chamado <i>uma vez</i>
			 * quando esse Conclusivo for conclu�do.
			 *
			 * @throws ConclusivoJaConcluidoConclusivoExcecao
			 */
			virtual Conclusivo& Conclusivo::conclui();

			/**
			 * Deve ser chamado <i>uma vez</i> quando esse
			 * Conclusivo for iniciado.
			 *
			 * @throws ConclusivoAindaNaoConcluidoConclusivoExcecao
			 */
			virtual Conclusivo& Conclusivo::inicia();

			/**
			 * @see #progresso(int parte, int todo)
			 */
			virtual Conclusivo& Conclusivo::progresso(
					double porcentagem);

			/**
			 * O controle de <b>parte</b> e <b>todo</b>
			 * deve ser feito por fora. Esta classe
			 * guarda apenas uma porcentagem.
			 *
			 * @see #progresso(double porcentagem)
			 */
			virtual Conclusivo& Conclusivo::progresso(
					int parte, int todo);

			/**
			 * Verifica se este Conclusivo foi conclu�do.
			 */
			virtual bool Conclusivo::concluido() const;

			/**
			 * Verifica se este Conclusivo j� iniciou.
			 */
			virtual bool Conclusivo::iniciou() const;

			/**
			 * Retorna o progresso em porcentagem (%).
			 */
			virtual double Conclusivo::porcentagem() const;

	};
  }
}

#endif // !defined(AFX_CONCLUSIVO_H__EB2C6DC6_5FA3_4C25_B8AA_162A2CBFE7D2__INCLUDED_)
