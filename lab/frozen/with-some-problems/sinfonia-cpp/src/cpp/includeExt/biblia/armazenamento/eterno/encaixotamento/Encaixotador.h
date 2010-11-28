/*
 * $RCSfile: Encaixotador.h,v $
 * $Date: 2005/01/20 21:28:33 $
 * $Revision: 1.5 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_ENCAIXOTADOR_H__E1691C00_FEE5_477B_8158_9FB35B3BEB6E__INCLUDED_)
#define AFX_ENCAIXOTADOR_H__E1691C00_FEE5_477B_8158_9FB35B3BEB6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/basico/Identificacao.h"
#include "biblia/util/Lixeira.h"
#include "biblia/armazenamento/volatil/Tipo.h"
#include "biblia/armazenamento/volatil/Informacao.h"
#include "biblia/armazenamento/eterno/empacotamento/Caixa.h"

using namespace biblia::basico;
using namespace biblia::util;
using namespace biblia::armazenamento::volatil;
using namespace biblia::armazenamento::eterno::empacotamento;

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace encaixotamento {
		/**
		 * Um Encaixotador serve para encaixotar
		 * mas serve também para armazenar uma
		 * caixa, sendo responsável pela
		 * deleção dos pacotes que ela cria.
		 * <p>
		 * Para informações compostas é necessário
		 * que haja um "encaixotamento" para distribuir
		 * uma mesma informação em diversos pacotes.
		 */
		class Encaixotador: public Objeto {
			private:
				Caixa Encaixotador::pCaixa;
				Lixeira Encaixotador::pPacotesADeletar;
				Encaixotador::Encaixotador(const Encaixotador&);

			protected:
				Encaixotador::Encaixotador();

				/**
				 * Pacotes e PacotesSelados
				 * instanciados internamente.
				 * Esta classe limpa esta lixeira
				 * no destrutor ou quando a função
				 * limpaCaixa(bool = true) é chamada.
				 * <p>
				 * Caso você queira guardar externamente
				 * algum ponteiro da caixa montada, lembre-se
				 * que eles serão deletados quando esta lixeira
				 * for apagada. Portanto, se quiser pegar a
				 * 'responsabilidade' de apagar os pacotes,
				 * 'sugue' os elementos dessa lixeira para si.
				 * Se fizer isso, certifique-se que a sua lixeira
				 * seja apagada após o uso deste encaixotador.
				 * <p>
				 * <i>nota de implementação: esta função (pública)
				 * foi trocada por sugaCaixaParaSi(Encaixotador&)
				 * para garantir que a caixa montada seja apagada
				 * logo após ser passada para outra responsabilidade.
				 * </i>
				 */
				virtual Lixeira& Encaixotador::pacotesADeletar();

				/**
				 * Retorna uma caixa montada pelos
				 * encaixotamentos.
				 * <p>
				 * É protegida porque é 'perigoso' demais e
				 * desnecessário para uso externo.
				 */
				virtual Caixa& Encaixotador::caixaMontadaProtegida();

			public:
				virtual Encaixotador::~Encaixotador();

				/**
				 * Transforma uma informação em um
				 * ou mais pacotes.
				 * <p>
				 * Essa função é responsável por deletar
				 * o pacote que é instanciado internamente.
				 *
				 * @throw EncaixotadorNaoSabeManipularEsseTipoExcecao
				 */
				virtual Encaixotador& Encaixotador
						::encaixota(const Identificacao&,
							const Informacao&) = 0;

				/**
				 * A informação retornada deve ser deletada
				 * lá fora. Esta função não apaga nenhum pacote
				 * selado da caixa: desencaixota mas mantém
				 * uma cópia do pacote na caixa. Para "sumir
				 * com o pacote" use a função
				 * {@link #someComPacote(const Identificacao&)}.
				 * <p>
				 * <i>Nota adicional:
				 * Se a Informacao for do tipo InformacaoConteiner,
				 * a implementação deve preferencialmente, por
				 * questão de padrão, adicionar os elementos
				 * internos na lixeira da InformacaoConteiner.
				 * Se a implementação seguir este padrão aqui
				 * definido, <b>não</b> apague os elementos
				 * da InformacaoConteiner porque
				 * eles já estarão "pendurados" na lixeira
				 * que a InformacaoConteiner carrega. Se você
				 * desejar apagar manualmente esses elementos,
				 * não se esqueça de então reciclá-los antes
				 * de apagá-los. --- Fica aqui definido que
				 * se na documentação da implementação
				 * específica nada estiver mudando
				 * o que esta nota diz, esta nota é válida.
				 * </i>
				 *
				 * @throw EncaixotadorNaoSabeManipularEsseTipoExcecao
				 * @throw InformacaoNaoEncaixotadaExcecao
				 */
				virtual Informacao* Encaixotador
						::desencaixota(const Identificacao&) = 0;

				/**
				 * Verifica se este encaixotador genérico
				 * sabe encaixotar este tipo.
				 */
				virtual const bool Encaixotador
						::sabeEncaixotar(const Tipo&) const = 0;

				/**
				 * Some com pacote da caixa e deleta
				 * da lixeira.
				 *
				 * @throw InformacaoNaoEncaixotadaExcecao
				 */
				virtual Encaixotador& Encaixotador
						::someComPacote(const Identificacao&);

				/**
				 * Por padrão, quem sabe encaixotar sabe também
				 * desencaixotar. Porém, adapte esta função
				 * caso seja necessário.
				 */
				virtual const bool Encaixotador
						::sabeDesencaixotar(const Tipo& t) const
				{
					return this->sabeEncaixotar(t);
				}

				/**
				 * Apaga os pacotes da caixa
				 * montada e por padrão
				 * limpa a lixeira.
				 */
				virtual Encaixotador& Encaixotador
						::limpaCaixa(const bool&
								apagandoLixeira = true);

				/**
				 * Retorna uma caixa montada pelos
				 * encaixotamentos, somente leitura.
				 */
				virtual const Caixa& Encaixotador::caixaMontada() const;

				/**
				 * Repassa a responsabilidade de manter
				 * a caixa de outro encaixotador para si.
				 * <p>
				 * <i>internamente: Repassa a lixeira e apaga
				 * a caixa do outro encaixotador.</i>
				 */
				virtual Encaixotador& Encaixotador
						::sugaCaixaParaSi(Encaixotador&
								encaixotadorQueSeraSugado);

				/**
				 * Acrescenta uma caixa alheia a si.
				 * Porém a responsabilidade de "deleção"
				 * fica para quem criou a caixa alheia.
				 * <p>
				 * <b>Cuidado!</b>: É importante que
				 * este encaixotador 'morra'
				 * ou seja limpado antes que
				 * os elementos da caixa alheia sejam
				 * deletados.
				 */
				virtual Encaixotador& Encaixotador
						::acrescentaEmSi(const Caixa&);

				// Objeto:
				virtual std::string Encaixotador::emString() const;
		};
	  }
	}
  }
}

#endif // !defined(AFX_ENCAIXOTADOR_H__E1691C00_FEE5_477B_8158_9FB35B3BEB6E__INCLUDED_)
