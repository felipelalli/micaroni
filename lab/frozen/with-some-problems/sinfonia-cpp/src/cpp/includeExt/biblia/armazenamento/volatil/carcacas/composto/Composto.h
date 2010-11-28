/*
 * $RCSfile: Composto.h,v $
 * $Date: 2004/07/13 21:13:31 $
 * $Revision: 1.6 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
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
			 * � uma 'inst�ncia' de uma
			 * DefinicaoDeComposto.
			 * <p>
			 * Um Composto � um conjunto de atributos
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
					 * O tamanho desse Mapa ser� fixo
					 * ap�s a defini��o desta classe pelo
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
					 * Retorna a defini��o deste
					 * composto. �til para consultar
					 * os campos (id/tipos).
					 */
					virtual const DefinicaoDeComposto&
							Composto::definicao() const;

					/**
					 * Retorna um conjunto de pares
					 * id/informa��o.
					 * <p>
					 * nota: <i>Cuidado com esta fun��o pois ela pode
					 * ser lenta (cria a lista em tempo de
					 * execu��o). Pode ser muito �til
					 * quando � chamada fora de um loop.</i>
					 *
					 * @return Deve ser deletado de fora.
					 */
					virtual Lista<InformacaoIdentificada>*
							Composto::composicao() const;

					/**
					 * Retorna a informa��o relativa
					 * ao campo pedido.
					 * <p>
					 * Nota: <i>Esta informa��o pode
					 * estar indefinida (estado
					 * de Informacao)!</i>
					 *
					 * @throws CampoNaoExistenteExcecao
					 */
					virtual Informacao& Composto
							::informacao(const Identificacao&
								campo);

					/**
					 * Retorna a informa��o relativa
					 * ao campo pedido para consulta.
					 * <p>
					 * Nota: <i>Esta informa��o pode
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
					 * este composto cont�m e inclusive
					 * ele mesma, atribuindo NULL em
					 * seguida para o ponteiro.
					 *
					 * @return true se queimou com
					 *         sucesso e false caso
					 *         contr�rio.
					 *
					static const bool queima(Composto*&);
					*/

					// Informa��o:
					virtual const Tipo Composto::tipo() const {
						return Composto::tipoEstatico();
					}

					static Tipo Composto::tipoEstatico() {
						return Tipo(Composto::TIPO);
					}

					// Objeto:

					/**
					 * Representa esta classe 'visualmente'
					 * para efeitos de debug. Para identific�-la
					 * utilize #definicao().
					 * <p>
					 * Nota: <i>cuidado ao cham�-la pois
					 * pode causar overhead desnecess�rio!</i>
					 */
					virtual std::string Composto::emString() const;
			};
		}
	  }
	}
  }
}

#endif /* Composto_h */
