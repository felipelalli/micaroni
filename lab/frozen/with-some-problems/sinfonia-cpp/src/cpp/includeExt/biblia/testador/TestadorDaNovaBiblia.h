/*
 * $RCSfile: TestadorDaNovaBiblia.h,v $
 * $Date: 2004/02/18 17:59:38 $
 * $Revision: 1.11 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_TESTADORDANOVABIBLIA_H__552F922D_6C8E_40B9_BDB6_B4BA65D7DE54__INCLUDED_)
#define AFX_TESTADORDANOVABIBLIA_H__552F922D_6C8E_40B9_BDB6_B4BA65D7DE54__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/mais/allegro/TempoGlobalAllegro.h"
#include "biblia/testador/TestadorComSaidaEmTexto.h"

#include "biblia/tempo/unidades/Milissegundo.h"
#include "biblia/util/instrucoes/Instrucao.h"
#include "biblia/util/instrucoes/ConjuntoDeInstrucoes.h"
#include "biblia/io/disco/ArquivoBinarioDeTamanhoFixo.h"
#include "biblia/armazenamento/volatil/InformacaoRestrita.h"
#include "biblia/armazenamento/volatil/FabricaDeInformacao.h"
#include "biblia/armazenamento/volatil/FabricaDeInformacoesBasicas.h"
#include "biblia/armazenamento/volatil/primitivos/Boleano.h"
#include "biblia/armazenamento/volatil/primitivos/Inteiro.h"
#include "biblia/armazenamento/volatil/primitivos/Flutuante.h"
#include "biblia/armazenamento/volatil/primitivos/Relativo.h"
#include "biblia/armazenamento/volatil/primitivos/String.h"
#include "biblia/armazenamento/volatil/primitivos/ConhecedorDePrimitivos.h"
#include "biblia/armazenamento/volatil/primitivos/universos/De0a100.h"
#include "biblia/armazenamento/volatil/primitivos/universos/InteiroLimitado.h"
#include "biblia/armazenamento/volatil/carcacas/Lista.h"
#include "biblia/armazenamento/volatil/carcacas/MapaMap.h"
#include "biblia/armazenamento/volatil/carcacas/MapaHash.h"
#include "biblia/armazenamento/volatil/carcacas/Dicionario.h"
#include "biblia/armazenamento/volatil/carcacas/DadosSemTipo.h"
#include "biblia/armazenamento/volatil/carcacas/composto/ConhecedorDeCompostos.h"
#include "biblia/armazenamento/volatil/carcacas/composto/instrucoes/CriaDefinicaoDeComposto.h"
#include "biblia/armazenamento/eterno/DadosEmArquivo.h"
#include "biblia/armazenamento/eterno/empacotamento/EmpacotadorDeTiposPrimitivos.h"
#include "biblia/armazenamento/eterno/encaixotamento/EncaixotadorBasico.h"
#include "biblia/armazenamento/eterno/eternizacao/EternizadorEmArquivo.h"
#include "biblia/armazenamento/eterno/eternizacao/EternizadorComEstatistica.h"

using namespace biblia::io::disco;
using namespace biblia::mais::allegro;
using namespace biblia::tempo::unidades;
using namespace biblia::util::instrucoes;
using namespace biblia::armazenamento::volatil;
using namespace biblia::armazenamento::volatil::carcacas;
using namespace biblia::armazenamento::volatil::primitivos;
using namespace biblia::armazenamento::volatil::primitivos::universos;
using namespace biblia::armazenamento::volatil::carcacas::composto;
using namespace biblia::armazenamento::volatil::carcacas::composto::instrucoes;
using namespace biblia::armazenamento::eterno;
using namespace biblia::armazenamento::eterno::empacotamento;
using namespace biblia::armazenamento::eterno::encaixotamento;
using namespace biblia::armazenamento::eterno::eternizacao;

namespace biblia {
  namespace testador {
	class TestadorDaNovaBiblia: public TestadorComSaidaEmTexto {
		protected:
			virtual TestadorDaNovaBiblia&
					TestadorDaNovaBiblia::defineUmaPorcentagem(
						const InformacaoRestrita<Relativo, De0a100>&);

			virtual TestadorDaNovaBiblia&
					TestadorDaNovaBiblia::defineUmaIdade(
						const InformacaoRestrita<Inteiro,
							InteiroLimitado<1, 130> >&);

		public:
			TestadorDaNovaBiblia::TestadorDaNovaBiblia(FluxoDeTexto&);
			virtual TestadorDaNovaBiblia::~TestadorDaNovaBiblia();

			// Executavel:
			virtual Executavel& TestadorDaNovaBiblia::executa();
	};
  }
}

#endif // !defined(AFX_TESTADORDANOVABIBLIA_H__552F922D_6C8E_40B9_BDB6_B4BA65D7DE54__INCLUDED_)
