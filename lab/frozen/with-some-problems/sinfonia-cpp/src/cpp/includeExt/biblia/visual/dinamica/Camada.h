/*
 * $RCSfile: Camada.h,v $
 * $Date: 2003/06/16 22:40:59 $
 * $Revision: 1.6 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_CAMADA_H__A1E9B936_C450_401B_8EDC_569D0661BA97__INCLUDED_)
#define AFX_CAMADA_H__A1E9B936_C450_401B_8EDC_569D0661BA97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/util/Debug.h"
#include "biblia/visual/dinamica/DinamicaExcecao.h"

using namespace biblia::util;

namespace biblia {
  namespace visual {
    namespace dinamica {

		/**
		 * Faz um controle de camadas
		 * completo. A partir de uma camada
		 * � poss�vel encontrar tudo e fazer
		 * todas as opera��es relativas a camadas.
		 * <p>
		 * A camada � sempre relativa a outras
		 * camadas, i. e., se este recurso n�o for
		 * "bem" utilizado ele poder� entrar em
		 * recurs�o infinita.
		 *
		 * @bug Possivelmente h� jeito mais eficiente
		 *        de se implementar esta Camada. Testar
		 *        exaustivamente porque n�o est� 100% testada! :)
		 */
		class Camada: public Objeto {
			private:
				Camada* Camada::pAcimaDe;
				Camada* Camada::pAbaixoDe;
				Objeto* Camada::pObjeto;

				/**
				 * N�o existe c�pia de camada.
				 */
				Camada::Camada(const Camada&) {};

			public:
				/**
				 * Cria uma camada do 'nada'.
				 * As fun��es colocaEmCimaDe()
				 * ou colocaEmBaixoDe() devem
				 * ser chamadas logo ap�s isto.
				 *
				 * Uma camada <i>pode</i> ser associada
				 * a um {@link biblia::basico::Objeto
				 * objeto} qualquer.
				 */
				Camada::Camada(Objeto* = NULL);
				virtual Camada::~Camada();

				Camada& Camada::pegaTopo();
				Camada& Camada::pegaBase();

				Camada& Camada::aDeBaixo() const;
				Camada& Camada::aDeCima() const;
				const bool Camada::estaNoTopo() const;
				const bool Camada::estaNaBase() const;
				const bool Camada::estaAcimaDe(const Camada&) const;
				const bool Camada::estaAbaixoDe(const Camada&) const;
				const bool Camada::eDaMesmaListaDeCamadas(const Camada&) const;
				const bool Camada::mesmaCamada(const Camada&) const;
				const bool Camada::sozinha() const;

				Camada& Camada::sobe();
				Camada& Camada::desce();
				Camada& Camada::vaiProTopo();
				Camada& Camada::vaiPraBase();
				Camada& Camada::colocaEmCimaDe(Camada&);
				Camada& Camada::colocaEmBaixoDe(Camada&);

				const bool Camada::estaAssociada() const;
				Objeto* Camada::associadaA() const;
				Camada& Camada::associaA(Objeto*);
		};
	}
  }
}

#endif // !defined(AFX_CAMADA_H__A1E9B936_C450_401B_8EDC_569D0661BA97__INCLUDED_)
