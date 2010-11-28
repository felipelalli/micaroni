/*
 * $RCSfile: Informacao.h,v $
 * $Date: 2004/02/11 23:28:52 $
 * $Revision: 1.11 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
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
		 * Representa qualquer tipo de Informação.
		 * Uma informação pode ser <i>indefinida</i>.
		 * <p>
		 * A leitura/manipulação varia de Informação
		 * para Informação, portanto é importante
		 * que se conheça o tipo final da Informação.
		 * <p>
		 * É também muito importante que qualquer
		 * classe filha conheça esta classe muito
		 * bem pois ela contém algumas particularidades
		 * em relação a definição/indefinição da informação
		 * e outras.
		 *
		 * @see InformacaoRestrita
		 */
		class Informacao: public Interface, public Objeto {		
			private:
				bool Informacao::pIndefinido;

			protected:
				/**
				 * É uma informação 'tipada' de
				 * qualquer coisa. Pode estar
				 * definida ou indefinida e
				 * por padrão inicia indefinida.
				 * <p>
				 * A princípio o tipo
				 * da informação é o próprio
				 * typeid da classe.
				 * <p>
				 * Não faz sentido uma
				 * instância de Informacao (sem
				 * ser uma classe filha).
				 */
				Informacao::Informacao();

				/**
				 * Não faz sentido uma
				 * instância de Informacao (sem
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
				 * da informação for retornado.
				 *
				 * @throws InformacaoNaoDefinidaExcecao
				 */
				virtual void Informacao
						::verificaSeInformacaoEstaDefinidaAntesDeRetornarOValor() const;

			public:
				virtual Informacao::~Informacao();

				/**
				 * Retorna uma identificação única relativa ao
				 * tipo desta informação.
				 */
				virtual const Tipo Informacao::tipo() const;

				/**
				 * Verifica se a outra informação
				 * é do mesmo tipo.
				 */
				virtual const bool Informacao::mesmoTipo(
						const Informacao& i) const
				{
					return this->mesmoTipo(i.tipo());
				}

				virtual const bool Informacao::mesmoTipo(
						const Tipo&) const;

				/**
				 * Diz se é indefinido ou desconhecido.
				 * <p>
				 * Se for indefinido, isso prevalece sobre
				 * qualquer valor que esta informação
				 * possa conter.
				 */
				virtual const bool Informacao::indefinida() const;
				virtual const bool Informacao::definida() const {
					return !this->indefinida();
				}

				/**
				 * Força essa informação a ser indefinida.
				 */
				virtual Informacao& Informacao::indefine();
		};
	}
  }
}

#endif /* Informacao_h */
