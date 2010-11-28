/*
 * $RCSfile: DHistorico.h,v $
 * $Date: 2005/01/20 21:28:53 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(SBS_AFX_DHISTORICO_H__98595372_4D45_4D1A_8200_5B489DB96C75__INCLUDED_)
#define SBS_AFX_DHISTORICO_H__98595372_4D45_4D1A_8200_5B489DB96C75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "biblia/jogos/special/dados/DadosXML.h"
#include "biblia/jogos/special/dados/DadosArqText.h"
#include "biblia/jogos/special/dados/Dados.h"
#include "biblia/jogos/special/dados/UltimasJogadas.h"
#include "biblia/util/CData.h"

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

using namespace biblia::util;


#define EVENTO_INICIOU_JOGO           1
#define EVENTO_FINALIZOU_JOGO         2
#define EVENTO_ABRIU_PORTA_MAQUINA    3
#define EVENTO_FECHOU_PORTA_MAQUINA   4
#define EVENTO_ABRIU_PORTA_DINHEIRO   5
#define EVENTO_FECHOU_PORTA_DINHEIRO  6
#define EVENTO_ENTROU_SISTEMA         7
#define EVENTO_SAIU_SISTEMA           8
#define EVENTO_ALTEROU_ACUMULADO      9
#define EVENTO_VOLTOU_AC_INICIAL     10
#define EVENTO_ALTEROU_AC_INICIAL    11
#define EVENTO_ZEROU_EST_E_CONT      12
#define EVENTO_ZEROU_REDE            13
#define EVENTO_CONFIGUROU_REDE       14
#define EVENTO_ENVIOU_CONF_REDE      15
#define EVENTO_RECEBEU_CONF_REDE     16
#define EVENTO_ENTROU_MENU           17
#define EVENTO_ALTEROU_MENU          18
#define EVENTO_RECUPEROU_SENHA       19
#define EVENTO_ABRIU_PORTA_CPU       20
#define EVENTO_FECHOU_PORTA_CPU      21

// novos eventos:

namespace biblia {
  namespace jogos {
    namespace special {
	  namespace dados {

		class DHistorico: public DadosXML {

			private:
				Dados* DHistorico::pDados;
				UltimasJogadas* DHistorico::pUltimasJogadas;

			public:
				static int EVENTO_LOGOU_USUARIO;
				static int EVENTO_DESLOGOU_USUARIO;
				static int EVENTO_RESET_PARCIAL;
				static int EVENTO_RESET_GERAL;
				static int EVENTO_SALVOU_SONS;
				static int EVENTO_CONCLUIU_REDE;
				static int EVENTO_DEFINIU_IP_LOCAL;
				static int EVENTO_MUDOU_LEITOR;

				enum Constantess{
					QTD_MAXIMA_REG_EVENTOS=500,
					QTD_MAXIMA_REG_NOTAS=500,
					QTD_MAXIMA_REG_PAGAMENTOS=500
				};

				DHistorico::DHistorico();
				virtual DHistorico::~DHistorico();

				virtual UltimasJogadas& DHistorico::ultimasJogadas();
				virtual DHistorico& DHistorico::adicionaEvento(
						long codigoDoEvento,
						const char* usuario = "?",
						const char* descricao = "?");

				virtual DHistorico& DHistorico::adicionaPagamento(
						double codigoDoPagamento,
						double valorDoPagamento);

				virtual DHistorico& DHistorico::adicionaNota(int nota);

				virtual biblia::armazenamento::volatil::Lista* DHistorico::eventos();
				virtual long DHistorico::proximoCodigo();

				static double DHistorico::emCodigo(
						long codigo, long maquina);

				static const char* DHistorico
						::dadosEmString(
								const CData&,
								long codigoDoEvento,
								const char* usuario,
								const char* adicional);

				static const char* DHistorico
						::dadosEmString(
								const CData& data,
								double codigoDoPagamento,
								double valor);

				static const CData& DHistorico
						::stringPagamentoEmData(const char* s);

				static const CData& DHistorico
						::stringEventoEmData(const char* s);

				static long DHistorico
						::stringEmCodigoDoEvento(const char* s);

				static int DHistorico
						::stringEmNota(const char* s);

				static double DHistorico
						::stringEmValorAcumulado(const char* s);

				static const char* DHistorico
						::stringEmUsuario(const char* s);

				static const char* DHistorico
						::stringEmDescricao(const char* s);

				static double DHistorico
						::stringEmCodigoDoPagamento(const char* s);

				static int DHistorico
						::stringEmValorDoPagamento(const char* s);

				bool DHistorico::salvarHistorico();
				DHistorico& DHistorico::zera();
		};
	  }
	}
  }
}

#endif // !defined(AFX_DHISTORICO_H__98595372_4D45_4D1A_8200_5B489DB96C75__INCLUDED_)
