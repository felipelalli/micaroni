/*
 * $RCSfile: Arquivo.h,v $
 * $Date: 2005/03/14 23:14:55 $
 * $Revision: 1.22 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: cvsroot $)
 */

#if !defined(AFX_ARQUIVO_H__D21E8A38_8723_44FE_8D44_564B10DC6E75__INCLUDED_)
#define AFX_ARQUIVO_H__D21E8A38_8723_44FE_8D44_564B10DC6E75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include <fstream>
#include "biblia/basico/Objeto.h"
#include "biblia/util/Debug.h"

using namespace std;
using namespace biblia::basico;
using namespace biblia::util;

#include "biblia/seguranca/ChaveSeguranca.h"
using namespace biblia::seguranca;

#include "biblia/io/disco/ArquivoBasico.h"
using namespace biblia::io::disco;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;


namespace biblia {
  namespace io {
    namespace disco {		

		class Arquivo: public Objeto {
			private:

				static int qtsAbertos;
				static Semaforo pSemaAberto;			

				std::string Arquivo::pCaminho;
				std::string Arquivo::pCaminhoCriptografado;
				std::string Arquivo::pCaminhoTemporario;
				mutable std::fstream Arquivo::pArquivo;
				bool Arquivo::pAutoFlush;
				bool Arquivo::pSomenteLeitura;
				bool Arquivo::pFimDeArquivo;
				bool Arquivo::pEstaLendo;
				bool Arquivo::pEstaEscrevendo;
				ChaveSeguranca* Arquivo::pChaveSeguranca;
				Arquivo::Arquivo(const Arquivo&) {}

			public:
				static std::string Arquivo::TAG_FIM;
				Arquivo::Arquivo(const std::string& caminho,
								 bool somenteLeitura = true,
								 ChaveSeguranca* chaveSeguranca = NULL,
								 bool autoFlush = false);

				virtual Arquivo::~Arquivo();
				virtual Arquivo& Arquivo::escreve(const std::string);
				virtual Arquivo& Arquivo::escreveLinha(const std::string = "");
				virtual std::string Arquivo::leLinha();
				virtual Arquivo& Arquivo::flush();
				virtual Arquivo& Arquivo::comecaLer();
				virtual Arquivo& Arquivo::comecaEscrever();
				virtual Arquivo& Arquivo::terminaLer();
				virtual Arquivo& Arquivo::terminaEscrever();
				virtual Arquivo& Arquivo::fecha();
				virtual const bool& Arquivo::estaEscrevendo() const;
				virtual const bool& Arquivo::estaLendo() const;
				virtual Arquivo& Arquivo::vaiParaOInicio();
				virtual Arquivo& Arquivo::vaiPara(int posicao);
				virtual Arquivo& Arquivo::forcaFimDeArquivo();
				virtual bool Arquivo::fimDeArquivo() const;
				virtual const std::string& Arquivo::caminho() const;
				virtual const bool& Arquivo::autoFlush() const;
				virtual const bool& Arquivo::somenteLeitura() const;
				virtual const bool Arquivo::estaAberto() const;
				virtual const bool Arquivo::deuErro() const;
				virtual Arquivo& Arquivo::limpaErro();
				virtual Arquivo& Arquivo::autoFlush(bool);
				virtual std::iostream& Arquivo::io();
				virtual const std::iostream& Arquivo::io() const;

				static AGES_INT_64 Arquivo::tamanho (string caminho);
		};
	}
  }
}

#endif // !defined(AFX_ARQUIVO_H__D21E8A38_8723_44FE_8D44_564B10DC6E75__INCLUDED_)
