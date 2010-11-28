/**
 * $RCSfile: Evento.cpp,v $
 * $Date: 2005/03/29 01:30:24 $
 * $Revision: 1.26 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/Evento.h"
using namespace biblia::dinamicas::sinfonia;

Evento::Evento(const Valor& nome)
		:Rotulado(nome), pModificador(NULL),
		 pMomento(NULL), pEspecial(false),
		 pGrupo("")
{}

Evento::Evento(const Valor& nome, const ModificadorDeEstado& mde)
		:Rotulado(nome), pModificador((ModificadorDeEstado*) mde.geraCopia()),
		 pMomento(NULL), pGrupo(""), pEspecial(false)
{}

Evento::Evento(const Evento& e):Rotulado("_"),
		pGrupo("_"), pMomento(NULL), pModificador(NULL)
{
	this->copiaEmSi(e);
}

Evento::~Evento() {
	if (this->pMomento) {
		delete this->pMomento;
	}

	if (this->pModificador) {
		delete this->pModificador;
	}
}

const Valor& Evento::grupo() const {
	return this->pGrupo;
}

Evento& Evento::grupo(const Valor& v) {
	this->pGrupo = v;
	return *this;
}

const Valor Evento::nomeCompleto() const {
	return Valor((this->grupo().valor().compare("") == 0?""
			:this->grupo().valor() + ".") + this->nome());
}

const bool& Evento::especial() const {
	return this->pEspecial;
}

Evento& Evento::especial(const bool& e) {
	this->pEspecial = e;
	return *this;
}

const bool Evento::modificaEstadoDiretamente() const {
	return (this->pModificador != NULL);
}

Evento* Evento::dispara(const UniversoDeTempo& u) const {
	if (this->disparado()) {
		EventoDisparadoExcecao e;
		e << "Evento::dispara:: não é possível disparar"
				" um evento através de outro já disparado!";

		throw e;
	}

	Evento* retorno = (Evento*) this->geraCopia();

	try {
		retorno->pMomento = new Momento(u.agora());
	} catch(...) {
		Debug::msg(WARN, "Evento::dispara:: não foi possível determinar"
				" o momento que este Evento foi disparado. Evento: " + *retorno);

		retorno->pMomento = NULL;
	}

	if (retorno->pMomento == NULL) {
		static UniversoSequencial us;
		retorno->pMomento = new Momento(us.agora());
	}

	return retorno;
}

const bool Evento::disparado() const {
	return this->pMomento != NULL;
}

const ModificadorDeEstado& Evento::modificador() const {
	if (this->modificaEstadoDiretamente()) {
		return *(this->pModificador);
	} else {
		EventoIntermediarioExcecao e;
		e << string() + "Evento::modificador():: só é possível acessar o modificador caso este"
				+ " modifique um estado diretamente.";

		throw e;
	}
}

const Momento& Evento::momentoDoDisparo() const {
	if (!this->disparado()) {
		EventoNaoDisparadoExcecao e;
		e << string() + "Evento::momentoDoDisparo():: esse Evento é para consulta,"
				+ " nunca foi disparado. " + *this;

		throw e;
	}

	return *(this->pMomento);
}

const bool Evento::igual(const Igualavel& alheio) const {
	bool retorno = false;

	try {
		const Evento& evento = dynamic_cast<const Evento&>(alheio);

		if (evento.nomeCompleto() == this->nomeCompleto()) {
			//Debug::msg(INFO, "--- nomes iguais!");

			if (evento.intermediario() || this->intermediario()) {
				//Debug::msg(INFO, "--- um dos dois é intermediário!");
				retorno = true;
			} else if (this->pModificador->igual(*(evento.pModificador))) {
				//Debug::msg(INFO, "--- os modificadores sao iguais!");
				retorno = true;
			}
		}
	} catch (...) {
		Debug::msg(WARN, "Evento::igual(...):: O que você está tentando comparar com um Evento?? "
				   + *this + " ??");
	}

	return retorno;
}

string Evento::emString() const {
	string retorno;

	if (this->especial()) {
		retorno += "* ";
	}

	if (this->nome().apelidos().tamanho() > 0) {
		retorno += this->nome().apelidos()[0] + " ";
	}

	if (this->disparado()) {
		retorno += this->grupo() + (this->grupo() == Valor("")?"":".");
	}

	retorno += "<" + this->nome().valor() + ">";

	if (this->nome().apelidos().tamanho() == 0) {
		if (this->pModificador != NULL) {
			if (this->pModificador->acao()
				!= ModificadorDeEstado::APENAS_ATRIBUI)
			{
				retorno += "" + this->pModificador->acao();
			}

			retorno += "(";

			if (this->pModificador->campo() != Multifuncional::CAMPO_PRINCIPAL) {
				retorno += this->pModificador->campo() + "=";
			}

			if (this->pModificador->parametros().tamanho() > 0) {
				int tamanho = this->pModificador->parametros().tamanho();

				for (int i = 0; i < tamanho; i++) {
					retorno += "" + this->pModificador->parametros()[i];

					if (i < tamanho - 1) {
						retorno += ", ";
					}
				}
			}

			retorno += ")";
		}
	}

	if (this->disparado()) {
		retorno += " " + Intervalo(this->momentoDoDisparo());
	}

	return retorno;
}

Objeto* Evento::geraCopia() const {
	return new Evento(*this);
}

Copiavel& Evento::copiaEmSi(const Copiavel& alheio) {
	const Evento& e = dynamic_cast<const Evento&>(alheio);
	
	this->mudaNome(e.nome());
	this->pEspecial = e.pEspecial;
	this->pGrupo = e.pGrupo;

	if (this->pModificador != NULL) {
		delete this->pModificador;
	}

	if (e.pModificador == NULL) {
		this->pModificador = NULL;
	} else {
		this->pModificador = (ModificadorDeEstado*) e.pModificador->geraCopia();
	}

	if (this->pMomento != NULL) {
		delete this->pMomento;
	}

	if (e.pMomento == NULL) {
		this->pMomento = NULL;
	} else {
		this->pMomento = new Momento(*(e.pMomento));
	}

	return *this;
}

Evento Evento::criaEventoIntermediarioRelacionadoAEstado(const Estado& e) {
	return Evento(e.nomeCompleto());
}
