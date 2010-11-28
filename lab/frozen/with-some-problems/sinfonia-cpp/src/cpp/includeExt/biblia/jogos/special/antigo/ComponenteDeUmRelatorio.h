/*
 * $RCSfile: ComponenteDeUmRelatorio.h,v $
 * $Date: 2003/06/26 00:52:31 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef SBS_COMPONENTE_H_SW
#define SBS_COMPONENTE_H_SW

/*
 * Componente de um relatório representa algo que pode
 * pode fazer parte de um relatório. Por exemplo: uma tabela,
 * inputs, labels,etc.
 */

namespace biblia{
	namespace jogos {
		namespace special {
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
