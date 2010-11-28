/*
 * $RCSfile: FabricaDeIdentificacao.h,v $
 * $Date: 2005/01/20 21:28:40 $
 * $Revision: 1.6 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(FabricaDeIdentificacao_h)
#define FabricaDeIdentificacao_h

#include "biblia/basico/Objeto.h"
#include "biblia/basico/Fabrica.h"
#include "biblia/basico/Identificacao.h"

namespace biblia {
  namespace basico {
	/**
	 * Gera uma Identifica��o a partir
	 * de uma String. Se n�o houver
	 * String ele gera uma (sequencial n�o-aleat�ria)
	 * e a retorna.
	 * <p>
	 * <i><b>[Justificativa desta f�brica]</b>
	 * <br>Identificacao a princ�pio � um
	 * tipo std::string, simples, e sua constru��o n�o � complexa.
	 * Portanto ela pode ser criada sem esta f�brica (seu
	 * construtor � p�blico). Por�m, esta existe para que
	 * fique aberta a possibilidade de se criar Identifica��es
	 * complexas (baseada em hardware, banco de dados, na fase
	 * lunar etc.) e f�bricas s�o muito bem vindas nesses casos.
	 */
	class FabricaDeIdentificacao: public Fabrica, public Objeto {
		private:
			std::string FabricaDeIdentificacao::pString;
			int FabricaDeIdentificacao::pSequencia;

		protected:
			static std::string FabricaDeIdentificacao::SEQUENCIALMENTE;

		public:
			FabricaDeIdentificacao::FabricaDeIdentificacao();
			virtual FabricaDeIdentificacao::~FabricaDeIdentificacao();

			virtual FabricaDeIdentificacao&
					FabricaDeIdentificacao
						::geraBaseadoEm(const std::string&);

			virtual FabricaDeIdentificacao&
					FabricaDeIdentificacao
						::geraBaseadoEm(const Identificacao&);

			virtual FabricaDeIdentificacao&
					FabricaDeIdentificacao
						::geraSequencialmente();

			virtual Identificacao* FabricaDeIdentificacao
					::geraIdentificacao()
			{
				return (Identificacao*) this->gera();
			}

			// Fabrica:

			virtual Objeto* FabricaDeIdentificacao::gera();
	};
  }
}

#endif /* FabricaDeIdentificacao_h */
