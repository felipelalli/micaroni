/**
 * $RCSfile: ModificadorDeEstado.h,v $
 * $Date: 2005/03/22 20:19:12 $
 * $Revision: 1.13 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
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
	 * Est� relacionado diretamente a um (nome de)
	 * Estado para modific�-lo
	 * com uma determinada a��o
	 * e eventuais valores como
	 * par�metro. Pode estar associado a algum campo espec�fico (pela
	 * fun��o {@link #defineCampo}),
	 * caso contr�rio se aplicar� no campo padr�o {@link Multifuncional#CAMPO_PRINCIPAL}.
	 * Os valores como par�metro s�o {@link EstadoAlvo apontadores para Estado}s
	 * que podem ser um {@link MediadorDeEstados#estadoConstante estado constante}.
	 * <p>
	 * Obs.: N�o � esta classe que modifica diretamente o Estado relacionado,
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
			 * Use {@link #geraCopia} ao inv�s deste.
			 */
			ModificadorDeEstado(const ModificadorDeEstado&);

		public:
			/**
			 * � uma {@link #acao a��o} especial que indica
			 * que haver� apenas um {@link #parametros par�metro} que ser� atribu�do
			 * ao {@link Estado} relacionado sem que seja
			 * executada outra a��o em conjunto.
			 */
			static Identificacao APENAS_ATRIBUI;

			/**
			 * Cria um ModificadorDeEstado.
			 *
			 * @param nomeCompletoDoEstado � necess�rio que seja o nome completo
			 *        do Estado, i. e., anexado ao grupo a que pertence.
			 *        Veja {@link Estado#nomeCompleto()}.
			 */
			explicit ModificadorDeEstado(const Valor& nomeCompletoDoEstado,
								const Identificacao& acao = APENAS_ATRIBUI);

			virtual ~ModificadorDeEstado();

			/**
			 * Retorna o nome completo do Estado em quest�o.
			 */
			virtual const Valor& estado() const;

			/**
			 * Retorna a a��o que ser� aplicada ao Estado
			 * em quest�o.
			 */
			virtual const Identificacao& acao() const;

			/**
			 * O campo a qual ser� aplicado este
			 * ModificadorDeEstado.
			 */
			virtual const Valor campo() const;

			/**
			 * Retorna os par�metros que ser�o aplicados ao {@link #estado Estado}
			 * em quest�o.
			 */
			virtual const Lista<EstadoAlvo>& parametros() const;

			/**
			 * Sup�e que este modificador tenha um s�
			 * par�metro.
			 *
			 @throws IndiceForaDeIntervaloListaExcecao
			 */
			virtual const EstadoAlvo& parametroUnico() const {
				return this->parametros()[0];
			}

			/**
			 * Adiciona um {@link EstadoAlvo} como par�metro a este ModificadorDeEstado
			 * que ser� usado como par�metro na aplica��o ao
			 * {@link #estado Estado} em quest�o.
			 */
			virtual ModificadorDeEstado& adicionaParametro(const EstadoAlvo&);

			/**
			 * Define o campo que este modificador aplicar�.
			 */
			virtual ModificadorDeEstado& defineCampo(
					const Valor& = Multifuncional::CAMPO_PRINCIPAL);

			// Igualavel:
			/**
			 * � igual quando as a��es s�o as mesmas,
			 * o Estado � o mesmo e os par�metros
			 * tamb�m.
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
