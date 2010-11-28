/*
 * $RCSfile: RenderizadorSimulacaoTropical.h,v $
 * $Date: 2004/05/31 04:16:26 $
 * $Revision: 1.3 $
 * $Name:  $
 * $Author: fernandofernandes $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#ifndef RENDERIZADOR_SIMULACAO_TROPICAL_TROPCIAL_H
#define RENDERIZADOR_SIMULACAO_TROPICAL_TROPCIAL_H

#include "biblia/logica/Renderizador.h"
using namespace biblia::logica;

#include "biblia/visual/dinamica/BasicoVisual.h"
using namespace biblia::visual::dinamica;

#include "biblia/visual/geometricos/Linha.h"
#include "biblia/visual/geometricos/Retangulo.h"
using namespace biblia::visual::geometricos;

#include "biblia/armazenamento/volatil/primitivos/Inteiro.h"
#include "biblia/armazenamento/volatil/primitivos/Flutuante.h"
using namespace biblia::armazenamento::volatil::primitivos;

#include "biblia/armazenamento/eterno/VariavelEmArquivo.h"
using namespace biblia::armazenamento::eterno;

#include "biblia/jogos/frutinha/estados/EstadosTropical.h"
using namespace biblia::jogos::frutinha::estados;

#include "biblia/jogos/frutinha/util/NumeroUtil.h"
using namespace biblia::jogos::frutinha::util;

#include "biblia/visual/fonte/RenderizadorDeFonteImagem.h"
using namespace biblia::visual::fonte;

#include "biblia/jogos/frutinha/visual/simulacao/ArqJogadas.h"
using namespace biblia::jogos::frutinha::visual::simulacao;


namespace biblia {
 namespace jogos {
  namespace frutinha {
   namespace visual {
	namespace simulacao {
		class RenderizadorSimulacaoTropical: public Renderizador {
			private:
				EstadosTropical& pEstados;
				BasicoVisual* pVisual;
				bool pPrimeiraVez;

			protected:
				RenderizadorSimulacaoTropical& desenha();
				RenderizadorSimulacaoTropical& telaDeCobranca();
				RenderizadorSimulacaoTropical& aposta();
				RenderizadorSimulacaoTropical& informacoes();
				RenderizadorSimulacaoTropical& descarregaBuffer(
						Lista<int>& buffer, const int& numeroDeJogadas);

			public:
				RenderizadorSimulacaoTropical
						::RenderizadorSimulacaoTropical(
							EstadosTropical& estados);

				virtual RenderizadorSimulacaoTropical
						::~RenderizadorSimulacaoTropical();

				virtual BasicoVisual&
						RenderizadorSimulacaoTropical::visual();

				virtual RenderizadorSimulacaoTropical&
						RenderizadorSimulacaoTropical::defineVisual(
								BasicoVisual&);

				// Executavel:
				virtual Executavel& RenderizadorSimulacaoTropical::executa();
		};
	}
   }
  }
 }
}

#endif // RENDERIZADOR_SIMULACAO_TROPICAL_TROPCIAL_H