/*
 * $RCSfile: Cobranca.h,v $
 * $Date: 2005/01/13 17:09:48 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_COBRANCA_H__76B85572_F0DA_400E_86C7_3AE021AD7511__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_COBRANCA_H__76B85572_F0DA_400E_86C7_3AE021AD7511__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "biblia/basico/Objeto.h"
#include "biblia/io/disco/Arquivo.h"
#include "biblia/tempo/Momento.h"
#include "biblia/tempo/Intervalo.h"
#include "biblia/tempo/UniversoSistema.h"

using namespace std;
using namespace biblia::basico;
using namespace biblia::io::disco;
using namespace biblia::tempo;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

namespace biblia {
  namespace jogos {
    namespace specialUpgrade {
	  namespace estados {

		class Cobranca: public Objeto {
			private:
				// travamento de tela com a chave de cobrança:
				UniversoDeTempo& Cobranca::pTempo;
				bool Cobranca::pTelaTravada;
				Momento Cobranca::pQuandoTravou;

                bool pSomCobranca;
				// tela de cobrança:
				bool Cobranca::pEstaNaTela;
                int Cobranca::pCreditos;
				string Cobranca::pCodigo;

				Arquivo pArquivo;

			public:
				Cobranca::Cobranca(UniversoDeTempo& universoDeTempo);

                virtual Cobranca& Cobranca::deveConsumirCobranca(bool sim);
                virtual bool Cobranca::consomeCobranca();

                virtual Cobranca::~Cobranca();

				virtual bool Cobranca::estaNela() const;
				virtual Cobranca& Cobranca::salvaEmArquivoBasico();
				virtual Cobranca& Cobranca::estaNela(bool sim,
						int creditos = 0, string codigo = "ERRO FATAL");

                virtual int Cobranca::creditos() const;
				virtual string Cobranca::codigo() const;

				// tela de travamento:
				virtual Cobranca& Cobranca::travaTela(bool = true);
				virtual const bool& Cobranca::telaTravada() const;
				virtual Intervalo Cobranca::quantoTempoParado() const;
		};
	  }
	}
  }
}

#endif // !defined(AFX_COBRANCA_H__76B85572_F0DA_400E_86C7_3AE021AD7511__INCLUDED_)
