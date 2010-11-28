/*
 * $RCSfile: FabricaDeSonsFMod.h,v $
 * $Date: 2005/01/20 21:29:03 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_FABRICADESONSFMOD_H__AB8F11A8_D69A_4315_BDB2_E719C376A75C__INCLUDED_)
#define AFX_FABRICADESONSFMOD_H__AB8F11A8_D69A_4315_BDB2_E719C376A75C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/mais/fmod/SomFMod.h"
#include "biblia/io/som/FabricaDeSons.h"

using namespace biblia::io::som;

namespace biblia {
  namespace mais {
    namespace fmod {

		class FabricaDeSonsFMod: public FabricaDeSons {
			public:
				FabricaDeSonsFMod::FabricaDeSonsFMod() {};
				virtual FabricaDeSonsFMod::~FabricaDeSonsFMod() {};

				// FabricaDeSons:
				virtual Som* FabricaDeSonsFMod::carregaDeArquivoBasico(
						const std::string& caminhoENomeDoArquivoBasico);
		};
	}
  }
}

#endif // !defined(AFX_FABRICADESONSFMOD_H__AB8F11A8_D69A_4315_BDB2_E719C376A75C__INCLUDED_)
