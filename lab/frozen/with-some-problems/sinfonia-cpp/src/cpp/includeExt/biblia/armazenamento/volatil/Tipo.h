/*
 * $RCSfile: Tipo.h,v $
 * $Date: 2003/12/05 18:49:52 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_TIPO_H__0DB68C67_76AA_417D_A65F_D3297228CF9A__INCLUDED_)
#define AFX_TIPO_H__0DB68C67_76AA_417D_A65F_D3297228CF9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/basico/Identificacao.h"

using namespace biblia::basico;

namespace biblia {
  namespace armazenamento{
    namespace volatil {
		/**
		 * Representa uma <b>identifica��o</b>
		 * �nica de um tipo qualquer.
		 * <p>
		 * Um Tipo n�o conhece seu pr�prio comportamento
		 * por ser gen�rico demais; uma terceira classe
		 * deve manipular a identifica��o de um tipo e
		 * us�-lo em conjunto com alguma informa��o do tipo.
		 * <p>
		 * Apenas 'esconde' uma Identificacao internamente
		 * e existe para facilitar a leitura do c�digo
		 * (e inclusive gerar erros de compila��o quando
		 * houver conceitos 'misturados' ou usados por
		 * engano) onde seria necess�rio uma identifica��o
		 * espec�fica de um <b>tipo</b>.
		 *
		 * @see Informacao
		 */
		class Tipo: public Objeto {
			private:
				Identificacao Tipo::pId;

			public:
				Tipo::Tipo(const Identificacao&);
				virtual Tipo::~Tipo();

				virtual const Identificacao& Tipo::id() const;
				virtual const bool Tipo::mesmo(const Tipo&) const;

				// operadores de compara��o
				// veja mesma(...) e menorQue(...)

				virtual const bool Tipo
						::operator!=(const Tipo& outra) const
				{
					return !this->mesmo(outra);
				}

				virtual const bool Tipo
						::operator==(const Tipo& outra) const
				{
					return this->mesmo(outra);
				}

				// outros operadores
				virtual Tipo& Tipo::operator=(const Tipo& outro);

				// Objeto:

				/**
				 * Retorna this->id().emString()
				 */
				virtual std::string Tipo::emString() const;
		};
	}
  }
}

#endif // !defined(AFX_TIPO_H__0DB68C67_76AA_417D_A65F_D3297228CF9A__INCLUDED_)
