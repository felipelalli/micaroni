/*
 * $RCSfile: ResolvedorDeNomes.h,v $
 * $Date: 2005/01/20 21:29:27 $
 * $Revision: 1.3 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_RESOLVEDORDENOMES_H__DD830FFC_9948_4C48_BD46_18DB76B2F8A8__INCLUDED_)
#define AFX_RESOLVEDORDENOMES_H__DD830FFC_9948_4C48_BD46_18DB76B2F8A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "biblia/basico/Objeto.h"

using namespace std;
using namespace biblia::basico;

namespace biblia {
  namespace texto {
	/**
	 * Transforma um nome qualquer
	 * em outro nome, seguindo as seguintes
	 * peculiaridades: A std::string
	 * "resolvida" não é necessariamente
	 * "humanamente legível" e também
	 * não pode ser transformada novamente
	 * em sua forma original. Para uma determinada
	 * entrada deve haver uma única saída. Talvez entradas
	 * diferentes possam gerar a mesma saída, porém
	 * a mesma entrada gerará sempre a mesma saída.
	 * <p>
	 * Pode ser útil para gerar identificadores,
	 * para restd::stringir uma cadeia de caracteres a um
	 * conjunto limitado de caracteres, para armazenar
	 * senhas etc.
	 * <p>
	 *
	 *<b>resolver</b>:
	 *<p>
	 *  do Lat. resolvere
	 *<p>
	 *  v. tr.,
	 *		separar os elementos constitutivos;
	 *		dissolver;
	 *		explicar;
	 *		achar a solução de;
	 *		decidir;
	 *		determinar;
	 *		deliberar;
	 *<p>
	 *  v. int.,
	 *		desembaraçar-se;
	 *		desfazer-se insensivelmente;
	 *<p>
	 *  v. refl.,
	 *		decidir-se;
	 *		dispor-se;
	 *		transformar-se;
	 *  	cifrar-se;
	 *		consistir;
	 *<p>
	 *  Med.,
	 *	terminar por meio de solução (processo inflamatório).
	 */
	class ResolvedorDeNomes: public Objeto {
		protected:
			ResolvedorDeNomes::ResolvedorDeNomes();

		public:
			virtual ResolvedorDeNomes::~ResolvedorDeNomes();

			virtual const std::string ResolvedorDeNomes
					::resolve(const std::string& nome) = 0;
	};
  }
}

#endif // !defined(AFX_RESOLVEDORDENOMES_H__DD830FFC_9948_4C48_BD46_18DB76B2F8A8__INCLUDED_)
