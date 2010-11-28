/*
 * $RCSfile: Autenticacao.h,v $
 * $Date: 2003/06/26 00:52:31 $
 * $Revision: 1.1 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(SBS_AFX_AUTENTICACAO_H__EED5CCE3_AC35_495B_A8F2_670A5BADAE26__INCLUDED_)
#define SBS_AFX_AUTENTICACAO_H__EED5CCE3_AC35_495B_A8F2_670A5BADAE26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/jogos/special/antigo/Marcacao.h"
#include "biblia/jogos/special/antigo/MensagemBmp.h"
#include "biblia/jogos/special/antigo/TelaCompleta.h"
#include "biblia/jogos/special/antigo/CoisaNaTela.h"
#include "biblia/jogos/special/io/botoes/Botoes.h"
#include "biblia/seguranca/Usuario.h"

using namespace biblia::basico;
using namespace biblia::jogos::special::io::botoes;

#define N_BOTOES_AUTENTICACAO 11

/*
 * Classe que � respons�vel por exibir
 * uma janela e capturar os eventos
 * dos bot�es para autentica��o atrav�s
 * de uma senha.
 */
namespace biblia {
	namespace jogos {
		namespace special {
			namespace antigo {
				class Autenticacao: public Objeto {

					private:

						static unsigned long Autenticacao::pKey[4];
						ChaveSeguranca* Autenticacao::pChaveSeguranca;

						bool Autenticacao::pLiberado;
						bool Autenticacao::pSaiu;
						bool Autenticacao::pErrouSenha;
						bool Autenticacao::pEsqueceuSenha;
						char Autenticacao::pDisplay[200];
						char Autenticacao::pSenhaCorreta[200];
						Usuario* Autenticacao::pUsuario;
						TipoUsuario* Autenticacao::pTipoUsuarioLogado;

						/** Inicializa todos os mebros*/
						void inicializa();

						/** Indice do botao selecionado */
						int Autenticacao::pBotaoSelecionado;
						/** Se o bot�o acima est� pressionado no momento */
						bool Autenticacao::pPressionado;

						/**
						 * @see Botoes
						 */
						Botao* Autenticacao::pBotaoEsquerda;

						/**
						 * @see Botoes
						 */
						Botao* Autenticacao::pBotaoDireita;

						/**
						 * @see Botoes
						 */
						Botao* Autenticacao::pBotaoSeleciona;

						/**
						 * @see Botoes
						 */
						Botao* Autenticacao::pBotaoEntra;

						/**
						 * @see Botoes
						 */
						Botao* Autenticacao::pBotaoCancela;

						/**
						 * @see Botoes
						 */
						Botao* Autenticacao::pBotaoSai;

						Marcacao* Autenticacao::pJanela;
						Marcacao* Autenticacao::pBotoes[N_BOTOES_AUTENTICACAO];
						MensagemBmp* Autenticacao::pNumeroBotao;
						MensagemBmp* Autenticacao::pNumeroDisplay;


					protected:
						/**
						 * Indica que o usu�rio cancelou
						 * a opera��o.
						 */
						virtual Autenticacao& Autenticacao
								::deveSair();

						/**
						 * Indica que o usu�rio acertou
						 * a senha e foi liberado.
						 */
						virtual Autenticacao& Autenticacao
								::liberou();

						/**
						 * Indica que o usu�rio
						 * esqueceu a senha.
						 */
						virtual Autenticacao& Autenticacao
								::esqueceuSenha(bool seEsqueceu);

						/**
						 * Modifica o texto do display.
						 */
						virtual Autenticacao& Autenticacao
								::display(const char* novoDisplay);

						/**
						 * Verifica o texto do display.
						 */
						virtual const char* Autenticacao
								::display() const;

						/**
						 * Modifica a senha correta.
						 */
						virtual Autenticacao& Autenticacao
								::modificaSenha(const char* novaSenha);

						/**
						 * Verifica se a senha est� correta.
						 */
						virtual bool Autenticacao
								::senhaCorreta(const char* senha);

						/**
						 * Verifica se ele esqueceu a senha.
						 */
						virtual bool Autenticacao
								::verificaSeEsqueceuSenha(const char* senha);

						/* Navega��o dos Bot�es */

						/**
						 * Vai para o primeiro bot�o.
						 */
						virtual Autenticacao& Autenticacao
								::primeiroBotao();

						/**
						 * Vai para o pr�ximo bot�o.
						 */
						virtual Autenticacao& Autenticacao
								::proximoBotao();

						/**
						 * Vai para o bot�o anterior.
						 */
						virtual Autenticacao& Autenticacao
								::botaoAnterior();

						/**
						 * Retorna o �ndice do bot�o selecionado.
						 */
						virtual int Autenticacao
								::botaoSelecionado() const;


						/**
						 * Indica que o bot�o foi pressionado.
						 */
						virtual Autenticacao& Autenticacao
								::apertouBotao();

						/**
						 * Indica que o bot�o foi solto.
						 */
						virtual Autenticacao& Autenticacao
								::soltouBotao();

						/**
						 * Verifica se o bot�o atual est� pressionado.
						 */
						virtual bool Autenticacao
								::pressionado() const;

						/**
						 * Verifica se a senha est� correta.
						 */
						virtual Autenticacao& Autenticacao
								::valida();

						/*
						 * Retorna a "cara" (t�tulo) do bot�o.
						 */
						static char Autenticacao
								::caraDoBotao(int posicao);

						/**
						 * Define que o usu�rio errou a senha.
						 */
						virtual Autenticacao& Autenticacao
								::errouSenha(bool errou);

					public:

						/* Defini��es Importantes */

						/**
						 * Aloca os elementos necess�rios:
						 *  o Janela
						 *  o Botao
						 *  o NumeroBotao
						 *  o NumeroDisplay
						 *
						 * @param senhaCorreta A senha
						 *                     que ser� utilizada
						 *                     para autentica��o.
						 *                     Se for NULL a autentica��o
						 *                     j� est� liberada.
						 */
						Autenticacao::Autenticacao(const char* senhaCorreta = NULL);

						/**
						 * Chama o outro contrutor.
						 *
						 * @param usuario A classe que controla
						 *                o acesso ao usu�rio.
						 */
						Autenticacao::Autenticacao(Usuario* usuario);

						/**
						 * Destr�i os elementos alocados.
						 */
						virtual Autenticacao::~Autenticacao();

						/**
						 * Define o bot�o para esquerda.
						 */
						virtual Autenticacao& Autenticacao
								::botaoEsquerda(const Botao& qualBotao);

						/* Defini��es Perif�ricas */

						/**
						 * Define a posi��o da janela.
						 */
						virtual Autenticacao& Autenticacao
								::move(int x, int y);

						/**
						 * Define o bot�o para direita.
						 */
						virtual Autenticacao& Autenticacao
								::botaoDireita(const Botao& qualBotao);

						/**
						 * Define o bot�o para selecionar.
						 */
						virtual Autenticacao& Autenticacao
								::botaoSeleciona(const Botao& qualBotao);

						/**
						 * Define o bot�o para entrar.
						 */
						virtual Autenticacao& Autenticacao
								::botaoEntra(const Botao& qualBotao);

						/**
						 * Define o bot�o para cancelar.
						 */
						virtual Autenticacao& Autenticacao
								::botaoCancela(const Botao& qualBotao);

						/**
						 * Define o bot�o para sair.
						 */
						virtual Autenticacao& Autenticacao
								::botaoSai(const Botao& qualBotao);

						/* A��es */

						/**
						 * Desenha a janela de autentica��o.
						 * <p>
						 * Essa fun��o deve ser chamada dentro
						 * de um loop.
						 *
						 * @see #trataEventos(Botoes&)
						 */
						virtual Autenticacao& Autenticacao
								::desenha(TelaCompleta&);

						/**
						 * Consome os enventos dos botoes
						 * e faz o tratamento devido.
						 * <p>
						 * Essa fun��o deve ser chamada dentro
						 * de um loop.
						 *
						 * @see #liberado()
						 * @see #saiu()
						 * @see #desenha(TelaCompleta&)
						 * @return Retorna o botao pressionado.
						 */
						virtual Botao Autenticacao
								::trataEventos(Botoes&);

						/* Verifica��es Importantes */

						/**
						 * Indica se foi autenticado ou n�o.
						 */
						virtual bool Autenticacao::liberado() const;

						/**
						 * Indica se saiu ou n�o.
						 */
						virtual bool Autenticacao::saiu() const;

						/**
						 * Indica se o motivo da sa�da foi
						 * porque o usu�rio errou a senha.
						 */
						virtual bool Autenticacao::errouSenha() const;

						/**
						 * Indica se o motivo da sa�da foi
						 * porque o usu�rio esqueceu a senha.
						 */
						virtual bool Autenticacao::esqueceuSenha() const;

						/**
						 * Retorna o �ltimo usu�rio que foi logado.
						 */
						virtual TipoUsuario& Autenticacao::
								tipoUsuarioLogado() const;

						/**
						 * For�a tal usu�rio ser logado.
						 */
						virtual Autenticacao& Autenticacao::
								forcaLogar(const TipoUsuario&);

						/* Verifica��es Perif�ricas */

						/**
						 * Verifica o bot�o para esquerda.
						 */
						virtual const Botao& Autenticacao::botaoEsquerda() const;

						/*
						 * Verifica o bot�o para direita.
						 */
						virtual const Botao& Autenticacao::botaoDireita() const;

						/**
						 * Verifica o bot�o para selecionar.
						 */
						virtual const Botao& Autenticacao::botaoSeleciona() const;

						/**
						 * Verifica o bot�o para entrar.
						 */
						virtual const Botao& Autenticacao::botaoEntra() const;

						/**
						 * Verifica o bot�o para cancelar.
						 */
						virtual const Botao& Autenticacao::botaoCancela() const;

						/**
						 * Verifica o bot�o para sair.
						 */
						virtual const Botao& Autenticacao::botaoSai() const;
				};
			}
		}
	}
}

#endif // !defined(AFX_AUTENTICACAO_H__EED5CCE3_AC35_495B_A8F2_670A5BADAE26__INCLUDED_)
