/*
 * $RCSfile: InformacaoConteiner.h,v $
 * $Date: 2004/02/16 23:30:19 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
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
		 * Representa uma informação que pode conter
		 * outras informações. Carrega consigo uma
		 * lixeira para auxiliar na deleção dos
		 * elementos desse contêiner.
		 */
		class InformacaoConteiner: public Informacao {
			private:
				Lixeira InformacaoConteiner::pLixoInterno;

			protected:
				InformacaoConteiner::InformacaoConteiner();

			public:
				/**
				 * Destrói o que há na {@link #lixeira()}.
				 */
				virtual InformacaoConteiner::~InformacaoConteiner();

				/**
				 * Seu uso é <b>opcional</b>, cabendo a
				 * responsabilidade a quem o utiliza.
				 * <p>
				 * Lixeira que é pra ser usada externamente,
				 * auxiliando na deleção dos elementos
				 * desse contêiner. Toda manipulação da lixeira,
				 * exceto a deleção automática no destrutor,
				 * deve ser feita por quem adiciona elementos
				 * a este contêiner.
				 * <p>
				 * <b>Cuidado com a manipulação desta
				 * lixeira e os seus elementos.</b> Ela
				 * serve basicamente quando você quer passar
				 * a responsabilidade de deleção dos objetos
				 * do contêiner para o destrutor do contêiner;
				 * numa cópia do contêiner, deve-se manipular
				 * a lixeira de acordo com o tipo da cópia,
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
