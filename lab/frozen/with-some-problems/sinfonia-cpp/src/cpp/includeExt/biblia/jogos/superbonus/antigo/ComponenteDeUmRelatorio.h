/*
 * $RCSfile: ComponenteDeUmRelatorio.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.2 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef COMPONENTE_H_SW
#define COMPONENTE_H_SW

/*
 * Componente de um relat�rio representa algo que pode
 * pode fazer parte de um relat�rio. Por exemplo: uma tabela,
 * inputs, labels,etc.
 */

class ComponenteDeUmRelatorio {
	protected:
		/*indica qual eh o tipo do componente*/
		long pTipoDoComponente;
		ComponenteDeUmRelatorio(long tipo);
	public:
		bool ehDoTipo(ComponenteDeUmRelatorio& componente) const ;
};
#endif
