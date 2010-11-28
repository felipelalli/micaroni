/*
 * $RCSfile: InformacoesSmiley.h,v $
 * $Date: 2003/10/28 23:45:27 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#ifndef INFORMACOES_SMILEY_H
#define INFORMACOES_SMILEY_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

namespace biblia{

	namespace io{

		namespace noteiro{

			namespace smiley{

				class InformacoesSmiley :	public Objeto{

					private:

						int  pSerial;
						int  pUnitType;
						char pFirmwareVersion [10];
						char pCountryCode [10];
						int  pValueMultiplier;
						int  pNumberOfChannels;
						int  pChannelValue [15];
						int  pSecurityOfChannel [15];
						int  pReteachCount;
						bool pChannelReteached [16];
						int  pProtocolVersion;

						bool pEnable;
						bool pReset;

					protected:
						InformacoesSmiley::InformacoesSmiley();

						void InformacoesSmiley::setSerial            (int valor);
						void InformacoesSmiley::setUnitType          (int valor);
						void InformacoesSmiley::setFirmwareVersion   (const char* valor);
						void InformacoesSmiley::setCountryCode       (const char* valor);
						void InformacoesSmiley::setValueMultiplier   (int valor);
						void InformacoesSmiley::setNumberOfChannels  (int valor);
						void InformacoesSmiley::setChannelValue      (int qual, int valor);
						void InformacoesSmiley::setSecurityOfChannel (int qual, int valor);
						void InformacoesSmiley::setReteachCount      (int valor);
						void InformacoesSmiley::setChannelReteached  (int qual, int valor);
						void InformacoesSmiley::setProtocolVersion   (int valor);
						void InformacoesSmiley::setEnable            (bool valor);
						
					public:
						
						virtual InformacoesSmiley::~InformacoesSmiley();

						int         InformacoesSmiley::getSerial            ();
						int         InformacoesSmiley::getUnitType          ();
						const char* InformacoesSmiley::getFirmwareVersion   ();
						const char* InformacoesSmiley::getCountryCode       ();
						int         InformacoesSmiley::getValueMultiplier   ();
						int         InformacoesSmiley::getNumberOfChannels  ();
						int         InformacoesSmiley::getChannelValue      (int qual);
						int         InformacoesSmiley::getSecurityOfChannel (int qual);
						int         InformacoesSmiley::getReteachCount      ();
						bool        InformacoesSmiley::getChannelReteached  (int qual);
						int         InformacoesSmiley::getProtocolVersion   ();
						bool        InformacoesSmiley::getEnable            ();						
				};
			}
		}
	}
}
#endif