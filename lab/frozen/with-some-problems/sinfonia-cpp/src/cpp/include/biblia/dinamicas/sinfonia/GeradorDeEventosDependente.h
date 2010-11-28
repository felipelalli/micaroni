/**
 * $RCSfile: GeradorDeEventosDependente.h,v $
 * $Date: 2005/03/30 01:23:44 $
 * $Revision: 1.14 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_GERADORDEEVENTOSDEPENDENTE_H__310CA99B_E994_48AE_9465_DCAE0F048830__INCLUDED_)
#define AFX_GERADORDEEVENTOSDEPENDENTE_H__310CA99B_E994_48AE_9465_DCAE0F048830__INCLUDED_

#include <biblia/util/Lixeira.h>
using namespace biblia::util;

#include <biblia/fluxo/Semaforo.h>
using namespace biblia::fluxo;

#include <biblia/tempo/UniversoDeTempo.h>
using namespace biblia::tempo;

#include <biblia/armazenamento/volatil/carcacas/Lista.h>
#include <biblia/armazenamento/volatil/carcacas/MapaHash.h>
using namespace biblia::armazenamento::volatil::carcacas;

#include "biblia/dinamicas/sinfonia/Situacao.h"
#include "biblia/dinamicas/sinfonia/GeradorDeEventos.h"
#include "biblia/dinamicas/sinfonia/MediadorDeEstados.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * <b>Dinâmica dos Estados</b>: gera Eventos a partir de diversas Situacoes.
	 * <p>
	 * Logo após ser criada, {@link Situacoes} devem ser adicionadas
	 * a esta pela função {@link #adicionaSituacao}. Sempre
	 * que um {@link Evento} ocorrer, ele deve ser informado
	 * na função {@link #aconteceu} e para gerar novos {@link Evento}s
	 * em {@link GeradorDeEventos#esperaAteQueHajaEvento}
	 * chame a função {@link #executa}.
	 *
	 * @see Situacao
	 * @see Evento
	 * @see GeradorDeEventosEspecial
	 * @see Concretizador
	 */
	class GeradorDeEventosDependente: public GeradorDeEventos {
		private:
			Lista<const Evento*> pEventosEmEspera;
			MapaHash<Lista<const Situacao*>*> pSituacoes;
			Lixeira pLixo;
			Semaforo pControle;
			mutable MapaHash<Lista<const Evento*> > pEventosParaChecagem;
			MapaHash<bool> pJaExibiuEsteErro;

			// só para consulta:
			MapaHash<int> pContadorParaQuandoNomeJaExiste;
			MapaHash<const Situacao*> pSituacoesParaConsultaExterna;
			Lista<Identificacao> pNomeDasSituacoes;

			virtual const bool validaRecursivamente(const Situacao& s) const;

		public:
			/**
			 * Este GeradorDeEventosDependente começa
			 * vazio e deve ser definido pela
			 * função {@link #adicionaSituacao}.
			 *
			 * @see #adicionaSituacao
			 */
			GeradorDeEventosDependente(const MediadorDeEstados&);
			virtual ~GeradorDeEventosDependente();

			/**
			 * Define este GeradorDeEventosDependente. Se a {@link Situacao}
			 * não for válida ele a adiciona e manda um WARN para o sistema.
			 *
			 * @param s Esta classe <b>não</b> pegará para si a responsabilidade
			 *          de deletar a situação passada.
			 */
			virtual GeradorDeEventosDependente&	adicionaSituacao(const Situacao* s);

			/**
			 * Retorna se a Situação é válida, ou seja, não entra em loop.
			 */
			virtual const bool valida(const Situacao& s) const;

			/**
			 * Informa a este GeradorDeEventosDependente
			 * que tal {@link Evento} aconteceu para
			 * que este tome as devidas providências
			 * quando for {@link #executa executado}.
			 *
			 * @param e O {@link Evento} passado deve estar disparado
			 *          e deve sobreviver até que este GeradorDeEventos
			 *          seja {@link #executa executado}.
			 *
			 * @see #executa
			 * @see Evento
			 */
			virtual GeradorDeEventosDependente& aconteceu(const Evento& e);

			/**
			 * Apaga todas as {@link Situacao Situações}.
			 */
			virtual GeradorDeEventosDependente& apagaTudo();

			// Consulta:
			/**
			 * Retorna o nome de todas as {@link Situacao Situações}.
			 *
			 * @see #situacao
			 */
			virtual const Lista<Identificacao>& nomeDeTodasSituacoes() const;

			/**
			 * Retorna a situação com o nome que foi passado como parâmetro.
			 * Caso haja mais de uma situação com o mesmo nome, será retornada
			 * somente a que foi adicionada primeira.
			 *
			 * @see #nomeDeTodasSituacoes
			 */
			virtual const Situacao& situacao(const Identificacao&) const;

			// GeradorDeEventos:
			/**
			 * Ignora, porque este GeradorDependente não
			 * é uma Thread que roda em loop. Veja {@link #executa}.
			 */
			virtual GeradorDeEventos& captaEGeraEmLoop() {
				return *this;
			};

			// Executavel:
			/**
			 * Toma as devidas providências de acordo com
			 * os Eventos adicionados pela função {@link #aconteceu}.
			 * Deve ser executado todo loop após todos os
			 * {@link Evento}s serem adicionados.
			 */
			virtual Executavel& executa();
	};
  }
 }
}

#endif // !defined(AFX_GERADORDEEVENTOSDEPENDENTE_H__310CA99B_E994_48AE_9465_DCAE0F048830__INCLUDED_)
