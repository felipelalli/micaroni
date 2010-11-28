/**
 * $RCSfile: Sinfonia.cpp,v $
 * $Date: 2005/04/01 00:24:40 $
 * $Revision: 1.36 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/Sinfonia.h"
using namespace biblia::dinamicas::sinfonia; 

const Valor Sinfonia::LIGADA = "Sinfonia.Reservados.ligada";
const Valor Sinfonia::RECARREGANDO = "Sinfonia.Reservados.recarregando";

const GeradorDeEventosDependente& Sinfonia::dinamica() const {
	return this->pDependentes;
}

GeradorDeEventosDependente& Sinfonia::dinamicaParaModificar() {
	return this->pDependentes;
}

Concretizador& Sinfonia::concretizador() {
	return *(this->pConcretizador);
}

MediadorDeEstados& Sinfonia::estadosParaModificar() {
	return this->pEstados;
}

const MediadorDeEstados& Sinfonia::estados() const {
	return this->pEstados;
}

Sinfonia::Sinfonia(const UniversoDeTempo& u, Genesis* genesis)
	:GeradorDeEventos(pEstados, true), pLixoThreads(),
	 pLixo(), pLixoOuvidores(), pLixoSituacoes(),
	 pEstados(u), pDependentes(pEstados),
	 pConcretizador(NULL),
	 pQuantoTempoExecutando(u, false),
	 pThreads(), pEsperarAcabar(1),
	 pEsperarExecutar(0), pTempo(u), pExecutou(false),
	 pGeradores(), pGeradoresPontuais(),
	 pGenesis(genesis)
{
	// Cria o Concretizador desta Sinfonia
	{
		this->pConcretizador = new Concretizador(this->pEstados);

		// Empilha o Concretizador pra ser disparado depois
		this->fazRodarUmaVezEmThread(*(this->pConcretizador), "concretizador");

		// Trata o Concretizador como um GeradorDeEventos
		this->adicionaGeradorDeEventos(this->pConcretizador);
	}

	// Cria um estado especial que diz se a Sinfonia está ligada ou não
	{
		Estado* sinfoniaLigada = new Estado(Sinfonia::LIGADA);
		sinfoniaLigada->externo(true);
		sinfoniaLigada->atribui(false, u); // começa desligada
		this->adicionaEstado(sinfoniaLigada);
	}

//	Debug::msg(INFO, "--- CRIOU SINFONIA!");
}

Sinfonia::~Sinfonia() {

	// lança evento que pára a Sinfonia
	{
		Valor nome(Sinfonia::LIGADA);
		nome.adicionaApelido("deixa de estar");
		this->lanca(false, nome);
	}

	if (!this->pExecutou) {
#ifdef _DEBUG
		Debug::msg(INFO, "Esperando Sinfonia executar...");
#endif
		this->pEsperarExecutar.esperar();
	}

	bool avisar = false;
	if (this->pExecutou) {
#ifdef _DEBUG
		Debug::msg(INFO, "Esperando Sinfonia acabar...");
		avisar = true;
#endif
		this->pEsperarAcabar.esperar();
	}

	try {
	//	Debug::msg(INFO, "--- vai limpar ouvidores!");
		this->pLixoOuvidores.limpa();
	} catch (const Excecao& e) {
		Debug::msg(WARN, "A exceção '" + e + "' ocorreu ao apagar ouvidores da Sinfonia.");
	} catch (const exception& e) {
		Debug::msg(WARN, "A exceção '" + string(e.what()) + "' ocorreu ao apagar ouvidores da Sinfonia.");
	} catch (...) {
		Debug::msg(WARN, "Ocorreu um erro desconhecido ao apagar ouvidores da Sinfonia.");
	}

	try {
	//	Debug::msg(INFO, "--- vai limpar lixo!");
		this->pLixoSituacoes.limpa();
		this->pLixo.limpa();
	} catch (const Excecao& e) {
		Debug::msg(WARN, "A exceção '" + e + "' ocorreu ao apagar o lixo da Sinfonia.");
	} catch (const exception& e) {
		Debug::msg(WARN, "A exceção '" + string(e.what()) + "' ocorreu ao apagar o lixo da Sinfonia.");
	} catch (...) {
		Debug::msg(WARN, "Ocorreu um erro desconhecido ao apagar o lixo da Sinfonia.");
	}

	try {
	//	Debug::msg(INFO, "--- vai limpar as threads!");
		this->pLixoThreads.limpa();
	} catch (const Excecao& e) {
		Debug::msg(WARN, "A exceção '" + e + "' ocorreu ao apagar as threads da Sinfonia.");
	} catch (const exception& e) {
		Debug::msg(WARN, "A exceção '" + string(e.what()) + "' ocorreu ao apagar as threads da Sinfonia.");
	} catch (...) {
		Debug::msg(WARN, "Ocorreu um erro desconhecido ao apagar as threads da Sinfonia.");
	}

	if (avisar) {
		Debug::msg(INFO, "Finalizou Sinfonia.");
	}

//	Debug::msg(INFO, "--- VAI DESTRUIR SINFONIA!");
}

Sinfonia& Sinfonia::adicionaGeradorDeEventos(GeradorDeEventos* ge) {
	this->pLixo.adiciona(ge);

	OuvidorDosGeradoresDeEventos* novoOuvidor
			= new OuvidorDosGeradoresDeEventos(this, ge);

	this->pLixoOuvidores.adiciona(novoOuvidor);
	this->fazRodarUmaVezEmThread(*novoOuvidor, "ouvidor de '" + *ge + "'");

	return *this;
}

Sinfonia& Sinfonia::fazRodarUmaVezEmThread(Executavel& e, const string& nome) {
	Thread* thread;
	
	if (!this->pExecutou) {
		thread = new Thread(e, nome);
	} else {
		thread = new Thread(e, "Thread executada instantaneamente"
				" (depois da Sinfonia estar executando)"
				", nome: " + nome);
	}

	this->pLixoThreads.adiciona(thread);

	if (!this->pExecutou) {
		this->pThreads.adiciona(thread);
	} else {
		thread->start();
	}

	Debug::msg(INFO, "Sinfonia: vai rodar '" + nome + "' em Thread...");

	return *this;
}

Sinfonia& Sinfonia::adicionaGeradorDeEventosEspecial(
		GeradorDeEventosEspecial* gee, const bool& executarUmaVezEmThread)
{
//	Debug::msg(ERRO, ">>> gee a ser adicionado: " + *gee);

	if (gee->naoRecebeNenhumEvento()) {
//		Debug::msg(ERRO, ">>> O gee não recebe nenhum evento :/");
	} else {
		if (gee->eventosQueTrata().tamanho() == 0) {
			Debug::msg(WARN, "Sinfonia::adicionaGeradorDeEventosEspecial::"
					" foi adicionado um GeradorDeEventosEspecial que não possui"
					" informações de quais eventos ele trata. Talvez você"
					" tenha esquecido de adicioná-los. Faça isso antes"
					" de chamar esta função. cee: " + *gee);

			this->pGeradores.adiciona(gee);
		} else {
			for (int i = 0; i < gee->eventosQueTrata().tamanho(); i++) {
				Valor id(gee->eventosQueTrata()[i].emString());

				if (!this->pGeradoresPontuais.existe(id.valor())) {
					this->pGeradoresPontuais.insere(id.valor(),
							Lista<GeradorDeEventosEspecial*>());
				}

				this->pGeradoresPontuais[id.valor()].adiciona(gee);
//				Debug::msg(ERRO, ">>> capt. de ev. espec. id='"
//						+ id + "' gee: " + *gee);
			}
		}
	}

	if (executarUmaVezEmThread) {
		this->fazRodarUmaVezEmThread(*gee,
				"gerador de eventos especial: " + *gee);
	}

	this->adicionaGeradorDeEventos(gee);

	return *this;
}

Sinfonia& Sinfonia::zeraDinamica() {
	this->dinamicaParaModificar().apagaTudo();
	this->pLixoSituacoes.limpa();
	return *this;
}

Sinfonia& Sinfonia::adicionaSituacao(const Situacao* s) {
	this->pLixoSituacoes.adiciona((Situacao*) s);
	this->dinamicaParaModificar().adicionaSituacao(s);
	return *this;
}

Sinfonia& Sinfonia::adicionaResultado(Resultado* r) {
	this->pLixo.adiciona((Resultado*) r);
	this->concretizador().adiciona(r);
	return *this;
}

Sinfonia& Sinfonia::adicionaEstado(Estado* e) {
	this->estadosParaModificar().adicionaEstado(e);
	return *this;
}

Sinfonia& Sinfonia::defineGenesisParaRecarregamento(Genesis* genesis) {
	this->pGenesis = genesis;
	return *this;
}

string Sinfonia::emString() const {
	string retorno = Objeto::emString() + " executando há "
				+ this->pQuantoTempoExecutando.intervalo().emString()
				+ ". Estados: {";

	int i, tamanho = this->estados().nomeDeTodosEstados().tamanho();
	for (i = 0; i < tamanho; i++) {
		retorno += "" + this->estados().estado(
				this->estados().nomeDeTodosEstados()[i].emString());

		if (i < tamanho - 1) {
			retorno += ", ";
		}
	}

	retorno += "}. Dinamica (Situacoes): {";
	tamanho = this->dinamica().nomeDeTodasSituacoes().tamanho();
	for (i = 0; i < tamanho; i++) {
//		Debug::msg(INFO, "--- situacao atual: " + this->dinamica().nomeDeTodasSituacoes()[i]);

		retorno += "{" + this->dinamica().situacao(
				this->dinamica().nomeDeTodasSituacoes()[i]);

		if (i < tamanho - 1) {
			retorno += "}, ";
		}
	}

	return retorno + "}.";
}

Sinfonia& Sinfonia::recarrega() {
	this->pGenesis->recarrega(this);
	this->lanca(Sinfonia::RECARREGANDO, false);
	return *this;
}

Sinfonia& Sinfonia::lancaEventoParaRecarregar() {
	this->lanca(Sinfonia::RECARREGANDO, true);
	return *this;
}

Sinfonia& Sinfonia::inicializa() {
	// Disparando todas as threads pendentes
	for (int i = 0; i < this->pThreads.tamanho(); i++) {
		this->pThreads[i]->start();
	}

	this->pThreads.limpa(); // mas elas continuam na lixeira

	// Gera o evento que liga a Sinfonia
	{
		Valor nome(Sinfonia::LIGADA);
		nome.adicionaApelido("torna");
		this->lanca(true, nome);
	}

	return *this;
}

GeradorDeEventos& Sinfonia::captaEGeraEmLoop() {
	if (this->pExecutou) {
		Debug::sair("Concretizador::executa:: só pode ser executado uma vez! "
				+ *this);
	} else {
		this->pEsperarAcabar.esperar();
		this->pExecutou = true;

//		Debug::msg(INFO, "--- Iniciou Sinfonia: " + *this);

		this->inicializa();

		do {
//			Debug::msg(ERRO, ">>> A Sinfonia está rodando! Aguardando algum evento! :)");

			const Evento* novoEvento = this->esperaAteQueHajaEvento();

			static bool jaAvisou = false;

			if (jaAvisou && this->quantosEventosEmEspera() == 0) {
				jaAvisou = false;
				Debug::msg(WARN, "Sinfonia::executa:: SOBRECARREGAMENTO:"
						" parece que a sinfonia se normalizou a tempo.");
			} else if (!jaAvisou && this->quantosEventosEmEspera() > 1000) {
				jaAvisou = true;

				Debug::msg(WARN, "Sinfonia::executa:: SOBRECARREGAMENTO:"
						" há mais de 1000"
						" eventos que não foram processados! A Sinfonia"
						" pode estar sendo sobrecarregada. Verifique isto. "
						" Pode ser que o número de eventos gerados não estão"
						" conseguindo ser processados no tempo de ciclo total"
						" da Sinfonia. Tente otimizar algum gerador de eventos"
						" especial e transformá-lo em algum \"Estado externo\"."
						" Caso a Sinfonia se normalize a tempo, outro aviso"
						" será lançado.");
			}

			// Tem que distribuir o evento para todo mundo.

			if (novoEvento != NULL) {
				bool valido = true;

				try {
					if (novoEvento->especial()) {}
				} catch(...) {
					Debug::msg(ERRO, "*** ERRO FATAL DENTRO DA SINFONIA! Chegou um"
						" evento na Sinfonia que não é válido! Tentando ignorar...");

					valido = false;
				}

				if (valido) {
#ifdef _DEBUG
					//if (!novoEvento->especial()) {
						Debug::msg(ERRO, ">>> A Sinfonia recebeu o Evento '"
								+ *novoEvento + "'");
					//}
#endif

					// verifica se tem que recarregar as dinâmicas
					if (novoEvento->igual(Evento(Sinfonia::RECARREGANDO))) {
						if (novoEvento->parametro() == Valor(true)) {
							Debug::msg(ERRO, ">>> OPS! VAI RECARREGAR!");
							this->recarrega();
							Debug::msg(ERRO, ">>> OPS! RECARREGOOOOOL!");
						}
					}

					string nomeDoEvento = novoEvento->nomeCompleto().valor();

					// No MediadorDeEstado definindo Estado do Evento atual
//					Debug::msg(INFO, "--- 1. antes de mandar para a dinâmica - evento: " + *novoEvento);
					this->estadosParaModificar()
							.defineEstadoDoEventoAtual(*novoEvento);

//					Debug::msg(INFO, "--- 2. mandando o evento para a dinâmica");
					// No GeradorDeEventosDependente informando qual Evento ocorreu
					this->dinamicaParaModificar().aconteceu(*novoEvento);

					// Processa a dinâmica da Sinfonia
//					Debug::msg(INFO, "--- 2,5. processando a dinâmica");
					this->dinamicaParaModificar().executa();

					// Puxando os Eventos gerados pela dinâmica para a Sinfonia
					while (this->dinamica().quantosEventosEmEspera() > 0) {
						this->gera(this->dinamicaParaModificar()
								.esperaAteQueHajaEvento());
					}

//					Debug::msg(ERRO, ">>> 3. mediador de estado");
					// MediadorDeEstado, aplicando o Evento de fato
					this->estadosParaModificar().aplica(*novoEvento);

//					Debug::msg(ERRO, ">>> 4. manda para geradores de eventos especiais");
					// Mandando Evento para GeradorDeEventos Especiais
					for (int i = 0; i < this->pGeradores.tamanho(); i++) {
//						Debug::msg(ERRO, ">>> 4,5. antes de mandar para gerador "
//								+ Inteiro(i + 1) + ": "
//								+ *(this->pGeradores[i]));

						this->pGeradores[i]->aconteceu(
								(Evento*) novoEvento->geraCopia());
					}

					// Mandando Evento para GeradorDeEventos Especiais pontuais
//					Debug::msg(ERRO, ">>> 4,6. Mandando Evento para GeradorDeEventos Especiais pontuais");
					if (this->pGeradoresPontuais.existe(nomeDoEvento)) {
//						Debug::msg(INFO, ">>> 4,7. encontrou!! evento: " + nomeDoEvento);

						Lista<GeradorDeEventosEspecial*>& pontuais
								= this->pGeradoresPontuais[nomeDoEvento];

						for (int j = 0; j < pontuais.tamanho(); j++) {
//							Debug::msg(INFO, ">>> 4,8. mandando evento: " + nomeDoEvento
//									+ " para " + *(pontuais[j]));

							pontuais[j]->aconteceu((Evento*) novoEvento->geraCopia());
						}
					}

//					Debug::msg(INFO, "--- 5. mandando pro concretizador");
					this->pConcretizador->aconteceu(
							(Evento*) novoEvento->geraCopia());

					delete novoEvento;
				}
			}
		} while (this->estados().estado(Sinfonia::LIGADA).valor().emBool()
				|| this->quantosEventosEmEspera() > 0);

		for (int i = 0; i < this->pGeradores.tamanho(); i++) {
			this->pGeradores[i]->encerra();
		}

#ifdef _DEBUG
		Debug::msg(INFO, "Finalizou loop principal da Sinfonia."); /*+ *this
				+ "...");*/
#endif

		this->pEsperarAcabar.liberar();
		this->pEsperarExecutar.liberar();
	}

	return *this;
}
