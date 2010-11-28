/*
 * $RCSfile: FluxoDeTexto.h,v $
 * $Date: 2005/01/20 21:28:45 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_FLUXODETEXTO_H__DC230C51_3DE8_4E7B_848E_351F5B5A89AF__INCLUDED_)
#define AFX_FLUXODETEXTO_H__DC230C51_3DE8_4E7B_848E_351F5B5A89AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "biblia/io/DispositivoDeSaida.h"
#include "biblia/armazenamento/volatil/EventoID.h"

using namespace std;

namespace biblia {
  namespace io {
	namespace texto {
		class FluxoDeTexto: public DispositivoDeSaida {
			private:
				bool FluxoDeTexto::pAuto;

			public:
				FluxoDeTexto::FluxoDeTexto();
				virtual FluxoDeTexto::~FluxoDeTexto();

				virtual FluxoDeTexto& FluxoDeTexto
						::escreve(const std::string&);

				virtual FluxoDeTexto& FluxoDeTexto
						::escreveLn(const std::string& = "");

				virtual FluxoDeTexto& FluxoDeTexto
						::automatico(bool);

				virtual const bool& FluxoDeTexto
						::automatico() const;

				// DispositivoDeSaida:
				virtual Executavel& FluxoDeTexto::executa() = 0;

				// Eventos:
				class EscreveEvento: public EventoID {
					private:
						std::string EscreveEvento::pTexto;
						static EventoID EscreveEvento::id;

					public:
						EscreveEvento::EscreveEvento(
								const std::string& = "");

						const std::string& EscreveEvento::texto() const;
				};

				class EscreveComLinhaEvento: public EventoID {
					private:
						std::string EscreveComLinhaEvento::pTexto;
						static EventoID EscreveComLinhaEvento::id;

					public:
						EscreveComLinhaEvento
								::EscreveComLinhaEvento(
									const std::string& = "");

						const std::string& EscreveComLinhaEvento
								::texto() const;
				};
		};
	}
  }
}

#endif // !defined(AFX_FLUXODETEXTO_H__DC230C51_3DE8_4E7B_848E_351F5B5A89AF__INCLUDED_)
