/*
 * $RCSfile: ConhecedorDeCompostos.h,v $
 * $Date: 2004/02/16 23:29:05 $
 * $Revision: 1.3 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
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
		 * Através de um conjunto de instruções
		 * faz operações como criar uma definição
		 * de composto, criar um composto a partir
		 * de uma definição, excluir uma definição
		 * de composto existente etc.
		 * <p>
		 * Essas operações e suas definições
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
		 * Através da função #gera() é possível
		 * resgatar o resultado das instruções.
		 *
		 * O retorno varia dependendo da instrução:
		 * - cria definição de composto: DefinicaoDeComposto*
		 *   que não precisa ser deletado externamente.
		 *
		 * - resgata uma definição de composto: DefinicaoDeComposto*
		 *   também não precisa ser deletado externamente.
		 *
		 * - cria um composto: Composto*
		 *   e precisa ser deletado uma só vez, mesmo que
		 *   a função gera() seja chamada várias vezes seguida.
		 *   Seus elementos <b>não</b> precisam ser deletados porque
		 *   este ConhecedorDeCompostos preenche a lixeira
		 *   da InformacaoConteiner adequadamente. Se quiser
		 *   apagá-los manualmente não se esqueça então de
		 *   reciclar a lixeira.
		 *
		 * - exclui uma definição de composto: NULL
		 * <p>
		 * Perceba que esta classe não é de uso tão simples,
		 * portanto não hesite em dar uma olhada também em
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
				 * Contrói um conhecedor de compostos.
				 * <p>
				 * Lembre-se que antes de usar um
				 * ConhecedorDeCompostos é necessário
				 * definir uma "fábrica dos elementos"
				 * pela função {@link #defineFabricaDosElementos(
				 * FabricaDeInformacao*)} para que este
				 * conhecedor saiba construir os elementos
				 * que ele carrega.
				 */
				ConhecedorDeCompostos::ConhecedorDeCompostos();

				/**
				 * Cuidado ao 'matar' um conhecedor de compostos!
				 * Ele deve sobreviver até o fim do uso de todos
				 * os compostos pois as informações internas
				 * do composto são deletadas quando este
				 * conhecedor de compostos é deletado.
				 */
				virtual ConhecedorDeCompostos::~ConhecedorDeCompostos();

				/*
				 * @param fabricaDosElementos
				 *        Precisa de uma fábrica de informação
				 *        para criar os elementos do Composto.
				 *        Não pode ser NULL. Se o elemento
				 *        for do tipo de alguma definição de
				 *        composto que este conhecedor já
				 *        tem, dá prioridade a este tipo
				 *        antes de tentar usar a fábrica
				 *        dos elementos.
				 */
				virtual ConhecedorDeCompostos& ConhecedorDeCompostos
						::defineFabricaDosElementos(FabricaDeInformacao*
							fabricaDosElementos);

				/**
				 * Verifica se uma Informação é
				 * um tipo composto.
				 */
				static const bool ConhecedorDeCompostos
						::eComposto(const Informacao& i)
				{
					return ConhecedorDeCompostos
							::eComposto(i.tipo());
				}

				/**
				 * Verifica se um 'Tipo' é
				 * um tipo composto.
				 */
				static const bool ConhecedorDeCompostos
						::eComposto(const Tipo&);

				const bool ConhecedorDeCompostos
						::conheceDefinicaoDeComposto(const Tipo&) const;

				// Processador:

				/**
				 * Processa uma instrução que pode gerar
				 * resutado que pode ser resgatado
				 * através da função gera().
				 *
				 * @see #gera()
				 */
				virtual Processador&
						ConhecedorDeCompostos::processa(
							const Instrucao& i);

				// Fabrica:

				/**
				 * É importante entender que esta função
				 * sempre retorna o resultado da última
				 * instrução. Portanto, uma sequencia de
				 * instruções seria interessante somente
				 * no caso onde o resultado pode ser
				 * resgatado num futuro através de outra
				 * instrução.
				 * <p>
				 * Veja na documentação desta classe
				 * quais tipos de retorno devem ser
				 * deletados após o 'resgate'.
				 */
				virtual Objeto* ConhecedorDeCompostos::gera();
		};
	}
   }
  }
 }
}

#endif /* ConhecedorDeCompostos_h */
