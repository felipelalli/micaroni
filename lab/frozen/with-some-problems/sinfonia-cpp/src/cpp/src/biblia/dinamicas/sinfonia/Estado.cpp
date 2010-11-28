/**
 * $RCSfile: Estado.cpp,v $
 * $Date: 2005/03/04 06:34:48 $
 * $Revision: 1.30 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/Estado.h"
using namespace biblia::dinamicas::sinfonia;

Multifuncional Estado::MULTIFUNCIONAL;
Valor Estado::CONSTANTE = "Sinfonia.Reservados.estado constante";
Valor Estado::META_NOME = "meta nome";

Estado::Estado(const Valor& nome, const Classe* c)
		:Rotulado(nome), pNomeCompleto(nome),
		 pClasse(c), pExterno(false),
		 pQuaisCampos(), pCampos(), pGrupo(""),
		 pUltimaMudanca(NULL), pUniversos(),
		 pLixo(), pConstante(false)
{
//	Valor* metaNome = new Valor(this->pNomeCompleto);
//	this->pCampos.insere(Estado::META_NOME.emString(), metaNome);
//	this->pQuaisCampos.adiciona(Estado::META_NOME.emString());
// VOLTAR AQUI
}

Estado::~Estado() {
	for (int i = 0; i < this->campos().tamanho(); i++) {
		delete this->pCampos[this->campos()[i]];
	}

	if (this->pUltimaMudanca) {
		delete this->pUltimaMudanca;
	}
}

const bool& Estado::externo() const {
	return this->pExterno;
}

Estado& Estado::externo(const bool& sim) {
	this->pExterno = sim;
	return *this;
}

const Valor& Estado::grupo() const {
	return this->pGrupo;
}

Estado& Estado::grupo(const Valor& grupo) {
	if (grupo.valor().compare("") != 0) {
		this->pGrupo = grupo;
		Valor nomeCompleto(this->grupo() + "." + this->nome());
		this->pNomeCompleto = nomeCompleto;

//		this->atribui(nomeCompleto, Estado::META_NOME);

//		if (nomeCompleto == Valor("teste.animacao.animacao3")) {
//			Debug::msg(INFO, "--- vai definir grupo para: " + nomeCompleto);
//		}
// VOLTAR AQUI
	}

	return *this;
}

const Valor Estado::nomeCompleto() const {
	return this->pNomeCompleto;
}

const Classe& Estado::classe() const {
	return *(this->pClasse);
}

const bool& Estado::constante() const {
	return this->pConstante;
}

const Valor& Estado::valor(const Valor& campo) const {
	const Valor* v = NULL;

	if (!this->pCampos.existe(campo.valor())) {
		CampoInexistenteExcecao e;
		e << "Estado::valor():: campo '"
				+ campo + "' ainda não definido! Estado: '"
				+ this->nomeCompleto() + "'. Endereço: "
				+ Inteiro((int) this);

		throw e;
	}

	v = this->pCampos[campo.valor()];

	if (v->indefinida()) {
		Debug::msg(WARN, "Estado::valor:: Cuidado! Valor buscado"
				" está indefinido! Este estado: "
				+ this->nomeCompleto() + "(" + campo + ")");
	}

	return *v;
}

const Lista<Identificacao>& Estado::campos() const {
	return this->pQuaisCampos;
}

const Valor Estado::executa(const Identificacao& acao,
					const Valor& valor,	const Valor& qualCampo) const
{
	const Valor* novoValor = new Valor(valor);
	Lista<const Valor*> valores;

	if (!valor.indefinida()) {
		valores.adiciona(novoValor);
	}

	Valor retorno(this->executa(acao, valores, qualCampo));
	delete novoValor;
	return retorno;
}

const Valor Estado::executa(const Identificacao& acao,
						const Lista<const Valor*>& valores,
						const Valor& qualCampo) const
{
	Valor retorno = Valor(Irrelevante());

	retorno = Valor(this->classe().aplica(
			this->valor(qualCampo), acao, valores));

	return retorno;
}

Estado& Estado::atribui(const Valor& valor,
						const Valor& campo)
{
	if (this->constante() && this->pUltimaMudanca != NULL) {
		EstadoConstanteExcecao e;
		e << "Estado::atribui:: o estado '" + this->nomeCompleto()
				+ "' de valor " + this->valor() + " é constante"
				" e não pode ser modificado pela segunda vez.";

		throw e;
	} else {
		if (!this->universo(campo).estaContido(valor)) {
			ForaDeIntervaloExcecao e;
			e << "Estado::atribui:: O valor '" + valor
					+ "' está fora do intervalo do universo: "
					+ this->universo(campo);

			throw e;
		} else {
			Valor* novoValor = (Valor*) valor.geraCopia();
			string id = campo.valor();

			if (this->pCampos.existe(id)) {
				Valor* aDeletar = this->pCampos[id];
				this->pCampos.modifica(id, novoValor);
				delete aDeletar;
			} else {
				this->pQuaisCampos.adiciona(id);
				this->pCampos.insere(id, novoValor);
			}
		}
	}

	return *this;
}

Estado& Estado::atribui(const Valor& valor,
						const UniversoDeTempo& udt,
						const Valor& campo)
{
	this->atribui(valor, campo);

	if (this->pUltimaMudanca) {
		delete this->pUltimaMudanca;
	}

	this->pUltimaMudanca = new Momento(udt.agora());

	return *this;
}

const Momento& Estado::ultimaModificacao() const {
	if (!this->pUltimaMudanca) {
		ReferenciaNulaExcecao e;
		e << "Estado::ultimaModificacao():: este Estado nunca foi modificado.";
		throw e;
	}

	return *(this->pUltimaMudanca);
}

const UniversoMultifuncional& Estado::universo(const Valor& campo) const {
	if (!this->pUniversos.existe(campo.valor())) {
		UniversoMultifuncional* novoUniverso = new UniversoMultifuncional();
		this->pLixo.adiciona(novoUniverso);
		this->pUniversos.insere(campo.valor(), novoUniverso);
	}

	return *(this->pUniversos[campo.valor()]);
}

UniversoMultifuncional& Estado::universoParaModificar(const Valor& campo) {
	if (!this->pUniversos.existe(campo.valor())) {
		UniversoMultifuncional* novoUniverso = new UniversoMultifuncional();
		this->pLixo.adiciona(novoUniverso);
		this->pUniversos.insere(campo.valor(), novoUniverso);
	}

	return *(this->pUniversos[campo.valor()]);
}

Estado& Estado::defineComoConstante() {
	this->pConstante = true;
	return *this;
}

string Estado::emString(const Valor& campo) const {
//	Debug::msg(INFO, "--- entrou aqui");
	bool temApelido = false;
	string retorno;

	if (this->constante()) {
		retorno = "[]";
	} else {
		retorno = string(this->externo()?"* ":"")
				+ "[" + this->nome().valor() + "]";
	}

	if (campo != Multifuncional::CAMPO_PRINCIPAL) {
		retorno += "." + campo;
	}

	try {
//		Debug::msg(INFO, "--- entrou aqui 2 - retorno: " + retorno);

		if (this->valor(campo).pareceSerBoleano()) {
//			Debug::msg(INFO, "--- entrou aqui 2.5");

			if (this->universo().correspondente(
					this->valor(campo)) != Irrelevante())
			{
//				Debug::msg(INFO, "--- entrou aqui 2.7");

				if (this->universo().correspondente(
					this->valor(campo)).apelidos().tamanho() > 0)
				{
//					Debug::msg(INFO, "--- entrou aqui 3");

					temApelido = true;
					retorno = this->universo().correspondente(
							this->valor(campo)).apelidos()[0] + " " + retorno;
				}
			}
		} 

//		Debug::msg(INFO, "--- antes do segundo if");	

		if (!temApelido) {
			if (this->valor(campo).indefinida()) {
				retorno += "(-indefinido-)";
			} else {
				retorno += "(" + this->valor(campo) + ")";
			}
		}
	} catch(const CampoInexistenteExcecao&) {
		retorno += "<< sem campo principal >>";
	}

//	Debug::msg(INFO, "--- saiu daqui");
	return retorno;
}