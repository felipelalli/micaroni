/**
 * $RCSfile: Demonstracao.cpp,v $
 * $Date: 2005/03/08 16:57:48 $
 * $Revision: 1.2 $
 * $Author: cvsroot $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/demonstracao/Demonstracao.h"
using namespace biblia::dinamicas::sinfonia::demonstracao;

Demonstracao::Demonstracao() {}
Demonstracao::~Demonstracao() {}

Executavel& Demonstracao::executa() {

	

	Vitrola vitrola;
	FabricaDeSonsFMod fabricaDeSons;
	CarregadorDeSom carregadorDeSom (fabricaDeSons);
	ResultadoSonoro resultadoSonoro;

	vitrola.outroResultado ((ResultadoSonoro*)&resultadoSonoro);

	carregadorDeSom
		.carregaSom ("musica1"        ,"sons/musica1.mp3")
		.carregaSom ("musica2"        ,"sons/musica2.mp3")
		.carregaSom ("musica3"        ,"sons/musica3.mp3")
		.carregaSom ("portaAbre"      ,"sons/abrePorta.wav")
		.carregaSom ("portaFecha"     ,"sons/fechaPorta.wav")
		.carregaSom ("janelaAbreFecha","sons/janelaAbreFecha.wav")
		.carregaSom ("tictac"         ,"sons/tictac.wav")
		.carregaSom ("torradeira"     ,"sons/torradeira.wav")
		.carregaSom ("liquidificador" ,"sons/liquidificador.wav")
		.carregaSom ("cuco"           ,"sons/cuco.wav")
		.carregaSom ("latido"         ,"sons/cachorro.wav")		
		.executa();
	
	// Carregando tela:

	BasicoVisualAllegro visual;

	CarregadorWizard carregadorWizard
			= CarregadorWizard(visual.carregador(),
					visual.resultadoGrafico(),
					visual.animacoes(),
					"dat/camadasDemonstracao.txt");

	carregadorWizard.executa();

	DesenhistaDeResultadoGraficoNaTela desenhista;
	desenhista.outraTela((TelaComFundo*) &visual.tela())
			.outraFabrica((FabricaDeImagens*) &visual.fabrica())
			.outroResultado((ResultadoGrafico*) &visual.resultadoGrafico());

	// Gerando o básico da Sinfonia:

	ScriptDinamica genesis("./dat/demonstracao.xml", visual,resultadoSonoro,carregadorDeSom);
	Sinfonia* sinfonia = genesis.geraSinfonia();
	Debug::msg(INFO, "--- Sinfonia gerada: " + *sinfonia);

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
		vitrola.executa();
	}

	delete sinfonia;


	return *this;
}

