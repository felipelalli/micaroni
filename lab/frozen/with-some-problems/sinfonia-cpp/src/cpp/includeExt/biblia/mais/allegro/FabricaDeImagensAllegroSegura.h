/*
 * $RCSfile: FabricaDeImagensAllegroSegura.h,v $
 * $Date: 2005/03/16 20:24:19 $
 * $Revision: 1.10 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: cvsroot $)
 */

#include "biblia/mais/allegro/ImagemAllegro.h"

#if !defined(AFX_ALLEGROSEGURO_H__69513B93_C116_4EE3_A2CA_04365CC377DF__INCLUDED_)
#define AFX_ALLEGROSEGURO_H__69513B93_C116_4EE3_A2CA_04365CC377DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include <typeinfo>
#include "biblia/basico/Objeto.h"
#include "biblia/io/monitor/Tela.h"
#include "biblia/io/disco/DiscoExcecao.h"
#include "biblia/io/disco/ArquivoBasico.h"
#include "biblia/io/disco/Arquivo.h"
#include "biblia/visual/imagem2d/FabricaDeImagens.h"
#include "biblia/visual/geometricos/Retangulo.h"
#include "biblia/seguranca/ChaveSeguranca.h"
#include "biblia/compactacao/CompactadorGZip.h"

using namespace std;
using namespace biblia::basico;
using namespace biblia::io::monitor;
using namespace biblia::visual::imagem2d;
using namespace biblia::visual::geometricos;
using namespace biblia::seguranca;
using namespace biblia::compactacao;

namespace biblia {
  namespace mais {
 	namespace allegro {

		class FabricaDeImagensAllegroSegura
				: public FabricaDeImagens, public Objeto
		{
			private:
				ChaveSeguranca*
						FabricaDeImagensAllegroSegura::pChaveSeguranca;

				const Tela&
						FabricaDeImagensAllegroSegura::pTela;

			public:
				FabricaDeImagensAllegroSegura
					::FabricaDeImagensAllegroSegura(
						const Tela&,
						ChaveSeguranca* chaveSeguranca = NULL);

				virtual FabricaDeImagensAllegroSegura
						::~FabricaDeImagensAllegroSegura();

				virtual Imagem* FabricaDeImagensAllegroSegura
						::carregaDeArquivoBasico
							(const std::string& nomeDoArquivoBasico);

				virtual Imagem* FabricaDeImagensAllegroSegura
						::fazClone(const Imagem*);

				virtual Imagem* FabricaDeImagensAllegroSegura
						::criaVazio(const Tamanho&);
		};
	}
  }
}

#endif // !defined(AFX_ALLEGROSEGURO_H__69513B93_C116_4EE3_A2CA_04365CC377DF__INCLUDED_)
