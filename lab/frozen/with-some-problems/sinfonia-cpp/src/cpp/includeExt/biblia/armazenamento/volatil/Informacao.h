/*
 * $RCSfile: Informacao.h,v $
 * $Date: 2004/02/11 23:28:52 $
 * $Revision: 1.11 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Informacao_h)
#define Informacao_h

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include "biblia/basico/Objeto.h"
#include "biblia/basico/Interface.h"
#include "biblia/basico/Identificacao.h"
#include "biblia/armazenamento/volatil/Tipo.h"
#include "biblia/armazenamento/volatil/VolatilExcecao.h"

using namespace biblia::basico;

namespace biblia {
  namespace armazenamento {
    namespace volatil {

		/**
		 * Representa qualquer tipo de Informa��o.
		 * Uma informa��o pode ser <i>indefinida</i>.
		 * <p>
		 * A leitura/manipula��o varia de Informa��o
		 * para Informa��o, portanto � importante
		 * que se conhe�a o tipo final da Informa��o.
		 * <p>
		 * � tamb�m muito importante que qualquer
		 * classe filha conhe�a esta classe muito
		 * bem pois ela cont�m algumas particularidades
		 * em rela��o a defini��o/indefini��o da informa��o
		 * e outras.
		 *
		 * @see InformacaoRestrita
		 */
		class Informacao: public Interface, public Objeto {		
			private:
				bool Informacao::pIndefinido;

			protected:
				/**
				 * � uma informa��o 'tipada' de
				 * qualquer coisa. Pode estar
				 * definida ou indefinida e
				 * por padr�o inicia indefinida.
				 * <p>
				 * A princ�pio o tipo
				 * da informa��o � o pr�prio
				 * typeid da classe.
				 * <p>
				 * N�o faz sentido uma
				 * inst�ncia de Informacao (sem
				 * ser uma classe filha).
				 */
				Informacao::Informacao();

				/**
				 * N�o faz sentido uma
				 * inst�ncia de Informacao (sem
				 * ser uma classe filha).
				 */
				Informacao::Informacao(const Informacao&);

				/**
				 * A classe filha deve informar a esta
				 * assim que ela se definir.
				 */
				virtual Informacao& Informacao::definiu();

				/**
				 * Deve ser chamado toda vez que o valor
				 * da informa��o for retornado.
				 *
				 * @throws InformacaoNaoDefinidaExcecao
				 */
				virtual void Informacao
						::verificaSeInformacaoEstaDefinidaAntesDeRetornarOValor() const;

			public:
				virtual Informacao::~Informacao();

				/**
				 * Retorna uma identifica��o �nica relativa ao
				 * tipo desta informa��o.
				 */
				virtual const Tipo Informacao::tipo() const;

				/**
				 * Verifica se a outra informa��o
				 * � do mesmo tipo.
				 */
				virtual const bool Informacao::mesmoTipo(
						const Informacao& i) const
				{
					return this->mesmoTipo(i.tipo());
				}

				virtual const bool Informacao::mesmoTipo(
						const Tipo&) const;

				/**
				 * Diz se � indefinido ou desconhecido.
				 * <p>
				 * Se for indefinido, isso prevalece sobre
				 * qualquer valor que esta informa��o
				 * possa conter.
				 */
				virtual const bool Informacao::indefinida() const;
				virtual const bool Informacao::definida() const {
					return !this->indefinida();
				}

				/**
				 * For�a essa informa��o a ser indefinida.
				 */
				virtual Informacao& Informacao::indefine();
		};
	}
  }
}

#endif /* Informacao_h */
