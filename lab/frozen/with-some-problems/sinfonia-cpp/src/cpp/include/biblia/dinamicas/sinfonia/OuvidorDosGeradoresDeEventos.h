/**
 * $RCSfile: OuvidorDosGeradoresDeEventos.h,v $
 * $Date: 2005/03/15 21:59:00 $
 * $Revision: 1.3 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_OUVIDORDOSGERADORESDEEVENTOSESPECIAIS_H__994A05F2_BBD7_4960_BE30_6E6E84412ACB__INCLUDED_)
#define AFX_OUVIDORDOSGERADORESDEEVENTOSESPECIAIS_H__994A05F2_BBD7_4960_BE30_6E6E84412ACB__INCLUDED_

#include <biblia/fluxo/Semaforo.h>
using namespace biblia::fluxo;

#include "biblia/dinamicas/sinfonia/GeradorDeEventos.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * � uma ponte de liga��o entre um gerador
	 * de eventos e outro. Tudo que o gerador de eventos
	 * doador gerar ser� transmitido para o gerador
	 * de eventos receptor. Geralmente � usado para unir
	 * v�rios geradores de eventos num s�, como por exemplo:
     * <p>
	 * Geradores doadores:
	 * <pre>
	   GeradorA |
	   GeradorB |
	   GeradorC +-----> GeradorReceptor
	   GeradorD |
	 * </pre>
	 *
	 * @see GeradorDeEventos
	 */
	class OuvidorDosGeradoresDeEventos: public Objeto, public Executavel {
		private:
			GeradorDeEventos* pGeradorReceptor;
			GeradorDeEventos* pGeradorDoador;
			bool pAcabou;
			bool pExecutou;
			Semaforo pEsperaAcabar;
			Semaforo pEsperaExecutar;

		public:
			OuvidorDosGeradoresDeEventos(
					GeradorDeEventos* receptor,
					GeradorDeEventos* doador);

			virtual ~OuvidorDosGeradoresDeEventos();

			// Executavel:

			/**
			 * Deve ser executado uma vez em Thread.
			 * Fica em modo de espera at� que algum evento
			 * do gerador doador ocorra. E caso ocorra,
			 * este o repassa para o Gerador receptor.
			 */
			virtual Executavel& executa();

			/**
			 * Exibe os geradores a que este est� relacionado.
			 */
			virtual string emString() const;
	};
  }
 }
}

#endif // !defined(AFX_OUVIDORDOSGERADORESDEEVENTOSESPECIAIS_H__994A05F2_BBD7_4960_BE30_6E6E84412ACB__INCLUDED_)
