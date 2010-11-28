/*
 * $RCSfile: Debug.h,v $
 * $Date: 2005/03/28 17:55:49 $
 * $Revision: 1.16 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

//#include "biblia/basico/Objeto.h"
//using namespace biblia::basico;

#include <cstdio>
#include <cstdlib>
#include <string>
#include <string>

#ifdef WIN32
#include <io.h>
#include <windows.h>
#else
#include <unistd.h>
#include <errno.h>
#endif

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "biblia/basico/Excecao.h"
using namespace biblia::basico;

#ifndef DEBUG_SW_H
#define DEBUG_SW_H

namespace biblia {
  namespace util {

	class ErroFatalExcecao: public Excecao {};

	enum NivelErro{
		INFO = 2,
		WARN = 1,
		ERRO = 0
	};

	class Debug {

		private:
			static NivelErro pNivel;
			static bool pMsgBox;
			static bool pToArquivoBasico;
			static char pArquivoBasico[256];
			static bool pInformacoesAdicionais;

		public:

			static void Debug::msgBox (bool colocar);
			static void Debug::informacoesAdicionais(bool);
			static void Debug::setNivel (NivelErro nivel);
			static void Debug::msg(NivelErro nivel, const char* ms);
			static void Debug::msg(NivelErro nivel, std::string ms) {
				Debug::msg(nivel, ms.c_str());
			}
			static void Debug::beep();
			static void Debug::toArquivoBasico(const char* arquivo,
										 bool mesmoArquivoBasico = false);
			static void Debug::sair(const char* = "");
			static void Debug::sair(std::string s) {
				Debug::sair(s.c_str());
			}

	};
  }
}

#endif
