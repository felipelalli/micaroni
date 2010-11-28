/**
 * $RCSfile: MediadorDeEstados.cpp,v $
 * $Date: 2005/03/31 23:45:27 $
 * $Revision: 1.30 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/MediadorDeEstados.h"
using namespace biblia::dinamicas::sinfonia;

Valor MediadorDeEstados::ESTADO_DO_EVENTO_ATUAL
		= "Sinfonia.Reservados.estado do evento atual";

MediadorDeEstados::MediadorDeEstados(
		const UniversoDeTempo& u)
	:pUniverso(u), pEstados(), pNomeEstados(),
	 pLixo(), pConstantes()
{}

MediadorDeEstados::~MediadorDeEstados() {}

MediadorDeEstados& MediadorDeEstados::adicionaEstado(
		Estado* e, const bool& ficaResponsavelPelaDelecao)
{
	string nome = e->nomeCompleto().valor();

	if (this->pEstados.existe(nome)) {
		Debug::msg(WARN, "MediadorDeEstados::adicionaEstado::"
				" Um Estado já foi adicionado"
			    " anteriormente com o mesmo nome: '" + nome
				+ "' . Verifique"
				" se realmente são os mesmos, e evite a duplicidade. Este ("
				+ *e + ") será ignorado! O Estado que aqui está é: "
				+ *(this->pEstados[nome]) + ".");
	} else {
		this->pEstados.insere(nome, e);
		this->pNomeEstados.adiciona(nome);
	}

	if (ficaResponsavelPelaDelecao) {
		this->pLixo.adiciona(e);
	}

	return *this;
}

const bool MediadorDeEstados::existeEstado(const Valor& nomeCompleto) const {
	string id = nomeCompleto.valor();
	return this->pEstados.existe(id);
}

const Estado& MediadorDeEstados::estado(const Valor& nomeCompleto) const {
	string id = nomeCompleto.valor();

	if (!this->existeEstado(nomeCompleto)) {
		string erro("MediadorDeEstados::estado::"
				" O estado '" + nomeCompleto + "' não existe!");

		Debug::msg(ERRO, erro);

		EstadoInexistenteExcecao e;
		e << erro;
		throw e;
	}

	return *(this->pEstados[id]);
}

EstadoDependente* MediadorDeEstados::criaEstadoDependente(
		const Estado* baseadoEm, const Valor& campo) const
{
	EstadoDependente* novoEstadoDependente
			= new EstadoDependente(EstadoAlvo(baseadoEm, campo));

	this->pLixo.adiciona(novoEstadoDependente);
	return novoEstadoDependente;
}

const Estado& MediadorDeEstados::estadoConstante(
		const Valor& valorDoEstado) const
{
	string id = "Sinfonia.Reservados.constante:"
			+ valorDoEstado.geraStringUnicaECompleta();

	if (this->pConstantes.existe(id)) {
		return *(this->pConstantes[id]);
	} else {
		Estado* novoEstado = new Estado(Valor(id, true));
		novoEstado->defineComoConstante();
		novoEstado->atribui(valorDoEstado, this->universo());
		this->pConstantes.insere(id, novoEstado);
		this->pLixo.adiciona(novoEstado);
		return *(this->pConstantes[id]);
	}
}

const Estado& MediadorDeEstados::estadoDoEventoAtual(
		const Valor& nomeCompleto) const
{
	string id = MediadorDeEstados::ESTADO_DO_EVENTO_ATUAL
			+ "(" + nomeCompleto + ")"; // ver defineEstadoDoEventoAtual

	if (!this->pEstados.existe(id)) {
		Estado* novoEstado = new Estado(id);

		// colocando todos os campos
		for (int i = 0; i < this->estado(nomeCompleto).campos().tamanho(); i++) {
			novoEstado->atribui(this->estado(nomeCompleto)
					.valor(this->estado(nomeCompleto).campos()[i].emString()),
					this->universo(), this->estado(nomeCompleto).campos()[i].emString());
		}

		this->pEstados.insere(novoEstado->nomeCompleto().valor(), novoEstado);
		this->pLixo.adiciona(novoEstado);
	}

	return *(this->pEstados[id]);
}

MediadorDeEstados& MediadorDeEstados::defineEstadoDoEventoAtual(const Evento& e) {
	if (e.intermediario()) {
//		Debug::msg(INFO, "--- MediadorDeEstados::defineEstadoDoEventoAtual:: "
//				"O Evento " + e + " é intermediário.");
	} else {
		const ModificadorDeEstado& m = e.modificador();
		string idDoEstado = m.estado().valor();

		if (!this->pEstados.existe(idDoEstado)) {
#ifdef _DEBUG
			if (!this->pJaExibiuEsteErro2.existe(idDoEstado)) {
				if (!e.especial()) {
					Debug::msg(INFO, "MediadorDeEstados::defineEstadoDoEventoAtual::"
							" não foi possível definir o estado do evento atual para "
							" o estado: '" + idDoEstado
							+ "' porque ele não foi previamente definido.");
				}

				this->pJaExibiuEsteErro2.insere(idDoEstado, true);
			}
#endif
		} else {
			string id = MediadorDeEstados::ESTADO_DO_EVENTO_ATUAL
					+ "(" + idDoEstado + ")"; // ver estadoDoEventoAtual

			Valor* resultado;
			if (m.acao() == ModificadorDeEstado::APENAS_ATRIBUI) {
				if (m.parametros().tamanho() != 1) {
					Debug::sair("MediadorDeEstados::defineEstadoDoEventoAtual:: "
							"para atribuir tem que ter UM ÚNICO parâmetro! Está sendo"
							" passado " + Inteiro(m.parametros().tamanho())
							+ " parametro(s)");
				}

				resultado = new Valor(m.parametros()[0].valorAlvo());
				// só pode ter um único parâmetro
			} else {
				Lista<const Valor*> valores;

				int i;
				for (i = 0; i < m.parametros().tamanho(); i++) {
					valores.adiciona(new Valor(m.parametros()[i].valorAlvo()));
				}

				resultado = new Valor(this->pEstados[idDoEstado]
						->executa(m.acao(), valores));

				for (i = 0; i < m.parametros().tamanho(); i++) {
					delete valores[i];
				}
			}

			if (!this->pEstados.existe(id)) {
				Estado* novoEstado = new Estado(id);

				// colocando todos os campos
				for (int i = 0; i < this->estado(idDoEstado).campos().tamanho(); i++) {
					novoEstado->atribui(this->estado(idDoEstado)
							.valor(this->estado(idDoEstado).campos()[i].emString()),
							this->universo(), this->estado(idDoEstado)
							.campos()[i].emString());
				}

				this->pEstados.insere(novoEstado->nomeCompleto().valor(), novoEstado);

				// this->pNomeEstados.adiciona(novoEstado->nomeCompleto().valor());
				// ^-- não é necessário porque se trata do atual
				this->pLixo.adiciona(novoEstado);
			}

			this->pEstados[id]->atribui(*resultado, this->universo(),
					e.modificador().campo());

			delete resultado;
		}
	}

	return *this;
}

MediadorDeEstados& MediadorDeEstados::aplica(const Evento& e) {
	if (e.modificaEstadoDiretamente()) {
		if (!e.disparado()) {
			EventoNaoDisparadoExcecao e;
			e << string() + "MediadorDeEstados::aplica()::"
					+ " só é possível aplicar Eventos que estão disparados. Evento: "
					+ e;

			throw e;
		} else {
			const ModificadorDeEstado& m = e.modificador();
			const string id = m.estado().valor();

			if (!this->pEstados.existe(id)) {
				if (!this->pJaExibiuEsteErro.existe(id)) {
					if (!e.especial()) {
						Debug::msg(WARN, "MediadorDeEstados::aplica::"
							" Evento " + e + " não tem estado correspondente"
							" definido!");
					}

					this->pJaExibiuEsteErro.insere(id, true);
				}
			} else {
				Valor* resultado;
				if (m.acao() == ModificadorDeEstado::APENAS_ATRIBUI) {
					if (m.parametros().tamanho() != 1) {
					Debug::sair("MediadorDeEstados::aplica:: "
							"para atribuir tem que ter UM ÚNICO parâmetro! Está sendo"
							" passado " + Inteiro(m.parametros().tamanho())
							+ " parametro(s)");
					}

					resultado = new Valor(m.parametros()[0].valorAlvo());
					// só pode ter um único parâmetro
				} else {
					Lista<const Valor*> valores;

					int i;
					for (i = 0; i < m.parametros().tamanho(); i++) {
						valores.adiciona(new Valor(m.parametros()[i].valorAlvo()));
					}

					resultado = new Valor(this->pEstados[m.estado().valor()]
							->executa(m.acao(), valores, m.campo()));

					for (i = 0; i < valores.tamanho(); i++) {
						delete valores[i];
					}
				}

//				Debug::msg(INFO, "--- MediadorDeEstados::aplica::"
//						" ao aplicar " + e + " no campo: " + m.campo());

				this->pEstados[m.estado().valor()]->atribui(
						*resultado, this->universo(), m.campo());

				delete resultado;
			}
		}
	}

	return *this;
}

const Lista<Identificacao>& MediadorDeEstados::nomeDeTodosEstados() const {
	return this->pNomeEstados;
}

const UniversoDeTempo& MediadorDeEstados::universo() const {
	return this->pUniverso;
}