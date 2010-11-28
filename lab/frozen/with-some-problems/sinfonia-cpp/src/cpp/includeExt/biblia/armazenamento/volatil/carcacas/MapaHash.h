/*
 * $RCSfile: MapaHash.h,v $
 * $Date: 2005/01/20 21:28:36 $
 * $Revision: 1.5 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_MAPAHASH_H__19C8F483_7F0F_402E_AA11_9387BBBCA67E__INCLUDED_)
#define AFX_MAPAHASH_H__19C8F483_7F0F_402E_AA11_9387BBBCA67E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef STLPORT
	#include <hash_map>
	using namespace std;
	#define COM_MAPA_HASH
#else
    //#error Please use the STLport to compile this class.
	#ifdef _MSC_EXTENSIONS
		#include <hash_map>
		using namespace stdext;
		#define COM_MAPA_HASH
		#define MSC_EXTENSIONS_EXCLUSIVO
	#endif
#endif

#include <string>

#ifndef COM_MAPA_HASH

	#define ERRO_MAPA_HASH ":: Cuidado! Você está pensando"\
						   " que está usando um MapaHash"\
						   " porém está usando um MapaMap."

#include "biblia/util/Debug.h"
#include "biblia/armazenamento/volatil/carcacas/MapaMap.h"

using namespace biblia::util;

namespace biblia {
  namespace armazenamento {
 	namespace volatil {
	  namespace carcacas {
		/**
		 * É importante lembrar que
		 * o MapHash não ordena as
		 * chaves nem os valores.
		 *
		 * @see Mapa
		 */
		template<class ClasseValor> class MapaHash
				:public MapaMap<Identificacao, ClasseValor>
		{
			public:
				MapaHash<ClasseValor>()
						:MapaMap<Identificacao,
							  ClasseValor>()
				{
					static int i = 0;
					i++;

					if (i == 1) {
						Debug::msg(WARN, string() + Objeto::emString()
									+ ERRO_MAPA_HASH);
					}
				}

		};
	  }
	}
  }
}

#else // COM_MAPA_HASH

#include <hash_map>
#include "biblia/basico/Objeto.h"
#include "biblia/basico/Identificacao.h"
#include "biblia/basico/FabricaDeIdentificacao.h"
#include "biblia/armazenamento/volatil/VolatilExcecao.h"
#include "biblia/armazenamento/volatil/carcacas/Mapa.h"

using namespace biblia::basico;
using namespace biblia::armazenamento::volatil;

namespace biblia {
  namespace armazenamento {
 	namespace volatil {
	  namespace carcacas {
		/**
		 * É um Mapa usando Hash e a classe
		 * Identificacao como chave.
		 */
		template<class ClasseValor> class MapaHash
				:public Mapa<Identificacao, ClasseValor>,
				 public Objeto
		{
			private:
#ifdef MSC_EXTENSIONS_EXCLUSIVO
				stdext::
#endif
				hash_map<std::string,
						 ClasseValor> pMapa;

			public:
				MapaHash<ClasseValor>():pMapa() {};

				MapaHash<ClasseValor>(const MapaHash& mm)
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
				 * implementar no Map ao invés de usar
				 * a do std::map<>.</i>
				 */
				virtual
#ifdef MSC_EXTENSIONS_EXCLUSIVO
					stdext::
#endif
					hash_map<std::string,
						ClasseValor>& emHashMap()
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
				 * implementar no Map ao invés de usar
				 * a do map<>.</i>
				 */
				virtual const
#ifdef MSC_EXTENSIONS_EXCLUSIVO
					stdext::
#endif					
					hash_map<std::string,
						ClasseValor>& emHashMap() const
				{
					return this->pMapa;
				}

				// Mapa:
				virtual ~MapaHash<ClasseValor>() {};

				virtual const int tamanho() const {
					return this->pMapa.size();
				}

				virtual const bool existe(
						const Identificacao& cc) const
				{
					return this->conta(cc) > 0;
				}

				virtual const int conta(
						const Identificacao& cc) const
				{
					return this->pMapa.count(cc.emString());
				}

				virtual const ClasseValor& acessa(
						const Identificacao& cc) const
				{
					if (this->existe(cc.emString())) {
						return
							/*pair<const ClasseChave,
							 ClasseValor> par(*/
									this->pMapa.find(cc.emString())
										->second;
						//);

						//return (const ClasseValor&) par.second;

						// dava pau porque a referência não
						// existia mais lá fora.
					} else {
						ChaveInexistenteExcecao e;
						e << std::string() + "acessa(...)::"
							+ " a chave não existe! Chave: \""
							+ cc + "\"";

						throw e;
					}
				}

				virtual ClasseValor& acessa(
						const Identificacao& cc)
				{
					if (this->existe(cc.emString())) {
						return this->pMapa[cc.emString()];
					} else {
						ChaveInexistenteExcecao e;
						e << std::string() + "acessa(...)::"
							+ " a chave não existe! Chave: \""
							+ cc + "\"";

						throw e;
					}
				}

				virtual Mapa<Identificacao,
						ClasseValor>& insere(
					const Identificacao& cc,
					const ClasseValor& cv)
				{
					if (!this->existe(cc.emString())) {
						//this->pMapa[cc] = cv;

						pair<std::string, ClasseValor>
								par(cc.emString(), cv);

						this->pMapa.insert(par);
					} else {
						ChaveJaExistenteExcecao e;
						e << std::string() + "insere(...)::"
							+ " a chave já existe! Chave: \""
							+ cc + "\"";

						throw e;
					}

					return *this;
				}

				virtual Mapa<Identificacao,
						ClasseValor>& modifica(
					const Identificacao& cc,
					const ClasseValor& cv)
				{
					this->apaga(cc.emString());
					this->insere(cc.emString(), cv);

					return *this;
				}

				virtual Mapa<Identificacao,
						ClasseValor>& apaga(
					const Identificacao& cc)
				{
					if (this->existe(cc.emString())) {
						this->pMapa.erase(this->pMapa
								.find(cc.emString()));
					} else {
						ChaveInexistenteExcecao e;
						e << std::string() + "acessa(...)::"
							+ " a chave não existe! --- Chave: \""
							+ cc + "\"";

						throw e;
					}

					return *this;
				}

				virtual Mapa<Identificacao,
						ClasseValor>& limpa()
				{
					this->pMapa.clear();
					return *this;
				}

				/**
				 * Prefira utilizar emHashMap() caso
				 * a otimização seja crítica. Esta
				 * função faz sempre uma cópia
				 * completa dos dados.
				 */
				virtual Lista<Identificacao>* chaves() const {
					Lista<Identificacao>* retorno
							= NOVO Lista<Identificacao>();

					Lista<Identificacao>& r = *retorno;
					typedef std::hash_map<std::string,
							ClasseValor>::const_iterator Iterador;

					for (Iterador p = this->pMapa.begin();
							p != this->pMapa.end(); p++)
					{
						static FabricaDeIdentificacao fi;
						fi.geraBaseadoEm(p->first);
						Identificacao* nova = fi.geraIdentificacao();
						r.adiciona(*nova); // faz uma cópia internamente
						delete nova;
					}

					return retorno;
				}

				/**
				 * Prefira utilizar emMap() caso
				 * a otimização seja crítica. Esta
				 * função faz sempre uma cópia
				 * completa dos dados.
				 */
				virtual Lista<ClasseValor>*	valores() const	{
					Lista<ClasseValor>* retorno
							= NOVO Lista<ClasseValor>();

					Lista<ClasseValor>& r = *retorno;
					typedef std::hash_map<std::string,
							ClasseValor>::const_iterator Iterador;

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

#endif // #ifndef COM_MAPA_HASH

#endif // !defined(AFX_MAPAHASH_H__19C8F483_7F0F_402E_AA11_9387BBBCA67E__INCLUDED_)
