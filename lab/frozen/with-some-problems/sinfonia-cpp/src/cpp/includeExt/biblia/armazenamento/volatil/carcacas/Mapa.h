/*
 * $RCSfile: Mapa.h,v $
 * $Date: 2005/01/06 19:21:44 $
 * $Revision: 1.6 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_MAPA_H__A86D5EB3_EEC6_40DE_87A3_0EA823C1953F__INCLUDED_)
#define AFX_MAPA_H__A86D5EB3_EEC6_40DE_87A3_0EA823C1953F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Interface.h"
#include "biblia/armazenamento/volatil/carcacas/Lista.h"

using namespace biblia::basico;

namespace biblia {
  namespace armazenamento {
 	namespace volatil {
	  namespace carcacas {
		/**
		 * Associa uma chave a um valor.
		 * <p>
		 * Não é garantia
		 * que os elementos fiquem
		 * em ordem, para garantir
		 * esse tipo de coisa ou
		 * outros detalhes de implementação
		 * ver a documentação da classe
		 * mais específica.
		 * <p>
		 * <i>Detalhe de implementação:
		 * a classe chave
		 * deve ter o operador menor-que (<)
		 * e o operador igual (==).</i>
		 * <p>
		 * <i>Baseado na classe <b>java.util.Map</b>
		 * da versão 1.4.1 (com restrições
		 * da implementação map da biblioteca
		 * padrão do C++):
		 * <p>
		 * An object that maps keys to values.
		 * A map cannot contain duplicate keys;
		 * each key can map to at most one value.
		 * (...)
		 * <p>
		 * Note: great care must be exercised
		 * if mutable objects are used as map keys.
		 * The behavior of a map is not specified
		 * if the value of an object is changed
		 * in a manner that affects equals comparisons
		 * while the object is a key in the map.
		 * A special case of this prohibition is that
		 * it is not permissible for a map to contain
		 * itself as a key. While it is permissible
		 * for a map to contain itself as a value,
		 * extreme caution is advised: <del>the equals
		 * and hashCode</del> </i>(adaptação:
		 * operator< e operator==)<i>
		 * methods are no longer
		 * well defined on a such a map. (...)
		 * </i>
		 */
		template<class ClasseChave, class ClasseValor>
			class Mapa: public Interface
		{
			public:
				virtual ~Mapa<ClasseChave,
						ClasseValor>() {};

				virtual const ClasseValor& operator[]
						(const ClasseChave& cc) const
				{
					return this->acessa(cc);
				}

				virtual ClasseValor& operator[]
						(const ClasseChave& cc)
				{
					return this->acessa(cc);
				}

				// funções abstratas que devem ser implementadas:

				virtual const bool existe(
						const ClasseChave&) const = 0;

				virtual const int conta(
						const ClasseChave&) const = 0;

				virtual const int tamanho() const = 0;

				/**
				 * @throws ChaveInexistenteExcecao
				 */
				virtual const ClasseValor& acessa(
						const ClasseChave&) const = 0;

				/**
				 * @throws ChaveInexistenteExcecao
				 */
				virtual ClasseValor& acessa(
						const ClasseChave&) = 0;

				/**
				 * @throws ChaveJaExistenteExcecao
				 */
				virtual Mapa<ClasseChave,
						ClasseValor>& insere(
							const ClasseChave&,
							const ClasseValor&) = 0;

				virtual Mapa<ClasseChave,
						ClasseValor>& modifica(
							const ClasseChave&,
							const ClasseValor&) = 0;

				/**
				 * @throws ChaveInexistenteExcecao
				 */
				virtual Mapa<ClasseChave,
						ClasseValor>& apaga(
							const ClasseChave&) = 0;

				virtual Mapa<ClasseChave,
						ClasseValor>& limpa() = 0;

				/**
				 * Deve ser desalocado de fora.
				 */
				virtual Lista<ClasseChave>* chaves() const = 0;

				/**
				 * Deve ser desalocado de fora.
				 */
				virtual Lista<ClasseValor>* valores() const = 0;

				// Operador:

				/**
				 * Sobrescreve este com um alheio.
				 */
				virtual Mapa<ClasseChave,
						ClasseValor>& operator=(
							const Mapa<ClasseChave,
							ClasseValor>& alheio)
				{
					this->limpa();
					Lista<ClasseChave>* chaves = this->chaves();

					for (int i = 0; chaves->tamanho(); i++) {
						this->insere((*chaves)[i], (*this)[(*chaves)[i]]);
					}

					delete chaves;
					return *this;
				}
		};
	  }
	}
  }
}

#endif // !defined(AFX_MAPA_H__A86D5EB3_EEC6_40DE_87A3_0EA823C1953F__INCLUDED_)
