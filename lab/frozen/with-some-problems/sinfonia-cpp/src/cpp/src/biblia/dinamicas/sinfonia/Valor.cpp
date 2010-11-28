/**
 * $RCSfile: Valor.cpp,v $
 * $Date: 2005/03/02 20:12:57 $
 * $Revision: 1.18 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/Valor.h"
using namespace biblia::dinamicas::sinfonia;

int Valor::IRRELEVANTE = -1;
int Valor::DESCONHECIDO = 0;
int Valor::BOOL = 1;
int Valor::DOUBLE = 2;
int Valor::STRING = 4;
string Valor::VERDADEIRO = "V";
string Valor::FALSO = "F";

Valor::Valor():Informacao(), pTipoParaComparacao(Valor::IRRELEVANTE) {}

Valor::Valor(const Valor& v) {
	*this = v;
}

Valor::Valor(const string& original, const bool& literal)
	:Informacao(), pTipoParaComparacao(Valor::DESCONHECIDO), pOriginal(original)
{
	this->pModificado = ((literal || this->pOriginal.compare(Valor::VERDADEIRO) == 0
			|| this->pOriginal.compare(Valor::FALSO) == 0)
			? this->pOriginal : this->modifica(this->pOriginal));

	if (literal) {
		this->pTipoParaComparacao = Valor::STRING;
	} else {
		this->determinaTipo();
	}

	this->definiu();
}

// FIXME: Como em C++ faz para chamar outro construtor da mesma classe?
Valor::Valor(const char* original, const bool& literal)
	:Informacao(), pTipoParaComparacao(Valor::DESCONHECIDO), pOriginal(string(original))
{
	this->pModificado = ((literal || this->pOriginal.compare(Valor::VERDADEIRO) == 0
			|| this->pOriginal.compare(Valor::FALSO) == 0)
			? this->pOriginal : this->modifica(this->pOriginal));

	if (literal) {
		this->pTipoParaComparacao = Valor::STRING;
	} else {
		this->determinaTipo();
	}

	this->definiu();
}

Valor::Valor(const int& original):Informacao(), pTipoParaComparacao(Valor::DOUBLE) {
	this->pOriginal = this->pModificado = Inteiro(original).emString();
	this->definiu();
}

Valor::Valor(const double& original):Informacao(), pTipoParaComparacao(Valor::DOUBLE) {
	this->pOriginal = this->pModificado = Flutuante(original).emString();
	this->definiu();
}

Valor::Valor(const bool& original):Informacao(), pTipoParaComparacao(Valor::BOOL) {
	this->pOriginal = this->pModificado = original?Valor::VERDADEIRO:Valor::FALSO;
	this->definiu();
}

Valor::~Valor() {}

const string Valor::modifica(const string& s) const {
	static string acentos   = "ãÃáÁâÂäÄàÀéÉêÊëËèÈíÍîÎïÏìÌõÕóÓôÔöÖòÒúÚûÛüÜùÙçÇıİ,_\t";
	static string semAcento = "aaaaaaaaaaeeeeeeeeiiiiiiiioooooooooouuuuuuuuccyy.  ";
	string retorno(s);

	for (unsigned int i = 0; i < s.size(); i++) {
		bool achou = false;
		unsigned int j = 0;

		for (; j < acentos.size() && !achou; j++) {
			if (s[i] == acentos[j]) {
				achou = true;
			}
		}

		j--;

		if (achou) {
			//char msg[200];
			//sprintf(msg, "--- trocando [%d]'%c' por [%d]'%c'", i, retorno[i], j, semAcento[j]);
			//Debug::msg(INFO, string() + msg);

			retorno[i] = semAcento[j];
		} else {
			retorno[i] = tolower(s[i]);
		}
	}

	// FIXME: tem que dar o "trim", mas acho q em c++ tem q implementar mesmo

	return retorno;
}

const int Valor::determinaTipo() {
	// determinando o tipo para fazer a comparação
	if (this->pTipoParaComparacao == Valor::DESCONHECIDO) {
		if ((this->pModificado.compare(Valor::VERDADEIRO) == 0
			|| this->pModificado.compare(Valor::FALSO) == 0))
		{
			this->pTipoParaComparacao = Valor::BOOL;
		} else {
			this->pTipoParaComparacao = Valor::DOUBLE;

			for (unsigned int i = 0; i < this->pModificado.size()
					&& this->pTipoParaComparacao == Valor::DOUBLE; i++)
			{
				if (!isdigit(this->pModificado[i])
					&& this->pModificado[i] != '.'
					&& this->pModificado[i] != '-')
				{
					this->pTipoParaComparacao = Valor::STRING;
				}
			}
		}
	}

	return this->pTipoParaComparacao;
}

Valor& Valor::adicionaApelido(const string& apelido) {
	//this->verificaSeInformacaoEstaDefinidaAntesDeRetornarOValor();
	const string apelidoModificado = this->modifica(apelido);

	if (this->pApelidos.existe(apelidoModificado)) {
		Debug::msg(WARN, "Valor::adicionaApelido: '" + apelido + "' já foi adicionado!");
	} else {
		this->pApelidos.insere(apelidoModificado, true);
		this->pListaDeApelidos.adiciona(apelidoModificado);
	}

	return *this;
}

const Lista<string>& Valor::apelidos() const {
	return this->pListaDeApelidos;
}

const string& Valor::valor() const {
	this->verificaSeInformacaoEstaDefinidaAntesDeRetornarOValor();
	return this->pModificado;
}

const string& Valor::original() const {
	this->verificaSeInformacaoEstaDefinidaAntesDeRetornarOValor();
	return this->pOriginal;
}

const int Valor::emInt() const {
	this->verificaSeInformacaoEstaDefinidaAntesDeRetornarOValor();
	//return Inteiro::valorDe(this->pOriginal).valor();
	return atoi(this->pOriginal.c_str());
}

string Valor::emString() const {
	return this->valor();
}

const double Valor::emDouble() const {
	this->verificaSeInformacaoEstaDefinidaAntesDeRetornarOValor();

	// FIXME: atualizar para Flutuante::valorDe na próx. atualização da biblioteca Bíblia
	return atof(this->pOriginal.c_str());
}

const bool Valor::emBool() const {
	this->verificaSeInformacaoEstaDefinidaAntesDeRetornarOValor();

	if (this->pOriginal.compare(Valor::VERDADEIRO) == 0) {
		return true;
	} else {
		return false;
	}
}

const bool Valor::pareceSerBoleano() const {
	return (this->pTipoParaComparacao == Valor::BOOL);
}

const bool Valor::pareceSerNumero() const {
	return (this->pTipoParaComparacao == Valor::DOUBLE);
}

const bool Valor::pareceSerString() const {
	return (this->pTipoParaComparacao == Valor::STRING);
}

string Valor::geraStringUnicaECompleta() const {
	string retorno = this->pOriginal + ":" + this->pModificado;

	for (int i = 0; i < this->pListaDeApelidos.tamanho(); i++) {
		retorno += ":" + this->pListaDeApelidos[i];
	}

	return retorno;
}

const bool Valor::menorQue(const Comparavel& alheio) const {
	try {
		this->verificaSeInformacaoEstaDefinidaAntesDeRetornarOValor();
	} catch (InformacaoNaoDefinidaExcecao inde) {
		inde << " + this: " + *this;
		throw inde;
	}

	const Valor& valor = dynamic_cast<const Valor&>(alheio);

	if (this->pareceSerBoleano() && valor.pareceSerBoleano()) {
		return (!this->emBool() && valor.emBool());
	} else if (this->pareceSerNumero() && valor.pareceSerNumero()) {
		return this->emDouble() < valor.emDouble();
	} else {
		if (!this->pareceSerString()) {
			Debug::msg(ERRO, string() + "Erro interno: Verificar função const bool"
					+ " Valor::menorQue(const Comparavel& alheio) const");
		}

		return this->pModificado.compare(valor.pModificado) < 0;
	}
}

const bool Valor::igual(const Igualavel& alheio) const {
	const Valor& valor = dynamic_cast<const Valor&>(alheio);
	bool retorno;

	if (this->indefinida() && valor.indefinida()) {
		retorno = true;
	} else if (this->indefinida() || valor.indefinida()) {
		retorno = false;
	} else if (this->pareceSerNumero() && valor.pareceSerNumero()) {
		retorno = (this->emDouble() == valor.emDouble());
	} else if (this->pareceSerBoleano() && valor.pareceSerBoleano()) {
		retorno = (this->emBool() == valor.emBool());
	} else {
		retorno = this->pModificado.compare(valor.pModificado) == 0;

		if (!retorno && this->pApelidos.tamanho() > 0
			&& valor.pApelidos.tamanho() > 0)
		{
			Lista<Identificacao>* chaves = valor.pApelidos.chaves();
			Lista<Identificacao>& c = *chaves;

			for (int i = 0; i < c.tamanho() || retorno; i++) {
				if (this->pApelidos.existe(c[i])) {
					if (this->pApelidos[c[i]]) {
						retorno = true;
					}
				}
			}

			delete chaves;
		}
	}

	return retorno;
}

const bool Valor::identico(const Valor& valor) const {
	if (this->indefinida() && valor.indefinida()) {
		return true;
	} else if (this->indefinida() || valor.indefinida()) {
		return false;
	} else {
		return this->pOriginal.compare(valor.pOriginal) == 0;
	}
}

Objeto* Valor::geraCopia() const {
	return new Valor(*this);
}

Copiavel& Valor::copiaEmSi(const Copiavel& alheio) {
//	Debug::msg(INFO, "--- vai copiar");
	const Valor& valor = dynamic_cast<const Valor&>(alheio);
	this->pOriginal = valor.pOriginal;
	this->pModificado = valor.pModificado;
	this->pApelidos = valor.pApelidos;
	this->pTipoParaComparacao = valor.pTipoParaComparacao;
	this->pListaDeApelidos = valor.pListaDeApelidos;

	if (valor.indefinida()) {
		this->indefine();
	} else {
		this->definiu();
	}

//	Debug::msg(INFO, "--- copiou");
	return *this;
}
