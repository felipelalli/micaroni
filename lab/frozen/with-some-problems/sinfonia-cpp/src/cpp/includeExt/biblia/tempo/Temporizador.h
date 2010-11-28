/*
 * $RCSfile: Temporizador.h,v $
 * $Date: 2003/06/16 22:40:59 $
 * $Revision: 1.11 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_TEMPORIZADOR_H__F878F23C_DC42_4157_9B44_D5C6C8265C5D__INCLUDED_)
#define AFX_TEMPORIZADOR_H__F878F23C_DC42_4157_9B44_D5C6C8265C5D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/tempo/Intervalo.h"
#include "biblia/tempo/Cronometro.h"
#include "biblia/tempo/Momento.h"
#include "biblia/tempo/UltraLong.h"
#include "biblia/tempo/UniversoDeTempo.h"
#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Executavel.h"
#include "biblia/fluxo/ExecutavelOtimizado.h"
#include "biblia/fluxo/ExecutavelOtimizadoImpl.h"

using namespace biblia::basico;
using namespace biblia::fluxo;

namespace biblia {
  namespace tempo {

	/**
 	 * Um Temporizador 'chama' o {@link #executavel()
	 * execut�vel} que cont�m toda vez que o tempo
	 * se esgota. O tempo � definido por {@link
	 * #intervalo()} e controlado por {@link
	 * #universoDeTempo()}.
	 * <p>
	 * Utilize {@link biblia::fluxo::ExecutaveisEmSerie}
	 * para facilitar o uso de v�rios temporizadores.
	 * <p>
	 * <i>Obs.: ele j� come�a {@link #ligado() ligado}.</i>
	 *
	 * @see biblia::fluxo::ExecutavelOtimizado
	 * @see biblia::fluxo::ExecutaveisEmSerie
	 *
	 * @todo Este temporizador pode sofrer diversos
	 *       tipos de otimiza��es. Esta vers�o existe
	 *       apenas para que ele funcione de uma forma ou
	 *       de outra.
	 *
	 * @bug Est� havendo um overhead de 1 milissegundo
	 *        eventualmente. Descobrir o porqu� e como corrigir.
	 */
	class Temporizador: public Objeto,
					    public Executavel
	{
		private:
			/* Construtor */
			ExecutavelOtimizado& Temporizador::pExecutavel;
			const UniversoDeTempo* Temporizador::pUniverso;
			Intervalo Temporizador::pIntervalo;

			/* Interno */
			UltraLong Temporizador::pVezesPassadas;
			UltraLong Temporizador::pUltimaVez;
			Momento Temporizador::pInicio;
			bool Temporizador::pLigado;

		protected:
			/**
			 * Zera este temporizador. Muito �til para
			 * evitar atrasos muito grandes e processamento
			 * desnecess�rio.
			 */
			virtual Temporizador& Temporizador::zera();

		public:
			/**
			 * Internamente o Temporizador
			 * utiliza um {@link
			 * biblia::fluxo::ExecutavelOtimizado
			 * execut�vel otimizado}. Se voc� quiser
			 * passar um {@link biblia::fluxo::Executavel
			 * execut�vel simples} converta-o passado como
			 * par�metro neste construtor pela classe {@link
			 * biblia::fluxo::ExecutavelOtimizadoImpl}.
			 * <p>
			 * @param u Prefira passar um {@link
			 *          biblia::tempo::Cronometro} como
			 *          {@link biblia::tempo::UniversoDeTempo},
			 *          pois ele tem as opera��es 'pause', 'play'
			 *          e 'reset'.
			 *
			 * @see biblia::fluxo::ExecutavelOtimizado
			 * @see biblia::fluxo::ExecutavelOtimizadoImpl
			 */
			Temporizador::Temporizador(
					ExecutavelOtimizado&,
					const Intervalo,
					const UniversoDeTempo& u);

			/**
			 * Cria um baseado em outro.
			 */
			Temporizador::Temporizador(const Temporizador&);
			virtual Temporizador::~Temporizador();

			/**
			 * Retorna o {@link biblia::tempo::Intervalo
			 * intervalo de tempo} que este este
			 * Temporizador invoca o {@link #executavel()
			 * execut�vel}.
			 */
			virtual const Intervalo& Temporizador
					::intervalo() const;

			/**
			 * Retorna o execut�vel que
			 * este temporizador cont�m.
			 *
			 * @see biblia::fluxo::ExecutavelOtimizado
			 */
			virtual ExecutavelOtimizado& Temporizador
					::executavel() const;

			/**
			 * Retorna o {@link biblia::tempo::UniversoDeTempo}
			 * que controla este temporizador.
			 */
			virtual const UniversoDeTempo& Temporizador
					::universoDeTempo() const;

			/**
			 * Verifica se este Temporizador est� ligado.
			 *
			 * @see #liga()
			 * @see #desliga()
			 */
			virtual bool Temporizador::ligado() const;

			/**
			 * Liga e zera este temporizador.
			 *
			 * @see #desliga()
			 */
			virtual Temporizador& Temporizador::liga();

			/**
			 * Desliga este temporizador at� que
			 * algu�m o {@link #liga() ligue}.
			 *
			 * @see #liga()
			 */
			virtual Temporizador& Temporizador::desliga();

			// Executavel:

			/**
			 * Atualiza quantas vezes o tempo se esgotou e
			 * invoca o {@link #executavel()
			 * execut�vel} quantas vezes forem necess�rias.
			 */
			virtual Executavel& Temporizador::executa();
	};
  }
}

#endif // !defined(AFX_TEMPORIZADOR_H__F878F23C_DC42_4157_9B44_D5C6C8265C5D__INCLUDED_)
