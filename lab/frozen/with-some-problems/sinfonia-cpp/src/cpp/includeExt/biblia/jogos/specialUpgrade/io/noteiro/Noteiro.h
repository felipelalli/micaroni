/*
 * $RCSfile: Noteiro.h,v $
 * $Date: 2005/01/13 17:09:49 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_NOTEIRO_H__7D2B9C6F_2661_4295_9F3E_84283460CD50__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_NOTEIRO_H__7D2B9C6F_2661_4295_9F3E_84283460CD50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/io/DispositivoDeEntrada.h"
#include "biblia/armazenamento/volatil/EventoID.h"
#include "biblia/io/noteiro/LeitorNotas.h"
#include "biblia/io/noteiro/LeitorNotasJCM.h"
#include "biblia/io/noteiro/LeitorNotasSmiles.h"
#include "biblia/jogos/specialUpgrade/io/noteiro/Nota.h"
#include "biblia/fluxo/Semaforo.h"

using namespace biblia::io;
using namespace biblia::armazenamento::volatil;
using namespace biblia::io::noteiro;
using namespace biblia::fluxo;

#include "biblia/io/placaDelta/PlacaDelta.h"
using namespace biblia::io::placadelta;

namespace biblia {
	namespace jogos {
		namespace specialUpgrade {
			namespace io {
				namespace noteiro {
                    class Noteiro : public DispositivoDeEntrada {
                        private :
                            //leitor de notas
							Semaforo* pSema;
							int pNoteiroAtual;
                            LeitorNotas* pLeitorNotas;

							PlacaDelta* pPlacaDelta;

							UniversoDeTempo& pUniversoDeTempo;

                        public:
                            static int Noteiro::JCM;
                            static int Noteiro::SMILES;
							static int Noteiro::PLACA_DELTA;

                            Noteiro::Noteiro(UniversoDeTempo& universoDeTempo,int qualNoteiro = Noteiro::SMILES, PlacaDelta* placaDelta = NULL);
	                        virtual Noteiro::~Noteiro();

                            virtual Executavel& Noteiro::executa();
							virtual Noteiro& Noteiro::habiliado(bool);
							virtual bool Noteiro::habiliado() const;
							virtual Noteiro& Noteiro::reinicia(int qualNoteiro);

                            class CincoReais: public Nota {
								private :
									static Nota CincoReais::id;
								public :
									CincoReais::CincoReais();
							};

                            class DezReais: public Nota {
								private :
									static Nota DezReais::id;
								public :
									DezReais::DezReais();
							};

							class VinteReais: public Nota {
								private :
									static Nota VinteReais::id;
								public :
									VinteReais::VinteReais();
							};

                            class CinquentaReais: public Nota {
								private :
									static Nota CinquentaReais::id;
								public :
									CinquentaReais::CinquentaReais();
							};

							class CemReais: public Nota {
								private :
									static Nota CemReais::id;
								public :
									CemReais::CemReais();
							};

                            class ColocouNota: public EventoID {
								private:
                                    Nota ColocouNota::pNota;
									static EventoID ColocouNota::id;

								public:
									ColocouNota::ColocouNota(const Nota&);
									const Nota& ColocouNota::nota() const;
			    			};

                    };
                }
            }
        }
    }
}
#endif // !defined(AFX_NOTEIRO_H__7D2B9C6F_2661_4295_9F3E_84283460CD50__INCLUDED_)
