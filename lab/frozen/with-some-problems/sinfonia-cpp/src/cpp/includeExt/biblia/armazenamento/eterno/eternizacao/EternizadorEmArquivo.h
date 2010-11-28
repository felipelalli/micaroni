/*
 * $RCSfile: EternizadorEmArquivo.h,v $
 * $Date: 2005/01/20 21:28:34 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_ETERNIZADOREMARQUIVO_H__E6FFBD3A_3EAF_4E0D_ABE5_87D9A22E9712__INCLUDED_)
#define AFX_ETERNIZADOREMARQUIVO_H__E6FFBD3A_3EAF_4E0D_ABE5_87D9A22E9712__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/util/Lixeira.h"
//#include "biblia/util/StringTokenizer.h"
#include "biblia/util/StrToken.h"
#include "biblia/armazenamento/volatil/carcacas/MapaHash.h"
#include "biblia/armazenamento/eterno/DadosEmArquivo.h"
#include "biblia/armazenamento/eterno/VariavelEmArquivo.h"
#include "biblia/armazenamento/eterno/eternizacao/EternizadorDePacotes.h"

using namespace biblia::util;
using namespace biblia::armazenamento::eterno;
using namespace biblia::armazenamento::volatil::carcacas;

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace eternizacao {
		class EternizadorEmArquivo: public EternizadorDePacotes {
			private:
				const std::string EternizadorEmArquivo::pIndice;
				VariavelEmArquivo<string>* EternizadorEmArquivo
						::pTodosPacotes;

				MapaHash<VariavelEmArquivo<string>* >
						EternizadorEmArquivo::pTipoDoDado;

				/**
				 * Se for -1 é tamanho variável.
				 * Se for >= 0 é o tamanho do dado em si.
				 */
				MapaHash<VariavelEmArquivo<int>* >
						EternizadorEmArquivo::pTamanhoDoDado;

				/**
				 * VariavelEmArquivo<string> ou
				 * DadosEmArquivo<tamanho>
				 */
				MapaHash<Objeto*> EternizadorEmArquivo::pDados;

				/**
				 * Tudo que esta classe instanciar.
				 */
				Lixeira EternizadorEmArquivo::pLixo;

			protected:
				// Resolução dos índices:

				virtual const std::string EternizadorEmArquivo
						::indiceInicial() const;

				virtual const std::string EternizadorEmArquivo
						::indiceTipoDoDado(
							const std::string& indice) const;

				virtual const std::string EternizadorEmArquivo
						::indiceTipoDoArmazenamento(
							const std::string& indice) const;

				virtual const std::string EternizadorEmArquivo
						::indiceDados(const std::string& indice) const;

				virtual VariavelEmArquivo<string>&
						EternizadorEmArquivo::pacotesEternos();

				virtual const VariavelEmArquivo<string>&
						EternizadorEmArquivo::pacotesEternos() const;

				// Dados:

				virtual VariavelEmArquivo<string>*
						EternizadorEmArquivo::tipoDoDado(
							const Identificacao& indice);

				virtual VariavelEmArquivo<int>*
						EternizadorEmArquivo::tamanhoDoDado(
							const Identificacao& indice);

				virtual Objeto*	EternizadorEmArquivo::dados(
							const Identificacao& indice,
							const int& tamanho);

				// Pacote:
				/**
				 * Cria um novo pacote baseado nas informações
				 * apenas para consulta.
				 */
				virtual PacoteSelado* EternizadorEmArquivo
						::criaNovoPacote(const Identificacao&,
									 const Tipo&,
									 const int& tamanho,
									 Objeto* dados) const;

				/**
				 * Adiciona novo pacote na caixa local.
				 */
				virtual EternizadorEmArquivo& EternizadorEmArquivo
						::adicionaNovoPacote(const Identificacao&,
									 const Tipo&,
									 const int& tamanho,
									 Objeto* dados);

				/**
				 * Verifica se o pacote existe no
				 * índice inicial.
				 */
				virtual const bool EternizadorEmArquivo
						::existeNoIndiceInicial(const Identificacao&) const;

			public:
				EternizadorEmArquivo::EternizadorEmArquivo(
						const bool& sincronizaTudo = true,
						const std::string& indice = "padrão");

				virtual EternizadorEmArquivo::~EternizadorEmArquivo();

				// EternizadorDePacotes:

				virtual EternizadorDePacotes&
						EternizadorEmArquivo
							::eterniza(const Caixa&,
								       const bool& forcar = false,
									   const bool& verificaSeMudou
											= true);

				virtual EternizadorDePacotes&
						EternizadorEmArquivo
							::apagaDiferenca(
								const Caixa& todaACaixa);

				virtual const bool EternizadorEmArquivo
						::estaDessincronizado(
							const Identificacao&
							qualPacote) const;

				virtual const bool EternizadorEmArquivo
						::estaDessincronizado() const;

				virtual EternizadorDePacotes& EternizadorEmArquivo
						::sincroniza(const Identificacao&
									 qualPacote);

				virtual EternizadorDePacotes& EternizadorEmArquivo
						::sincronizaTudo();
		};
	  }
	}
  }
}

#endif // !defined(AFX_ETERNIZADOREMARQUIVO_H__E6FFBD3A_3EAF_4E0D_ABE5_87D9A22E9712__INCLUDED_)
