/**
 * $RCSfile: EstadoDependente.cpp,v $
 * $Date: 2005/03/02 00:30:59 $
 * $Revision: 1.9 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/EstadoDependente.h"
using namespace biblia::dinamicas::sinfonia;

UniversoSequencial EstadoDependente::pSequencial;

EstadoDependente::EstadoDependente(const EstadoAlvo& primeiroEstado)
	:Estado("EstadoDependente(" + EstadoDependente::pSequencial.agora() + ")"),
	 pUltimoValor(Irrelevante())
{
	this->pEstados.adiciona(primeiroEstado);
	this->externo(true);
}

EstadoDependente::~EstadoDependente() {}

EstadoDependente& EstadoDependente::adicionaEstado(
		const Identificacao& operacao, const EstadoAlvo& ea)
{
	this->pEstados.adiciona(ea);
	this->pOperacoes.adiciona(operacao);
	return *this;
}

const Valor& EstadoDependente::valor(const Valor& campo) const {
	if (campo != Multifuncional::CAMPO_PRINCIPAL) {
		FuncaoNaoImplementadaExcecao e;
		e << "EstadoDependente::valor::"
				" Só é possível acessar campo Multifuncional::CAMPO_PRINCIPAL";

		throw e;
	} else {
		this->pUltimoValor = this->pEstados[0].estado().valor(
				this->pEstados[0].campoAlvo().emString());

		bool indefinido = false;
		for (int i = 1; i < this->pEstados.tamanho()
				&& !indefinido; i++)
		{
			if (this->pUltimoValor.indefinida()
				|| this->pEstados[i]
					.estado().valor(
						this->pEstados[i].campoAlvo().emString())
						.indefinida())
			{
				indefinido = true;
				this->pUltimoValor = Irrelevante();
				Debug::msg(WARN, "Há um valor indefinido na montagem"
						" deste EstadoDependente: '" + *this + "'. O"
						" seu valor passa a ser Irrelevante.");
			} else {
				Valor novoValor(this->pEstados[i - 1].estado()
						.classe().aplica(this->pUltimoValor,
							this->pOperacoes[i - 1], this->pEstados[i]
							.estado().valor(this->pEstados[i].campoAlvo().emString())));

				this->pUltimoValor = novoValor;
			}
		}
	}

	return this->pUltimoValor;
}

string EstadoDependente::emString(const Valor& v) const {
	if (v != Multifuncional::CAMPO_PRINCIPAL) {
		FuncaoNaoImplementadaExcecao e;
		e << "EstadoDependente::valor::"
				" Só é possível acessar campo Multifuncional::CAMPO_PRINCIPAL";

		throw e;
	}

	string retorno = "" + this->pEstados[0].estado();

	if (Valor(this->pEstados[0].campoAlvo().emString())
		!= Multifuncional::CAMPO_PRINCIPAL)
	{
		retorno += "." + this->pEstados[0].campoAlvo();
	}

	for (int i = 1; i < this->pEstados.tamanho(); i++) {
		retorno += " " + this->pOperacoes[i - 1]
				+ " " + this->pEstados[i].estado();

		if (Valor(this->pEstados[i].campoAlvo().emString())
			!= Multifuncional::CAMPO_PRINCIPAL)
		{
			retorno += "." + this->pEstados[i].campoAlvo();
		}
	}

	return retorno;
}
