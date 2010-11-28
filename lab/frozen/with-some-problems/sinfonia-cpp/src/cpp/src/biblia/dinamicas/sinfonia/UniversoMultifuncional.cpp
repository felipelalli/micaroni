/**
 * $RCSfile: UniversoMultifuncional.cpp,v $
 * $Date: 2005/01/27 22:42:28 $
 * $Revision: 1.7 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/UniversoMultifuncional.h"
using namespace biblia::dinamicas::sinfonia;

UniversoMultifuncional::UniversoMultifuncional()
		:pPossibilidades(), pNaoPodeSer(), pLixo(),
		 pMenorQue(Irrelevante()), pMaiorQue(Irrelevante())
{}

UniversoMultifuncional::~UniversoMultifuncional() {}

UniversoMultifuncional& UniversoMultifuncional::maiorQue(const Valor& v) {
	this->pMaiorQue = v;
	return *this;
}

UniversoMultifuncional& UniversoMultifuncional::menorQue(const Valor& v) {
	this->pMenorQue = v;
	return *this;
}

UniversoMultifuncional& UniversoMultifuncional::maiorOuIgualA(const Valor& v) {
	this->pMaiorQue = v;
	this->adicionaPossibilidade(v);
	return *this;
}

UniversoMultifuncional& UniversoMultifuncional::menorOuIgualA(const Valor& v) {
	this->pMenorQue = v;
	this->adicionaPossibilidade(v);
	return *this;
}

UniversoMultifuncional& UniversoMultifuncional
		::adicionaPossibilidade(const Valor& v)
{
	Valor* novoValor = new Valor(v);
	this->pLixo.adiciona(novoValor);

	if (!this->pPossibilidades.existe(v.valor())) {
		this->pPossibilidades.insere(v.valor(), novoValor);
	} else {
		Debug::msg(WARN, "UniversoMultifuncional::adicionaPossibilidade(" + *this
				+ ") a possibilidade '" + v + "' já foi adicionada anteriormente.");
	}

	for (int i = 0; i < v.apelidos().tamanho(); i++) {
		string id = v.apelidos()[i];
		if (!this->pPossibilidades.existe(id)) {
			this->pPossibilidades.insere(id, novoValor);
		} else {
			Debug::msg(WARN, "UniversoMultifuncional::adicionaPossibilidade(" + *this
					+ ") apelido - a possibilidade '" + v + "' já foi adicionada anteriormente.");
		}
	}

	return *this;
}

UniversoMultifuncional& UniversoMultifuncional
		::adicionaNaoPodeSer(const Valor& v)
{
	Valor* novoValor = new Valor(v);
	this->pLixo.adiciona(novoValor);
	this->pNaoPodeSer.insere(v.valor(), novoValor);

	for (int i = 0; i < v.apelidos().tamanho(); i++) {
		this->pNaoPodeSer.insere(v.apelidos()[i], novoValor);
	}

	return *this;
}

const bool UniversoMultifuncional::estaContido(const Valor& v) const {
//	Debug::msg(INFO, "--- vai ver se está contido");

	bool retorno = true;

	if (!v.indefinida()) {
		if (this->pPossibilidades.existe(v.valor())
			&& !this->pNaoPodeSer.existe(v.valor()))
		{
			retorno = true;
		} else {
			if (!this->pMaiorQue.indefinida()) {
				if (v < this->pMaiorQue) {
					retorno = false;
				}
			}

			if (!this->pMenorQue.indefinida()) {
				if (v > this->pMenorQue) {
					retorno = false;
				}
			}

			if (this->pNaoPodeSer.existe(v.valor())) {
				retorno = false;
			}
		}
	}

//	Debug::msg(INFO, "--- viu se está contido");

	return retorno;
}

const Valor& UniversoMultifuncional::correspondente(const Valor& v) const {
//	Debug::msg(INFO, "--- entrou no multif.");

	const static Irrelevante irrelevante;

	if (v.indefinida()) {
		return irrelevante;
	} else if (!this->pPossibilidades.existe(v.valor())) {
//		Debug::msg(INFO, "--- vai sair do multif. com indef");
		return irrelevante;
	} else {
//		Debug::msg(INFO, "--- vai sair do multif. com a possib.");
		return *(this->pPossibilidades[v.valor()]);
	}
}

Lista<Identificacao>* UniversoMultifuncional::possibilidades() const {
	return this->pPossibilidades.chaves();
}

Lista<Identificacao>* UniversoMultifuncional::naoPodeAssumir() const {
	return this->pNaoPodeSer.chaves();
}

string UniversoMultifuncional::emString() const {
	Lista<Identificacao>* podeSer = this->possibilidades();
	Lista<Identificacao>* naoPodeSer = this->naoPodeAssumir();

	string retorno = "aceita somente {";

	for (int i = 0; i < podeSer->tamanho(); i++) {
		retorno += (*podeSer)[i].emString();

		if (i < podeSer->tamanho() - 1) {
			retorno += ", ";
		}
	}

	retorno += "} e não aceita {";

	for (int j = 0; j < naoPodeSer->tamanho(); j++) {
		retorno += (*naoPodeSer)[j].emString();

		if (j < naoPodeSer->tamanho() - 1) {
			retorno += ", ";
		}
	}

	retorno += "}";

	delete naoPodeSer;
	delete podeSer;

	return retorno;
}
