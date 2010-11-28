/*
 * $RCSfile: Fabrica.h,v $
 * $Date: 2004/03/30 21:09:21 $
 * $Revision: 1.3 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
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
	 * Tem a função de produzir um Objeto qualquer a partir de
	 * determinadas configurações.
	 * <p>
	 * Deve ser configurada de alguma forma antes
	 * de se gerar alguma coisa. Para cada fábrica específica
	 * há uma maneira diferente de ser preparada para ser
	 * capaz de produzir algo. --- Isso (ter um método
	 * gera() em comum) pode ser interessante
	 * quando se necessita de produções em série e não se
	 * sabe o tipo das fábricas.
	 * <p>
	 * O uso de Fabrica é adequado para objetos que têm
	 * construção complexa; para quando é importante a separação
	 * do conceito de 'criação do objeto' do objeto em si; e também
	 * para efeitos de polimorfismos interessantes e fácil troca
	 * da construção de um objeto. --- Porém, para efeito de
	 * praticidade, é importante medir a necessidade
	 * de uma fábrica. --- Em caso de dúvida, é interessante
	 * criar uma fábrica pois a quantidade de código pode
	 * ficar praticamente a mesma que ter um construtor e o
	 * processo de converter construtores em fábricas (depois
	 * de um código já pronto) pode ser custoso demais.
	 * <p>
	 * <i>nota1: Existem outras formas de implementação de fábrica
	 * que, e. g., usam uma instância-padrão de si estática para
	 * 'esconder' a criação da própria fábrica, porém esse tipo
	 * de implementação não cabe a este tipo de fábrica específico
	 * que precisa de pré-configurações para ser capaz de gerar
	 * alguma coisa.</i>
	 * <p>
	 * <i>nota2: Foi definido no diagrama como um "estereótipo" porque uma
	 * Fábrica é um tipo especial pois necessita ser "friend" da Classe
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
