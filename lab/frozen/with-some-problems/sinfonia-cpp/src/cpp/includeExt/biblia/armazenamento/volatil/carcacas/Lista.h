/*
 * $RCSfile: Lista.h,v $
 * $Date: 2005/01/20 21:28:36 $
 * $Revision: 1.6 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
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
		 * � uma lista indexada (de 0 a N)
		 * gen�rica de qualquer Objeto.
		 */
		template<class T = Objeto*> class Lista
				:public InformacaoConteiner
		{
			private:
				std::deque<T> Lista::pLista;

 			public:
				/**
				 * Cria uma c�pia da lista.
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
				 * inicial l. Existe por quest�es
				 * pr�ticas quando um par�metro
				 * necessita de uma lista e voc�
				 * quer passar um elemento s�.
				 */
				Lista<T>(const T& l):pLista() {
					this->adiciona(l);
					this->definiu();
				}

				Lista<T>():pLista() {
					this->definiu();
				}

				virtual ~Lista<T>() {}

				// ver em biblia/doc/rascunhos/c�digos-lixo.txt

				/**
				 * Apaga os elementos
				 * desta lista.
				 * <p>
				 * Os elementos internos n�o s�o
				 * deletados caso sejam ponteiros.
				 * <del>Use a fun��o queima() se quiser
				 * fazer isso.</del>
				 */
				virtual Lista<T>& limpa() {
					this->pLista.clear();
					return *this;
				}

				/**
				 * Adiciona um elemento �
				 * lista (<i>no final</i> por padr�o).
				 */
				virtual Lista<T>& adiciona(const T& o) {
					this->pLista.push_back(o);
					return *this;
				}

				/**
				 * Adiciona no in�cio da lista.
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
				 * Evite usar esta fun��o porque
				 * ela retorna um tipo especial
				 * do C++. Sempre que poss�vel
				 * e quando a otimiza��o n�o for
				 * caso cr�tico use as fun��es
				 * definidas nesta classe para
				 * acessar os valores independentementes.
				 * <p>
				 * <i>Nota para o programador:
				 * se faltar alguma fun��o, prefira
				 * implementar aqui ao inv�s de usar
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
				 * esta lista cont�m e inclusive
				 * ela mesma, atribuindo NULL em
				 * seguida para o ponteiro.
				 *
				 * @return true se queimou com
				 *         sucesso e false caso
				 *         contr�rio. Esta fun��o
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

				// Informa��o:
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
