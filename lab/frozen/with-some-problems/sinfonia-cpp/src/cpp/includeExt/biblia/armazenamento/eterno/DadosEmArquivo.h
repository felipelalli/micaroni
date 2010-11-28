/*
 * $RCSfile: DadosEmArquivo.h,v $
 * $Date: 2005/01/20 21:28:32 $
 * $Revision: 1.5 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_DADOSEMARQUIVO_H__2EC83409_E4C3_42FE_92B6_154CE2EE6883__INCLUDED_)
#define AFX_DADOSEMARQUIVO_H__2EC83409_E4C3_42FE_92B6_154CE2EE6883__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/io/disco/ArquivoBasico.h"
#include "biblia/io/disco/ArquivoBinarioDeTamanhoFixo.h"
#include "biblia/armazenamento/volatil/carcacas/DadosSemTipo.h"
#include "biblia/armazenamento/eterno/VariavelEmArquivo.h"
#include "biblia/armazenamento/eterno/VariavelEterna.h"

using namespace biblia::basico;
using namespace biblia::io::disco;
using namespace biblia::armazenamento::volatil::carcacas;

namespace biblia {
  namespace armazenamento {
    namespace eterno {
		class DadosEmArquivo: public VariavelEterna<DadosSemTipo> {
			private:
				ArquivoBinarioDeTamanhoFixo*
						DadosEmArquivo::pArquivo;

				bool DadosEmArquivo::pMudou;
				DadosSemTipo* DadosEmArquivo::pDados;

				/**
				 * Proibido.
				 */
				DadosEmArquivo(const DadosEmArquivo&)
						:VariavelEterna<DadosSemTipo>("") {}

			protected:
				virtual ArquivoBinarioDeTamanhoFixo&
						DadosEmArquivo::arquivo();

			public:
				DadosEmArquivo::DadosEmArquivo(
						const int& tamanho, const std::string& id,
						ResolvedorDeNomes& r = ResolvedorAlphaNumerico::singleton());

				virtual DadosEmArquivo::~DadosEmArquivo();

				// VariavelEterna:

				/**
				 * Retorna o conteúdo.
				 */
				virtual const DadosSemTipo&
						DadosEmArquivo::valor() const;

				/**
				 * Retorna o conteúdo para ser modificado.
				 */
				virtual DadosSemTipo& DadosEmArquivo
						::pegaValorPraMudar();

				/**
				 * É necessário que o Tipo tenha o operador !=
				 *
				 * @throw DadosDeTamanhoDiferenteExcecao
				 */
				virtual VariavelEterna<DadosSemTipo>&
						DadosEmArquivo::muda(
							const DadosSemTipo& c);

				virtual VariavelEterna<DadosSemTipo>&
						DadosEmArquivo::restaura();

				virtual VariavelEterna<DadosSemTipo>&
						DadosEmArquivo::destroi();

				// Executavel:
				virtual VariavelEterna<DadosSemTipo>&
						DadosEmArquivo::salva();
		};
	}
  }
}

#endif // !defined(AFX_DADOSEMARQUIVO_H__2EC83409_E4C3_42FE_92B6_154CE2EE6883__INCLUDED_)
