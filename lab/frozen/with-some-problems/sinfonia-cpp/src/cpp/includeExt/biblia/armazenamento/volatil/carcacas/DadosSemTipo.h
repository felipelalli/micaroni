/*
 * $RCSfile: DadosSemTipo.h,v $
 * $Date: 2004/02/26 18:49:18 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_DADOSSEMTIPO_H__C6205E88_CD15_400F_BB85_79D936BA86B6__INCLUDED_)
#define AFX_DADOSSEMTIPO_H__C6205E88_CD15_400F_BB85_79D936BA86B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <cctype>
#include "biblia/basico/Objeto.h"
#include "biblia/basico/Excecao.h"
#include "biblia/armazenamento/volatil/primitivos/Inteiro.h"

using namespace biblia::basico;
using namespace biblia::armazenamento::volatil::primitivos;

namespace biblia {
  namespace armazenamento {
 	namespace volatil {
	  namespace carcacas {
		/**
		 * Esta classe representa um bloco
		 * de dados de um tipo desconhecido.
		 * <p>
		 * Esses dados são armazenados num vetor
		 * de bytes (char) com um tamanho fixo
		 * porque a maioria dos <i>hardwares</i> são
		 * otimizados para uma sequência de bytes.
		 * <p>
		 * Para acessar diretamente o ponteiro
		 * dos dados utilize a função <code>acessoDireto()</code>:
		 * isso pode ser mais otimizado, como no caso de
		 * funções de cópia de blocos de memória
		 * otimizados em assembler.
		 * <p>
		 * <i>Cuidado com os valores iniciais
		 * pois eles são lixos. Utilize essa
		 * classe da mesma forma que você utilizaria
		 * um <code>char[]</code>.</i>
		 */
		class DadosSemTipo: public Objeto {
			private:
				char* DadosSemTipo::pDados;
				unsigned int DadosSemTipo::pTamanho;

				/**
				 * Proibido: seria lento demais.
				 */
				DadosSemTipo::DadosSemTipo(const DadosSemTipo&);

			public:
				DadosSemTipo::DadosSemTipo(const unsigned int& tamanho);
				virtual DadosSemTipo::~DadosSemTipo();

				virtual DadosSemTipo& DadosSemTipo
						::modifica(const unsigned int& posicao,
								   const char& valor)
				{
					this->pDados[posicao] = valor;
					return *this;
				}

				virtual unsigned char DadosSemTipo
						::acessaByte(const unsigned int& posicao) const
				{
					return this->pDados[posicao];
				}

				virtual const char* DadosSemTipo::acessoDireto() const;
				virtual char* DadosSemTipo::acessoDireto();
				inline virtual const unsigned int& DadosSemTipo
						::tamanho() const;

				// operadores:
				virtual char& DadosSemTipo
						::operator[](const unsigned int& posicao);

				virtual const char& DadosSemTipo
						::operator[](const unsigned int& posicao) const;

				virtual DadosSemTipo& DadosSemTipo
						::operator=(const DadosSemTipo&);

				virtual const bool DadosSemTipo
						::operator==(const DadosSemTipo&) const;

				virtual const bool DadosSemTipo
						::operator!=(const DadosSemTipo& dst) const
				{
					return !((*this) == dst);
				}

				// Objeto:
				virtual std::string DadosSemTipo::emString() const;
		};
	  }
	}
  }
}

#endif // !defined(AFX_DADOSSEMTIPO_H__C6205E88_CD15_400F_BB85_79D936BA86B6__INCLUDED_)
