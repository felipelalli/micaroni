/*
 * $RCSfile: RenderizadorSimulacaoSpecial.h,v $
 * $Date: 2004/06/23 14:25:05 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: fernandofernandes $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#ifndef RENDERIZADOR_SIMULACAO_SPECIAL_H
#define RENDERIZADOR_SIMULACAO_SPECIAL_H

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

#include "biblia/armazenamento/volatil/carcacas/Lista.h"
using namespace biblia::armazenamento::volatil::carcacas;

#include "biblia/armazenamento/eterno/VariavelEmArquivo.h"
using namespace biblia::armazenamento::eterno;

#include "biblia/jogos/special/EstadosSpecial.h"
using namespace biblia::jogos::special;

#include "biblia/jogos/special/util/NumeroUtil.h"
using namespace biblia::jogos::special::util;

#include "biblia/visual/fonte/RenderizadorDeFonteImagem.h"
using namespace biblia::visual::fonte;

#include "biblia/jogos/special/util/ArqJogadasSpecial.h"
using namespace biblia::jogos::special::util;


namespace biblia {
 namespace jogos {
  namespace special {
   namespace visual {
	class RenderizadorSimulacaoSpecial: public Renderizador {
		private:
			EstadosSpecial& pEstados;
			BasicoVisual* pVisual;
			bool pPrimeiraVez;

		protected:
			RenderizadorSimulacaoSpecial& desenha();
			RenderizadorSimulacaoSpecial& telaDeCobranca();
			RenderizadorSimulacaoSpecial& aposta();
			RenderizadorSimulacaoSpecial& informacoes();
			RenderizadorSimulacaoSpecial& descarregaBuffer(
					biblia::armazenamento::volatil::carcacas::Lista<int>& buffer, const int& numeroDeJogadas);

		public:
			RenderizadorSimulacaoSpecial
					::RenderizadorSimulacaoSpecial(
						EstadosSpecial& estados);

			virtual RenderizadorSimulacaoSpecial
					::~RenderizadorSimulacaoSpecial();

			virtual BasicoVisual&
					RenderizadorSimulacaoSpecial::visual();

			virtual RenderizadorSimulacaoSpecial&
					RenderizadorSimulacaoSpecial::defineVisual(
							BasicoVisual&);

			// Executavel:
			virtual Executavel& RenderizadorSimulacaoSpecial::executa();
	};
   }
  }
 }
}

#endif // RENDERIZADOR_SIMULACAO_SPECIAL_H