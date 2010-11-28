/**
 * $RCSfile: GenesisTeste.cpp,v $
 * $Date: 2005/03/04 00:32:20 $
 * $Revision: 1.8 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/miniaplicacao/GenesisTeste.h"
using namespace biblia::dinamicas::sinfonia::miniaplicacao;

GenesisTeste::GenesisTeste(const BasicoVisual& bv):pVisual(bv) {}
GenesisTeste::~GenesisTeste() {}

Sinfonia* GenesisTeste::geraSinfonia() {
	this->inicia();
	Sinfonia* s = new Sinfonia(this->pVisual.tempo());
	const MediadorDeEstados& mediadorDeEstados = s->estados();

	// Criando situa��o que se apertar CTRL+ALT+DEL sai da Sinfonia
	{
		// Criando os Estados
		Estado* tecla51 = new Estado("Sinfonia.Reservados.Teclas.tecla51");
		Estado* tecla107 = new Estado("Sinfonia.Reservados.Teclas.tecla107");
		Estado* tecla105 = new Estado("Sinfonia.Reservados.Teclas.tecla105");

		// Inicializando
		tecla51->atribui(false, this->pVisual.tempo());
		tecla107->atribui(false, this->pVisual.tempo());
		tecla105->atribui(false, this->pVisual.tempo());

		// Adicionando-os na Sinfonia
		s->adicionaEstado(tecla51);
		s->adicionaEstado(tecla107);
		s->adicionaEstado(tecla105);

		// Criando Situa��o
		Situacao* controlAltDel = new Situacao();

		// Eventos que a validam
		Evento control("Sinfonia.Reservados.Teclas.tecla51", ModificadorDeEstado(
				"Sinfonia.Reservados.Teclas.tecla51").adicionaParametro(
						Valor("V")));

		controlAltDel->adicionaEvento(control);
		Evento alt("Sinfonia.Reservados.Teclas.tecla107", ModificadorDeEstado(
				"Sinfonia.Reservados.Teclas.tecla107").adicionaParametro(
						Valor("V")));

		controlAltDel->adicionaEvento(alt);
		Evento del("Sinfonia.Reservados.Teclas.tecla105", ModificadorDeEstado(
				"Sinfonia.Reservados.Teclas.tecla105").adicionaParametro(
						Valor("V")));

		controlAltDel->adicionaEvento(del);

		// Criando Condi��o da Situa��o
		CondicaoDeComparacao controlPressionado(
				EstadoAlvo((const Estado*) & s->estados()
				.estadoDoEventoAtual("Sinfonia.Reservados.Teclas.tecla51")),
				"=", Valor("V"));

		CondicaoDeComparacao altPressionado(
				EstadoAlvo((const Estado*) & s->estados()
				.estadoDoEventoAtual("Sinfonia.Reservados.Teclas.tecla107")),
				"=", Valor("V"));

		CondicaoDeComparacao delPressionado(
				EstadoAlvo((const Estado*) & s->estados()
				.estadoDoEventoAtual("Sinfonia.Reservados.Teclas.tecla105")),
				"=", Valor("V"));

		CondicaoComposta cc(controlPressionado);
		cc.adiciona(AND, altPressionado);
		cc.adiciona(AND, delPressionado);

		controlAltDel->defineCondicao(cc);

		// Evento que gerar�
		Valor nome(Sinfonia::LIGADA);
		nome.adicionaApelido("ctrl+alt+F5, deixa de estar");
		ModificadorDeEstado mde(nome);
		mde.adicionaParametro(Valor(false));
		Evento e(nome, mde);

		controlAltDel->adicionaEventoQueGera(e);

		// Adicionando Situa��o � Sinfonia
		s->adicionaSituacao(controlAltDel);
	}
	
//	Debug::msg(INFO, "--- saiu geraSinfonia");

	this->conclui();
	return s;
}
