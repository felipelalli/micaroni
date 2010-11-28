/*
 * $RCSfile: SomFMod.h,v $
 * $Date: 2005/01/20 21:29:03 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_SOMFMOD_H__66C4AEC5_D58F_4CF5_A553_521184453555__INCLUDED_)
#define AFX_SOMFMOD_H__66C4AEC5_D58F_4CF5_A553_521184453555__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/mais/fmod/FMod.h"
#include "biblia/io/som/Som.h"
#include "biblia/tempo/UltraLong.h"

using namespace biblia::io::som;
using namespace biblia::tempo;

namespace biblia {
  namespace mais {
    namespace fmod {

		/**
		 * Não pode ser instanciado.
		 * Só pode ser criado por uma fábrica.
		 */
		class SomFMod: public Som {
			friend class FabricaDeSonsFMod;

			private:
				int SomFMod::pCanal;

			protected:
				static FMod SomFMod::pFMod;
				virtual int SomFMod::canal() const;
				SomFMod::SomFMod(int canal, std::string chave);

			public:
				virtual SomFMod::~SomFMod();

				// Som:
				virtual Som& SomFMod::play(
						double volume = 100.0,
						int prioridade =
							Som::PRIORIDADE_PARALELA);

				virtual Som& SomFMod::stop();
				virtual Som& SomFMod::paraTudo();
				virtual bool SomFMod::tocando() const;
				virtual bool SomFMod::temSomTocandoMaiorQue(
						int prioridade) const;
		};
	}
  }
}

#endif // !defined(AFX_SOMFMOD_H__66C4AEC5_D58F_4CF5_A553_521184453555__INCLUDED_)
