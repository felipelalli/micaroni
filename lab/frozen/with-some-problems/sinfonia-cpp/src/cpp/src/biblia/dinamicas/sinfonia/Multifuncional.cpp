/**
 * $RCSfile: Multifuncional.cpp,v $
 * $Date: 2005/03/12 00:43:07 $
 * $Revision: 1.10 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/Multifuncional.h"
using namespace biblia::dinamicas::sinfonia;

Valor Multifuncional::CAMPO_PRINCIPAL = "* PRINCIPAL";

Identificacao Multifuncional::NOT = "!";
Identificacao Multifuncional::OR = "|";
Identificacao Multifuncional::AND = "&";
Identificacao Multifuncional::DIVIDIDO = "/";
Identificacao Multifuncional::VEZES = "*";
Identificacao Multifuncional::MENOS = "-";
Identificacao Multifuncional::MAIS = "+";
Identificacao Multifuncional::IGUALDADE = "=";
Identificacao Multifuncional::DIFERENCA = "!=";
Identificacao Multifuncional::MENOR = "<";
Identificacao Multifuncional::MAIOR = ">";
Identificacao Multifuncional::MENOR_OU_IGUAL = "<=";
Identificacao Multifuncional::MAIOR_OU_IGUAL = ">=";

Multifuncional::Multifuncional():Classe("Multifuncional") {
	this->acoes().adiciona(NOT).adiciona(OR)
			.adiciona(AND).adiciona(DIVIDIDO)
			.adiciona(VEZES).adiciona(MENOS)
			.adiciona(MAIS).adiciona(IGUALDADE)
			.adiciona(MENOR).adiciona(MAIOR)
			.adiciona(MENOR_OU_IGUAL).adiciona(MAIOR_OU_IGUAL)
			.adiciona(DIFERENCA);

	this->camposParaModificar().adiciona(
			Multifuncional::CAMPO_PRINCIPAL.original());
}

Multifuncional::~Multifuncional() {}

const Valor Multifuncional::aplica(const Valor& valorA,
		const Identificacao& acao, const Lista<const Valor*>& valores) const
{
	if (valores.tamanho() > 1) {
		AcaoIndisponivelExcecao e;
		e << "Multifuncional::aplica:: valor A: " + valorA + ", ação: "
				+ acao + ", valores: " + valores 
				+ ". Um Multifuncional não sabe aplicar um"
				" valor qualquer a mais de um valor ou nenhum valor!";
		throw e;
	} else if (valores.tamanho() == 0) {
	    if (acao == Multifuncional::NOT) {
			return Valor(!valorA.emBool());
		} else if (acao == Multifuncional::IGUALDADE) {
			return Valor(valorA == Irrelevante());
		} else if (acao == Multifuncional::DIFERENCA) {
			return Valor(valorA != Irrelevante());
		} else {
			AcaoIndisponivelExcecao e;
			e << "Multifuncional::aplica:: valor A: " + valorA + ", ação: "
					+ acao + ". Um Multifuncional não sabe aplicar"
					" esta ação unária! Só é possível aplicar NOT.";
			throw e;
		}
	} else {
		const Valor& valorB = *(valores[0]);

		// FIXME: otimizar isto aqui utilizando MapaHash
		if (acao == Multifuncional::OR) {
			return Valor(valorA.emBool() || valorB.emBool());
		} else if (acao == Multifuncional::AND) {
			return Valor(valorA.emBool() && valorB.emBool());
		} else if (acao == Multifuncional::DIVIDIDO) {
			return Valor(valorA.emDouble() / valorB.emDouble());
		} else if (acao == Multifuncional::VEZES) {
			return Valor(valorA.emDouble() * valorB.emDouble());
		} else if (acao == Multifuncional::MENOS) {
			return Valor(valorA.emDouble() - valorB.emDouble());
		} else if (acao == Multifuncional::MAIS) {
			if (valorA.pareceSerNumero()
				&& valorB.pareceSerNumero())
			{
				return Valor(valorA.emDouble() + valorB.emDouble());
			} else {
				return Valor(valorA.emString() + valorB.emString());
			}
		} else if (acao == Multifuncional::IGUALDADE) {
			return Valor(valorA == valorB);
		} else if (acao == Multifuncional::DIFERENCA) {
			return Valor(valorA != valorB);
		} else if (acao == Multifuncional::MENOR) {
			return Valor(valorA < valorB);
		} else if (acao == Multifuncional::MAIOR) {
			return Valor(valorA > valorB);
		} else if (acao == Multifuncional::MENOR_OU_IGUAL) {
			return Valor(valorA <= valorB);
		} else if (acao == Multifuncional::MAIOR_OU_IGUAL) {
			return Valor(valorA >= valorB);
		} else {
			AcaoIndisponivelExcecao e;
			e << "Multifuncional::aplica:: valor A: " + valorA + ", ação: "
					+ acao + ", valor B: " + valorB 
					+ ". Um Multifuncional não sabe aplicar esta"
					" ação binária! Só é possível aplicar ações binárias.";
			throw e;
		}
	}
}