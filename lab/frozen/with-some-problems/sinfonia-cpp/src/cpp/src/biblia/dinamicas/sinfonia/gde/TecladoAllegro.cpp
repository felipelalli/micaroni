/**
 * $RCSfile: TecladoAllegro.cpp,v $
 * $Date: 2005/03/30 01:23:46 $
 * $Revision: 1.14 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/gde/TecladoAllegro.h"
using namespace biblia::dinamicas::sinfonia::gde;

/* CPPDOC_BEGIN_EXCLUDE */

void biblia::dinamicas::sinfonia::gde::evento_tecla(int scancode) {
	static Semaforo s(1);
	Lock lock(s);

	try {
		TecladoAllegro* ta = TecladoAllegro::unicaInstancia();
		Evento* soltouOuPressionou = NULL;
		Evento* soltouOuPressionouUltimaTecla = NULL;
		Valor nomeDaTecla = Irrelevante();

		if (ta->ligado()) {
			if (scancode < 128) {
				// Pressionou a tecla específica
				{
					nomeDaTecla = Valor("Sinfonia.Reservados.Teclas.tecla"
							+ Inteiro(scancode).emString());

					nomeDaTecla.adicionaApelido("pressionou");
					ModificadorDeEstado mde(nomeDaTecla);
					mde.adicionaParametro(Valor(true));

					soltouOuPressionou = Evento(nomeDaTecla, mde)
							.dispara(TecladoAllegro::tempo());

					soltouOuPressionou->especial(true);
				}

				// Pressionou qualquer tecla
				{
					Valor nome("Sinfonia.Reservados.Teclas.ultima tecla pressionada");
					ModificadorDeEstado mde(nome);
					mde.adicionaParametro(Valor("tecla"
							+ Inteiro(scancode).emString()));

					soltouOuPressionouUltimaTecla = Evento(nome, mde)
							.dispara(TecladoAllegro::tempo());

					soltouOuPressionouUltimaTecla->especial(true);
				}
			} else {
				scancode -= 128;
				// Soltou a tecla específica
				{
					nomeDaTecla = Valor("Sinfonia.Reservados.Teclas.tecla"
							+ Inteiro(scancode).emString());

					nomeDaTecla.adicionaApelido("soltou");
					ModificadorDeEstado mde(nomeDaTecla);
					mde.adicionaParametro(Valor(false));

					soltouOuPressionou = Evento(nomeDaTecla, mde).dispara(
							TecladoAllegro::tempo());

					soltouOuPressionou->especial(true);
				}

				// Soltou qualquer tecla
				{
					Valor nome("Sinfonia.Reservados.Teclas.ultima tecla solta");
					ModificadorDeEstado mde(nome);
					mde.adicionaParametro(Valor("tecla"
							+ Inteiro(scancode).emString()));

					soltouOuPressionouUltimaTecla = Evento(nome, mde).dispara(
							TecladoAllegro::tempo());

					soltouOuPressionouUltimaTecla->especial(true);
				}
			}

			if (soltouOuPressionou != NULL) {
				if (ta->mediadorDeEstados().existeEstado(nomeDaTecla)) {
					if (ta->mediadorDeEstados().estado(nomeDaTecla).valor()
						!= soltouOuPressionou->parametro())
					{
						ta->gera(soltouOuPressionou);
						ta->gera(soltouOuPressionouUltimaTecla);
					}
				} else {
					Debug::msg(INFO, "evento_tecla(int scancode):: Ignorando evento: '"
							+ *soltouOuPressionou + "' pois Estado correspondente"
							" não existe");

					// ignora
					delete soltouOuPressionou;
				}
			}
		}
	} catch(exception& e) {
		throw e;
	} catch(...) {
		Debug::msg(ERRO, "biblia::dinamicas::sinfonia::gde::evento_tecla::"
				" Ocorreu um erro desconhecido ao capturar uma tecla."
				" Provavelmente ocorreu porque a função não terminou"
				" enquanto o TecladoAllegro era deletado.");
	}

} END_OF_FUNCTION(evento_tecla);

/* CPPDOC_END_EXCLUDE */

TecladoAllegro* TecladoAllegro::singleton = NULL;
UniversoDeTempo* TecladoAllegro::pTempo = NULL;
Valor TecladoAllegro::ESTADO_DE_BLOQUEIO = "Sinfonia.Reservados.Teclas.bloqueado";

TecladoAllegro* TecladoAllegro::criaTecladoAllegro(
		const MediadorDeEstados& mde, const UniversoDeTempo& u)
{
	if (TecladoAllegro::singleton != NULL) {
		delete TecladoAllegro::singleton;
	}
	
	TecladoAllegro::singleton = new TecladoAllegro(mde);

	TecladoAllegro::pTempo = (UniversoDeTempo*) &u;
	return TecladoAllegro::singleton;
}

TecladoAllegro* TecladoAllegro::unicaInstancia() {
	if (TecladoAllegro::singleton == NULL) {
		Debug::sair("TecladoAllegro::unicaInstancia():: a "
				"função 'criaTecladoAllegro'"
				" deve ser chamada antes desta!");
	}

	return TecladoAllegro::singleton;
}

const UniversoDeTempo& TecladoAllegro::tempo() {
	if (TecladoAllegro::pTempo == NULL) {
		Debug::sair("TecladoAllegro::tempo():: tempo nao definido!");
	}

	return *(TecladoAllegro::pTempo);
}

TecladoAllegro::TecladoAllegro(const MediadorDeEstados& mde)
		:GeradorDeEventosBloqueavel(mde, TecladoAllegro::ESTADO_DE_BLOQUEIO),
		 pLiga(false), pEsperaAcabar(0)
{
	static bool jaExecutou = false;

	if (jaExecutou) {
		Debug::sair("TecladoAllegro::TecladoAllegro:: só é possível"
				" criar uma vez por aplicação.");
	} else {
		jaExecutou = true;
		LOCK_FUNCTION(evento_tecla);
		keyboard_lowlevel_callback = evento_tecla;
		three_finger_flag = (int) false;
	}

	//this->naoDeveReceberNenhumEvento();
}

TecladoAllegro::~TecladoAllegro() {
//	Debug::msg(INFO, "--- vai acabar teclado allegro...");
	this->pLiga = false;

	while (!this->pAcabou) {
//		Debug::msg(INFO, "--- vai simular tecla...");
		simulate_keypress(0);
		Thread::sleep(Intervalo(100, Milissegundo()));
	}

	keyboard_lowlevel_callback = NULL;
	Thread::sleep(Intervalo(100, Milissegundo()));

	this->pEsperaAcabar.esperar();
//	Debug::msg(INFO, "--- acabou teclado allegro...");
}

const bool& TecladoAllegro::ligado() const {
	return this->pLiga;
}

TecladoAllegro::CapturaUltimaTeclaASCII
		::CapturaUltimaTeclaASCII(TecladoAllegro* ta)
	:pTA(ta)
{}

Executavel& TecladoAllegro::CapturaUltimaTeclaASCII::executa() {
	TecladoAllegro* ta = TecladoAllegro::unicaInstancia();
	
	while (this->pTA->pLiga && !this->pTA->encerrou()) {
//		Debug::msg(INFO, "--- espera por ler tecla...");
		int tecla = readkey();
//		Debug::msg(INFO, "--- leu tecla...");
		char msg[5];
		sprintf(msg, "%c", tecla & 0xff);

		{
			Valor nome("Sinfonia.Reservados.Teclas.ultima tecla ascii");
			ModificadorDeEstado mde(nome);
			mde.adicionaParametro(Valor(msg, true));

			Evento* pressionou = Evento(nome, mde).dispara(TecladoAllegro::tempo());
			pressionou->especial(true);
			ta->gera(pressionou);
		}
	}

	return *this;
}

GeradorDeEventos& TecladoAllegro::captaEGeraEmLoop() {
	this->pLiga = true;
	this->pAcabou = false;

	CapturaUltimaTeclaASCII cuta(this);
	Thread cutaThread(cuta);
	cutaThread.start();

	while (this->pLiga && !this->encerrou()) {
		const Evento* e = this->esperaAteQueVenhaEvento();
		delete e;
	}

	this->pAcabou = true;
	this->pEsperaAcabar.liberar();

	return *this;
}
