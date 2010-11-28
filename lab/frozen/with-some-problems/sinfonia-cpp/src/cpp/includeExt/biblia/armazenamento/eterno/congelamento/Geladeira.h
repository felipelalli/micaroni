/*
 * $RCSfile: Geladeira.h,v $
 * $Date: 2004/01/28 23:46:58 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
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
		 * A Geladeira tem a função principal de
		 * congelar e resgatar uma Informação.
		 * <p>
		 * Ela é composta de um ou mais compartimentos.
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
				 * Para efeito de exibição.
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
				 * Congela uma informação associada
				 * a uma identificação em um
				 * compartimento específico.
				 */
				virtual Geladeira& Geladeira::congela(
						const Identificacao& chave,
						Informacao* informacao,
						const Identificacao& qualCompartimento
								= Geladeira::COMPARTIMENTO_PADRAO);

				/**
				 * Congela uma informação associada
				 * a uma identificação em algum
				 * compartimento que seja o mais parecido
				 * possível com as características
				 * passadas de acordo com a avaliação
				 * do ProcuradorDeCompartimentoSemelhante
				 * que também é passado como parâmetro.
				 * <p>
				 * Se quiser um compartimento que tenha
				 * exatamente as mesmas características
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
