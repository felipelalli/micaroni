/*
 * $RCSfile: MapaMap.h,v $
 * $Date: 2005/01/20 21:28:36 $
 * $Revision: 1.3 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_MAPAMAP_H__72BEB8C3_DA70_4683_B35F_FAC832E872D8__INCLUDED_)
#define AFX_MAPAMAP_H__72BEB8C3_DA70_4683_B35F_FAC832E872D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <map>
#include "biblia/basico/Objeto.h"
#include "biblia/basico/Excecao.h"
#include "biblia/armazenamento/volatil/VolatilExcecao.h"
#include "biblia/armazenamento/volatil/carcacas/Mapa.h"

using namespace std;
using namespace biblia::basico;
using namespace biblia::armazenamento::volatil;

namespace biblia {
  namespace armazenamento {
 	namespace volatil {
	  namespace carcacas {
		/**
		 * Implementa um Mapa usando
		 * o map da biblioteca padr�o
		 * do C++.
		 *
		 * As chaves ficar�o ordenadas
		 * utilizando o operador < .
		 *
		 * @see Mapa
		 */
		template<class ClasseChave, class ClasseValor>
			class MapaMap: public Objeto,
				public Mapa<ClasseChave, ClasseValor>
		{
			private:
				map<ClasseChave, ClasseValor> pMapa;

			public:
				MapaMap<ClasseChave,
						ClasseValor>():pMapa()
				{};

				MapaMap<ClasseChave,
						ClasseValor>(const MapaMap& mm)
							:pMapa(mm.pMapa)
				{};

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
				 * implementar no Mapa ao inv�s de usar
				 * a do std::map<>.</i>
				 */
				virtual map<ClasseChave,
						ClasseValor>& emMap()
				{
					return this->pMapa;
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
				 * implementar no Mapa ao inv�s de usar
				 * a do map<>.</i>
				 */
				virtual const map<ClasseChave,
						ClasseValor>& emMap() const
				{
					return this->pMapa;
				}

				// Mapa:
				virtual ~MapaMap<ClasseChave,
						ClasseValor>() {};

				virtual const int tamanho() const {
					return this->pMapa.size();
				}

				virtual const bool existe(
						const ClasseChave& cc) const
				{
					return this->conta(cc) > 0;
				}

				virtual const int conta(
						const ClasseChave& cc) const
				{
					return this->pMapa.count(cc);
				}

				virtual const ClasseValor& acessa(
						const ClasseChave& cc) const
				{
					if (this->existe(cc)) {
						return
							/*pair<const ClasseChave,
							 ClasseValor> par(*/
									this->pMapa.find(cc)
										->second;
						//);

						//return (const ClasseValor&) par.second;

						// dava pau porque a refer�ncia n�o
						// existia mais l� fora.
					} else {
						ChaveInexistenteExcecao e;
						e << std::string() + "acessa(...)::"
							+ " a chave n�o existe! --- nota:"
							+ " N�o � poss�vel exibir seu valor"
							+ " pois n�o se conhece"
							+ " o seu tipo. Implemente (ou use)"
							+ " um Mapa mais espec�fico como"
							+ " MapaHash ou Dicionario.";

						throw e;
					}
				}

				virtual ClasseValor& acessa(
						const ClasseChave& cc)
				{
					if (this->existe(cc)) {
						return this->pMapa[cc];
					} else {
						ChaveInexistenteExcecao e;
						e << std::string() + "acessa(...)::"
							+ " a chave n�o existe! --- nota:"
							+ " N�o � poss�vel exibir seu valor"
							+ " pois n�o se conhece"
							+ " o seu tipo. Implemente (ou use)"
							+ " um Mapa mais espec�fico como"
							+ " MapaHash ou Dicionario.";

						throw e;
					}
				}

				virtual Mapa<ClasseChave,
						ClasseValor>& insere(
						const ClasseChave& cc,
						const ClasseValor& cv)
				{
					if (!this->existe(cc)) {
						//this->pMapa[cc] = cv;

						pair<const ClasseChave,
							 ClasseValor> par(cc, cv);

						this->pMapa.insert(
								this->pMapa.begin(), par);
					} else {
						ChaveJaExistenteExcecao e;
						e << std::string() + "insere(...)::"
							+ " a chave j� existe! --- nota:"
							+ " N�o � poss�vel exibir seu valor"
							+ " pois n�o se conhece"
							+ " o seu tipo. Implemente (ou use)"
							+ " um Mapa mais espec�fico como"
							+ " MapaHash ou Dicionario.";

						throw e;
					}

					return *this;
				}

				virtual Mapa<ClasseChave,
						ClasseValor>& modifica(
						const ClasseChave& cc,
						const ClasseValor& cv)
				{
					this->apaga(cc);
					this->insere(cc, cv);

					return *this;
				}

				virtual Mapa<ClasseChave,
						ClasseValor>& apaga(
						const ClasseChave& cc)
				{
					if (this->existe(cc)) {
						this->pMapa.erase(this->pMapa.find(cc));
					} else {
						ChaveInexistenteExcecao e;
						e << std::string() + "acessa(...)::"
							+ " a chave n�o existe! --- nota:"
							+ " N�o � poss�vel exibir seu valor"
							+ " pois n�o se conhece"
							+ " o seu tipo. Implemente (ou use)"
							+ " um Mapa mais espec�fico como"
							+ " MapaHash ou Dicionario.";

						throw e;
					}

					return *this;
				}

				virtual Mapa<ClasseChave,
						ClasseValor>& limpa()
				{
					this->pMapa.clear();
					return *this;
				}

				/**
				 * Prefira utilizar emMap() caso
				 * a otimiza��o seja cr�tica. Esta
				 * fun��o faz sempre uma c�pia
				 * completa dos dados.
				 */
				virtual Lista<ClasseChave>* chaves() const {
					Lista<ClasseChave>* retorno
							= NOVO Lista<ClasseChave>();

					Lista<ClasseChave>& r = *retorno;
					typedef map<ClasseChave, ClasseValor>
							::const_iterator Iterador;

					for (Iterador p = this->pMapa.begin();
							p != this->pMapa.end(); p++)
					{
						r.adiciona(p->first);
					}

					return retorno;
				}

				/**
				 * Prefira utilizar emMap() caso
				 * a otimiza��o seja cr�tica. Esta
				 * fun��o faz sempre uma c�pia
				 * completa dos dados.
				 */
				virtual Lista<ClasseValor>* valores() const {
					Lista<ClasseValor>* retorno
							= NOVO Lista<ClasseValor>();

					Lista<ClasseValor>& r = *retorno;
					typedef map<ClasseChave, ClasseValor>
							::const_iterator Iterador;

					for (Iterador p = this->pMapa.begin();
							p != this->pMapa.end(); p++)
					{
						r.adiciona(p->second);
					}

 					return retorno;
				}
		};
	  }
	}
  }
}

#endif // !defined(AFX_MAPAMAP_H__72BEB8C3_DA70_4683_B35F_FAC832E872D8__INCLUDED_)
