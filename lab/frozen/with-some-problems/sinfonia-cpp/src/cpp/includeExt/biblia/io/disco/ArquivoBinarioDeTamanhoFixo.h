/*
 * $RCSfile: ArquivoBinarioDeTamanhoFixo.h,v $
 * $Date: 2005/01/20 21:28:43 $
 * $Revision: 1.3 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_ARQUIVOBINARIODETAMANHOFIXO_H__0A6BD93A_8076_4859_99E4_88C4F006C750__INCLUDED_)
#define AFX_ARQUIVOBINARIODETAMANHOFIXO_H__0A6BD93A_8076_4859_99E4_88C4F006C750__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include <fstream>
#include "biblia/util/Debug.h"
#include "biblia/basico/Objeto.h"
#include "biblia/fluxo/Semaforo.h"
#include "biblia/io/disco/DiscoExcecao.h"
#include "biblia/armazenamento/volatil/carcacas/DadosSemTipo.h"

using namespace std;
using namespace biblia::util;
using namespace biblia::basico;
using namespace biblia::fluxo;
using namespace biblia::armazenamento::volatil::carcacas;

namespace biblia {
  namespace io {
    namespace disco {
		class ArquivoBinarioDeTamanhoFixo:public Objeto	{
			private:
				std::string ArquivoBinarioDeTamanhoFixo::pCaminho;
				mutable fstream ArquivoBinarioDeTamanhoFixo::pArquivo;
				bool ArquivoBinarioDeTamanhoFixo::pAutoFlush;
				bool ArquivoBinarioDeTamanhoFixo::pSomenteLeitura;
				Semaforo ArquivoBinarioDeTamanhoFixo::pSemaforo;
				int ArquivoBinarioDeTamanhoFixo::pTamanho;

				ArquivoBinarioDeTamanhoFixo::ArquivoBinarioDeTamanhoFixo
						(const ArquivoBinarioDeTamanhoFixo&):pSemaforo(1)
				{}

			public:
				ArquivoBinarioDeTamanhoFixo
					::ArquivoBinarioDeTamanhoFixo
						(const int& tamanho,
						 const std::string& caminho,
						 bool somenteLeitura = true,
						 bool autoFlush = false);

				virtual ArquivoBinarioDeTamanhoFixo
						::~ArquivoBinarioDeTamanhoFixo();

				virtual ArquivoBinarioDeTamanhoFixo&
						ArquivoBinarioDeTamanhoFixo::fecha();

				virtual ArquivoBinarioDeTamanhoFixo&
						ArquivoBinarioDeTamanhoFixo::flush();

				virtual ArquivoBinarioDeTamanhoFixo&
						ArquivoBinarioDeTamanhoFixo::limpaErro();

				virtual const std::string&
					ArquivoBinarioDeTamanhoFixo::caminho() const;

				virtual const bool& ArquivoBinarioDeTamanhoFixo
						::autoFlush() const;

				virtual const bool& ArquivoBinarioDeTamanhoFixo
						::somenteLeitura() const;

				virtual ArquivoBinarioDeTamanhoFixo&
						ArquivoBinarioDeTamanhoFixo
							::autoFlush(bool sim);

				virtual const bool ArquivoBinarioDeTamanhoFixo
						::estaAberto() const;

				virtual iostream& ArquivoBinarioDeTamanhoFixo::io();

				virtual const iostream&
						ArquivoBinarioDeTamanhoFixo::io() const;

				virtual const bool ArquivoBinarioDeTamanhoFixo
						::deuErro() const;

				virtual const int ArquivoBinarioDeTamanhoFixo
						::tamanho() const;

				virtual ArquivoBinarioDeTamanhoFixo&
						ArquivoBinarioDeTamanhoFixo
							::grava(const DadosSemTipo& dados);

				virtual ArquivoBinarioDeTamanhoFixo&
						ArquivoBinarioDeTamanhoFixo
							::le(DadosSemTipo& dados);

				// Objeto:
				virtual std::string ArquivoBinarioDeTamanhoFixo
						::emString();
		};
	}
  }
}

#endif // !defined(AFX_ARQUIVOBINARIODETAMANHOFIXO_H__0A6BD93A_8076_4859_99E4_88C4F006C750__INCLUDED_)
