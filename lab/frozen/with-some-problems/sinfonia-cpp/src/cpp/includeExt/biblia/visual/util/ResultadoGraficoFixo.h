/*
 * $RCSfile: ResultadoGraficoFixo.h,v $
 * $Date: 2004/06/30 19:20:15 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_RESULTADOGRAFICOFIXO_H__098E36B6_A700_46C8_A943_0487ABEF8B42__INCLUDED_)
#define AFX_RESULTADOGRAFICOFIXO_H__098E36B6_A700_46C8_A943_0487ABEF8B42__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/armazenamento/volatil/carcacas/Lista.h"
using namespace biblia::armazenamento::volatil::carcacas;

#include "biblia/visual/dinamica/ResultadoGrafico.h"
#include "biblia/visual/dinamica/CarregadorDeComponentes.h"
using namespace biblia::visual::dinamica;

#include "biblia/visual/imagem2d/ImagemPosicionada.h"
using namespace biblia::visual::imagem2d;

#include "biblia/visual/animacao/Video.h"
using namespace biblia::visual::animacao;

#include "biblia/visual/fonte/TextoComFonte.h"
#include "biblia/visual/fonte/FonteImagem.h"
using namespace biblia::visual::fonte;

#include "biblia/visual/util/ComponenteFixo.h"

namespace biblia {
 namespace visual {
  namespace util {	
	class ResultadoGraficoFixo: public Objeto {
		private:
			biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo> pResultado;

		public:
			ResultadoGraficoFixo(const biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo>& resultado);
			ResultadoGraficoFixo(ResultadoGrafico& rg);
			virtual ~ResultadoGraficoFixo();

			virtual const biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo>& componentesFixos() const;
			virtual const ResultadoGraficoFixo& atualiza(
					CarregadorDeComponentes& cc) const;
	};
  }
 }
}

#endif // !defined(AFX_RESULTADOGRAFICOFIXO_H__098E36B6_A700_46C8_A943_0487ABEF8B42__INCLUDED_)
