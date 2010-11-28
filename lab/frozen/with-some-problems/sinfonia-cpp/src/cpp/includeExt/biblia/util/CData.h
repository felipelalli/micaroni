/*
 * $RCSfile: CData.h,v $
 * $Date: 2005/01/20 21:29:27 $
 * $Revision: 1.13 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#include "biblia/basico/Objeto.h"
#include "biblia/io/disco/ArquivoBasico.h"
#include "biblia/util/Debug.h"


#ifndef CDATA_H_SW
#define CDATA_H_SW



#include <string>
#include <time.h>
#include <sys/timeb.h>

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

using namespace std;



using namespace biblia::basico;

using namespace biblia::io::disco;

using namespace biblia::util;




namespace biblia {

  namespace util {

	class CData: public Objeto {

		private:
			int pDia;
			int pMes;
			int pAno;

			int pHora;
			int pMinuto;
			int pSegundo;
			int pMilesimo;

		public:
			/* Cria uma data a partir da data atual */
			CData::CData();
			virtual CData::~CData();

			/* Cria uma data a partir dos parametros passados */
			CData::CData(int ano, int mes, int dia, int hora = 0,
				   int minuto = 0, int segundo = 0, int milesimo = 0);

			/* Cria uma data a partir de milissegundos absolutos */
			CData::CData(long milissegundos);

			/* Cria uma data a partir de outra */
			CData::CData(const CData&);

			virtual int CData::dia() const { return this->pDia; }
			virtual int CData::mes() const { return this->pMes; }
			virtual int CData::ano() const { return this->pAno; }

			virtual int CData::hora() const { return this->pHora; }
			virtual int CData::minuto() const { return this->pMinuto; }
			virtual int CData::segundo() const { return this->pSegundo; }
			virtual int CData::milesimo() const { return this->pMilesimo; }

			virtual const CData& CData::emString(char* destino) const;
			virtual std::string CData::emString() const;

			static const CData& CData::valorDe(const char* s);

			static bool mudarData(const CData&);
	};
  }
}

#endif
