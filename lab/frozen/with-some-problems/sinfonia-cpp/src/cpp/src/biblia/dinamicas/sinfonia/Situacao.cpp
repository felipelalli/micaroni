/**
 * $RCSfile: Situacao.cpp,v $
 * $Date: 2005/03/17 01:18:09 $
 * $Revision: 1.13 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/Situacao.h"
using namespace biblia::dinamicas::sinfonia; 

Situacao::Situacao(const Valor& nome)
		:Rotulado(nome), pQuandoOcorrer(),
		 pOQueGera(), pOQueGeraSenao(),
		 pSomenteSe(NULL)
{}

Situacao::~Situacao() {
	if (this->pSomenteSe) {
		delete this->pSomenteSe;
	}
}

Situacao& Situacao::adicionaEvento(const Evento& e) {
	Evento* novoEvento = (Evento*) e.geraCopia();
	this->pQuandoOcorrer.adiciona(novoEvento);
	this->pLixo.adiciona(novoEvento);
	return *this;
}

Situacao& Situacao::defineCondicao(const Condicao& c) {
	if (this->pSomenteSe) {
		delete this->pSomenteSe;
	}

	this->pSomenteSe = (Condicao*) c.geraCopia();
	return *this;
}

const bool Situacao::aconteceu(const Evento& e) const {
	bool retorno = false;

	if (this->eventoCorresponde(e)) {
		if (this->condicaoVerdadeira()) {
			retorno = true;
		}
	}

	return retorno;
}

const bool Situacao::eventoCorresponde(const Evento& e) const {
	bool corresponde = false;

	for (int i = 0; i < this->pQuandoOcorrer.tamanho() && !corresponde; i++) {
		if (this->pQuandoOcorrer[i]->igual(e)) {
			corresponde = true;
//			Debug::msg(INFO, "--- igual: " + *(this->pQuandoOcorrer[i])
//					+ " e: " + e);
		} else {
//			Debug::msg(INFO, "--- diferente: " + *(this->pQuandoOcorrer[i])
//					+ " e: " + e);
		}
	}

	return corresponde;
}

const bool Situacao::condicaoVerdadeira() const {
	return this->condicao().verdadeira();
}

const Lista<const Evento*>& Situacao::seAcontecerUmDessesEventos() const {
	return this->pQuandoOcorrer;
}

Situacao& Situacao::adicionaEventoQueGera(const Evento& e) {
	Evento* novoEvento = (Evento*) e.geraCopia();
	this->pOQueGera.adiciona(novoEvento);
	this->pLixo.adiciona(novoEvento);

	return *this;
}

const Lista<const Evento*>& Situacao::oQueGera() const {
	return this->pOQueGera;
}

Situacao& Situacao::adicionaEventoQueGeraSenao(const Evento& e) {
	Evento* novoEvento = (Evento*) e.geraCopia();
	this->pOQueGeraSenao.adiciona(novoEvento);
	this->pLixo.adiciona(novoEvento);

	return *this;
}

const Lista<const Evento*>& Situacao::oQueGeraSenao() const {
	return this->pOQueGeraSenao;
}

const Condicao& Situacao::condicao() const {
	static Boleana verdadeiro(true);
	
	if (this->pSomenteSe == NULL) {
		return verdadeiro;
	} else {
		return *(this->pSomenteSe);
	}
}

string Situacao::emString() const {
	string retorno;

//	Debug::msg(INFO, "--- vai exibir");

	retorno += Rotulado::emString() + ". Eventos que a dispara: {";

//	Debug::msg(INFO, "--- eventos q a dispara");

	int i;
	for (i = 0; i < this->seAcontecerUmDessesEventos().tamanho(); i++) {
		retorno += this->seAcontecerUmDessesEventos()[i]->emString();

		if (i < this->seAcontecerUmDessesEventos().tamanho() - 1) {
			retorno += ", ";
		}
	}

//	Debug::msg(INFO, "--- condicao");

	retorno += "}. Condicao: {" + this->condicao().emString() + "}. --> {";

//	Debug::msg(INFO, "--- o que gera");

	for (i = 0; i < this->oQueGera().tamanho(); i++) {
		retorno += this->oQueGera()[i]->emString();

		if (i < this->oQueGera().tamanho() - 1) {
			retorno += ", ";
		}
	}

	retorno += "} ~ {";

//	Debug::msg(INFO, "--- o que gera senao");

	for (i = 0; i < this->oQueGeraSenao().tamanho(); i++) {
		retorno += this->oQueGeraSenao()[i]->emString();

		if (i < this->oQueGeraSenao().tamanho() - 1) {
			retorno += ", ";
		}
	}

//	Debug::msg(INFO, "--- pronto");

	return retorno + "}";
}
