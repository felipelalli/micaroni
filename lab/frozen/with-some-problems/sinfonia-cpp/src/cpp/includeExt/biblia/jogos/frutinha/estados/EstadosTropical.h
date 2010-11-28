/*
 * $RCSfile: EstadosTropical.h,v $
 * $Date: 2004/11/24 21:42:55 $
 * $Revision: 1.13 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef ESTADOS_TROPCIAL_H
#define ESTADOS_TROPCIAL_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/jogos/frutinha/estados/Acumulado.h"
#include "biblia/jogos/frutinha/estados/Ajuda.h"
#include "biblia/jogos/frutinha/estados/BarraDeMensagens.h"
#include "biblia/jogos/frutinha/estados/BarraPrincipal.h"
#include "biblia/jogos/frutinha/estados/Bonus.h"
#include "biblia/jogos/frutinha/estados/Cobranca.h"
#include "biblia/jogos/frutinha/estados/Configuracao.h"
#include "biblia/jogos/frutinha/estados/Dados.h"
#include "biblia/jogos/frutinha/estados/Jogada.h"
#include "biblia/jogos/frutinha/estados/RodilhoAnimado.h"
#include "biblia/jogos/frutinha/estados/Eventos.h"
using namespace biblia::jogos::frutinha::estados;

#include "biblia/util/Versao.h"
using namespace biblia::util;



namespace biblia{

	namespace jogos{

		namespace frutinha{

			namespace estados{

				class EstadosTropical : public Objeto{

					private:
						Acumulado pAcumulado;
						Ajuda pAjuda;
						BarraDeMensagens pBarraDeMensagens;
						BarraPrincipal pBarraPrincipal;						
						Bonus pBonus;
						Cobranca pCobranca;
						Configuracao pConfiguracao;
						Dados pDados;
						Jogada pJogada;
						RodilhoAnimado pRodilho;
						Eventos pEventos;
												
						bool pDeveRestaurarFundo;
						bool pTelaCarregando;
						Versao pVersao;

					public:
						EstadosTropical::EstadosTropical(
								UniversoDeTempo&, Contador&);

						virtual EstadosTropical::~EstadosTropical();

						virtual Acumulado& EstadosTropical::acumulado();
						virtual BarraPrincipal& EstadosTropical::barraPrincipal();
						virtual Bonus& EstadosTropical::bonus();
						virtual RodilhoAnimado& EstadosTropical::rodilho();
						virtual Ajuda& EstadosTropical::ajuda();
						virtual Cobranca& EstadosTropical::cobranca();
						virtual Jogada& EstadosTropical::jogada();
						virtual Configuracao& EstadosTropical::configuracao();
						virtual Dados& EstadosTropical::dados();
						virtual Versao& EstadosTropical::versao();
						virtual BarraDeMensagens& EstadosTropical::barraDeMensagem();
						virtual Eventos& EstadosTropical::eventos();

						virtual EstadosTropical& EstadosTropical
								::deveRestaurarFundo(const bool&);

						virtual const bool& EstadosTropical
								::deveRestaurarFundo() const;

						virtual EstadosTropical& EstadosTropical
								::telaCarregando(const bool&);

						virtual const bool& EstadosTropical
								::telaCarregando() const;
				};
			}
		}
	}
}

#endif