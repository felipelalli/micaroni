/*
 * $RCSfile: ComponenteDeUmRelatorio.h,v $
 * $Date: 2004/04/26 20:59:05 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#ifndef TROPICAL_SBS_COMPONENTE_H_SW
#define TROPICAL_SBS_COMPONENTE_H_SW

/*
 * Componente de um relatório representa algo que pode
 * pode fazer parte de um relatório. Por exemplo: uma tabela,
 * inputs, labels,etc.
 */

namespace biblia{
	namespace jogos {
		namespace frutinha {
			namespace antigo {

				class ComponenteDeUmRelatorio {
					protected:
						/*indica qual eh o tipo do componente*/
						long pTipoDoComponente;
						ComponenteDeUmRelatorio(long tipo);
					public:
						bool ehDoTipo(ComponenteDeUmRelatorio& componente) const ;
				};
			}
		}
	}
}
#endif
