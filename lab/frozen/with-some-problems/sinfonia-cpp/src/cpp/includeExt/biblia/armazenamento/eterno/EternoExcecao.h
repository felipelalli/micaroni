/*
 * $RCSfile: EternoExcecao.h,v $
 * $Date: 2005/01/20 21:28:32 $
 * $Revision: 1.6 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_ETERNO_VOLATILEXCECAO_H__978F2EC5_DA6A_4FC1_B413_C5416B33717D__INCLUDED_)
#define AFX_ETERNO_VOLATILEXCECAO_H__978F2EC5_DA6A_4FC1_B413_C5416B33717D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <deque>
#include <string>
#include "biblia/basico/Excecao.h"
#include "biblia/basico/Identificacao.h"

using namespace std;
using namespace biblia::basico;

namespace biblia {
  namespace armazenamento{
    namespace eterno {
		class EternoExcecao: public Excecao {
			public:
				EternoExcecao::EternoExcecao() {}
		};

		class CongelamentoExcecao: public EternoExcecao {
			public:
				CongelamentoExcecao::CongelamentoExcecao() {}
		};

		class NenhumCompartimentoAdequadoExcecao
				:public CongelamentoExcecao
		{
			NenhumCompartimentoAdequadoExcecao
					::NenhumCompartimentoAdequadoExcecao() {}
		};

		class EmpacotamentoExcecao: public EternoExcecao {
			public:
				EmpacotamentoExcecao::EmpacotamentoExcecao() {}
		};

		class PacoteNaoEncontradoExcecao: public EmpacotamentoExcecao {
			public:
				PacoteNaoEncontradoExcecao::PacoteNaoEncontradoExcecao() {}
		};

		class FormaEternaModificadaExcecao: public EmpacotamentoExcecao {
			private:
				std::deque<Identificacao> FormaEternaModificadaExcecao
						::pPacotesNaoSincronizados;

			public:
				FormaEternaModificadaExcecao
						::FormaEternaModificadaExcecao(
							const FormaEternaModificadaExcecao& irmao)
					:EmpacotamentoExcecao(irmao), pPacotesNaoSincronizados()
				{
					for (unsigned int i = 0; i < irmao
						 .pacotesNaoSincronizados().size(); i++)
					{
						this->pPacotesNaoSincronizados.push_back(
								irmao.pacotesNaoSincronizados()[i]);
					}
				}

				FormaEternaModificadaExcecao
						::FormaEternaModificadaExcecao()
					:pPacotesNaoSincronizados()
				{}

				virtual FormaEternaModificadaExcecao
						::~FormaEternaModificadaExcecao() {}

				virtual std::deque<Identificacao>& FormaEternaModificadaExcecao
						::pacotesNaoSincronizados()
				{
					return this->pPacotesNaoSincronizados;
				}

				virtual const std::deque<Identificacao>&
						FormaEternaModificadaExcecao
							::pacotesNaoSincronizados() const
				{
					return this->pPacotesNaoSincronizados;
				}

				// Objeto:
				virtual std::string FormaEternaModificadaExcecao
						::emString() const
				{
					std::string retorno = Excecao::emString() +
							" Pacotes dessincronizados: { ";

					for (unsigned int i = 0;
					     i < this->pacotesNaoSincronizados().size(); i++)
					{
						retorno += "'"
							+ this->pacotesNaoSincronizados()[i] + "' ";
					}

					return retorno + "}";
				}
		};

		class PacoteDeTamanhoVariavelExcecao: public EmpacotamentoExcecao {
			public:
				PacoteDeTamanhoVariavelExcecao
						::PacoteDeTamanhoVariavelExcecao() {}
		};

		class PacoteDeTamanhoFixoExcecao: public EmpacotamentoExcecao {
			public:
				PacoteDeTamanhoFixoExcecao
						::PacoteDeTamanhoFixoExcecao() {}
		};

		class EncaixotamentoExcecao: public EternoExcecao {
			public:
				EncaixotamentoExcecao::EncaixotamentoExcecao() {}
		};

		class FabricaDeEncaixotadorExcecao: public EncaixotamentoExcecao {
			public:
				FabricaDeEncaixotadorExcecao
						::FabricaDeEncaixotadorExcecao() {}
		};

		class FabricaNaoSabeFabricarEsseEncaixotador
				:public FabricaDeEncaixotadorExcecao
		{
			public:
				FabricaNaoSabeFabricarEsseEncaixotador
						::FabricaNaoSabeFabricarEsseEncaixotador() {}
		};

		class CaixaExcecao: public EmpacotamentoExcecao {
			public:
				CaixaExcecao::CaixaExcecao() {}
		};

		class PacotesRepetidosExcecao: public CaixaExcecao {
			public:
				PacotesRepetidosExcecao::PacotesRepetidosExcecao() {}
		};

		class EmpacotadorNaoSabeManipularEsseTipoExcecao
				:public EmpacotamentoExcecao
		{
			public:
				EmpacotadorNaoSabeManipularEsseTipoExcecao
						::EmpacotadorNaoSabeManipularEsseTipoExcecao() {}
		};

		class EncaixotadorNaoSabeManipularEsseTipoExcecao
				:public EncaixotamentoExcecao
		{
			public:
				EncaixotadorNaoSabeManipularEsseTipoExcecao
						::EncaixotadorNaoSabeManipularEsseTipoExcecao() {}
		};

		class InformacaoNaoEncaixotadaExcecao
				:public EncaixotamentoExcecao
		{
			public:
				InformacaoNaoEncaixotadaExcecao
						::InformacaoNaoEncaixotadaExcecao() {}
		};
	}
  }
}

#endif // !defined(AFX_ETERNO_VOLATILEXCECAO_H__978F2EC5_DA6A_4FC1_B413_C5416B33717D__INCLUDED_)
