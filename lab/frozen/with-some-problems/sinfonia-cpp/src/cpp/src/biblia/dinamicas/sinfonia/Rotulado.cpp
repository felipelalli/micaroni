/**
 * $RCSfile: Rotulado.cpp,v $
 * $Date: 2004/12/29 02:24:21 $
 * $Revision: 1.4 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/Rotulado.h"
using namespace biblia::dinamicas::sinfonia;

Rotulado::Rotulado(const Valor& nome):pNome(nome), pComentario("") {}
Rotulado::~Rotulado() {}

Rotulado& Rotulado::mudaNome(const Valor& nome) {
	this->pNome = nome;
	return *this;
}

const Valor& Rotulado::nome() const {
	return this->pNome;
}

const string& Rotulado::comentario() const {
	return this->pComentario;
}

Rotulado& Rotulado::defineComentario(const string& c) {
	this->pComentario = c;
	return *this;
}

string Rotulado::emString() const {
	return "nome: '" + this->nome() + "', comentário: '"
			+ this->comentario() + "'";
}
