/*
 * $RCSfile: DefinicaoDeComposto.h,v $
 * $Date: 2005/01/20 21:28:37 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
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
			 * Uma defini��o de composto � a carca�a,
			 * esqueleto ou tipo de um Composto.
			 *
			 * (o que estiver entre chaves � uma Identificacao)
			 * Exemplo de uma defini��o de composto:
			 *
			 * {"Composto:Pessoa"} (seria o seu typeid ou sua
			 * Identifica��o):
			 *
			 * - {"idade"}, [Informa��o]{"Inteiro"}
			 * - {"cor do cabelo"}, [Informa��o]{"Composto:Cabelo"}
			 * - {"nome"}, [Informa��o]{"String"}
			 */
			class DefinicaoDeComposto: public Objeto {
				friend class ConhecedorDeCompostos;

				private:
					/**
					 * Identifica��o �nica desta
					 * defini��o de composto no universo.
					 */
					Identificacao DefinicaoDeComposto
							::pIdentificadoPor;

//					const DefinicaoDeComposto*
//							DefinicaoDeComposto
//								::pHerdaDe; // recurs�o

					/**
					 * O tamanho desse Mapa ser� fixo
					 * ap�s a defini��o desta classe pelo
					 * ConhecedorDeCompostos.
					 */
					MapaHash<Tipo*> DefinicaoDeComposto
							::pComposicao;

					bool DefinicaoDeComposto::pAberto;
					bool DefinicaoDeComposto::pFechado;

					/**
					 * C�pia proibida pois cont�m ponteiros
					 * e pode ser 'perigoso' demais al�m
					 * de n�o fazer sentido uma c�pia de uma
					 * defini��o de composto.
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
					 *         Verifica se n�o h�
					 *         recurs�o nas heran�as
					 *		   e lan�a a exce��o caso
					 *         esteja em loop.
					 *
					 * @throws CampoJaExistenteExcecao
					 *         Quando houver conflitos
					 *         de nome entre a hierarquia
					 *         ou quando j� houver um
					 *         'Composto pai' definido
					 *         anteriormente.
					 *
					 * @throws CompostoNaoAbertoExcecao
					 *         � necess�rio que este composto
					 *         esteja aberto para receber
					 *         essa instru��o.
					 */
				//	virtual DefinicaoDeComposto& DefinicaoDeComposto
				//			::herdaDe(const DefinicaoDeComposto*);
				// TODO, FIXME

					/**
					 * Cria um campo com uma informa��o
					 * indefinida.
					 *
					 * @param doCampo Identifica��o do
					 *        campo deste composto. � a
					 *        chave pelo qual a informa��o
					 *        ser� acessada.
					 *
					 * @param doTipo Tipo que deve ser
					 *        previamente conhecido
					 *        pelo ConhecedorDeCompostos.
					 *        Lembre-se que nesse caso e
					 *        no caso da heran�a a ordem
					 *        de cria��o dos compostos
					 *        � importante.
					 *
					 * @throws CampoJaExistenteExcecao
					 *         � lan�ado quando j� existe
					 *         um campo com a mesma
					 *		   identifica��o.
					 *
					 * @throws CompostoNaoAbertoExcecao
					 *         � necess�rio que este composto
					 *         esteja aberto para receber
					 *         essa instru��o.
					 */
					virtual DefinicaoDeComposto& DefinicaoDeComposto
							::criaCampo(const Identificacao& doCampo,
										const Tipo& doTipo);

					/**
					 * Remove um campo criado anteriormente.
					 *
					 * Nota: <i><b>Deve ser evitado.</b> Esta
					 * fun��o existe apenas para casos
					 * onde as informa��es para cria��o
					 * do composto est�o ileg�veis ou
					 * inacess�veis e uma poss�vel
					 * exten��o (patch) desse composto
					 * � necess�ria. Lembre-se que apagar
					 * um campo pode gerar in�meras
					 * exce��es de CampoNaoExistenteExcecao
					 * em vers�es antigas.
					 *
					 * @throws CampoNaoExistenteExcecao
					 *
					 * @throws CompostoNaoAbertoExcecao
					 *         � necess�rio que este composto
					 *         esteja aberto para receber
					 *         essa instru��o.
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
					 * at� que seja fechado (#fecha()).
					 */
					virtual DefinicaoDeComposto&
							DefinicaoDeComposto
								::abre();

					/**
					 * Deve ser chamado
					 * ap�s terminar
					 * a 'montagem' de uma defini��o
					 * de composto.
					 * <p>
					 * Um composto permanecer�
					 * indefinido at� que esta
					 * fun��o seja chamada. Ap�s
					 * ela n�o � poss�vel fazer
					 * nenhuma modifica��o a n�o
					 * ser que ele seja 'reaberto'.
					 *
					 * @throws CompostoNaoAbertoExcecao
					 *         � necess�rio que este composto
					 *         esteja aberto para receber
					 *         essa instru��o.
					 */
					virtual DefinicaoDeComposto&
							DefinicaoDeComposto
								::fecha();

				public:
					DefinicaoDeComposto::DefinicaoDeComposto();
					virtual DefinicaoDeComposto::~DefinicaoDeComposto();

					/**
					 * Retorna a identifica��o �nica
					 * desta defini��o de composto no universo.
					 */
					virtual const Identificacao&
							DefinicaoDeComposto::nome() const;

					/**
					 * Utiliza tamb�m (al�m das suas)
					 * a rela��o id/tipo
					 * do composto que herda.
					 *
					 * @throws HerancaNaoDefinidaExcecao
					 *         veja #possuiPai() para
					 *         n�o ocorrer mais esse tipo
					 *         de exce��o.
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
					 * id/tipo da informa��o.
					 * <p>
					 * nota: <i>Cuidado com esta fun��o pois ela pode
					 * ser lenta (cria a lista em tempo de
					 * execu��o). Pode ser muito �til
					 * quando h� um elemento.</i>
					 */
					virtual Lista<TipoIdentificado>
							DefinicaoDeComposto::composicao() const;

					/**
					 * Retorna o tipo da informa��o relativa
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
					 * para efeitos de debug. Para identific�-la
					 * utilize #definicao().
					 * <p>
					 * Nota: <i>cuidado ao cham�-la pois
					 * pode causar overhead desnecess�rio!</i>
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
