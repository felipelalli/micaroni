/*
 * $RCSfile: EmpacotadorAprendiz.h,v $
 * $Date: 2004/02/02 19:44:52 $
 * $Revision: 1.5 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(EmpacotadorAprendiz_h)
#define EmpacotadorAprendiz_h

#include "biblia/util/Lixeira.h"
#include "biblia/armazenamento/volatil/carcacas/Lista.h"
#include "biblia/armazenamento/eterno/EternoExcecao.h"
#include "biblia/armazenamento/eterno/empacotamento/Empacotador.h"

using namespace biblia::util;
using namespace biblia::armazenamento::eterno;
using namespace biblia::armazenamento::volatil::carcacas;

namespace biblia {
  namespace armazenamento{
    namespace eterno {
      namespace empacotamento {

 		/**
 		 * Empacotador que "aprende" através
		 * de outros Empacotadores avulsos.
		 * <p>
		 * Se houver mais de um Empacotador
		 * para um mesmo Tipo ele usa o primeiro
		 * que encontrar sem causar erro ou
		 * aviso.
		 */
		class EmpacotadorAprendiz: public Empacotador {
			private:
				Lista<Empacotador*> EmpacotadorAprendiz
						::pEmpacotadores;

				Lixeira EmpacotadorAprendiz::pLixeira;

			public:
				EmpacotadorAprendiz::EmpacotadorAprendiz();
				virtual EmpacotadorAprendiz
						::~EmpacotadorAprendiz();

				/**
				 * Ensina a este EmpacotadorAprendiz
				 * através de outro Empacotador.
				 * <p>
				 * Este adquirirá todo o 'conhecimento'
				 * do que for passado por parâmetro.
				 * <p>
				 * Pega para si a responsabilidade
				 * de deletar o pacote alheio.
				 */
				virtual EmpacotadorAprendiz& EmpacotadorAprendiz
						::adiciona(Empacotador*);

				// Empacotador:

				/**
				 * Gera um novo Pacote
				 * a partir de uma Informacao
				 * devendo ser deletado
				 * de fora.
				 */
				virtual Pacote* EmpacotadorAprendiz
						::empacota(const Informacao&);

				/**
				 * Gera uma nova Informação
				 * a partir de um Pacote
				 * devendo ser deletado
				 * de fora.
				 */
				virtual Informacao* EmpacotadorAprendiz
						::desempacota(const Pacote&);

				/**
				 * Retorna verdadeiro caso algum
				 * dos empacotadores que este empacotador
				 * aprendiz contém sabe manipular
				 * a informação de tal tipo.
				 */
				virtual const bool EmpacotadorAprendiz
						::sabeManipular(const Tipo&) const;

				// Objeto:
				/**
				 * Para efeito de debug.
				 */
				virtual std::string EmpacotadorAprendiz
						::emString() const;
		};
	  }
	}
  }
}

#endif /* EmpacotadorAprendiz_h */
