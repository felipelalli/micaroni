/*
 * $RCSfile: MontadorDeTelas.h,v $
 * $Date: 2005/01/20 21:29:01 $
 * $Revision: 1.37 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_MONTADORDETELAS_H__85D5DA5B_7114_4F2A_BD66_7D2BB019A67B__INCLUDED_)
#define AFX_MONTADORDETELAS_H__85D5DA5B_7114_4F2A_BD66_7D2BB019A67B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include "biblia/util/CData.h"
#include "biblia/util/Carregador.h"
#include "biblia/fluxo/Executavel.h"
#include "biblia/seguranca/Usuario.h"
#include "biblia/seguranca/util/TipoUsuario.h"
#include "biblia/seguranca/ChaveSeguranca.h"
#include "biblia/seguranca/ControleLicenca.h"
#include "biblia/io/som/CarregadorDeSom.h"
#include "biblia/armazenamento/volatil/ListaString.h"
#include "biblia/jogos/superbonus/logica/LogicaAcumulado.h"
#include "biblia/jogos/superbonus/dados/DadosConfiguracao.h"
#include "biblia/jogos/superbonus/dados/DEstatisticaEmRede.h"
#include "biblia/jogos/superbonus/dados/DHistoricoEmRede.h"
#include "biblia/jogos/superbonus/dados/DEstatistica.h"
#include "biblia/jogos/superbonus/dados/EnviadorDeDadosPelaRede.h"
#include "biblia/jogos/superbonus/dados/ZeradorDeDados.h"
#include "biblia/jogos/superbonus/dados/util/DadosJogada.h"
#include "biblia/jogos/superbonus/util/NumeroUtil.h"
#include "biblia/visual/dinamica/CarregadorDeComponentes.h"
#include "biblia/visual/formulario/Paginas.h"
#include "biblia/visual/formulario/PosicaoXYRelativa.h"
#include "biblia/visual/formulario/Formulario.h"
#include "biblia/visual/formulario/Plano.h"
#include "biblia/visual/formulario/Grupo.h"
#include "biblia/visual/formulario/Caixa3D.h"
#include "biblia/visual/formulario/Label.h"
#include "biblia/visual/formulario/SelecaoImagem.h"
#include "biblia/visual/formulario/TamanhoRelativo.h"
#include "biblia/visual/formulario/TabelaComponente.h"
#include "biblia/visual/formulario/TabelaMagica.h"
#include "biblia/visual/formulario/BotaoComponente.h"
#include "biblia/visual/formulario/InputInteiro.h"
#include "biblia/visual/formulario/InputLimitado.h"
#include "biblia/visual/formulario/AnimacaoComponente.h"
#include "biblia/visual/formulario/Volume.h"

using namespace biblia::util;
using namespace biblia::fluxo;
using namespace biblia::seguranca;
using namespace biblia::io::som;
using namespace biblia::armazenamento::volatil;
using namespace biblia::visual::formulario;
using namespace biblia::visual::dinamica;
using namespace biblia::jogos::superbonus::logica;
using namespace biblia::jogos::superbonus::dados;
using namespace biblia::jogos::superbonus::util;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace visual {
		namespace formulario {
			class MontadorDeTelas;

			class BotaoComThis: public Executavel, public Objeto {
				private:
					MontadorDeTelas* BotaoComThis::pThis;

				protected:
					BotaoComThis::BotaoComThis();

				public:
					virtual BotaoComThis::~BotaoComThis();
					virtual BotaoComThis& BotaoComThis
							::defineThis(MontadorDeTelas*);

					virtual MontadorDeTelas& BotaoComThis::it();
					virtual Executavel& BotaoComThis::executa() = 0;
			};

			class ExecutandoBotao: public BotaoComThis {
				private:
					std::string ExecutandoBotao::oq;

				protected:
					virtual ExecutandoBotao& ExecutandoBotao::aperte();

				public:
					ExecutandoBotao::ExecutandoBotao(std::string id);
					virtual ExecutandoBotao::~ExecutandoBotao();
					virtual ExecutandoBotao& ExecutandoBotao
							::processamentoEspecifico();

					virtual Executavel& ExecutandoBotao::executa();
			};

			class BotaoGravaSons: public BotaoComThis {
				public:
					BotaoGravaSons::BotaoGravaSons() {}
					virtual BotaoGravaSons::~BotaoGravaSons() {}
					virtual Executavel& BotaoGravaSons::executa();
			};

			class InputDefineUsuario: public BotaoComThis {
				public:
					InputDefineUsuario::InputDefineUsuario() {}
					virtual InputDefineUsuario::~InputDefineUsuario() {}
					virtual Executavel& InputDefineUsuario::executa();
			};

			class BotaoRecuperaSenha: public BotaoComThis {
				public:
					BotaoRecuperaSenha::BotaoRecuperaSenha() {}
					virtual BotaoRecuperaSenha::~BotaoRecuperaSenha() {}
					virtual Executavel& BotaoRecuperaSenha::executa();
			};

			class BotaoResetPeriodica: public BotaoComThis {
				public:
					BotaoResetPeriodica::BotaoResetPeriodica() {}
					virtual BotaoResetPeriodica::~BotaoResetPeriodica() {}
					virtual Executavel& BotaoResetPeriodica::executa();
			};

			class BotaoResetPermanente: public BotaoComThis {
				public:
					BotaoResetPermanente::BotaoResetPermanente() {}
					virtual BotaoResetPermanente::~BotaoResetPermanente() {}
					virtual Executavel& BotaoResetPermanente::executa();
			};

			class BotaoViraPaginaHistorico: public BotaoComThis {
				private:
					bool praFrente;
					std::string oq;

				public:
					BotaoViraPaginaHistorico
							::BotaoViraPaginaHistorico(std::string o,
								bool praTras = false)
									:praFrente(!praTras), oq(o) {}

					virtual BotaoViraPaginaHistorico::~BotaoViraPaginaHistorico() {}
					virtual Executavel& BotaoViraPaginaHistorico::executa();
			};

			class AtualizaHabilitacoes: public BotaoComThis {
				public:
					AtualizaHabilitacoes::AtualizaHabilitacoes() {}
					virtual AtualizaHabilitacoes::~AtualizaHabilitacoes() {}
					virtual Executavel& AtualizaHabilitacoes::executa();
			};

			class BotaoDeExcluirMaquina: public BotaoComThis {
				public:
					BotaoDeExcluirMaquina::BotaoDeExcluirMaquina() {}
					virtual BotaoDeExcluirMaquina::~BotaoDeExcluirMaquina() {}
					virtual Executavel& BotaoDeExcluirMaquina::executa();
			};

			class BotaoAtualizaRede: public BotaoComThis {
				public:
					BotaoAtualizaRede::BotaoAtualizaRede() {}
					virtual BotaoAtualizaRede::~BotaoAtualizaRede() {}
					virtual Executavel& BotaoAtualizaRede::executa();
			};

			class BotaoZeraRede: public BotaoComThis {
				public:
					BotaoZeraRede::BotaoZeraRede() {}
					virtual BotaoZeraRede::~BotaoZeraRede() {}
					virtual Executavel& BotaoZeraRede::executa();
			};
/*
			class BotaoAtualizaMaquinasNaTelaPrincipal: public BotaoComThis {
				public:
					BotaoAtualizaMaquinasNaTelaPrincipal::BotaoAtualizaMaquinasNaTelaPrincipal() {}
					virtual BotaoAtualizaMaquinasNaTelaPrincipal::~BotaoAtualizaMaquinasNaTelaPrincipal() {}
					virtual Executavel& BotaoAtualizaMaquinasNaTelaPrincipal::executa();
			};
*/
			class BotaoDefineNoteiro: public BotaoComThis {
				public:
					BotaoDefineNoteiro::BotaoDefineNoteiro() {}
					virtual BotaoDefineNoteiro::~BotaoDefineNoteiro() {}
					virtual Executavel& BotaoDefineNoteiro::executa();
			};

			class BotaoEnviaCoisasPelaRede: public BotaoComThis {
				public:
					BotaoEnviaCoisasPelaRede::BotaoEnviaCoisasPelaRede() {}
					virtual BotaoEnviaCoisasPelaRede::~BotaoEnviaCoisasPelaRede() {}
					virtual Executavel& BotaoEnviaCoisasPelaRede::executa();
			};

			class BotaoZeraTudo: public BotaoComThis {
				public:
					BotaoZeraTudo::BotaoZeraTudo() {}
					virtual BotaoZeraTudo::~BotaoZeraTudo() {}
					virtual Executavel& BotaoZeraTudo::executa();
			};

			class BotaoMudaAcumulado: public BotaoComThis {
				public:
					BotaoMudaAcumulado::BotaoMudaAcumulado() {}
					virtual BotaoMudaAcumulado::~BotaoMudaAcumulado() {}
					virtual Executavel& BotaoMudaAcumulado::executa();
			};

			class BotaoMudaAcumuladoInicial: public BotaoComThis {
				public:
					BotaoMudaAcumuladoInicial::BotaoMudaAcumuladoInicial() {}
					virtual BotaoMudaAcumuladoInicial::~BotaoMudaAcumuladoInicial() {}
					virtual Executavel& BotaoMudaAcumuladoInicial::executa();
			};

			class BotaoMudaAcumuladoMaximo: public BotaoComThis {
				public:
					BotaoMudaAcumuladoMaximo::BotaoMudaAcumuladoMaximo() {}
					virtual BotaoMudaAcumuladoMaximo::~BotaoMudaAcumuladoMaximo() {}
					virtual Executavel& BotaoMudaAcumuladoMaximo::executa();
			};

			class BotaoAtualizaData: public BotaoComThis {
				public:
					BotaoAtualizaData::BotaoAtualizaData() {}
					virtual BotaoAtualizaData::~BotaoAtualizaData() {}
					virtual Executavel& BotaoAtualizaData::executa();
			};

			class BotaoMudaSenha: public BotaoComThis {
				public:
					BotaoMudaSenha::BotaoMudaSenha() {}
					virtual BotaoMudaSenha::~BotaoMudaSenha() {}
					virtual Executavel& BotaoMudaSenha::executa();
			};

			class BotaoRecupera: public BotaoComThis {
				public:
					BotaoRecupera::BotaoRecupera() {}
					virtual BotaoRecupera::~BotaoRecupera() {}
					virtual Executavel& BotaoRecupera::executa();
			};

			class BotaoAtualizaLicenca: public BotaoComThis {
				public:
					BotaoAtualizaLicenca::BotaoAtualizaLicenca() {}
					virtual BotaoAtualizaLicenca::~BotaoAtualizaLicenca() {}
					virtual Executavel& BotaoAtualizaLicenca::executa();
			};

			class BotaoDefineMaquinaLocal: public BotaoComThis {
				public:
					BotaoDefineMaquinaLocal::BotaoDefineMaquinaLocal() {}
					virtual BotaoDefineMaquinaLocal::~BotaoDefineMaquinaLocal() {}
					virtual Executavel& BotaoDefineMaquinaLocal::executa();
			};

			class BotaoAdicionaMaquina: public BotaoComThis {
				public:
					BotaoAdicionaMaquina::BotaoAdicionaMaquina() {}
					virtual BotaoAdicionaMaquina::~BotaoAdicionaMaquina() {}
					virtual Executavel& BotaoAdicionaMaquina::executa();
			};

			class ColocaMaisUmCaracterAutenticacao: public BotaoComThis {
				public:
					ColocaMaisUmCaracterAutenticacao::ColocaMaisUmCaracterAutenticacao() {}
					virtual ColocaMaisUmCaracterAutenticacao::~ColocaMaisUmCaracterAutenticacao() {}
					virtual Executavel& ColocaMaisUmCaracterAutenticacao::executa();
			};

			class ColocaMaisUmCaracterAcumuladoInicial: public BotaoComThis {
				public:
					ColocaMaisUmCaracterAcumuladoInicial::ColocaMaisUmCaracterAcumuladoInicial() {}
					virtual ColocaMaisUmCaracterAcumuladoInicial::~ColocaMaisUmCaracterAcumuladoInicial() {}
					virtual Executavel& ColocaMaisUmCaracterAcumuladoInicial::executa();
			};

			class ColocaMaisUmCaracterAcumuladoAtual: public BotaoComThis {
				public:
					ColocaMaisUmCaracterAcumuladoAtual::ColocaMaisUmCaracterAcumuladoAtual() {}
					virtual ColocaMaisUmCaracterAcumuladoAtual::~ColocaMaisUmCaracterAcumuladoAtual() {}
					virtual Executavel& ColocaMaisUmCaracterAcumuladoAtual::executa();
			};

			class ColocaMaisUmCaracterNoLabel: public BotaoComThis {
				private:
					LabelComponente* pL;
					InputLimitado* pIL;
					int m;

				public:
					ColocaMaisUmCaracterNoLabel::ColocaMaisUmCaracterNoLabel(
							LabelComponente* l, InputLimitado* il,
							int maximo = 4):pL(l), pIL(il), m(maximo) {}

					virtual ColocaMaisUmCaracterNoLabel::~ColocaMaisUmCaracterNoLabel() {}
					virtual Executavel& ColocaMaisUmCaracterNoLabel::executa();
			};

			class ColocaMaisUmCaracterNoLabelSenha: public BotaoComThis {
				private:
					LabelComponente* pL;
					LabelComponente* pO;
					InputLimitado* pIL;
					int m;

				public:
					ColocaMaisUmCaracterNoLabelSenha::ColocaMaisUmCaracterNoLabelSenha(
							LabelComponente* l, LabelComponente* o, InputLimitado* il,
							int maximo = 4):pL(l), pO(o), pIL(il), m(maximo) {}

					virtual ColocaMaisUmCaracterNoLabelSenha::~ColocaMaisUmCaracterNoLabelSenha() {}
					virtual Executavel& ColocaMaisUmCaracterNoLabelSenha::executa();
			};

			class BotaoTocaSom: public BotaoComThis {
				protected:
					std::string BotaoTocaSom::nome;

				public:
					BotaoTocaSom::BotaoTocaSom(std::string nome);
					virtual BotaoTocaSom::~BotaoTocaSom();
					virtual Executavel& BotaoTocaSom::executa();
			};

			class BotaoProximaPagina: public Executavel, public Objeto {
				private:
					Paginas* BotaoProximaPagina::pPaginas;

				public:
					BotaoProximaPagina::BotaoProximaPagina(Paginas*);
					virtual BotaoProximaPagina::~BotaoProximaPagina();
					virtual Executavel& BotaoProximaPagina::executa();
			};

			class BotaoPaginaAnterior: public Executavel, public Objeto {
				private:
					Paginas* BotaoPaginaAnterior::pPaginas;

				public:
					BotaoPaginaAnterior::BotaoPaginaAnterior(Paginas*);
					virtual BotaoPaginaAnterior::~BotaoPaginaAnterior();
					virtual Executavel& BotaoPaginaAnterior::executa();
			};

			class MontadorDeTelas: public Carregador {
				private:
					Plano MontadorDeTelas::pInicial;
					CarregadorDeComponentes* MontadorDeTelas::pCarregador;
					Usuario* MontadorDeTelas::pUsuarios;
					DadosConfiguracao* MontadorDeTelas::pConfiguracao;
					DConfiguracao* MontadorDeTelas::pConfiguracaoLocal;
					CarregadorDeSom* MontadorDeTelas::pSom;
					ControleLicenca* MontadorDeTelas::pLicenca;
					LogicaAcumulado* MontadorDeTelas::pAcumulado;
					bool MontadorDeTelas::pDeveZerarCronometros;

				protected:
					virtual CarregadorDeComponentes&
							MontadorDeTelas::carregador();

				public:
					AnimacaoComponente* MontadorDeTelas::ultimaAnimacao;
					TipoUsuario* MontadorDeTelas::ultimoUsuarioLogado;

					biblia::visual::formulario::Botao*
							MontadorDeTelas::ultimoBotao;

					MontadorDeTelas::MontadorDeTelas();
					virtual MontadorDeTelas::~MontadorDeTelas();
					virtual bool MontadorDeTelas::deveZerarCronometros();
					virtual MontadorDeTelas& MontadorDeTelas
							::deveZerarCronometros(bool);

					virtual DadosConfiguracao& MontadorDeTelas::dados();
					virtual DConfiguracao& MontadorDeTelas::dadosLocal();
					virtual CarregadorDeSom& MontadorDeTelas::som();
					virtual ControleLicenca& MontadorDeTelas::licenca();
					virtual LogicaAcumulado& MontadorDeTelas::acumulado();
					virtual Usuario& MontadorDeTelas::usuario();
					virtual Componente& MontadorDeTelas::partida();
					virtual const Componente& MontadorDeTelas::partida() const;
					virtual MontadorDeTelas& MontadorDeTelas
							::define(CarregadorDeComponentes*,
									 ChaveSeguranca*,
									 DadosConfiguracao*,
									 DConfiguracao*,
									 CarregadorDeSom*,
									 ControleLicenca&,
									 LogicaAcumulado&);

					virtual MontadorDeTelas& MontadorDeTelas::zera();

					// Carregador -> Executavel:
					virtual Executavel& MontadorDeTelas::executa();
			};
		}
	  }
	}
  }
}

#endif // !defined(AFX_MONTADORDETELAS_H__85D5DA5B_7114_4F2A_BD66_7D2BB019A67B__INCLUDED_)
