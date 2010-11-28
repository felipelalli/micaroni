/**
 * $RCSfile: GeradorDeEventosDependente.cpp,v $
 * $Date: 2005/03/28 21:07:46 $
 * $Revision: 1.25 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/GeradorDeEventosDependente.h"
using namespace biblia::dinamicas::sinfonia;

GeradorDeEventosDependente::GeradorDeEventosDependente(const MediadorDeEstados& mde)
		:GeradorDeEventos(mde, true), pEventosEmEspera(),
		 pSituacoes(), pLixo(), pControle(1),
		 pContadorParaQuandoNomeJaExiste()
{}

GeradorDeEventosDependente::~GeradorDeEventosDependente() {
	this->pControle.esperar();
}

const bool GeradorDeEventosDependente::validaRecursivamente(const Situacao& s) const {
// 	Debug::msg(INFO, "--- vai validar!");
	
	for (int k = 0; k < s.seAcontecerUmDessesEventos().tamanho(); k++) {
		string id = s.seAcontecerUmDessesEventos()[k]->nomeCompleto().valor();

		if (!this->pEventosParaChecagem.existe(id)) {
			this->pEventosParaChecagem.insere(id, Lista<const Evento*>());
		}

		this->pEventosParaChecagem[id].adiciona(
				(Evento*) s.seAcontecerUmDessesEventos()[k]->geraCopia());

//		Debug::msg(INFO, "--- adicionando em 'eventos para chegagem': "
//				+ *((Evento*) s.seAcontecerUmDessesEventos()[k]));
	}

	for (int o = 0; o < 2; o++) {
//		Debug::msg(INFO, "--- validando: " + Inteiro(o));

		const Lista<const Evento*>& oQueGera
				= (o == 0?s.oQueGera():s.oQueGeraSenao());

//		Debug::msg(INFO, "--- antes do for");
		for (int i = 0; i < oQueGera.tamanho(); i++) {
//			Debug::msg(INFO, "--- tamanho: " + Inteiro(oQueGera.tamanho()));
//			Debug::msg(INFO, "--- o que gera[" + Inteiro(i) + "]=" + *(oQueGera[i]));

			string id = oQueGera[i]->nomeCompleto().valor();

			if (this->pEventosParaChecagem.existe(id)) {
//				Debug::msg(INFO, "--- id: " + id + " existe!!");

//				Debug::msg(INFO, "--- eventos para checagem tem "
//						+ Inteiro(this->pEventosParaChecagem[id].tamanho()) + " elementos.");

				for (int w = 0; w < this->pEventosParaChecagem[id].tamanho(); w++) {
//					Debug::msg(INFO, "--- validacao: evento " + *(this->pEventosParaChecagem[id][w])
//							+ " é igual a " + *(oQueGera[i]) + "???");

					if (this->pEventosParaChecagem[id][w]->igual(*(oQueGera[i]))) {
						// Encontrou alguém no histórico.
//						Debug::msg(INFO, "--- encontrou alguem no historico");
						return false;
					}
				}
			}

			if (this->pSituacoes.existe(id)) {
//				Debug::msg(INFO, "--- existe situação para o id " + id);

				Lista<const Situacao*>* situacoes = this->pSituacoes[id];

				for (int w = 0; w < situacoes->tamanho(); w++) {
					if (! (*situacoes)[w]->mesmaInstancia(&s)) {
//						Debug::msg(INFO, "--- validando recursivamente: " + *(*situacoes)[w]);
						this->validaRecursivamente(*(*situacoes)[w]);
					}
				}
			}
		}

//		Debug::msg(INFO, "--- após o for");
	}

	// Não encontrou ninguém no histórico
	return true;
}

const bool GeradorDeEventosDependente::valida(const Situacao& s) const {
	return true;

//	FIXME FIXME FIXME FIXME FIXME FIXME FIXME FIXME FIXME 
//		FIXME FIXME FIXME FIXME FIXME FIXME FIXME FIXME FIXME 
//		FIXME FIXME FIXME FIXME FIXME FIXME FIXME FIXME FIXME 
//		FIXME FIXME FIXME FIXME FIXME FIXME FIXME FIXME FIXME FIXME 

//	Debug::msg(INFO, "--- vai validar");

	bool retorno = this->validaRecursivamente(s);

	// Apagando histórico:
	Lista<Lista<const Evento*> >* lista = this->pEventosParaChecagem.valores();
	this->pEventosParaChecagem.limpa();

	for (int i = 0; i < lista->tamanho(); i++) {
		for (int w = 0; w < (*lista)[i].tamanho(); w++) {
			delete (*lista)[i][w];
		}
	}

	delete lista;

//	Debug::msg(INFO, "--- validou");

	return retorno;
}

GeradorDeEventosDependente&	GeradorDeEventosDependente
		::adicionaSituacao(const Situacao* s)
{
	if (s != NULL) {
//		Debug::msg(INFO, "--- vai validar");

		if (!this->valida(*s)) {
//			Debug::msg(INFO, "--- vai exibir");
			Debug::msg(WARN, "A Situação '" + *s + "' pode fazer com que a Sinfonia"
					" entre em loop! Verifique cada elemento que ela gera.");
		}

		const Lista<const Evento*>& relacionados = s->seAcontecerUmDessesEventos();

//		Debug::msg(INFO, "--- vai adicionar situacao: " + *s);

		for (int i = 0; i < relacionados.tamanho(); i++) {
			string id = relacionados[i]->nomeCompleto().valor();
//			Debug::msg(INFO, "--- id: " + id);

			if (this->pSituacoes.existe(id)) {
//				Debug::msg(INFO, "--- GeradorDeEventosDependente::adicionaSituacao:: ja existia "
//						+ id + "... Adicionando na lista! ;)");

				bool existe = false;

				Lista<const Situacao*>& situacoes = *(this->pSituacoes[id]);

				for (int j = 0 ; j < situacoes.tamanho() && !existe; j++) {
					if (situacoes[j] == s) {
						existe = true;
					}
				}

				if (!existe) {
					this->pSituacoes[id]->adiciona(s);
				}
			} else {
				Lista<const Situacao*>* novaLista = new Lista<const Situacao*>();
				this->pLixo.adiciona(novaLista);
				novaLista->adiciona(s);
				this->pSituacoes.insere(id, novaLista);
			}
		}

		// Para consulta externa:
		string nome;

		if (!this->pSituacoesParaConsultaExterna.existe(s->nome().valor())) {
			nome = s->nome().valor();
		} else {
			if (!this->pContadorParaQuandoNomeJaExiste.existe(s->nome().valor())) {
				this->pContadorParaQuandoNomeJaExiste.insere(s->nome().valor(), 1);
			}

			int& valor = this->pContadorParaQuandoNomeJaExiste[s->nome().valor()];
			valor++;
			nome = s->nome() + " " + Inteiro(valor);
		}

		this->pSituacoesParaConsultaExterna.insere(nome, s);
		this->pNomeDasSituacoes.adiciona(nome);
	}

	return *this;
}

GeradorDeEventosDependente& GeradorDeEventosDependente::apagaTudo() {
	this->pSituacoes.limpa();
	this->pSituacoesParaConsultaExterna.limpa();
	this->pNomeDasSituacoes.limpa();
	this->pLixo.limpa();

	return *this;
}

const Lista<Identificacao>& GeradorDeEventosDependente
		::nomeDeTodasSituacoes() const
{
	return this->pNomeDasSituacoes;
}

const Situacao& GeradorDeEventosDependente
		::situacao(const Identificacao& nome) const
{
	return *(this->pSituacoesParaConsultaExterna[nome]);
}

GeradorDeEventosDependente& GeradorDeEventosDependente
		::aconteceu(const Evento& e)
{
	if (!e.disparado()) {
		Debug::sair("GeradorDeEventos::aconteceu:: o Evento "
				"passado deve estar disparado!! Evento: " + e);
	} else {
		this->pEventosEmEspera.adiciona((const Evento*) &e);
	}

	return *this;
}

// Executavel:

Executavel& GeradorDeEventosDependente::executa() {
	// essa função não pode ser executada ao mesmo tempo
	Lock lock(this->pControle);
	Lista<Evento*> eventosGerados;

	for (int i = 0; i < this->pEventosEmEspera.tamanho(); i++) {
		const Evento& e = *(this->pEventosEmEspera[i]);
		const string id = e.nomeCompleto().valor();
		const UniversoDeTempo& tempo = e.momentoDoDisparo().universo();

//		Debug::msg(INFO, "--- evento recebido pela dinamica: " + e);

/*
		if (!this->pSituacoes.existe(id)) {

#ifdef _DEBUG
			if (!this->pJaExibiuEsteErro.existe(id)) {
				Debug::msg(INFO, "GeradorDeEventosDependente::executa()::"
					" ignorando evento: " + e);

				this->pJaExibiuEsteErro.insere(id, true);
			}
#endif

		} else {
*/
		if (this->pSituacoes.existe(id)) {
//			Debug::msg(INFO, "--- id: " + id + " existe!!!");

			const Lista<const Situacao*>& situacoes = *(this->pSituacoes[id]);

			for (int j = 0; j < situacoes.tamanho(); j++) {
				const Situacao& situacao = *(situacoes[j]);
//				Debug::msg(WARN, "--- situacao: " + situacao);
//				Debug::msg(WARN, "--- evento: " + e);

				if (situacao.eventoCorresponde(e)) {
//					Debug::msg(WARN, "--- evento corresponde!");

					if (situacao.condicaoVerdadeira()) {
//						Debug::msg(WARN, "--- condicao verdadeira!");

						const Lista<const Evento*>& oQueGera = situacao.oQueGera();

						for (int w = 0; w < oQueGera.tamanho(); w++) {
//							Debug::msg(WARN, "--- vai disparar: " + *(oQueGera[w]));
							bool existe = false;

							for (int p = 0; p < eventosGerados.tamanho() && !existe; p++) {
								if (eventosGerados[p]->igual(*(oQueGera[w]))) {
									existe = true;
								}
							}

							if (!existe) {
								eventosGerados.adiciona(oQueGera[w]->dispara(tempo));
							}
						}
					} else {
//						Debug::msg(INFO, "--- condicao falsa!");

						const Lista<const Evento*>& oQueGeraSenao
								= situacao.oQueGeraSenao();

						for (int w = 0; w < oQueGeraSenao.tamanho(); w++) {
//							Debug::msg(INFO, "--- vai disparar (senão): "
//									+ *(oQueGeraSenao[w]));

							bool existe = false;

							for (int p = 0; p < eventosGerados.tamanho() && !existe; p++) {
								if (eventosGerados[p]->igual(*(oQueGeraSenao[w]))) {
									existe = true;
								}
							}

							if (!existe) {
								eventosGerados.adiciona(oQueGeraSenao[w]->dispara(tempo));
							}
						}
					}
				}
			}
		}
	}

	this->pEventosEmEspera.limpa();

	for (int p = 0; p < eventosGerados.tamanho(); p++) {
//		Debug::msg(INFO, "--- manda gerar: " + *(eventosGerados[p]));
		this->gera(eventosGerados[p]);
	}

	return *this;
}
