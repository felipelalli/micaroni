/*
 * $RCSfile: InformacaoConteiner.h,v $
 * $Date: 2004/02/16 23:30:19 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_INFORMACAOCONTEINER_H__BD225B34_5458_4B05_A34A_5C27F12047B2__INCLUDED_)
#define AFX_INFORMACAOCONTEINER_H__BD225B34_5458_4B05_A34A_5C27F12047B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/util/Lixeira.h"
#include "biblia/armazenamento/volatil/Informacao.h"

using namespace biblia::util;

namespace biblia {
  namespace armazenamento {
    namespace volatil {
		/**
		 * Representa uma informa��o que pode conter
		 * outras informa��es. Carrega consigo uma
		 * lixeira para auxiliar na dele��o dos
		 * elementos desse cont�iner.
		 */
		class InformacaoConteiner: public Informacao {
			private:
				Lixeira InformacaoConteiner::pLixoInterno;

			protected:
				InformacaoConteiner::InformacaoConteiner();

			public:
				/**
				 * Destr�i o que h� na {@link #lixeira()}.
				 */
				virtual InformacaoConteiner::~InformacaoConteiner();

				/**
				 * Seu uso � <b>opcional</b>, cabendo a
				 * responsabilidade a quem o utiliza.
				 * <p>
				 * Lixeira que � pra ser usada externamente,
				 * auxiliando na dele��o dos elementos
				 * desse cont�iner. Toda manipula��o da lixeira,
				 * exceto a dele��o autom�tica no destrutor,
				 * deve ser feita por quem adiciona elementos
				 * a este cont�iner.
				 * <p>
				 * <b>Cuidado com a manipula��o desta
				 * lixeira e os seus elementos.</b> Ela
				 * serve basicamente quando voc� quer passar
				 * a responsabilidade de dele��o dos objetos
				 * do cont�iner para o destrutor do cont�iner;
				 * numa c�pia do cont�iner, deve-se manipular
				 * a lixeira de acordo com o tipo da c�pia,
				 * que pode ser copiando elemento por elemento
				 * ou copiando apenas os ponteiros.
				 */
				virtual Lixeira& InformacaoConteiner::lixeira();

				/**
				 * @see #lixeira()
				 */
				virtual const Lixeira& InformacaoConteiner::lixeira() const;
		};
	}
  }
}

#endif // !defined(AFX_INFORMACAOCONTEINER_H__BD225B34_5458_4B05_A34A_5C27F12047B2__INCLUDED_)
