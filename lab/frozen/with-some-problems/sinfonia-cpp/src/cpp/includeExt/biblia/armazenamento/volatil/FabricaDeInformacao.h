/*
 * $RCSfile: FabricaDeInformacao.h,v $
 * $Date: 2004/02/11 23:28:52 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_FABRICADEINFORMACAO_H__E272D0BD_51F5_449B_835A_64AFC7D00228__INCLUDED_)
#define AFX_FABRICADEINFORMACAO_H__E272D0BD_51F5_449B_835A_64AFC7D00228__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/basico/Fabrica.h"
#include "biblia/armazenamento/volatil/Tipo.h"
#include "biblia/armazenamento/volatil/VolatilExcecao.h"

using namespace biblia::basico;

namespace biblia {
  namespace armazenamento {
    namespace volatil {
		/**
		 * Fabrica uma Informacao a partir de um Tipo.
		 * Pode ser muito �til para criar inst�ncias de
		 * informa��es de Tipo din�mico/desconhecido
		 * em tempo de execu��o.
		 */
		class FabricaDeInformacao: public Fabrica, public Objeto {
			private:
				Tipo FabricaDeInformacao::pAFabricar;

			public:
				static const Tipo FabricaDeInformacao::TIPO_INDEFINIDO;

				FabricaDeInformacao::FabricaDeInformacao();
				virtual FabricaDeInformacao::~FabricaDeInformacao();

				/**
				 * Define qual tipo primivo esta
				 * f�brica vai gerar. A fun��o
				 * #gera() deve ser chamada ap�s
				 * esta.
				 *
				 * @throw TipoDesconhecidoExcecao
				 * @see #sabeGerarUm(const Tipo&) const
				 */
				virtual FabricaDeInformacao& FabricaDeInformacao
						::preparaParaGerarUm(const Tipo&);

				/**
				 * Retorna o �ltimo tipo definido
				 * em "preparaParaGerarUm(const Tipo&)".
				 */
				virtual const Tipo& FabricaDeInformacao::aGerar() const;

				/**
				 * Verifica se esta f�brica sabe
				 * gerar um determinado tipo.
				 */
				virtual const bool FabricaDeInformacao
						::sabeGerarUm(const Tipo&) const = 0;

				// Fabrica:
				virtual Objeto* FabricaDeInformacao::gera() = 0;
		};
	}
  }
}

#endif // !defined(AFX_FABRICADEINFORMACAO_H__E272D0BD_51F5_449B_835A_64AFC7D00228__INCLUDED_)
