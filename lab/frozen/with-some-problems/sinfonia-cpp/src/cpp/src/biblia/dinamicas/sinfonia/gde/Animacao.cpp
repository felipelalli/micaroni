/**
 * $RCSfile: Animacao.cpp,v $
 * $Date: 2005/03/31 23:45:28 $
 * $Revision: 1.13 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/gde/Animacao.h"
using namespace biblia::dinamicas::sinfonia::gde;

AnimacaoBiblia::AnimacaoBiblia(const MediadorDeEstados& mde,
		 BasicoVisual& bva,
		 Estado* e)
	:GeradorDeEventosEspecial(mde), pVisual(bva),
	 pEstado(e), pAnimacaoRelacionada("???"),
	 pGeradorDeEventosParaAnimacaoEmThread(NULL)
{
	this->pGeradorDeEventosParaAnimacao.defineThis(this);

	bool impossivelCriar = false;
	ImpossivelCriarAnimacaoBibliaExcecao icabe;

	try {
		if (e->valor().indefinida()) {
			impossivelCriar = true;
			icabe << "Valor Indefinido! ";
		} else {
			this->pAnimacaoRelacionada = e->valor().emString();

			if (!this->pVisual.carregador()
				.animacaoJaCarregada(this->pAnimacaoRelacionada))
			{
				impossivelCriar = true;
				icabe << "Animação não definida no arquivo de Camadas! ";
			}
		}
	} catch (const Excecao& ee) {
		impossivelCriar = true;
		icabe << ee + " - ";
	}

	if (impossivelCriar) {
		icabe << "Erro na criação da AnimacaoBiblia relativa ao Estado '"
				+ *e
				+ "'. Campo PRINCIPAL obrigatório / a animação "
				+ "'" + this->pAnimacaoRelacionada + "' deve estar"
				+ " previamente criada.";

		throw icabe;
	} else {
		{
			int largura = this->animacaoRelacionada().componente()
					.animacao().areaQueOcupa().largura();

			int altura = this->animacaoRelacionada().componente()
					.animacao().areaQueOcupa().altura();

			this->pEstado->atribui(largura, this->pVisual.tempo(), "largura");
			this->pEstado->atribui(altura, this->pVisual.tempo(), "altura");
		}

		{
			int x = this->animacaoRelacionada().componente()
					.animacao().posicao().x();

			int y = this->animacaoRelacionada().componente()
					.animacao().posicao().y();

			try {
				x = e->valor("x").emInt();
			} catch (const Excecao&) {
				this->pEstado->atribui(x, this->pVisual.tempo(), "x");
			}

			try {
				y = e->valor("y").emInt();
			} catch (const Excecao&) {
				this->pEstado->atribui(y, this->pVisual.tempo(), "y");
			}

			this->animacaoRelacionada().componente()
					.animacao().reposiciona(Ponto(x, y));
		}

		{
			bool visivel = true;
			try {
				visivel = e->valor("visível").emBool();
			} catch (const Excecao&) {
				this->pEstado->atribui(visivel,
						this->pVisual.tempo(), "visível");
			}

			this->animacaoRelacionada().visivel(visivel);
		}

		{
			bool sentidoInverso = false;
			try {
				sentidoInverso = e->valor("sentido inverso").emBool();
			} catch (const Excecao&) {
				this->pEstado->atribui(sentidoInverso,
						this->pVisual.tempo(), "sentido inverso");
			}

			this->animacaoRelacionada().componente()
					.animacao().sentidoInverso(sentidoInverso);
		}

		{
			double fps = 10;

			try {
				fps = e->valor("quadros por segundo").emDouble();
			} catch (const Excecao&) {
				// Colocando 10 fixo porque é o padrão
				// FIXME: substituir isso por uma variável
				// que calcula o fps
				this->pEstado->atribui(10,
						this->pVisual.tempo(), "quadros por segundo");
			}

			if (fps <= 0) {
				ImpossivelCriarAnimacaoBibliaExcecao icabe;
				icabe << "Erro na criação da AnimacaoBiblia"
						" relativa ao Estado '" + *e
						+ "'. Não é possível que a animação tenha"
						" 0 ou menos quadros por segundo.";

				throw icabe;
			}

			this->animacaoRelacionada().componente()
					.mudaIntervalo(Intervalo(
						1.0 / fps * 1000.0, Milissegundo()));
		}

		{
			double transparencia = 0;

			try {
				transparencia = e->valor("transparência").emDouble();
			} catch (const Excecao&) {
				this->pEstado->atribui(transparencia,
						this->pVisual.tempo(), "transparencia");
			}

			this->animacaoRelacionada().componente()
					.animacao().pinta(Transparente(transparencia));
		}

		{
			bool emLoop = false;

			try {
				emLoop = e->valor("loop").emBool();
			} catch (const Excecao&) {
				this->pEstado->atribui(emLoop,
						this->pVisual.tempo(), "loop");
			}

			this->animacaoRelacionada().componente()
					.animacao().emLoop(emLoop);
		}

		{
			bool iniciado = false;

			try {
				iniciado = e->valor("iniciado").emBool();
			} catch (const Excecao&) {
				this->pEstado->atribui(iniciado,
						this->pVisual.tempo(), "iniciado");
			}

			if (iniciado) {
				this->animacaoRelacionada().componente()
						.play();

				if (this->animacaoRelacionada().componente()
					.animacao().sentidoInverso())
				{
					this->animacaoRelacionada().componente().animacao().vaiParaOFim();
				} else {
					this->animacaoRelacionada().componente().animacao().reinicia();
				}
			} else {
				this->animacaoRelacionada().componente()
						.stop();
			}
		}
	}

	this->pGeradorDeEventosParaAnimacaoEmThread
			= new Thread(pGeradorDeEventosParaAnimacao,
			"gerador de eventos para animacao em thread: " + *this);

	this->pGeradorDeEventosParaAnimacaoEmThread->start();

	this->modificaEventosQueTrata().adiciona(
			this->pEstado->nomeCompleto().valor());
}

AnimacaoBiblia::~AnimacaoBiblia() {
	this->pGeradorDeEventosParaAnimacao.termina();

	while (!this->pGeradorDeEventosParaAnimacao.terminou()) {
		Thread::sleep(Intervalo(10, Milissegundo()));
	}

	if (this->pGeradorDeEventosParaAnimacaoEmThread) {
		delete this->pGeradorDeEventosParaAnimacaoEmThread;
	}
}

ComponenteGrafico<Video>& AnimacaoBiblia::animacaoRelacionada() const {
	return this->pVisual.carregador().animacao(this->pAnimacaoRelacionada);
}

const string& AnimacaoBiblia::nomeDaAnimacaoRelacionada() const {
	return this->pAnimacaoRelacionada;
}

string AnimacaoBiblia::emString() const {
	return "Animacao(" + this->nomeDaAnimacaoRelacionada() + ")("
			+ this->animacaoRelacionada() + ")";
}

GeradorDeEventos& AnimacaoBiblia::captaEGeraEmLoop() {
	while (!this->encerrou()) {
		const Evento* e = this->esperaAteQueVenhaEvento();

		if (e != NULL) {
			if (e->modificaEstadoDiretamente()
				&& (e->nomeCompleto() == this->pEstado->nomeCompleto()))
			{
				Valor campo = e->modificador().campo();

				if (campo == Multifuncional::CAMPO_PRINCIPAL) {
					Debug::msg(WARN, "AnimacaoBiblia::executa::"
							" Erro ao tentar mudar de '"
							+ this->nomeDaAnimacaoRelacionada()
							+ "' para '"
							+ this->pEstado->valor()
							+ "'. Não é possível mudar o nome da"
							" animação relacionada! Corrija isto"
							" o mais rápido possível porque"
							" o Estado ficou desatualizado!");
				} else if (campo == Valor("largura") || campo == Valor("altura")) {
					Debug::msg(WARN, "AnimacaoBiblia::executa::"
							" Não é possível mudar o tamanho da"
							" animação relacionada! Corrija isto"
							" o mais rápido possível porque"
							" o Estado ficou desatualizado!");		
				} else if (campo == Valor("x") || campo == Valor("y")) {
					int x = this->animacaoRelacionada().componente()
							.animacao().posicao().x();

					int y = this->animacaoRelacionada().componente()
							.animacao().posicao().y();

					try {
						x = this->pEstado->valor("x").emInt();
					} catch (const CampoInexistenteExcecao&) {}

					try {
						y = this->pEstado->valor("y").emInt();
					} catch (const CampoInexistenteExcecao&) {}

					Ponto ponto(x, y);
					this->animacaoRelacionada().componente()
							.animacao().reposiciona(ponto);
				} else if (campo == Valor("visível")) {
					this->animacaoRelacionada().visivel(
							this->pEstado->valor("visível").emBool());
				} else if (campo == Valor("sentido inverso")) {
					this->animacaoRelacionada().componente()
							.animacao().sentidoInverso(
								this->pEstado->valor(
									"sentido inverso").emBool());
				} else if (campo == Valor("quadros por segundo")) {
					double fps = this->pEstado->valor(
							"quadros por segundo").emDouble();

					if (fps > 0) {
						this->animacaoRelacionada().componente()
								.mudaIntervalo(Intervalo(
									1.0 / fps * 1000.0, Milissegundo()));
					} else {
						Debug::msg(WARN, "AnimacaoBiblia::executa"
								" não é possível mudar 'quadros por segundo'"
								" para um valor igual ou menor que zero."
								" Mantendo o valor anterior.");
					}
				} else if (campo == Valor("transparência")) {
					double valor = this->pEstado->valor(
							"transparência").emDouble();

					if (valor < 0) {
						Debug::msg(WARN, "AnimacaoBiblia::executa"
								" não é possível mudar 'transparência'"
								" para um valor menor que zero. Definindo"
								" para zero.");

						valor = 0;
					} else if (valor > 100) {
						Debug::msg(WARN, "AnimacaoBiblia::executa"
								" não é possível mudar 'transparência'"
								" para um valor maior que 100. Definindo"
								" para 100.");

						valor = 100;
					}

					this->animacaoRelacionada().componente()
							.animacao().pinta(Transparente(valor));
				} else if (campo == Valor("loop")) {
					this->animacaoRelacionada().componente()
							.animacao().emLoop(
								this->pEstado->valor(
									"loop").emBool());
				} else if (campo == Valor("iniciado")) {
					bool iniciado = this->pEstado->valor("iniciado").emBool();

					if (!iniciado) {
						if (this->animacaoRelacionada().componente().animacao().fim()) {
							this->animacaoRelacionada().componente().stop();
						} else {
							this->animacaoRelacionada().componente().pause();
						}
					} else {
						if (this->animacaoRelacionada().componente().pausado()) {
							this->animacaoRelacionada().componente().play();
						} else {
							this->animacaoRelacionada().componente().play();

							if (this->animacaoRelacionada().componente()
								.animacao().sentidoInverso())
							{
								this->animacaoRelacionada().componente()
										.animacao().vaiParaOFim();
							} else {
								this->animacaoRelacionada().componente()
										.animacao().reinicia();
							}
						}
					}
				}
			}

			delete e;
		}
	}

	return *this;
}

AnimacaoBiblia::GeraEventosParaAnimacao
		::GeraEventosParaAnimacao()
	:pAnimacaoBiblia(NULL), pTerminou(false),
	 pTermina(false), pFimAnterior(false)
{}

const bool AnimacaoBiblia::GeraEventosParaAnimacao::fim() const {
	if (this->pAnimacaoBiblia->animacaoRelacionada()
				.componente().animacao().sentidoInverso())
	{
		return this->pAnimacaoBiblia->animacaoRelacionada()
					.componente().animacao().inicio();
	} else {
		return this->pAnimacaoBiblia->animacaoRelacionada()
					.componente().animacao().fim();
	}
}

Executavel& AnimacaoBiblia::GeraEventosParaAnimacao::executa() {
	try {
		this->pFimAnterior = this->fim();

		while (!this->pTermina) {
			bool fimAtual = this->fim();

			if (!this->pAnimacaoBiblia->animacaoRelacionada()
				.componente().animacao().emLoop())
			{
				if (fimAtual && !this->pFimAnterior) {
					// Lança evento que terminou
					AnimacaoBiblia& a = *(this->pAnimacaoBiblia);

					ModificadorDeEstado mde(a.pEstado->nomeCompleto());
					mde.adicionaParametro(Valor(false));

					mde.defineCampo("iniciado");
					Evento deixaDeEstarIniciado(a.pEstado->nome(), mde);
					deixaDeEstarIniciado.grupo(a.pEstado->grupo());
					Evento* disparado = deixaDeEstarIniciado.dispara(a.pVisual.tempo());
					disparado->especial(true);
					a.gera(disparado);
				}
			}

			Thread::sleep(Intervalo(10, Milissegundo()));

			this->pFimAnterior = fimAtual;
		}
	} catch(exception& e) {
		throw e;
	} catch(...) {
		Debug::msg(ERRO, string()
				+ "AnimacaoBiblia::GeraEventosParaAnimacao::executa::"
				" Ocorreu um erro desconhecido na animação."
				" Provavelmente ocorreu porque a função não terminou"
				" enquanto a Animacao era deletada. This: "
				+ *(this->pAnimacaoBiblia));
	}

	this->pTerminou = true;
	return *this;
}

AnimacaoBiblia::GeraEventosParaAnimacao& AnimacaoBiblia
		::GeraEventosParaAnimacao::termina()
{
	this->pTermina = true;
	return *this;
}

const bool& AnimacaoBiblia::GeraEventosParaAnimacao::terminou() {
	return this->pTerminou;
}

void AnimacaoBiblia::GeraEventosParaAnimacao::defineThis(AnimacaoBiblia* ab) {
	this->pAnimacaoBiblia = ab;
}
