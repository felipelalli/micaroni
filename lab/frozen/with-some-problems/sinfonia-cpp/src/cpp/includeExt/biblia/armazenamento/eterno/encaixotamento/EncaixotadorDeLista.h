/*
 * $RCSfile: EncaixotadorDeLista.h,v $
 * $Date: 2004/02/16 23:29:05 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_ENCAIXOTADORDELISTA_H__2F262A79_385B_41BB_8555_AADDCFE9CA7F__INCLUDED_)
#define AFX_ENCAIXOTADORDELISTA_H__2F262A79_385B_41BB_8555_AADDCFE9CA7F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Identificacao.h"
#include "biblia/armazenamento/volatil/carcacas/Lista.h"
#include "biblia/armazenamento/eterno/encaixotamento/Encaixotador.h"
#include "biblia/armazenamento/eterno/encaixotamento/IndiceDeLista.h"
#include "biblia/armazenamento/eterno/encaixotamento/FabricaDeEncaixotador.h"

using namespace biblia::basico;
using namespace biblia::armazenamento::volatil::carcacas;

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace encaixotamento {
		class EncaixotadorDeLista: public Encaixotador {
			private:
				FabricaDeEncaixotador* EncaixotadorDeLista
						::pFabricaDeEncaixotador;

			protected:
				virtual FabricaDeEncaixotador& EncaixotadorDeLista
						::fabricaDeEncaixotador() const;

				virtual const Identificacao EncaixotadorDeLista
						::geraIdentificadorParaElemento(
							const Identificacao& id,
							int indice) const;

			public:
				/**
				 * Sabe 'espalhar' uma lista em diversos
				 * pacotes. Sabe também 'reconstituir' tudo, dos
				 * pacotes para a lista.
				 * <p>
				 * Precisa de uma fábrica de encaixotadores
				 * para encaixotar/desencaixotar os elementos
				 * dessa lista.
				 */
				EncaixotadorDeLista
						::EncaixotadorDeLista(
							FabricaDeEncaixotador* encaixotador);

				virtual EncaixotadorDeLista::~EncaixotadorDeLista();

				// Encaixotador:
				virtual Encaixotador& EncaixotadorDeLista
						::encaixota(const Identificacao&,
							const Informacao&);

				/**
				 * A nova Lista deve ser apagada de fora.
				 * <b>Não</b> apague seus elementos porque
				 * eles já estão "pendurados" na lixeira
				 * que a InformacaoConteiner carrega. Se você
				 * quer apagar manualmente esses elementos,
				 * não se esqueça de então reciclá-los antes
				 * de apagá-los.
				 */
				virtual Informacao* EncaixotadorDeLista
						::desencaixota(const Identificacao&);

				virtual const bool EncaixotadorDeLista
						::sabeEncaixotar(const Tipo&) const;

				virtual const bool EncaixotadorDeLista
						::sabeDesencaixotar(const Tipo& t) const;

				static const bool EncaixotadorDeLista
						::sabeEncaixotarEstatico(const Tipo&);

				static const bool EncaixotadorDeLista
						::sabeDesencaixotarEstatico(const Tipo&);
		};
	  }
	}
  }
}

#endif // !defined(AFX_ENCAIXOTADORDELISTA_H__2F262A79_385B_41BB_8555_AADDCFE9CA7F__INCLUDED_)
