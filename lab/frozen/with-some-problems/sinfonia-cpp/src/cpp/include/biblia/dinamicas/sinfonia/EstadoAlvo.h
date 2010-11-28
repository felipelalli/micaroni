/**
 * $RCSfile: EstadoAlvo.h,v $
 * $Date: 2005/03/04 00:32:16 $
 * $Revision: 1.4 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_ESTADOALVO_H__D99ABA99_F8CF_4D06_9EE0_AC9D8F301E97__INCLUDED_)
#define AFX_ESTADOALVO_H__D99ABA99_F8CF_4D06_9EE0_AC9D8F301E97__INCLUDED_

#include <biblia/basico/Copiavel.h>
#include <biblia/basico/Igualavel.h>
using namespace biblia::basico;

#include "biblia/dinamicas/sinfonia/Estado.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * Aponta para um Estado indicando qual � o campo alvo.
	 * <p>
	 * Por quest�o de otimiza��o e praticidade,
	 * esse EstadoAlvo pode ser tamb�m diretamente
	 * um valor {@link #constante}. � bom salientar
	 * que existem dois tipos de Estado constante: existe
	 * o que pode ser obtido atrav�s da fun��o
	 * {@link MediadorDeEstados#estadoConstante} e a desta
	 * classe. Onde for poss�vel, utilizar o valor constante
	 * diretamente nesta classe pode otimizar a performance
	 * do software, mas n�o � poss�vel us�-la em todos os casos.
	 *
	 * @see Estado
	 */
	class EstadoAlvo: public Objeto, public Copiavel, public Igualavel {
		private:
			const Estado* pEstado;
			Valor pCampo;

		public:

			/**
			 * Cria um EstadoAlvo constante com o valor
			 * passado como par�metro.
			 */
			EstadoAlvo(const Valor& valorConstante);

			/**
			 * Cria um EstadoAlvo apontando para um determinado
			 * Estado e um campo.
			 */
			EstadoAlvo(const Estado* estado, const Valor& campoAlvo);
			
			/**
			 * Utiliza {@link Multifuncional#CAMPO_PRINCIPAL}
			 * como padr�o.
			 */
			explicit EstadoAlvo(const Estado* estado);

			/**
			 * Por quest�o de compatibilidade com listas e hashes.
			 * N�o � poss�vel manipular
			 * um EstadoAlvo com o Estado NULL.
			 */
			EstadoAlvo():pEstado(NULL), pCampo(Valor("ERRO", true)) {}

			virtual ~EstadoAlvo();

			/**
			 * Significa que este EstadoAlvo � um valor
			 * constante.
			 */
			virtual const bool constante() const;
			
			/**
			 * Nome do campo que este EstadoAlvo referencia. Deve
			 * ser usado em conjunto com {@link estado}.
			 */
			virtual const Valor& campoAlvo() const;

			/**
			 * Estado que este EstadoAlvo referencia. Deve
			 * ser usado em conjunto com {@link #campoAlvo}.
			 */
			virtual const Estado& estado() const;

			/**
			 * Valor do campo do Estado alvo.
			 */
			virtual const Valor valorAlvo() const;

			// Copiavel:
			virtual Objeto* geraCopia() const;
			virtual Copiavel& copiaEmSi(const Copiavel& alheio);

			// Igualavel:
			/**
			 * � igual se aponta para o mesmo {@link Estado}
			 * e para o mesmo {@link #campoAlvo campo do Estado}.
			 * <i>Obs.: n�o compara os valores dos Estados!</i>
			 */
			virtual const bool igual(const Igualavel& alheio) const;

			// Objeto:
			/**
			 * Retorna ">>[nome-do-estado].campo(valor)"
			 */
			virtual string emString() const;
	};
  }
 }
}

#endif // !defined(AFX_ESTADOALVO_H__D99ABA99_F8CF_4D06_9EE0_AC9D8F301E97__INCLUDED_)
