/*
 * $RCSfile: Pilha.h,v $
 * $Date: 2005/01/20 21:28:37 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_PILHA_H__CD6B9306_0FAE_44D1_B5E0_884832AE9163__INCLUDED_)
#define AFX_PILHA_H__CD6B9306_0FAE_44D1_B5E0_884832AE9163__INCLUDED_

#include <stack>
using namespace std;

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/armazenamento/volatil/InformacaoConteiner.h"
using namespace biblia::armazenamento::volatil;

namespace biblia {
  namespace armazenamento {
    namespace volatil {
	  namespace carcacas {
		/**
		 * É uma pilha genérica.
		 */
		template<class T = Objeto*> class Pilha
				:public InformacaoConteiner
		{
			private:
				std::stack<T> pPilha;

			public:
				/**
				 * Cria uma cópia da pilha.
				 */
				Pilha<T>(const Pilha<T>& p):pPilha(p.pPilha) {
					if (p.definida()) {
						this->definiu();
					}
				}

				Pilha<T>():pPilha() {
					this->definiu();
				}

				virtual ~Pilha<T>() {}

				/**
				 * Desempilha todos os elementos da pilha.
				 */
				virtual Pilha<T>& esvazia() {
					while (!this->pPilha.empty()) {
						this->pPilha.pop();
					}

					return *this;
				}

				/**
				 * Empilha um elemento à pilha.
				 */
				virtual Pilha<T>& empilha(const T& o) {
					this->pPilha.push(o);
					return *this;
				}

				/**
				 * Desempilha.
				 */
				virtual Pilha<T>& desempilha() {
					this->pPilha.pop();
					return *this;
				}

				/**
				 * Retorna o topo da pilha.
				 */
				virtual T& topo() {
					return this->pPilha.top();
				}

				/**
				 * Retorna o topo da pilha.
				 */
				virtual const T& topo() const {
					return this->pPilha.top();
				}

				/**
				 * Retorna o tamanho da pilha.
				 */
				virtual const int altura() const {
					return this->pPilha.size();
				}

				/**
				 * Verifica se a pilha está vazia.
				 */
				virtual const bool vazia() const {
					return this->pPilha.empty();
				}
		};
	  }
	}
  }
}

#endif // !defined(AFX_PILHA_H__CD6B9306_0FAE_44D1_B5E0_884832AE9163__INCLUDED_)
