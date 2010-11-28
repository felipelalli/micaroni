/*
 * $RCSfile: Botoes.h,v $
 * $Date: 2005/01/20 17:44:47 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */
#if !defined(SBS_AFX_BOTOES_H__3833E2CD_FD6E_4140_9477_E3A089C3DBCA__INCLUDED_FRUTINHA)
#define SBS_AFX_BOTOES_H__3833E2CD_FD6E_4140_9477_E3A089C3DBCA__INCLUDED_FRUTINHA

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/io/DispositivoDeEntrada.h"
#include "biblia/jogos/frutinha/io/botoes/Botao.h"
#include "biblia/armazenamento/volatil/EventoID.h"

using namespace biblia::io;
using namespace biblia::armazenamento::volatil;

namespace biblia {
	namespace jogos {
		namespace frutinha {
			namespace io {
				namespace botoes {
					class Botoes : public DispositivoDeEntrada  {
						protected:
							Botoes();

						public:
							virtual ~Botoes();
							virtual Executavel& Botoes::executa() = 0 ;

							virtual bool pressionado(const Botao&) = 0;

							class BotaoAjuda : public Botao {
								private :
									static Botao BotaoAjuda::id;
								public :
									BotaoAjuda::BotaoAjuda();
							};

							class BotaoAutomatico : public Botao {
								private :
									static Botao BotaoAutomatico::id;
								public :
									BotaoAutomatico::BotaoAutomatico();
							};

							class BotaoMudaAposta1: public Botao {
								private :
									static Botao BotaoMudaAposta1::id;
								public :
									BotaoMudaAposta1::BotaoMudaAposta1();
							};						
							
							class BotaoMudaAposta2: public Botao {
								private :
									static Botao BotaoMudaAposta2::id;
								public :
									BotaoMudaAposta2::BotaoMudaAposta2();
							};	

							class BotaoMudaAposta3: public Botao {
								private :
									static Botao BotaoMudaAposta3::id;
								public :
									BotaoMudaAposta3::BotaoMudaAposta3();
							};						
							
							class BotaoMudaAposta4: public Botao {
								private :
									static Botao BotaoMudaAposta4::id;
								public :
									BotaoMudaAposta4::BotaoMudaAposta4();
							};	

							class BotaoMudaAposta5: public Botao {
								private :
									static Botao BotaoMudaAposta5::id;
								public :
									BotaoMudaAposta5::BotaoMudaAposta5();
							};							

							class BotaoCobrar : public Botao {
								private :
									static Botao BotaoCobrar::id;
								public :
									BotaoCobrar::BotaoCobrar();
							};


							class BotaoApostaMaxima : public Botao {
								private :
									static Botao BotaoApostaMaxima::id;
								public :
									BotaoApostaMaxima::BotaoApostaMaxima();
							};

							class BotaoJogar: public Botao {
								private :
									static Botao BotaoJogar::id;
								public:
									BotaoJogar::BotaoJogar();

							};

							class ChaveCobranca : public Botao {
								private :
									static Botao ChaveCobranca::id;
								public :
									ChaveCobranca::ChaveCobranca();
							};

							class ChaveConfiguracao : public Botao {
								private :
									static Botao ChaveConfiguracao::id;
								public :
									ChaveConfiguracao::ChaveConfiguracao();
							};

							
							class BotaoQualquer : public Botao {
								private :
									static Botao BotaoQualquer::id;
								public :
									BotaoQualquer::BotaoQualquer();
							};

							class BotaoSair: public Botao {
								private :
									static Botao BotaoSair::id;
								public :
									BotaoSair::BotaoSair();
							};


							class PressionouBotao: public EventoID {
								private:
									Botao pBotao;
									static EventoID PressionouBotao::id;

								public:
									PressionouBotao::PressionouBotao();
									PressionouBotao::PressionouBotao(const Botao&);
									const Botao& PressionouBotao::botao() const;
							};

							class LiberouBotao : public EventoID {
								private :
									Botao pBotao;
									static EventoID LiberouBotao::id;
								public :
									LiberouBotao::LiberouBotao();
									LiberouBotao::LiberouBotao(const Botao&);
									const Botao& LiberouBotao::botao() const;

							};

					};
				}
			}
		}
	}
}
#endif
