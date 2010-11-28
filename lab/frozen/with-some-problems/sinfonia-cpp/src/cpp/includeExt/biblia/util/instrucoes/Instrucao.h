/*
 * $RCSfile: Instrucao.h,v $
 * $Date: 2004/02/11 23:28:52 $
 * $Revision: 1.9 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Instrucao_h)
#define Instrucao_h

#include "biblia/basico/Objeto.h"
#include "biblia/basico/Identificacao.h"
#include "biblia/util/Lixeira.h"
#include "biblia/util/UtilExcecao.h"
#include "biblia/armazenamento/volatil/carcacas/MapaHash.h"
#include "biblia/armazenamento/volatil/carcacas/Lista.h"
#include "biblia/armazenamento/volatil/primitivos/Inteiro.h"

using namespace biblia::basico;
using namespace biblia::util;
using namespace biblia::armazenamento::volatil::carcacas;
using namespace biblia::armazenamento::volatil::primitivos;

namespace biblia {
  namespace util {
    namespace instrucoes {
		/**
		 * � composto de um comando e um
		 * conjunto de par�metros vari�veis.
		 * <p>
		 * Pode ser usado como um mapa:
		 * [comando]
		 * [nome:Ananias]
		 * [idade:18]
		 * [automovel:carro]
		 * [animal:cachorro]
		 * <p>
		 * Ou como uma lista:
		 * [comando]
		 * [0:Ananias]
		 * [1:18]
		 * [2:carro]
		 * [tamanhoSequencial()-1:cachorro]
		 */
		class Instrucao: public Objeto {
			private:
				Identificacao Instrucao::pComando;
				MapaHash<Identificacao> Instrucao::pParametros;
				int Instrucao::pSequencia;

			protected:
				Identificacao Instrucao
						::geraIdentificacaoPraPosicao(
							const Inteiro& posicao) const;

			public:
				Instrucao::Instrucao(
						const Identificacao& comando);

				Instrucao::Instrucao(
						const Instrucao& outra);

				virtual Instrucao::~Instrucao();

				virtual const bool Instrucao
						::mesmoComando(const Instrucao& i) const
				{
					return this->comando().mesma(i.comando());
				}

				/**
				 * Retorna o comando principal.
				 */
				virtual const Identificacao Instrucao::comando() const;

				/**
				 * Acessa o par�metro atrav�s de um nome.
				 *
				 * @throws ParametroInexistenteExcecao
				 */
				virtual const Identificacao Instrucao
						::parametro(const Identificacao&) const;

				/**
				 * Acessa o par�metro atrav�s de um �ndice
				 * sequencia.
				 *
				 * @throws ParametroInexistenteExcecao
				 * @see #tamanhoSequencial()
				 */
				virtual const Identificacao Instrucao
						::parametro(const Inteiro& posicao) const;

				/**
				 * Quantos par�metros existem no total.
				 *
				 * @see #tamanhoSequencial()
				 */
				virtual const int Instrucao
						::quantosParametros() const;

				/**
				 * Retorna todos os nomes par�metros,
				 * informa��o suficiente para capturar
				 * o valor do par�metro.
				 * <p>
				 * Nota: <i>Cuidado ao usar esta fun��o,
				 * ela pode ser lenta! Evite seu uso em
				 * loops.</i>
				 */
				virtual const Lista<Identificacao> Instrucao
						::quaisParametros() const;

				/**
				 * Quantos par�metros sequenciais existem.
				 */
				virtual const int Instrucao
						::tamanhoSequencial() const;

				const bool Instrucao::existe(const Identificacao&
						parametro) const;

				/**
				 * Funciona como uma lista
				 * sequencial. Como se fossem
				 * par�metro 1, 2, 3 etc.
				 */
				virtual Instrucao& Instrucao
						::adiciona(const Identificacao& parametro);

				/**
				 * Define um par�metro atrav�s
				 * de um nome.
				 */
				virtual Instrucao& Instrucao
						::define(const Identificacao& onde,
								const Identificacao& parametro);

				/**
				 * Modifica um par�metro atrav�s
				 * de sua posi��o sequencial.
				 *
				 * @throws ParametroInexistenteExcecao
				 */
				virtual Instrucao& Instrucao
						::modifica(const Inteiro& posicao,
								const Identificacao& parametro);

				// operadores:
				virtual const Identificacao Instrucao
						::operator[](const int& i) const
				{
					return this->parametro(i);
				}

				virtual const Identificacao Instrucao
						::operator[](const Identificacao& i) const
				{
					return this->parametro(i);
				}

				/**
				 * Atribui a si (apagando as informa��es
				 * locais e criando novas baseado nas outras).
				 */
				virtual Instrucao& Instrucao
						::operator=(const Instrucao&);

				// Objeto:

				/**
				 * Retorna: <comando>(nomeParam1:valor,
				 *          nomeParam2:valor, ...)
				 * <p>
				 * Esta fun��o pode ser lenta.
				 */
				virtual std::string Instrucao::emString() const;
		};
	}
  }
}

#endif /* Instrucao_h */
