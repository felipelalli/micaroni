/*
 * $RCSfile: DefinicaoDeComposto.h,v $
 * $Date: 2005/01/20 21:28:37 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_DEFINICAODECOMPOSTO_H__863D3D08_2511_45F2_AF54_F0EA5E2AB5E4__INCLUDED_)
#define AFX_DEFINICAODECOMPOSTO_H__863D3D08_2511_45F2_AF54_F0EA5E2AB5E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/basico/Identificacao.h"
#include "biblia/armazenamento/volatil/Tipo.h"
#include "biblia/armazenamento/volatil/VolatilExcecao.h"
#include "biblia/armazenamento/volatil/carcacas/MapaHash.h"
#include "biblia/armazenamento/volatil/carcacas/composto/ConhecedorDeCompostos.h"
#include "biblia/armazenamento/volatil/carcacas/composto/TipoIdentificado.h"

using namespace biblia::basico;
using namespace biblia::armazenamento::volatil;
using namespace biblia::armazenamento::volatil::carcacas;

using namespace biblia::basico;

namespace biblia {
  namespace armazenamento {
    namespace volatil {
	  namespace carcacas {
	    namespace composto {
			class ConhecedorDeCompostos;

			/**
			 * Uma definição de composto é a carcaça,
			 * esqueleto ou tipo de um Composto.
			 *
			 * (o que estiver entre chaves é uma Identificacao)
			 * Exemplo de uma definição de composto:
			 *
			 * {"Composto:Pessoa"} (seria o seu typeid ou sua
			 * Identificação):
			 *
			 * - {"idade"}, [Informação]{"Inteiro"}
			 * - {"cor do cabelo"}, [Informação]{"Composto:Cabelo"}
			 * - {"nome"}, [Informação]{"String"}
			 */
			class DefinicaoDeComposto: public Objeto {
				friend class ConhecedorDeCompostos;

				private:
					/**
					 * Identificação única desta
					 * definição de composto no universo.
					 */
					Identificacao DefinicaoDeComposto
							::pIdentificadoPor;

//					const DefinicaoDeComposto*
//							DefinicaoDeComposto
//								::pHerdaDe; // recursão

					/**
					 * O tamanho desse Mapa será fixo
					 * após a definição desta classe pelo
					 * ConhecedorDeCompostos.
					 */
					MapaHash<Tipo*> DefinicaoDeComposto
							::pComposicao;

					bool DefinicaoDeComposto::pAberto;
					bool DefinicaoDeComposto::pFechado;

					/**
					 * Cópia proibida pois contém ponteiros
					 * e pode ser 'perigoso' demais além
					 * de não fazer sentido uma cópia de uma
					 * definição de composto.
					 */
					DefinicaoDeComposto::DefinicaoDeComposto(
								const DefinicaoDeComposto&)
							:pIdentificadoPor("...") {}

				protected:
 					/**
					 * @see ConhecedorDeCompostos
					 */
					DefinicaoDeComposto::DefinicaoDeComposto(
							const Identificacao&);

					/**
					 * @throws CompostoNaoAbertoExcecao
					 */
					virtual const DefinicaoDeComposto&
							DefinicaoDeComposto
								::deveEstarAberto() const;

					/**
					 * @throws CompostoNaoFechadoExcecao
					 */
					virtual const DefinicaoDeComposto&
							DefinicaoDeComposto
								::deveEstarFechado() const;

					/**
					 * Adiciona os campos do composto 'c'
					 * recursivamente.
					 */
					virtual DefinicaoDeComposto&
							DefinicaoDeComposto
								::adicionaCamposDe(
									const DefinicaoDeComposto* c);

					/* processo de 'montagem' da
					   DefinicaoDeComposto que somente um
					   ConhecedorDeCompostos sabe
					   montar...
					*/

					/**
					 * Define de quem o
					 * composto herda.
					 * <p>
					 * Percorre
					 * os 'pais' adicionando
					 * (imediatamente)
					 * os campos a este.
					 *
					 * @throws HerancaEmLoopExcecao
					 *         Verifica se não há
					 *         recursão nas heranças
					 *		   e lança a exceção caso
					 *         esteja em loop.
					 *
					 * @throws CampoJaExistenteExcecao
					 *         Quando houver conflitos
					 *         de nome entre a hierarquia
					 *         ou quando já houver um
					 *         'Composto pai' definido
					 *         anteriormente.
					 *
					 * @throws CompostoNaoAbertoExcecao
					 *         É necessário que este composto
					 *         esteja aberto para receber
					 *         essa instrução.
					 */
				//	virtual DefinicaoDeComposto& DefinicaoDeComposto
				//			::herdaDe(const DefinicaoDeComposto*);
				// TODO, FIXME

					/**
					 * Cria um campo com uma informação
					 * indefinida.
					 *
					 * @param doCampo Identificação do
					 *        campo deste composto. É a
					 *        chave pelo qual a informação
					 *        será acessada.
					 *
					 * @param doTipo Tipo que deve ser
					 *        previamente conhecido
					 *        pelo ConhecedorDeCompostos.
					 *        Lembre-se que nesse caso e
					 *        no caso da herança a ordem
					 *        de criação dos compostos
					 *        é importante.
					 *
					 * @throws CampoJaExistenteExcecao
					 *         É lançado quando já existe
					 *         um campo com a mesma
					 *		   identificação.
					 *
					 * @throws CompostoNaoAbertoExcecao
					 *         É necessário que este composto
					 *         esteja aberto para receber
					 *         essa instrução.
					 */
					virtual DefinicaoDeComposto& DefinicaoDeComposto
							::criaCampo(const Identificacao& doCampo,
										const Tipo& doTipo);

					/**
					 * Remove um campo criado anteriormente.
					 *
					 * Nota: <i><b>Deve ser evitado.</b> Esta
					 * função existe apenas para casos
					 * onde as informações para criação
					 * do composto estão ilegíveis ou
					 * inacessíveis e uma possível
					 * extenção (patch) desse composto
					 * é necessária. Lembre-se que apagar
					 * um campo pode gerar inúmeras
					 * exceções de CampoNaoExistenteExcecao
					 * em versões antigas.
					 *
					 * @throws CampoNaoExistenteExcecao
					 *
					 * @throws CompostoNaoAbertoExcecao
					 *         É necessário que este composto
					 *         esteja aberto para receber
					 *         essa instrução.
					 */
					virtual DefinicaoDeComposto&
							DefinicaoDeComposto
								::removeCampo(
									const Identificacao& doCampo);

					/**
					 * Deve ser chamado
					 * antes de se iniciar
					 * a 'montagem' de um composto.
					 * <p>
					 * Torna este composto 'indefinido'
					 * até que seja fechado (#fecha()).
					 */
					virtual DefinicaoDeComposto&
							DefinicaoDeComposto
								::abre();

					/**
					 * Deve ser chamado
					 * após terminar
					 * a 'montagem' de uma definição
					 * de composto.
					 * <p>
					 * Um composto permanecerá
					 * indefinido até que esta
					 * função seja chamada. Após
					 * ela não é possível fazer
					 * nenhuma modificação a não
					 * ser que ele seja 'reaberto'.
					 *
					 * @throws CompostoNaoAbertoExcecao
					 *         É necessário que este composto
					 *         esteja aberto para receber
					 *         essa instrução.
					 */
					virtual DefinicaoDeComposto&
							DefinicaoDeComposto
								::fecha();

				public:
					DefinicaoDeComposto::DefinicaoDeComposto();
					virtual DefinicaoDeComposto::~DefinicaoDeComposto();

					/**
					 * Retorna a identificação única
					 * desta definição de composto no universo.
					 */
					virtual const Identificacao&
							DefinicaoDeComposto::nome() const;

					/**
					 * Utiliza também (além das suas)
					 * a relação id/tipo
					 * do composto que herda.
					 *
					 * @throws HerancaNaoDefinidaExcecao
					 *         veja #possuiPai() para
					 *         não ocorrer mais esse tipo
					 *         de exceção.
					 */
//					virtual const DefinicaoDeComposto&
//							DefinicaoDeComposto::herdaDe() const;

					/**
					 * Retorna verdadeiro caso
					 * um 'Composto pai'
					 * foi definido anteriormente.
					 *
					 * @see #herdaDe()
					 */
//					virtual const bool DefinicaoDeComposto
//							::possuiPai() const;

					/**
					 * Retorna um conjunto de pares
					 * id/tipo da informação.
					 * <p>
					 * nota: <i>Cuidado com esta função pois ela pode
					 * ser lenta (cria a lista em tempo de
					 * execução). Pode ser muito útil
					 * quando há um elemento.</i>
					 */
					virtual Lista<TipoIdentificado>
							DefinicaoDeComposto::composicao() const;

					/**
					 * Retorna o tipo da informação relativa
					 * ao campo pedido para consulta.
					 *
					 * @throws CampoNaoExistenteExcecao
					 */
					virtual const Tipo&
							DefinicaoDeComposto
								::informacao(const Identificacao&
									campo) const;

					// Objeto:

					/**
					 * Representa esta classe 'visualmente'
					 * para efeitos de debug. Para identificá-la
					 * utilize #definicao().
					 * <p>
					 * Nota: <i>cuidado ao chamá-la pois
					 * pode causar overhead desnecessário!</i>
					 */
					virtual std::string DefinicaoDeComposto
							::emString() const;
			};
		}
	  }
	}
  }
}

#endif // !defined(AFX_DEFINICAODECOMPOSTO_H__863D3D08_2511_45F2_AF54_F0EA5E2AB5E4__INCLUDED_)
