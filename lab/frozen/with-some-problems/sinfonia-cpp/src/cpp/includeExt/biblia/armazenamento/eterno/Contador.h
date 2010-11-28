/*
 * $RCSfile: Contador.h,v $
 * $Date: 2004/11/09 23:18:18 $
 * $Revision: 1.11 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef CONTADOR_H
#define CONTADOR_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/util/Debug.h"
using namespace biblia::util;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

#include "biblia/io/disco/Arquivo.h"
using namespace biblia::io::disco;

#include "biblia/fluxo/Semaforo.h"
using namespace biblia::fluxo;


namespace biblia{

	namespace armazenamento{

		namespace eterno{


			/**
			 * @deprecated Essa classe se utiliza
			 *             de conceitos muito específicos.            
			 */
			class Contador: public Objeto{

				private:

					Arquivo Contador::pBackup;

				protected:					

					long pApostadoTotal;
					long pApostadoParcial;
					long pApostadoAux;//Guarda o valor ate que a variavel pApostado esteja liberada para recebe-lo
					long pApostado;

					long pGanhoTotal;
					long pGanhoParcial;
					long pGanhoAux;//Guarda o valor ate que a variavel pGanho esteja liberada para recebe-lo
					long pGanho;

					long pPagamentoManualTotal;
					long pPagamentoManualParcial;
					long pPagamentoManualAux;//Guarda o valor ate que a varial pPagamentoManual esteja liberada para recebe-lo
					long pPagamentoManual;

					long pEntradaTotal;
					long pEntradaParcial;
					long pEntradaAux;//Guarda o valor ate que a variavel pEntrada esteja liberada para recebe-lo
					long pEntrada;

					long pJogadaTotal;
					long pJogadaParcial;
					long pJogadaAux;//Guarda o valor ate que a varial pSaida esteja liberada para recebe-lo
					long pJogada;					

					Semaforo pSemaforo;					
					

					void Contador::pFazerBackup();
					
					bool pSalvar;

				public:

					Contador::Contador(bool salvar=false);
					virtual Contador::~Contador();

					long Contador::getApostado();
					long Contador::getGanho();
					long Contador::getPagamentoManual();
					long Contador::getEntrada();
					long Contador::getJogada();					

					long Contador::getApostadoParcial();
					long Contador::getGanhoParcial();
					long Contador::getPagamentoManualParcial();
					long Contador::getEntradaParcial();
					long Contador::getJogadaParcial();					
					void Contador::zerarParcial();

					long Contador::setApostado(long valor);
					long Contador::setGanho(long valor);
					long Contador::setPagamentoManual(long valor);
					long Contador::setEntrada(long valor);
					long Contador::setJogada(long valor);					

					long Contador::addApostado(long valor);
					long Contador::addGanho(long valor);
					long Contador::addPagamentoManual(long valor);
					long Contador::addEntrada(long valor);
					long Contador::addJogada(long valor);					
			};
		}

	}

}

#endif