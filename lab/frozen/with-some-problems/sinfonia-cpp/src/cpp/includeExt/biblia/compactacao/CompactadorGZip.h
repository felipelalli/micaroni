/*
 * $RCSfile: CompactadorGZip.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef COMPACTADOR_GZIP_H
#define COMPACTADOR_GZIP_H
#include "biblia/compactacao/Compactador.h"
using namespace biblia::compactacao;

#include "biblia/io/disco/ArquivoBasico.h"
using namespace biblia::io::disco;

namespace biblia{

	namespace compactacao{

		class CompactadorGZip : public Objeto{

			public:

				static bool CompactadorGZip::compactar (const char* arqOrigem, const char* arqDestino);
				static bool CompactadorGZip::descompactar (const char* arqOrigem, const char* arqDestino);
		};
	}
}

#endif