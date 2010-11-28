/*
 * $RCSfile: Objeto.h,v $
 * $Date: 2004/12/02 20:56:49 $
 * $Revision: 1.18 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#pragma warning(disable:4290) // SLTport: C++ Exception Specification ignored
#endif

#ifndef OBJETO_SW_H
#define OBJETO_SW_H

//#include <deque>
#include <string>
#include <typeinfo>
#include <stdlib.h>
#include <stdio.h>

/*
 * Toda classe dentro da b�blia
 * deriva de {@link basico.Objeto}.
 */

/*
 * A biblioteca dmalloc � respons�vel pela
 * depura��o de erros relacionados � aloca��o
 * din�mica de mem�ria.
 * Como seu uso � restrito ao linux, foi-se
 * necess�rio a cria��o da macro NOVO para que
 * o programa tamb�m pudesse ser compilado
 * para windows.
 *
 * Essa macro � apenas um "apelido" para o
 * operator new (compila��o para windows) ou
 * para a macro chamada D_NEW - utilizada pela dmalloc
 * para registrar o numero da linha e o arquivo
 * onde oncorreu o memory leak.
 *
 */

#ifdef DMALLOC
	#include "dmalloc.h"
	#define NOVO D_NEW
#else
	#define NOVO new
#endif

#ifdef WIN32
	#define UNSIGNED_INT_64_BIBLIA unsigned __int64
	#define INT_64_BIBLIA __int64
#else
	#define UNSIGNED_INT_64_BIBLIA unsigned long long
	#define INT_64_BIBLIA long long
#endif

namespace biblia {
  namespace basico {

	/**
	 * Classe pai, comum entre todas
	 * do pacote biblia.
	 */
	class Objeto {
		protected:
			/**
			 * S� pode ser instanciado por um filho.
			 */
			Objeto::Objeto() {}

		public:
			virtual Objeto::~Objeto() {}

			/**
			 * Usado para debug.
			 * � implementado por padr�o
			 * para exibir sua posi��o na mem�ria.
			 */
			virtual std::string Objeto::emString() const;

			/**
			 * Usado para concatenar diretamente um Objeto �
			 * qualquer {@link std::string} sem a necessidade
			 * de se usar {@link #emString() const}.
			 */
			virtual std::string Objeto::operator+(const std::string) const;

			/**
			 * Verifica se � da mesma inst�ncia.
			 * <b>N�o pode ser reimplementado.</b>
			 */
			bool Objeto::mesmaInstancia(const Objeto*) const;

			/**
			 * Retorna o endere�o deste Objeto.
			 * <i>Reimplementado para que o C++
			 * n�o pegue o endere�o <s>de uma refer�ncia</s>
			 * 'por engano'.</i>
			 */
			virtual Objeto* Objeto::operator&();

			/**
			 * Retorna o endere�o deste Objeto.
			 * <i>Reimplementado para que o C++
			 * n�o pegue o endere�o <s>de uma refer�ncia</s>
			 * 'por engano'.</i>
			 */
			virtual const Objeto* const Objeto::operator&() const;
	};
  }
}

std::string operator+(const std::string, const biblia::basico::Objeto&);

#endif
