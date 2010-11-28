/**
 * $RCSfile: MiniAplicacao.cpp,v $
 * $Date: 2005/03/11 22:03:32 $
 * $Revision: 1.22 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/miniaplicacao/MiniAplicacao.h"
using namespace biblia::dinamicas::sinfonia::miniaplicacao;

MiniAplicacao::MiniAplicacao() {}
MiniAplicacao::~MiniAplicacao() {}

Executavel& MiniAplicacao::executa() {
	// Sons:

	Vitrola vitrola;
	FabricaDeSonsFMod fabricaDeSons;
	CarregadorDeSom carregadorDeSom(fabricaDeSons);
	ResultadoSonoro resultadoSonoro;

	vitrola.outroResultado((ResultadoSonoro*) &resultadoSonoro);

	// Carregando tela:

	BasicoVisualAllegro visual;

	CarregadorWizard carregadorWizard
			= CarregadorWizard(visual.carregador(),
					visual.resultadoGrafico(),
					visual.animacoes(),
					//"dat/camadas.txt");
					"dat/camadasDemonstracao.txt");

	carregadorWizard.executa();

	DesenhistaDeResultadoGraficoNaTela desenhista;
	desenhista.outraTela((TelaComFundo*) &visual.tela())
			.outraFabrica((FabricaDeImagens*) &visual.fabrica())
			.outroResultado((ResultadoGrafico*) &visual.resultadoGrafico());

	// Gerando o básico da Sinfonia:

	ScriptDinamica genesis("../../com.ages.jogos.space-dev/deploy/dat/space.xml",
			visual, resultadoSonoro, carregadorDeSom);

	Sinfonia* sinfonia = genesis.geraSinfonia();

#ifdef _DEBUG
	Debug::msg(INFO, "--- Sinfonia gerada: " + *sinfonia);
#endif

	// Teclado:

	TecladoAllegro* tecladoAllegro = TecladoAllegro
			::criaTecladoAllegro(sinfonia->estados(), visual.tempo());

	sinfonia->adicionaGeradorDeEventosEspecial(tecladoAllegro, true);

	// Sinfonia:

	Thread sinfoniaEmThread(*sinfonia, "Sinfonia em thread");
	sinfoniaEmThread.start();

	while (!sinfonia->estados().estado(Sinfonia::LIGADA).valor().emBool());

	while (sinfonia->estados().estado(Sinfonia::LIGADA).valor().emBool()) {
		Thread::sleep(Intervalo(10, Milissegundo()));
		visual.animacoes().executa();
		desenhista.executa();
	}

	delete sinfonia;

	return *this;
}

