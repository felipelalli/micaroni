/**
 * $RCSfile: Situacao.h,v $
 * $Date: 2005/03/17 01:18:09 $
 * $Revision: 1.13 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_SITUACAO_H__04C71F0A_F6EB_4422_A65A_96F09C2EF62E__INCLUDED_)
#define AFX_SITUACAO_H__04C71F0A_F6EB_4422_A65A_96F09C2EF62E__INCLUDED_

#include <biblia/basico/Objeto.h>
using namespace biblia::basico;

#include <biblia/util/Lixeira.h>
using namespace biblia::util;

#include <biblia/armazenamento/volatil/carcacas/Lista.h>
using namespace biblia::armazenamento::volatil::carcacas;

#include "biblia/dinamicas/sinfonia/Evento.h"
#include "biblia/dinamicas/sinfonia/Condicao.h"
#include "biblia/dinamicas/sinfonia/CondicaoImpl.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * Uma situa��o "acontece" se um ou qualquer um
	 * de v�rios Eventos acontecerem e alguma Condicao
	 * for verdadeira. Uma Situacao est� tamb�m
	 * associada ao(s) Evento(s) que ela poder� gerar.
	 *
	 * @see Evento
	 * @see Condicao
	 * @see GeradorDeEventosDependente
	 */
	class Situacao: public Rotulado {
		private:
			Lista<const Evento*> pOQueGera;
			Lista<const Evento*> pOQueGeraSenao;
			Lista<const Evento*> pQuandoOcorrer;
			const Condicao* pSomenteSe;
			Lixeira pLixo;

			Situacao(const Situacao&);

		public:
			/**
			 * Cria uma situa��o vazia.
			 * <p>
			 * Use as fun��es {@link #adicionaEvento},
			 * {@link #defineCondicao}, {@link #adicionaEventoQueGera}
			 * e {@link #adicionaEventoQueGeraSenao} para definir
			 * esta Situacao. Enquanto uma condi��o
			 * n�o for definida, esta situa��o n�o "acontece".
			 */
			Situacao(const Valor& nome = "(sem nome)");
			virtual ~Situacao();

			/**
			 * Adiciona um {@link Evento} que pode ser capaz
			 * de tornar esta {@link Situacao} verdadeira.
			 * <p>
			 * <b>Importante:</b> caso esta Situacao n�o
			 * tenha nenhum Evento relacionado, deve-se adicionar
			 * Eventos intermedi�rios com o mesmo nome <b>de todos
			 * os {@link Estados}</b> envolvidos na {@link Condicao}
			 * desta Situacao. Para isso, use a fun��o {@link
			 * Evento#criaEventoIntermediarioRelacionadoAEstado}.
			 */
			virtual Situacao& adicionaEvento(const Evento&);

			/**
			 * Define uma {@link Condicao} para
			 * esta {@link Situacao}.
			 */
			virtual Situacao& defineCondicao(const Condicao&);

			/**
			 * Verifica se esta situa��o "aconteceu",
			 * verificando se o {@link Evento} passado
			 * corresponde ({@link #eventoCorresponde})
			 * e a condi��o atrelada � verdadeira.
			 *
			 * @deprecated Importante: por quest�o de otimiza��o, prefira
			 * usar uma combina��o de {@link #eventoCorresponde}
			 * e {@link #condicaoVerdadeira} ao inv�s desta.
			 *
			 * @see #eventoCorresponde
			 * @see #condicaoVerdadeira
			 */
			virtual const bool aconteceu(const Evento&) const;

			/**
			 * Verifica se a condi��o desta Situacao � verdadeira.
			 *
			 * @see #eventoCorresponde
			 */
			virtual const bool condicaoVerdadeira() const;

			/**
			 * Retorna a condi��o associada a esta Situacao.
			 * Prefira utilizar direto {@link #condicaoVerdadeira}.
			 */
			virtual const Condicao& condicao() const;

			/**
			 * Verifica se o {@link Evento} passado
			 * corresponde a um dos {@link #seAcontecerUmDessesEventos
			 * eventos} desta Situa��o.
			 *
			 * @see Evento#igual
			 * @see #condicaoVerdadeira
			 */
			virtual const bool eventoCorresponde(const Evento&) const;

			/**
			 * Retorna uma lista dos {@link Evento}s que s�o
			 * capazes de tornar essa situa��o verdadeira ou falsa.
			 */
			virtual const Lista<const Evento*>& seAcontecerUmDessesEventos() const;

			/**
			 * Adiciona {@link Evento}s que ser�o gerados quando
			 * a {@link Situacao} deste GeradorDeEventosDependente
			 * ocorrer.
			 *
			 * @see #oQueGera()
			 */
			virtual Situacao& adicionaEventoQueGera(const Evento&);

			/**
			 * Retorna os {@link Evento}s que ser�o gerados quando
			 * esta {@link Situacao} ocorrer.
			 *
			 * @see #adicionaEventoQueGera
			 */
			virtual const Lista<const Evento*>& oQueGera() const;

			/**
			 * Adiciona {@link Evento}s que ser�o gerados quando
			 * algum evento da {@link Situacao} deste GeradorDeEventosDependente
			 * ocorrer mas sua condi��o n�o for verdadeira.
			 *
			 * @see #oQueGeraSenao()
			 */
			virtual Situacao& adicionaEventoQueGeraSenao(const Evento&);

			/**
			 * Retorna os {@link Evento}s que ser�o gerados quando
			 * algum evento da {@link Situacao} ocorrer mas sua condi��o
			 * n�o for verdadeira.
			 *
			 * @see #adicionaEventoQueGeraSenao
			 */
			virtual const Lista<const Evento*>& oQueGeraSenao() const;

			// Objeto:
			virtual string emString() const;
	};
  }
 }
}

#endif // !defined(AFX_SITUACAO_H__04C71F0A_F6EB_4422_A65A_96F09C2EF62E__INCLUDED_)
