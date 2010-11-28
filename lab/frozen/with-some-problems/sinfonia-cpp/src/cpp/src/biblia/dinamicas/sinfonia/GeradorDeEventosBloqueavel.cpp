/**
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Space
 * Ages Software e Tecnologia, julho de 2005.
 */

#include "biblia/dinamicas/sinfonia/GeradorDeEventosBloqueavel.h"
using namespace biblia::dinamicas::sinfonia;

GeradorDeEventosBloqueavel::GeradorDeEventosBloqueavel(
		const MediadorDeEstados& mde, const Valor& n)
	:GeradorDeEventosEspecial(mde),
	 pBloqueio(0), pNomeCompletoDoEstadoDeBloqueio(n),
	 pLockIda(1), pLockVolta(1)
{}

GeradorDeEventosBloqueavel& GeradorDeEventosBloqueavel::dizQueEstaBloqueado() {
	// indica que o estado est� bloqueado de forma "hard coded"
	const_cast<Estado&>(this->estadoDeBloqueio()).atribui(true);
	return *this;
}

GeradorDeEventosBloqueavel& GeradorDeEventosBloqueavel::desbloqueia() {
	this->pBloqueio.liberar();
	return *this;
}

GeradorDeEventosBloqueavel::~GeradorDeEventosBloqueavel() {}

const Estado& GeradorDeEventosBloqueavel::estadoDeBloqueio() const {
	return this->mediadorDeEstados().estado(
			this->pNomeCompletoDoEstadoDeBloqueio);
}

GeradorDeEventos& GeradorDeEventosBloqueavel::encerra() {
	GeradorDeEventos::encerra();

	while (!this->pBloqueio.esperar(false)) {
		this->pBloqueio.liberar();
	}

	return *this;
}

const Evento* GeradorDeEventosBloqueavel::esperaAteQueVenhaEvento() {
	Lock(this->pLockVolta);
	Debug::msg(ERRO, ">>> GDEB: espera at� que venha evento...");

	const Evento* eventoRecebido = GeradorDeEventosEspecial
			::esperaAteQueVenhaEvento();

	if (eventoRecebido == NULL) {
		Debug::msg(ERRO, ">>> GDEB::esperaAteQueVenhaEvento():: capturou evento NULO");
	} else {
		Debug::msg(ERRO, ">>> GDEB::esperaAteQueVenhaEvento():: capturou evento: " + *eventoRecebido);

		if (*eventoRecebido
			== Evento(this->pNomeCompletoDoEstadoDeBloqueio))
		{
			// mandou desbloquear
			if (!eventoRecebido->parametro().emBool()) {
				this->desbloqueia();
				Debug::msg(ERRO, ">>> GDEB::esperaAteQueVenhaEvento():: capturou evento de desbloqueio!"
						" Vai desbloquear!");
			}
		}
	}

	return eventoRecebido;
}

const Evento* GeradorDeEventosBloqueavel::esperaAteQueHajaEvento() {
	Lock(this->pLockIda);
	const Evento* retorno = NULL;
	
	Debug::msg(ERRO, ">>> GDEB: espera at� que haja evento...");
	retorno = GeradorDeEventosEspecial::esperaAteQueHajaEvento();

	if (this->estadoDeBloqueio().valor().emBool()) {
		// est� bloqueado, deve esperar at� que seja desbloqueado,
		// para assim se bloquear novamente

		Debug::msg(ERRO, ">>> GDEB::esperaAteQueHajaEvento() est� bloqueado!");
		this->pBloqueio.esperar();
		Debug::msg(ERRO, ">>> GDEB::esperaAteQueHajaEvento() liberou bloqueio!");
	}

	// ap�s fazer tudo, bloqueia:
	this->dizQueEstaBloqueado();

	Debug::msg(ERRO, ">>> GDEB::esperaAteQueHajaEvento() vai retornar: "
			+ string(!retorno?"NULL":""+ *retorno));

	return retorno;
}

