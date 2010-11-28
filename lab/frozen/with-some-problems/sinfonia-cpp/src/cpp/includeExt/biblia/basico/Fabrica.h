/*
 * $RCSfile: Fabrica.h,v $
 * $Date: 2004/03/30 21:09:21 $
 * $Revision: 1.3 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#pragma warning(disable:4290) // SLTport: C++ Exception Specification ignored
#endif

#if !defined(Fabrica_h)
#define Fabrica_h

#include "biblia/basico/Objeto.h"
#include "biblia/basico/Interface.h"

namespace biblia {
  namespace basico {
	/**
	 * Tem a fun��o de produzir um Objeto qualquer a partir de
	 * determinadas configura��es.
	 * <p>
	 * Deve ser configurada de alguma forma antes
	 * de se gerar alguma coisa. Para cada f�brica espec�fica
	 * h� uma maneira diferente de ser preparada para ser
	 * capaz de produzir algo. --- Isso (ter um m�todo
	 * gera() em comum) pode ser interessante
	 * quando se necessita de produ��es em s�rie e n�o se
	 * sabe o tipo das f�bricas.
	 * <p>
	 * O uso de Fabrica � adequado para objetos que t�m
	 * constru��o complexa; para quando � importante a separa��o
	 * do conceito de 'cria��o do objeto' do objeto em si; e tamb�m
	 * para efeitos de polimorfismos interessantes e f�cil troca
	 * da constru��o de um objeto. --- Por�m, para efeito de
	 * praticidade, � importante medir a necessidade
	 * de uma f�brica. --- Em caso de d�vida, � interessante
	 * criar uma f�brica pois a quantidade de c�digo pode
	 * ficar praticamente a mesma que ter um construtor e o
	 * processo de converter construtores em f�bricas (depois
	 * de um c�digo j� pronto) pode ser custoso demais.
	 * <p>
	 * <i>nota1: Existem outras formas de implementa��o de f�brica
	 * que, e. g., usam uma inst�ncia-padr�o de si est�tica para
	 * 'esconder' a cria��o da pr�pria f�brica, por�m esse tipo
	 * de implementa��o n�o cabe a este tipo de f�brica espec�fico
	 * que precisa de pr�-configura��es para ser capaz de gerar
	 * alguma coisa.</i>
	 * <p>
	 * <i>nota2: Foi definido no diagrama como um "estere�tipo" porque uma
	 * F�brica � um tipo especial pois necessita ser "friend" da Classe
	 * que produz.</i>
	 */
	class Fabrica: public Interface {
		public:
			/*
			 * Gera um Objeto e o retorna.
			 */
			virtual Objeto* Fabrica::gera() = 0;
	};
  }
}

#endif /* Fabrica_h */
