/*
 * $RCSfile: ComponenteDeUmRelatorio.h,v $
 * $Date: 2005/01/19 17:21:52 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_COMPONENTE_H_SW
#define AGES_SPECIAL_UPGRADE_SBS_COMPONENTE_H_SW

/*
 * Componente de um relatório representa algo que pode
 * pode fazer parte de um relatório. Por exemplo: uma tabela,
 * inputs, labels,etc.
 */

namespace biblia{
	namespace jogos {
		namespace specialUpgrade {
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
