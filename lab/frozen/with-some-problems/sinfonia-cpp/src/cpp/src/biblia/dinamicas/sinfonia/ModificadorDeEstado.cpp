/**
 * $RCSfile: ModificadorDeEstado.cpp,v $
 * $Date: 2005/03/04 06:34:50 $
 * $Revision: 1.11 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/ModificadorDeEstado.h"
using namespace biblia::dinamicas::sinfonia;

Identificacao ModificadorDeEstado::APENAS_ATRIBUI = "apenas atribui";

ModificadorDeEstado::ModificadorDeEstado(
		const Valor& nomeDoEstado, const Identificacao& acao)
	:pEstado(nomeDoEstado), pAcao(acao), pValores()
{
	this->defineCampo();
}

ModificadorDeEstado::~ModificadorDeEstado() {}

const Valor& ModificadorDeEstado::estado() const {
	return this->pEstado;
}

const Identificacao& ModificadorDeEstado::acao() const {
	return this->pAcao;
}

const Valor ModificadorDeEstado::campo() const {
	return Valor(this->pCampo.emString());
}

ModificadorDeEstado& ModificadorDeEstado::defineCampo(const Valor& campo) {
	this->pCampo = campo.valor();
	return *this;
}

const Lista<EstadoAlvo>& ModificadorDeEstado::parametros() const {
	return this->pValores;
}

ModificadorDeEstado& ModificadorDeEstado::adicionaParametro(const EstadoAlvo& ea) {
	this->pValores.adiciona(ea);
	return *this;
}

const bool ModificadorDeEstado::igual(const Igualavel& alheio) const {
	bool retorno = false;
	const ModificadorDeEstado& mde = dynamic_cast<const ModificadorDeEstado&>(alheio);

	if (mde.acao() == this->acao()
		&& mde.estado() == this->estado()
		&& mde.campo() == this->campo()
		&& mde.parametros().tamanho() == this->parametros().tamanho())
	{
		retorno = true;

		for (int i = 0; i < mde.parametros().tamanho() && retorno; i++) {
 			if (mde.parametros()[i].valorAlvo()
				!= this->parametros()[i].valorAlvo())
			{
				retorno = false;
			}
		}
	}

	return retorno;
}

Objeto* ModificadorDeEstado::geraCopia() const {
	ModificadorDeEstado* novo = new ModificadorDeEstado(this->pEstado, this->pAcao);
	novo->defineCampo(this->campo());
	for (int i = 0; i < this->parametros().tamanho(); i++) {
		novo->adicionaParametro(this->parametros()[i]);
		//Debug::msg(INFO, "--- ModificadorDeEstado::geraCopia:: adicionando: "
		//		+ this->parametros()[i]);
	}

	return novo;
}

Copiavel& ModificadorDeEstado::copiaEmSi(const Copiavel& alheio) {
	const ModificadorDeEstado& mde = dynamic_cast<const ModificadorDeEstado&>(alheio);
	this->pAcao = mde.pAcao;
	this->pCampo = mde.pCampo;
	this->pEstado = mde.pEstado;
	this->pValores.limpa();

	for (int i = 0; i < mde.parametros().tamanho(); i++) {
		this->adicionaParametro(mde.parametros()[i]);

		//Debug::msg(INFO, "--- ModificadorDeEstado::copiaEmSi:: adicionando: "
		//		+ mde.parametros()[i]);
	}

	return *this;
}

