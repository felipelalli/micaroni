/*
 * $RCSfile: FabricaDeIdentificacao.h,v $
 * $Date: 2005/01/20 21:28:40 $
 * $Revision: 1.6 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
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
	 * Gera uma Identificação a partir
	 * de uma String. Se não houver
	 * String ele gera uma (sequencial não-aleatória)
	 * e a retorna.
	 * <p>
	 * <i><b>[Justificativa desta fábrica]</b>
	 * <br>Identificacao a princípio é um
	 * tipo std::string, simples, e sua construção não é complexa.
	 * Portanto ela pode ser criada sem esta fábrica (seu
	 * construtor é público). Porém, esta existe para que
	 * fique aberta a possibilidade de se criar Identificações
	 * complexas (baseada em hardware, banco de dados, na fase
	 * lunar etc.) e fábricas são muito bem vindas nesses casos.
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
