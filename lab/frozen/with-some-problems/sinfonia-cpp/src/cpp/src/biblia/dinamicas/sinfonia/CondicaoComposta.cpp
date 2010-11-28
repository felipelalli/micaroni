/**
 * $RCSfile: CondicaoComposta.cpp,v $
 * $Date: 2005/02/23 22:32:51 $
 * $Revision: 1.5 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/CondicaoComposta.h"
using namespace biblia::dinamicas::sinfonia;

CondicaoComposta::CondicaoComposta(const Condicao& primeiraCondicao)
		:pLixo(), pLigacoes(), pCondicoes()
{
	Condicao* novaCondicao = (Condicao*) primeiraCondicao.geraCopia();
	this->pCondicoes.adiciona(novaCondicao);
	this->pLixo.adiciona(novaCondicao);
}

CondicaoComposta::CondicaoComposta() {}
CondicaoComposta::~CondicaoComposta() {}

CondicaoComposta& CondicaoComposta
		::adiciona(const Ligacao& ligacao, const Condicao& c)
{
	this->pLigacoes.adiciona(ligacao);

	Condicao* novaCondicao = (Condicao*) c.geraCopia();
	this->pCondicoes.adiciona(novaCondicao);
	this->pLixo.adiciona(novaCondicao);
	return *this;
}

bool CondicaoComposta::verdadeira() const {
	bool retorno = this->pCondicoes[0]->verdadeira();

	for (int i = 1; i < this->pCondicoes.tamanho(); i++) {
		const Ligacao& ligacao = this->pLigacoes[i - 1];
		const Condicao& condicao = *(this->pCondicoes[i]);

		switch (ligacao) {
		case AND:
			retorno = (retorno && condicao.verdadeira());
			break;

		case OR:
			retorno = (retorno || condicao.verdadeira());
			break;

		case XOR:
			retorno = (retorno != condicao.verdadeira());
			break;

		case EQ:
			retorno = (retorno == condicao.verdadeira());
			break;

		default:
			Debug::msg(ERRO, "CondicaoComposta::verdadeira():: Ligacao desconhecida!");
			break;
		}
	}

	return retorno;
}

Objeto* CondicaoComposta::geraCopia() const {
	CondicaoComposta* novaCondicao = new CondicaoComposta();
	novaCondicao->copiaEmSi(*this);
	return novaCondicao;
}

Copiavel& CondicaoComposta::copiaEmSi(const Copiavel& alheio) {
	const CondicaoComposta& cc = dynamic_cast<const CondicaoComposta&>(alheio);

	this->pCondicoes.limpa();
	this->pLigacoes.limpa();
	this->pLixo.limpa();

	for (int i = 0; i < cc.pCondicoes.tamanho(); i++) {
		Condicao* novaCondicao = (Condicao*) cc.pCondicoes[i]->geraCopia();
		this->pCondicoes.adiciona(novaCondicao);
		this->pLixo.adiciona(novaCondicao);

		if (i < cc.pLigacoes.tamanho()) {
			this->pLigacoes.adiciona(cc.pLigacoes[i]);
		}
	}

	return *this;
}

string CondicaoComposta::emString() const {
	string retorno = "(";

	for (int i = 0; i < this->pCondicoes.tamanho(); i++) {
		retorno += this->pCondicoes[i]->emString();

		if (i < this->pCondicoes.tamanho() - 1) {
			retorno += string(" ")
				+ string(this->pLigacoes[i] == AND?"&":this->pLigacoes[i] == OR?"|"
				:this->pLigacoes[i] == XOR?"XOR":this->pLigacoes[i] == EQ?"="
				:this->pLigacoes[i] == DIF?"!=":"???") + string(" ");
		}
	}

	return retorno + ")";
}
