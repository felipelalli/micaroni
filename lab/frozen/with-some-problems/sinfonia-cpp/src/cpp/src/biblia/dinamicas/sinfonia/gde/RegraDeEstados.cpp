/**
 * $RCSfile: RegraDeEstados.cpp,v $
 * $Date: 2005/03/30 01:23:46 $
 * $Revision: 1.8 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/gde/RegraDeEstados.h"
using namespace biblia::dinamicas::sinfonia::gde;

RegraDeEstados::RegraDeEstados(
		const MediadorDeEstados& mde,
		const UniversoDeTempo& u)
	:GeradorDeEventosEspecial(mde), pTempo(u)
{}

RegraDeEstados::~RegraDeEstados() {}

RegraDeEstados& RegraDeEstados::adicionaEstado(const Valor& nomeCompletoDoEstado) {
	this->modificaEventosQueTrata().adiciona(nomeCompletoDoEstado.valor());
	return *this;
}

GeradorDeEventos& RegraDeEstados::captaEGeraEmLoop() {
	while (!this->encerrou()) {
		const Evento* e = this->esperaAteQueVenhaEvento();
		if (e != NULL) {
			if (e->modificaEstadoDiretamente())	{
				const Valor& valor = this->mediadorDeEstados()
						.estado(e->nomeCompleto()).valor();

				if (!valor.pareceSerBoleano()) {
#ifdef _DEBUG
					Debug::msg(INFO, "RegraDeEstados::executa::"
							" o estado '" + e->nomeCompleto()
							+ "' parece não ser boleano, e esta classe"
							" só trabalha com valores boleanos. this: "
							+ *this);
#endif
				} else if (valor.emBool() == true) {
					for (int i = 0; i < this->eventosQueTrata().tamanho(); i++) {
						Identificacao id(this->eventosQueTrata()[i]);

						if (id != e->nomeCompleto().valor()) {
							const Estado& estadoAtual
									= this->mediadorDeEstados().estado(id.emString());

							if (!estadoAtual.valor().pareceSerBoleano()) {
#ifdef _DEBUG
								Debug::msg(INFO, "RegraDeEstados::executa::"
										" o estado '" + estadoAtual
										+ "' parece não ser boleano, e esta classe"
										" só trabalha com valores boleanos. this: "
										+ *this);
#endif
							} else if (estadoAtual.valor().emBool() == true) {
								// Lançar evento para o tornar falso.
								Valor nome(e->nomeCompleto());
								nome.adicionaApelido("desligou pela regra de estado associado");
								ModificadorDeEstado mde(nome);
								mde.adicionaParametro(Valor(false));

								Evento evento(e->nome(), mde);
								evento.grupo(e->grupo());
								Evento* tornaFalso = evento.dispara(this->pTempo);
								this->gera(tornaFalso);
							}
						}
					}
				}
			}
		}
	}

	return *this;
}
