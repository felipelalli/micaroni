/*
 * $RCSfile: Geometrico.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_GEOMETRICO_H__28CABDE9_17AA_4E5F_9B67_6FA1248BD342__INCLUDED_)
#define AFX_GEOMETRICO_H__28CABDE9_17AA_4E5F_9B67_6FA1248BD342__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/Area.h"
#include "biblia/visual/Unicolor.h"
#include "biblia/visual/Preenchivel.h"
#include "biblia/visual/Posicionado.h"
#include "biblia/visual/Bidimensional.h"
#include "biblia/visual/VisualExcecao.h"
#include "biblia/basico/Objeto.h"

using namespace biblia::basico;

namespace biblia {
  namespace visual {

	/**
	 * Deriva deste um objeto geometrico
	 * que pode ser posicionado, tem uma cor
	 * e pode ser preenchido.
	 */
	class Geometrico:
		public Posicionado,
		public Unicolor,
		public Preenchivel,
		public Bidimensional,
		public Objeto
	{
		private:
			long Geometrico::pCodigoUnico;

		protected:
			Geometrico::Geometrico(
					const Ponto& posicao,
					const Cor& cor,
					const bool& preenchido,
					long codigoUnico = 0);

			virtual Geometrico::~Geometrico();

		public:
			bool Geometrico::mesmoTipo(const Geometrico&) const;
	};
  }
}

#endif // !defined(AFX_GEOMETRICO_H__28CABDE9_17AA_4E5F_9B67_6FA1248BD342__INCLUDED_)
