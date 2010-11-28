/*
 * $RCSfile: ConhecedorDeCompostos.h,v $
 * $Date: 2004/02/16 23:29:05 $
 * $Revision: 1.3 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(ConhecedorDeCompostos_h)
#define ConhecedorDeCompostos_h

#include "biblia/basico/Fabrica.h"
#include "biblia/util/Lixeira.h"
#include "biblia/util/UtilExcecao.h"
#include "biblia/util/instrucoes/Instrucao.h"
#include "biblia/util/instrucoes/Processador.h"
#include "biblia/armazenamento/volatil/FabricaDeInformacao.h"
#include "biblia/armazenamento/volatil/carcacas/MapaHash.h"
#include "biblia/armazenamento/volatil/carcacas/composto/Composto.h"
#include "biblia/armazenamento/volatil/carcacas/composto/DefinicaoDeComposto.h"
#include "biblia/armazenamento/volatil/carcacas/composto/instrucoes/CriaComposto.h"
#include "biblia/armazenamento/volatil/carcacas/composto/instrucoes/CriaDefinicaoDeComposto.h"
#include "biblia/armazenamento/volatil/carcacas/composto/instrucoes/ExcluiDefinicaoDeComposto.h"
#include "biblia/armazenamento/volatil/carcacas/composto/instrucoes/ResgataDefinicaoDeComposto.h"

using namespace biblia::basico;
using namespace biblia::util;
using namespace biblia::util::instrucoes;
using namespace biblia::armazenamento::volatil;
using namespace biblia::armazenamento::volatil::carcacas;
using namespace biblia::armazenamento::volatil::carcacas::composto::instrucoes;

namespace biblia {
 namespace armazenamento {
  namespace volatil {
   namespace carcacas {
    namespace composto {
		class Composto;
		class DefinicaoDeComposto;

		/**
		 * Atrav�s de um conjunto de instru��es
		 * faz opera��es como criar uma defini��o
		 * de composto, criar um composto a partir
		 * de uma defini��o, excluir uma defini��o
		 * de composto existente etc.
		 * <p>
		 * Essas opera��es e suas defini��es
		 * podem ser encontradas no pacote
		 * biblia::armazenamento::volatil::primitivos::composto::instrucoes
		 * <p>
		 * Exemplo de uso:
		 * <code>
		 * ConhecedorDeCompostos cdc;
		 * cdc.processa(CriaComposto(carro));
		 * Composto* novoCarro = (Composto*) cdc.gera();
		 * </code>
		 * <p>
		 * Atrav�s da fun��o #gera() � poss�vel
		 * resgatar o resultado das instru��es.
		 *
		 * O retorno varia dependendo da instru��o:
		 * - cria defini��o de composto: DefinicaoDeComposto*
		 *   que n�o precisa ser deletado externamente.
		 *
		 * - resgata uma defini��o de composto: DefinicaoDeComposto*
		 *   tamb�m n�o precisa ser deletado externamente.
		 *
		 * - cria um composto: Composto*
		 *   e precisa ser deletado uma s� vez, mesmo que
		 *   a fun��o gera() seja chamada v�rias vezes seguida.
		 *   Seus elementos <b>n�o</b> precisam ser deletados porque
		 *   este ConhecedorDeCompostos preenche a lixeira
		 *   da InformacaoConteiner adequadamente. Se quiser
		 *   apag�-los manualmente n�o se esque�a ent�o de
		 *   reciclar a lixeira.
		 *
		 * - exclui uma defini��o de composto: NULL
		 * <p>
		 * Perceba que esta classe n�o � de uso t�o simples,
		 * portanto n�o hesite em dar uma olhada tamb�m em
		 * biblia::armazenamento::volatil::carcacas::composto::FabricaDeComposto
		 * ou em biblia::armazenamento::volatil::FabricaDeInformacoesBasicas
		 *
		 * @see biblia::armazenamento::volatil::primitivos::composto::instrucoes
		 * @see FabricaDeInformacoesBasicas
		 */
		class ConhecedorDeCompostos: public Processador, public Objeto {
			private:
				MapaHash<DefinicaoDeComposto*>
						ConhecedorDeCompostos
							::pDefinicoesDeComposto;

				Objeto* ConhecedorDeCompostos::pUltimoResultado;
				FabricaDeInformacao* ConhecedorDeCompostos
						::pFabricaDosElementos;

			protected:
				virtual FabricaDeInformacao& ConhecedorDeCompostos
						::fabricaDosElementos();

				virtual DefinicaoDeComposto*
						ConhecedorDeCompostos::resgata(
							const Identificacao&);

				virtual ConhecedorDeCompostos&
						ConhecedorDeCompostos::define(
							const Identificacao&,
							DefinicaoDeComposto*);

				virtual DefinicaoDeComposto*
						ConhecedorDeCompostos::criaDefinicaoDeComposto(
							const CriaDefinicaoDeComposto& instrucao);

				virtual DefinicaoDeComposto*
						ConhecedorDeCompostos::resgataDefinicaoDeComposto(
							const ResgataDefinicaoDeComposto& instrucao);

				virtual ConhecedorDeCompostos&
						ConhecedorDeCompostos::excluiDefinicaoDeComposto(
							const ExcluiDefinicaoDeComposto& instrucao);

				virtual Composto* ConhecedorDeCompostos
						::criaComposto(const CriaComposto& instrucao);

			public:
				/**
				 * Contr�i um conhecedor de compostos.
				 * <p>
				 * Lembre-se que antes de usar um
				 * ConhecedorDeCompostos � necess�rio
				 * definir uma "f�brica dos elementos"
				 * pela fun��o {@link #defineFabricaDosElementos(
				 * FabricaDeInformacao*)} para que este
				 * conhecedor saiba construir os elementos
				 * que ele carrega.
				 */
				ConhecedorDeCompostos::ConhecedorDeCompostos();

				/**
				 * Cuidado ao 'matar' um conhecedor de compostos!
				 * Ele deve sobreviver at� o fim do uso de todos
				 * os compostos pois as informa��es internas
				 * do composto s�o deletadas quando este
				 * conhecedor de compostos � deletado.
				 */
				virtual ConhecedorDeCompostos::~ConhecedorDeCompostos();

				/*
				 * @param fabricaDosElementos
				 *        Precisa de uma f�brica de informa��o
				 *        para criar os elementos do Composto.
				 *        N�o pode ser NULL. Se o elemento
				 *        for do tipo de alguma defini��o de
				 *        composto que este conhecedor j�
				 *        tem, d� prioridade a este tipo
				 *        antes de tentar usar a f�brica
				 *        dos elementos.
				 */
				virtual ConhecedorDeCompostos& ConhecedorDeCompostos
						::defineFabricaDosElementos(FabricaDeInformacao*
							fabricaDosElementos);

				/**
				 * Verifica se uma Informa��o �
				 * um tipo composto.
				 */
				static const bool ConhecedorDeCompostos
						::eComposto(const Informacao& i)
				{
					return ConhecedorDeCompostos
							::eComposto(i.tipo());
				}

				/**
				 * Verifica se um 'Tipo' �
				 * um tipo composto.
				 */
				static const bool ConhecedorDeCompostos
						::eComposto(const Tipo&);

				const bool ConhecedorDeCompostos
						::conheceDefinicaoDeComposto(const Tipo&) const;

				// Processador:

				/**
				 * Processa uma instru��o que pode gerar
				 * resutado que pode ser resgatado
				 * atrav�s da fun��o gera().
				 *
				 * @see #gera()
				 */
				virtual Processador&
						ConhecedorDeCompostos::processa(
							const Instrucao& i);

				// Fabrica:

				/**
				 * � importante entender que esta fun��o
				 * sempre retorna o resultado da �ltima
				 * instru��o. Portanto, uma sequencia de
				 * instru��es seria interessante somente
				 * no caso onde o resultado pode ser
				 * resgatado num futuro atrav�s de outra
				 * instru��o.
				 * <p>
				 * Veja na documenta��o desta classe
				 * quais tipos de retorno devem ser
				 * deletados ap�s o 'resgate'.
				 */
				virtual Objeto* ConhecedorDeCompostos::gera();
		};
	}
   }
  }
 }
}

#endif /* ConhecedorDeCompostos_h */
