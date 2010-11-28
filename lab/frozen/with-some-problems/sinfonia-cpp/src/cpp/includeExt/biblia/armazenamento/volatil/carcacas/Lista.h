/*
 * $RCSfile: Lista.h,v $
 * $Date: 2005/01/20 21:28:36 $
 * $Revision: 1.6 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Lista_h)
#define Lista_h

#include <deque>
#include "biblia/basico/Objeto.h"
#include "biblia/armazenamento/volatil/InformacaoConteiner.h"
#include "biblia/armazenamento/volatil/VolatilExcecao.h"
#include "biblia/armazenamento/volatil/primitivos/Inteiro.h"

using namespace std;
using namespace biblia::basico;
using namespace biblia::armazenamento::volatil;
using namespace biblia::armazenamento::volatil::primitivos;

//#include "biblia/util/Debug.h"
//using namespace biblia::util;

namespace biblia {
  namespace armazenamento {
    namespace volatil {
	  namespace carcacas {
		/**
		 * É uma lista indexada (de 0 a N)
		 * genérica de qualquer Objeto.
		 */
		template<class T = Objeto*> class Lista
				:public InformacaoConteiner
		{
			private:
				std::deque<T> Lista::pLista;

 			public:
				/**
				 * Cria uma cópia da lista.
				 */
				Lista<T>(const Lista<T>& l):pLista() {
					if (l.definida()) {
						this->limpa();

						for (int i = 0; i < l.tamanho(); i++) {
							this->adiciona(l[i]);
						}

						this->definiu();
					}
				}

				/**
				 * Cria uma lista com um elemento
				 * inicial l. Existe por questões
				 * práticas quando um parâmetro
				 * necessita de uma lista e você
				 * quer passar um elemento só.
				 */
				Lista<T>(const T& l):pLista() {
					this->adiciona(l);
					this->definiu();
				}

				Lista<T>():pLista() {
					this->definiu();
				}

				virtual ~Lista<T>() {}

				// ver em biblia/doc/rascunhos/códigos-lixo.txt

				/**
				 * Apaga os elementos
				 * desta lista.
				 * <p>
				 * Os elementos internos não são
				 * deletados caso sejam ponteiros.
				 * <del>Use a função queima() se quiser
				 * fazer isso.</del>
				 */
				virtual Lista<T>& limpa() {
					this->pLista.clear();
					return *this;
				}

				/**
				 * Adiciona um elemento à
				 * lista (<i>no final</i> por padrão).
				 */
				virtual Lista<T>& adiciona(const T& o) {
					this->pLista.push_back(o);
					return *this;
				}

				/**
				 * Adiciona no início da lista.
				 */
				virtual Lista<T>& adicionaNoInicio(const T& o) {
					this->pLista.push_front(o);
					return *this;
				}

				/**
				 * Remove o elemento e desloca os outros.
				 */
				virtual Lista<T>& remove(const int& indice) {
					if (indice >= 0
						&& indice < this->tamanho())
					{
						this->pLista.erase(
								this->pLista.begin() + indice);
					} else {
 						IndiceForaDeIntervaloListaExcecao e;
						e << std::string() + "Lista::remove(int indice)"
							+ " Tentando remover registro inexistente! "
							+ Inteiro(indice) + " de "
							+ Inteiro(this->tamanho());

						throw e;
					}

					return *this;
				}

				/**
				 * Evite usar esta função porque
				 * ela retorna um tipo especial
				 * do C++. Sempre que possível
				 * e quando a otimização não for
				 * caso crítico use as funções
				 * definidas nesta classe para
				 * acessar os valores independentementes.
				 * <p>
				 * <i>Nota para o programador:
				 * se faltar alguma função, prefira
				 * implementar aqui ao invés de usar
				 * a do std::deque.</i>
				 */
				virtual const std::deque<T>& emDeque() const {
					return this->pLista;
				}

				/**
				 * @see const std::deque<T>& emDeque() const
				 */
				virtual std::deque<T>& emDeque() {
					return this->pLista;
				}

				/**
				 * @throw IndiceForaDeIntervaloListaExcecao
				 */
				virtual T& operator[](const int& indice) {
					this->verificaSeInformacaoEstaDefinidaAntesDeRetornarOValor();

					if (indice >= 0
						&& indice < this->tamanho())
					{
						return this->pLista[indice];
					} else {
						IndiceForaDeIntervaloListaExcecao e;
						e << std::string() + "Lista::operator[](int indice)"
							+ " Tentando acessar registro inexistente! "
							+ Inteiro(indice) + " de "
							+ Inteiro(this->tamanho()) + ".";

						throw e;
					}
				}

				/**
				 * @throw IndiceForaDeIntervaloListaExcecao
				 */
				virtual const T& operator[](const int& indice) const {
					this->verificaSeInformacaoEstaDefinidaAntesDeRetornarOValor();

					if (indice >= 0
						&& indice < this->tamanho())
					{
						return this->pLista[indice];
					} else {
						IndiceForaDeIntervaloListaExcecao e;
						e << std::string() + "Lista::operator[](int indice)"
							+ " Tentando acessar registro inexistente! "
							+ Inteiro(indice) + " de "
							+ Inteiro(this->tamanho()) + ".";

						throw e;
					}
				}

				virtual const int tamanho() const {
					this->verificaSeInformacaoEstaDefinidaAntesDeRetornarOValor();
					return this->pLista.size();
				}

				virtual const bool vazia() const
						{ return (bool) !tamanho(); }

				/*
				 * Apaga todos os elementos que
				 * esta lista contém e inclusive
				 * ela mesma, atribuindo NULL em
				 * seguida para o ponteiro.
				 *
				 * @return true se queimou com
				 *         sucesso e false caso
				 *         contrário. Esta função
				 *         aceita apenas listas do
				 *         tipo Lista<>.
				 *
				static const bool queima(Lista<>*& lista) {
					try {
						for (int i = 0; i < lista->tamanho(); i++) {
							delete (*lista)[i];
						}

						delete lista;
						lista = NULL;

						return true;
					} catch (...) {
						return false;
					}
				}*/

				// Informação:
				virtual const Tipo tipo() const {
					return Lista<T>::tipoEstatico();
				}

				static const Tipo tipoEstatico() {
					return Tipo("lista<" + std::string(
							typeid(T).name()) + ">");
				}

				// Objeto:
				virtual std::string emString() const {
					if (this->indefinida()) {
						return "-indefinido-";
					} else {
						return std::string("Lista (" + Objeto::emString()
									  + ") de "
									  + Inteiro(this->tamanho())
									  + " elementos.");
					}
				}
		};
	  }
	}
  }
}

#endif /* Lista_h */
