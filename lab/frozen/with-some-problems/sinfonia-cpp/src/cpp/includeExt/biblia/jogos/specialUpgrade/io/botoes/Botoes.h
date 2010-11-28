/*
 * $RCSfile: Botoes.h,v $
 * $Date: 2005/01/19 17:22:03 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */
#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_BOTOES_H__3833E2CD_FD6E_4140_9477_E3A089C3DBCA__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_BOTOES_H__3833E2CD_FD6E_4140_9477_E3A089C3DBCA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/io/DispositivoDeEntrada.h"
#include "biblia/jogos/specialUpgrade/io/botoes/Botao.h"
#include "biblia/armazenamento/volatil/EventoID.h"

using namespace biblia::io;
using namespace biblia::armazenamento::volatil;

namespace biblia {
	namespace jogos {
		namespace specialUpgrade {
			namespace io {
				namespace botoes {
					class Botoes : public DispositivoDeEntrada  {
						protected:
							Botoes();

						public:

							virtual ~Botoes();
							virtual Executavel& Botoes::executa() = 0 ;

							virtual bool pressionado(const Botao&) = 0;

							virtual bool Botoes::pressionado(int tecla){
								return false;
							}

							class BotaoAjuda : public Botao {
								private :
									static Botao BotaoAjuda::id;
								public :
									BotaoAjuda::BotaoAjuda();
							};

							class BotaoAposta: public Botao {
								private :
									static Botao BotaoAposta::id;
								public :
									BotaoAposta::BotaoAposta();
							};

							class BotaoBolaExtra: public Botao {
								private :
									static Botao BotaoBolaExtra::id;
								public:
									BotaoBolaExtra::BotaoBolaExtra();

							};

							class BotaoCartelas: public Botao {
								private :
									static Botao BotaoCartelas::id;
								public :
									BotaoCartelas::BotaoCartelas();
							};

							class BotaoCobrar : public Botao {
								private :
									static Botao BotaoCobrar::id;
								public :
									BotaoCobrar::BotaoCobrar();
							};


                            class BotaoChavePagto : public Botao {
                                private :
									static Botao BotaoChavePagto::id;
								public :
									BotaoChavePagto::BotaoChavePagto();
                            };

							class BotaoChaveConfiguracao : public Botao {
                                private :
									static Botao BotaoChaveConfiguracao::id;
								public :
									BotaoChaveConfiguracao::BotaoChaveConfiguracao();
                            };

							class BotaoJogar: public Botao {
								private :
									static Botao BotaoJogar::id;
								public:
									BotaoJogar::BotaoJogar();

							};

							class BotaoNumeros : public Botao {
								private :
									static Botao BotaoNumeros::id;
								public:
									BotaoNumeros::BotaoNumeros();
							};


							class BotaoSuperTurbo: public Botao {
								private :
									static Botao BotaoSuperTurbo::id;
								public:
									BotaoSuperTurbo::BotaoSuperTurbo();
							};

							class BotaoPortaMaquina: public Botao {
								private :
									static Botao BotaoPortaMaquina::id;
								public:
									BotaoPortaMaquina::BotaoPortaMaquina();
							};

							class BotaoPortaDinheiro: public Botao {
								private :
									static Botao BotaoPortaDinheiro::id;
								public:
									BotaoPortaDinheiro::BotaoPortaDinheiro();
							};

							class BotaoPortaCPU: public Botao {
								private :
									static Botao BotaoPortaCPU::id;
								public:
									BotaoPortaCPU::BotaoPortaCPU();
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
