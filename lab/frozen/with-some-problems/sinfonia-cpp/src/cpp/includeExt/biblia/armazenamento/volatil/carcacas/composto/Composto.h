/*
 * $RCSfile: Composto.h,v $
 * $Date: 2004/07/13 21:13:31 $
 * $Revision: 1.6 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Composto_h)
#define Composto_h

#include "biblia/armazenamento/volatil/InformacaoConteiner.h"
#include "biblia/armazenamento/volatil/carcacas/MapaHash.h"
#include "biblia/armazenamento/volatil/carcacas/Lista.h"
#include "biblia/armazenamento/volatil/carcacas/composto/DefinicaoDeComposto.h"
#include "biblia/armazenamento/volatil/carcacas/composto/InformacaoIdentificada.h"
#include "biblia/armazenamento/volatil/carcacas/composto/ConhecedorDeCompostos.h"

using namespace biblia::armazenamento::volatil;
using namespace biblia::armazenamento::volatil::carcacas;

namespace biblia {
  namespace armazenamento {
    namespace volatil {
	  namespace carcacas {
	    namespace composto {
			class DefinicaoDeComposto;
			class ConhecedorDeCompostos;

			/**
			 * É uma 'instância' de uma
			 * DefinicaoDeComposto.
			 * <p>
			 * Um Composto é um conjunto de atributos
			 * (valores tipados identificados) podendo
			 * ser composto por qualquer Informacao,
			 * inclusive outros Compostos.
			 *
			 * @see ConhecedorDeCompostos
			 * @see DefinicaoDeComposto
			 */
			class Composto: public InformacaoConteiner {
				friend class ConhecedorDeCompostos;

				private:
					/**
					 * O tamanho desse Mapa será fixo
					 * após a definição desta classe pelo
					 * ConhecedorDeCompostos.
					 */
					MapaHash<Informacao*> Composto::pComposicao;
					const DefinicaoDeComposto* Composto::pDefinicao;
					static Tipo Composto::TIPO;

				protected:
					/**
					 * Somente um ConhecedorDeCompostos
					 * sabe construir um composto.
					 */
					Composto::Composto(const Lista
							<InformacaoIdentificada>&,
							const DefinicaoDeComposto& ddc);

				public:
					virtual Composto::~Composto();

					/**
					 * Retorna a definição deste
					 * composto. Útil para consultar
					 * os campos (id/tipos).
					 */
					virtual const DefinicaoDeComposto&
							Composto::definicao() const;

					/**
					 * Retorna um conjunto de pares
					 * id/informação.
					 * <p>
					 * nota: <i>Cuidado com esta função pois ela pode
					 * ser lenta (cria a lista em tempo de
					 * execução). Pode ser muito útil
					 * quando é chamada fora de um loop.</i>
					 *
					 * @return Deve ser deletado de fora.
					 */
					virtual Lista<InformacaoIdentificada>*
							Composto::composicao() const;

					/**
					 * Retorna a informação relativa
					 * ao campo pedido.
					 * <p>
					 * Nota: <i>Esta informação pode
					 * estar indefinida (estado
					 * de Informacao)!</i>
					 *
					 * @throws CampoNaoExistenteExcecao
					 */
					virtual Informacao& Composto
							::informacao(const Identificacao&
								campo);

					/**
					 * Retorna a informação relativa
					 * ao campo pedido para consulta.
					 * <p>
					 * Nota: <i>Esta informação pode
					 * estar indefinida (estado
					 * de Informacao)!</i>
					 *
					 * @throws CampoNaoExistenteExcecao
					 */
					virtual const Informacao& Composto
							::informacao(const Identificacao&
								campo) const;

					// Operadores

					/**
					 * Pode ser usado em alternativa
					 * de informacao(const Identificacao&) const
					 * <p>
					 * Pode ser usado assim:
					 * composto,"campo"
					 */
					virtual const Informacao& Composto
							::operator,(const Identificacao&
								campo) const
					{
						return this->informacao(campo);
					}

					/**
					 * Pode ser usado em alternativa
					 * de informacao(const Identificacao&)
					 * <p>
					 * Pode ser usado assim:
					 * composto,"campo"
					 */
					virtual Informacao& Composto
							::operator,(const Identificacao&
								campo)
					{
						return this->informacao(campo);
					}

					/*
					 * Apaga todos os subelementos que
					 * este composto contém e inclusive
					 * ele mesma, atribuindo NULL em
					 * seguida para o ponteiro.
					 *
					 * @return true se queimou com
					 *         sucesso e false caso
					 *         contrário.
					 *
					static const bool queima(Composto*&);
					*/

					// Informação:
					virtual const Tipo Composto::tipo() const {
						return Composto::tipoEstatico();
					}

					static Tipo Composto::tipoEstatico() {
						return Tipo(Composto::TIPO);
					}

					// Objeto:

					/**
					 * Representa esta classe 'visualmente'
					 * para efeitos de debug. Para identificá-la
					 * utilize #definicao().
					 * <p>
					 * Nota: <i>cuidado ao chamá-la pois
					 * pode causar overhead desnecessário!</i>
					 */
					virtual std::string Composto::emString() const;
			};
		}
	  }
	}
  }
}

#endif /* Composto_h */
