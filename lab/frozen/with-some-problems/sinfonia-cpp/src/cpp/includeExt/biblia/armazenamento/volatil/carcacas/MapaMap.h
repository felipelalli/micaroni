/*
 * $RCSfile: MapaMap.h,v $
 * $Date: 2005/01/20 21:28:36 $
 * $Revision: 1.3 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
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
		 * o map da biblioteca padrão
		 * do C++.
		 *
		 * As chaves ficarão ordenadas
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
				 * implementar no Mapa ao invés de usar
				 * a do std::map<>.</i>
				 */
				virtual map<ClasseChave,
						ClasseValor>& emMap()
				{
					return this->pMapa;
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
				 * implementar no Mapa ao invés de usar
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

						// dava pau porque a referência não
						// existia mais lá fora.
					} else {
						ChaveInexistenteExcecao e;
						e << std::string() + "acessa(...)::"
							+ " a chave não existe! --- nota:"
							+ " Não é possível exibir seu valor"
							+ " pois não se conhece"
							+ " o seu tipo. Implemente (ou use)"
							+ " um Mapa mais específico como"
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
							+ " a chave não existe! --- nota:"
							+ " Não é possível exibir seu valor"
							+ " pois não se conhece"
							+ " o seu tipo. Implemente (ou use)"
							+ " um Mapa mais específico como"
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
							+ " a chave já existe! --- nota:"
							+ " Não é possível exibir seu valor"
							+ " pois não se conhece"
							+ " o seu tipo. Implemente (ou use)"
							+ " um Mapa mais específico como"
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
							+ " a chave não existe! --- nota:"
							+ " Não é possível exibir seu valor"
							+ " pois não se conhece"
							+ " o seu tipo. Implemente (ou use)"
							+ " um Mapa mais específico como"
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
				 * a otimização seja crítica. Esta
				 * função faz sempre uma cópia
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
				 * a otimização seja crítica. Esta
				 * função faz sempre uma cópia
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
