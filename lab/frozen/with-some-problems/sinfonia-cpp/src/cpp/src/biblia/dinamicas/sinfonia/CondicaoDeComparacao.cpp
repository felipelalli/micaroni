/**
 * $RCSfile: CondicaoDeComparacao.cpp,v $
 * $Date: 2005/03/04 00:32:18 $
 * $Revision: 1.13 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/CondicaoDeComparacao.h"
using namespace biblia::dinamicas::sinfonia;

CondicaoDeComparacao::CondicaoDeComparacao(
		const EstadoAlvo& estado1,
		const Identificacao& operacao,
		const EstadoAlvo& estado2)
	:pEstado1(estado1), pEstado2(estado2),
	 pOperador(operacao)
{}

CondicaoDeComparacao::CondicaoDeComparacao(const CondicaoDeComparacao& cdc)
	:pEstado1(cdc.pEstado1), pEstado2(cdc.pEstado2),
	 pOperador(cdc.pOperador)
{}

CondicaoDeComparacao::~CondicaoDeComparacao() {}

bool CondicaoDeComparacao::verdadeira() const {
//	Debug::msg(INFO, "--- vai executar: " + string(
//			this->pEstado1->valor(this->pCampo1)
//			.indefinida()?"<<IND>>":this->pEstado1->valor(this->pCampo1).emString())
//			+ " " + this->pOperador + " " + string(
//			this->pEstado2->valor(this->pCampo2)
//			.indefinida()?"<<IND>>":this->pEstado2->valor(this->pCampo2).emString()));

	Valor novoValor = Valor(Irrelevante());
	bool impossivelComparar = false;

	try {
		Estado* estado1;
		Estado* estado2;
		bool deletar1 = false, deletar2 = false;

		if (!this->pEstado1.constante()) {
			estado1 = (Estado*) &(this->pEstado1.estado());
		} else {
			deletar1 = true;
			estado1 = new Estado("&temp1");
			estado1->defineComoConstante();
			estado1->atribui(this->pEstado1.valorAlvo());
		}

		if (!this->pEstado2.constante()) {
			estado2 = (Estado*) &(this->pEstado2.estado());
		} else {
			deletar2 = true;
			estado2 = new Estado("&temp2");
			estado2->defineComoConstante();
			estado2->atribui(this->pEstado2.valorAlvo());
		}

		novoValor = estado1->executa(
				this->pOperador, estado2->valor(this->pEstado2.campoAlvo()),
				this->pEstado1.campoAlvo());

		if (deletar1) {
			delete estado1;
		}

		if (deletar2) {
			delete estado2;
		}

	} catch(const InformacaoNaoDefinidaExcecao&) {
		Debug::msg(ERRO, "CondicaoDeComparacao::verdadeira()::"
				" há valor indefinido!");

		impossivelComparar = true;
	} catch(const CampoInexistenteExcecao&) {
		Debug::msg(ERRO, "CondicaoDeComparacao::verdadeira()::"
				" há campo inválido!");

		impossivelComparar = true;
	}

//	Debug::msg(INFO, "--- resultado: " + novoValor);

	if (novoValor.indefinida()) {
		impossivelComparar = true;
	} else if (!novoValor.pareceSerBoleano()) {
		Debug::msg(ERRO, "CondicaoDeComparacao::verdadeira()::"
				" o resultado não é boleano!");

		impossivelComparar = true;
	}

	if (impossivelComparar) {
		ImpossivelCompararExcecao e;
		e << string() + "CondicaoDeComparacao::verdadeira() O resultado de: "
				+ *this + " não é um valor boleano! Resultado: "
				+ string(novoValor.indefinida()
					?"<<INDEFINIDO>>":novoValor.emString())
				+ ". Verifique qual é o problema desta condição. Pode"
				" ser um campo indefinido ou a referência de um campo"
				" que não existe no Estado apontado.";

		throw e;
	}

	return novoValor.emBool();
}

Objeto* CondicaoDeComparacao::geraCopia() const {
	return new CondicaoDeComparacao(*this);
}

Copiavel& CondicaoDeComparacao::copiaEmSi(const Copiavel& alheio) {
	const CondicaoDeComparacao& cdc
			= dynamic_cast<const CondicaoDeComparacao&>(alheio);

	this->pEstado1 = cdc.pEstado1;
	this->pEstado2 = cdc.pEstado2;
	this->pOperador = cdc.pOperador;

	return *this;
}

string CondicaoDeComparacao::emString() const {
	string retorno;

	Valor v1 = Valor(Irrelevante());
	Valor v2 = Valor(Irrelevante());

	try {
		v1 = this->pEstado1.valorAlvo();

		if (v1.indefinida()) {
			v1 = Valor("<<indefinido>>");
		}
	} catch(const CampoInexistenteExcecao&) {
		v1 = Valor("<<campo '" + this->pEstado1.campoAlvo() + "' indefinido>>");
	}

	try {
		v2 = this->pEstado2.valorAlvo();

		if (v2.indefinida()) {
			v2 = Valor("<<indefinido>>");
		}
	} catch(const CampoInexistenteExcecao&) {
		v2 = Valor("<<campo '" + this->pEstado2.campoAlvo() + "' indefinido>>");
	}

	retorno = string((this->pEstado1.constante()?true
					:this->pEstado1.estado().constante())
					?"":this->pEstado1.estado().nome().emString())
			+ string(this->pEstado1.campoAlvo()
			== Multifuncional::CAMPO_PRINCIPAL?"":"."
				+ this->pEstado1.campoAlvo())
			+ "(" + v1 + ") "
			+ this->pOperador + " "
			+ string((this->pEstado2.constante()?true
					:this->pEstado2.estado().constante())
					?"":this->pEstado2.estado().nome().emString())
			+ string(this->pEstado2.campoAlvo()
			== Multifuncional::CAMPO_PRINCIPAL?"":"."
				+ this->pEstado2.campoAlvo())
			+ "(" + v2 + ")";

	return retorno;
}
