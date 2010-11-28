/*
 * $RCSfile: Geladeira.h,v $
 * $Date: 2004/01/28 23:46:58 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Geladeira_h)
#define Geladeira_h

#include "biblia/basico/Objeto.h"
#include "biblia/basico/Identificacao.h"
#include "biblia/fluxo/Executavel.h"
#include "biblia/armazenamento/volatil/carcacas/MapaHash.h"
#include "biblia/armazenamento/volatil/carcacas/Lista.h"
#include "biblia/armazenamento/eterno/empacotamento/EmpacotadorAprendiz.h"
#include "biblia/armazenamento/eterno/congelamento/Compartimento.h"
#include "biblia/armazenamento/eterno/congelamento/ProcuradorDeCompartimentoSemelhante.h"

using namespace biblia::basico;
using namespace biblia::armazenamento::volatil::carcacas;
using namespace biblia::armazenamento::eterno::empacotamento;

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace congelamento {
		/**
		 * A Geladeira tem a fun��o principal de
		 * congelar e resgatar uma Informa��o.
		 * <p>
		 * Ela � composta de um ou mais compartimentos.
		 * O CompartimentoTemporario
		 */
		class Geladeira: public Executavel, 
						 public Objeto
		{
			private:
				static int Geladeira::pQuantasInstancias;
				MapaHash<Compartimento*> Geladeira::pCompartimentos;
				MapaHash<Identificacao> Geladeira::pOndeEstaoAsInformacoes;
				Compartimento* Geladeira::pCompartimentoPadrao;
				EmpacotadorAprendiz Geladeira::pEmpacotador;

			protected:
				MapaHash<Compartimento*>& Geladeira::compartimentos();
				const MapaHash<Compartimento*>& Geladeira
						::compartimentos() const;

			public:
				static Identificacao Geladeira::COMPARTIMENTO_PADRAO;

				static ProcuradorDeCompartimentoSemelhante*
						Geladeira::PROCURADOR_PADRAO;

				static ProcuradorDeCompartimentoSemelhante*
						Geladeira::PROCURADOR_IDENTICO;

				/**
				 * Para efeito de exibi��o.
				 */
				virtual const Lista<Identificacao> Geladeira
						::informacoes() const;

				virtual const bool Geladeira
						::existe(const Identificacao&) const;

				virtual Geladeira& Geladeira
						::adiciona(Compartimento*,
								   bool padrao = false);

				virtual Geladeira& Geladeira
						::defineComoPadrao(
							const Identificacao& qual);

				/**
				 * Congela uma informa��o associada
				 * a uma identifica��o em um
				 * compartimento espec�fico.
				 */
				virtual Geladeira& Geladeira::congela(
						const Identificacao& chave,
						Informacao* informacao,
						const Identificacao& qualCompartimento
								= Geladeira::COMPARTIMENTO_PADRAO);

				/**
				 * Congela uma informa��o associada
				 * a uma identifica��o em algum
				 * compartimento que seja o mais parecido
				 * poss�vel com as caracter�sticas
				 * passadas de acordo com a avalia��o
				 * do ProcuradorDeCompartimentoSemelhante
				 * que tamb�m � passado como par�metro.
				 * <p>
				 * Se quiser um compartimento que tenha
				 * exatamente as mesmas caracter�sticas
				 * das passadas use Geladeira::PROCURADOR_IDENTICO.
				 */
				virtual Geladeira& Geladeira::congela(
						const Identificacao& chave,
						Informacao* informacao,
						const Caracteristicas&,
						const ProcuradorDeCompartimentoSemelhante*
								= Geladeira::PROCURADOR_PADRAO);

				virtual Informacao* Geladeira::resgata(
						const Identificacao& chave);
		};
	  }
	}
  }
}

#endif /* Geladeira_h */
