/*
 * $RCSfile: ArqInfoGerenciadorRede.h,v $
 * $Date: 2004/05/17 21:07:02 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef ARQ_INFO_GERENCIADOR_REDE_H
#define ARQ_INFO_GERENCIADOR_REDE_H



#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/io/disco/Arquivo.h"
using namespace biblia::io::disco;

#include "biblia/fluxo/Semaforo.h"
using namespace biblia::fluxo;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

namespace biblia{

	namespace io{

		namespace rede{

			namespace util{

				class ArqInfoGerenciadorRede : public Objeto{

					private:

						int pCodigo;
						int pSequencia;

						Semaforo* pSemaforo;

						Arquivo ArqInfoGerenciadorRede::pArquivo;

					public:

						ArqInfoGerenciadorRede::ArqInfoGerenciadorRede();
						ArqInfoGerenciadorRede::~ArqInfoGerenciadorRede();

						bool ArqInfoGerenciadorRede::carregar();
						bool ArqInfoGerenciadorRede::salvar();

						int  ArqInfoGerenciadorRede::getCodigo   ();
						void ArqInfoGerenciadorRede::setCodigo   (int codigo);

						int  ArqInfoGerenciadorRede::getSequencia();
						void ArqInfoGerenciadorRede::setSequencia(int sequencia);
						void ArqInfoGerenciadorRede::addSequencia();

				};
			}
		}
	}
}

#endif