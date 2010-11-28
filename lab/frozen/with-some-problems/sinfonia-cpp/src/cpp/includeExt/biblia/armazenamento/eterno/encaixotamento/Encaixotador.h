/*
 * $RCSfile: Encaixotador.h,v $
 * $Date: 2005/01/20 21:28:33 $
 * $Revision: 1.5 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
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
		 * mas serve tamb�m para armazenar uma
		 * caixa, sendo respons�vel pela
		 * dele��o dos pacotes que ela cria.
		 * <p>
		 * Para informa��es compostas � necess�rio
		 * que haja um "encaixotamento" para distribuir
		 * uma mesma informa��o em diversos pacotes.
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
				 * no destrutor ou quando a fun��o
				 * limpaCaixa(bool = true) � chamada.
				 * <p>
				 * Caso voc� queira guardar externamente
				 * algum ponteiro da caixa montada, lembre-se
				 * que eles ser�o deletados quando esta lixeira
				 * for apagada. Portanto, se quiser pegar a
				 * 'responsabilidade' de apagar os pacotes,
				 * 'sugue' os elementos dessa lixeira para si.
				 * Se fizer isso, certifique-se que a sua lixeira
				 * seja apagada ap�s o uso deste encaixotador.
				 * <p>
				 * <i>nota de implementa��o: esta fun��o (p�blica)
				 * foi trocada por sugaCaixaParaSi(Encaixotador&)
				 * para garantir que a caixa montada seja apagada
				 * logo ap�s ser passada para outra responsabilidade.
				 * </i>
				 */
				virtual Lixeira& Encaixotador::pacotesADeletar();

				/**
				 * Retorna uma caixa montada pelos
				 * encaixotamentos.
				 * <p>
				 * � protegida porque � 'perigoso' demais e
				 * desnecess�rio para uso externo.
				 */
				virtual Caixa& Encaixotador::caixaMontadaProtegida();

			public:
				virtual Encaixotador::~Encaixotador();

				/**
				 * Transforma uma informa��o em um
				 * ou mais pacotes.
				 * <p>
				 * Essa fun��o � respons�vel por deletar
				 * o pacote que � instanciado internamente.
				 *
				 * @throw EncaixotadorNaoSabeManipularEsseTipoExcecao
				 */
				virtual Encaixotador& Encaixotador
						::encaixota(const Identificacao&,
							const Informacao&) = 0;

				/**
				 * A informa��o retornada deve ser deletada
				 * l� fora. Esta fun��o n�o apaga nenhum pacote
				 * selado da caixa: desencaixota mas mant�m
				 * uma c�pia do pacote na caixa. Para "sumir
				 * com o pacote" use a fun��o
				 * {@link #someComPacote(const Identificacao&)}.
				 * <p>
				 * <i>Nota adicional:
				 * Se a Informacao for do tipo InformacaoConteiner,
				 * a implementa��o deve preferencialmente, por
				 * quest�o de padr�o, adicionar os elementos
				 * internos na lixeira da InformacaoConteiner.
				 * Se a implementa��o seguir este padr�o aqui
				 * definido, <b>n�o</b> apague os elementos
				 * da InformacaoConteiner porque
				 * eles j� estar�o "pendurados" na lixeira
				 * que a InformacaoConteiner carrega. Se voc�
				 * desejar apagar manualmente esses elementos,
				 * n�o se esque�a de ent�o recicl�-los antes
				 * de apag�-los. --- Fica aqui definido que
				 * se na documenta��o da implementa��o
				 * espec�fica nada estiver mudando
				 * o que esta nota diz, esta nota � v�lida.
				 * </i>
				 *
				 * @throw EncaixotadorNaoSabeManipularEsseTipoExcecao
				 * @throw InformacaoNaoEncaixotadaExcecao
				 */
				virtual Informacao* Encaixotador
						::desencaixota(const Identificacao&) = 0;

				/**
				 * Verifica se este encaixotador gen�rico
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
				 * Por padr�o, quem sabe encaixotar sabe tamb�m
				 * desencaixotar. Por�m, adapte esta fun��o
				 * caso seja necess�rio.
				 */
				virtual const bool Encaixotador
						::sabeDesencaixotar(const Tipo& t) const
				{
					return this->sabeEncaixotar(t);
				}

				/**
				 * Apaga os pacotes da caixa
				 * montada e por padr�o
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
				 * Por�m a responsabilidade de "dele��o"
				 * fica para quem criou a caixa alheia.
				 * <p>
				 * <b>Cuidado!</b>: � importante que
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
