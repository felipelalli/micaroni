/**
 * $RCSfile: ModificadorDeEstado.h,v $
 * $Date: 2005/03/22 20:19:12 $
 * $Revision: 1.13 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_MODIFICADORDEESTADO_H__FEBCF918_6F60_4D45_A5C8_D154EA1F46E0__INCLUDED_)
#define AFX_MODIFICADORDEESTADO_H__FEBCF918_6F60_4D45_A5C8_D154EA1F46E0__INCLUDED_

#include <biblia/basico/Objeto.h>
#include <biblia/basico/Copiavel.h>
#include <biblia/basico/Igualavel.h>
using namespace biblia::basico;

#include <biblia/util/Lixeira.h>
using namespace biblia::util;

#include "biblia/dinamicas/sinfonia/Valor.h"
#include "biblia/dinamicas/sinfonia/EstadoAlvo.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * Está relacionado diretamente a um (nome de)
	 * Estado para modificá-lo
	 * com uma determinada ação
	 * e eventuais valores como
	 * parâmetro. Pode estar associado a algum campo específico (pela
	 * função {@link #defineCampo}),
	 * caso contrário se aplicará no campo padrão {@link Multifuncional#CAMPO_PRINCIPAL}.
	 * Os valores como parâmetro são {@link EstadoAlvo apontadores para Estado}s
	 * que podem ser um {@link MediadorDeEstados#estadoConstante estado constante}.
	 * <p>
	 * Obs.: Não é esta classe que modifica diretamente o Estado relacionado,
	 * para esse fim veja {@link MediadorDeEstados}.
	 *
	 * @see Evento
	 * @see MediadorDeEstados
	 * @see Estado#CAMPO_PRINCIPAL
	 */
	class ModificadorDeEstado: public Copiavel,
							   public Igualavel, public Objeto
	{
		private:
			Valor pEstado;
			Identificacao pAcao;
			Identificacao pCampo;
			Lista<EstadoAlvo> pValores;
			Lista<const Valor*> pValoresConstantes;

		protected:
			/**
			 * Use {@link #geraCopia} ao invés deste.
			 */
			ModificadorDeEstado(const ModificadorDeEstado&);

		public:
			/**
			 * É uma {@link #acao ação} especial que indica
			 * que haverá apenas um {@link #parametros parâmetro} que será atribuído
			 * ao {@link Estado} relacionado sem que seja
			 * executada outra ação em conjunto.
			 */
			static Identificacao APENAS_ATRIBUI;

			/**
			 * Cria um ModificadorDeEstado.
			 *
			 * @param nomeCompletoDoEstado É necessário que seja o nome completo
			 *        do Estado, i. e., anexado ao grupo a que pertence.
			 *        Veja {@link Estado#nomeCompleto()}.
			 */
			explicit ModificadorDeEstado(const Valor& nomeCompletoDoEstado,
								const Identificacao& acao = APENAS_ATRIBUI);

			virtual ~ModificadorDeEstado();

			/**
			 * Retorna o nome completo do Estado em questão.
			 */
			virtual const Valor& estado() const;

			/**
			 * Retorna a ação que será aplicada ao Estado
			 * em questão.
			 */
			virtual const Identificacao& acao() const;

			/**
			 * O campo a qual será aplicado este
			 * ModificadorDeEstado.
			 */
			virtual const Valor campo() const;

			/**
			 * Retorna os parâmetros que serão aplicados ao {@link #estado Estado}
			 * em questão.
			 */
			virtual const Lista<EstadoAlvo>& parametros() const;

			/**
			 * Supõe que este modificador tenha um só
			 * parâmetro.
			 *
			 @throws IndiceForaDeIntervaloListaExcecao
			 */
			virtual const EstadoAlvo& parametroUnico() const {
				return this->parametros()[0];
			}

			/**
			 * Adiciona um {@link EstadoAlvo} como parâmetro a este ModificadorDeEstado
			 * que será usado como parâmetro na aplicação ao
			 * {@link #estado Estado} em questão.
			 */
			virtual ModificadorDeEstado& adicionaParametro(const EstadoAlvo&);

			/**
			 * Define o campo que este modificador aplicará.
			 */
			virtual ModificadorDeEstado& defineCampo(
					const Valor& = Multifuncional::CAMPO_PRINCIPAL);

			// Igualavel:
			/**
			 * É igual quando as ações são as mesmas,
			 * o Estado é o mesmo e os parâmetros
			 * também.
			 */
			virtual const bool igual(const Igualavel& alheio) const;

			// Copiavel:
			virtual Objeto* geraCopia() const;
			virtual Copiavel& copiaEmSi(const Copiavel& alheio);
	};
  }
 }
}

#endif // !defined(AFX_MODIFICADORDEESTADO_H__FEBCF918_6F60_4D45_A5C8_D154EA1F46E0__INCLUDED_)
