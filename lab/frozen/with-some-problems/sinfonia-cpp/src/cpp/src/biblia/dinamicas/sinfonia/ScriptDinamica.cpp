/**
 * $RCSfile: ScriptDinamica.cpp,v $
 * $Date: 2005/03/28 21:07:47 $
 * $Revision: 1.32 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include "biblia/dinamicas/sinfonia/ScriptDinamica.h"
using namespace biblia::dinamicas::sinfonia; 

ScriptDinamica::ScriptDinamica(const string& caminhoDoArquivo, 
							   BasicoVisual& bv,
							   ResultadoSonoro& resultadoSonoro,
							   CarregadorDeSom& carregadorDeSom)

		:pSinfonia(NULL), 
		 pArquivo(caminhoDoArquivo), 
		 pVisual(bv),
		 pResultadoSonoro (resultadoSonoro),
		 pCarregadorDeSom (carregadorDeSom),
		 pTempo(bv.tempo()),
		 pRecarregando(false)
{}

ScriptDinamica::~ScriptDinamica() {}

const Sinfonia& ScriptDinamica::sinfonia() const {
	return *(this->pSinfonia);
}

Sinfonia& ScriptDinamica::sinfonia() {
	return *(this->pSinfonia);
}

Sinfonia* ScriptDinamica::geraSinfonia() {
	// lembrar que este deriva de Conclusivo
	this->zera().inicia();

	if (!this->pRecarregando) {
		this->pSinfonia = new Sinfonia(this->pTempo, this);
	} else {
		this->pEstados.limpa();
		this->pEstadosAtuais.limpa();
		this->pEventos.limpa();
		this->pAtributo.limpa();
		this->pParametro.limpa();
	}

	string erro = "ScriptDinamica::executa:: ocorreu um erro"
				" ao ler o arquivo '" + this->pArquivo + "'. Certifique-se que"
				" ele esteja disponível para leitura e que ele tenha sido gerado"
				" exclusivamente pelo software auxiliar SinfoniaScriptCreator.";

	try {
		this->carregaEstados(this->pArquivo);
	} catch(const Excecao& e) {
		Debug::sair(erro + " A Exceção '" + typeid(e).name() + "' foi lançada: " + e);
	}/* catch(...) {
		Debug::sair(erro + " Uma exceção desconhecida foi lançada!");
	}*/

	// limpa os Eventos que foram criados temporariamente.
	this->pLixoEventosTemporarios.limpa();
	this->conclui();

	Sinfonia* aRetornar = this->pSinfonia;

	// zerando:
	this->pSinfonia = NULL;
	this->pRecarregando = false;

	return aRetornar;
}

Genesis& ScriptDinamica::recarrega(Sinfonia* s) {
	s->zeraDinamica();
	this->pSinfonia = s;
	this->pRecarregando = true;

	this->geraSinfonia();

	return *this;
}

const string ScriptDinamica::grupo() const {
	string retorno;

	for (int i = 0; i < this->pGrupo.tamanho(); i++) {
		retorno += this->pGrupo[i];

		if (i < this->pGrupo.tamanho() - 1) {
			retorno += ".";
		}
	}

	return retorno;
}

bool ScriptDinamica::carregaEstados(string arquivo){
    ArquivoXMLXerces arquivoXML (arquivo);
    
    if (!arquivoXML.carregado()){
        return false;
        
	}else{

		string tabulacao = "\t";

		char* campos[] = {"Nome"};
		GrupoXML grupoSinfonia (arquivoXML.noPrincipal(),campos,1);
		tabulacao += "\t";
//		Debug::msg(INFO, "--- passo 1");
        percorreGruposParaEstados(arquivoXML.noPrincipal()->primeiroFilho());
//		Debug::msg(INFO, "--- passo 2");
		percorreGruposParaEventos(arquivoXML.noPrincipal()->primeiroFilho());
//		Debug::msg(INFO, "--- passo 3");
		percorreGruposParaDinamica(arquivoXML.noPrincipal()->primeiroFilho());
//		Debug::msg(INFO, "--- passo 4");
    
        return true;
    
    }
}

void ScriptDinamica::percorreGruposParaEstados(NoXML* no){

    if (no != NULL){

        if (no->nome().compare("Grupo") == 0){            
            
			char* campos[] = {"Id", "Nome", "Descricao"};
            GrupoXML grupoXML (no,campos,3);

			this->pGrupo.adiciona(Valor(grupoXML.getCampo("Nome")->valor()).valor());
            percorreGruposParaEstados (no->primeiroFilho());
            this->pGrupo.remove(this->pGrupo.tamanho() - 1);

        }else if (no->nome().compare("Estado") == 0){
                           
            char* campos[] = {"Id", "Nome", "Classe",
					"Descricao", "Externo", "SomenteEsses"};

			char* grupos[] = {"Atributos", "Eventos"};

            GrupoXML grupoEstado (no,campos,6,grupos,2);

			Estado* novoEstado = new Estado(grupoEstado.getCampo("Nome")->valor());
			novoEstado->grupo(this->grupo());
			Valor classe(grupoEstado.getCampo("Classe")->valor());

			if (classe == Valor("MultiFuncional")
				|| classe == Valor("Timer")
				|| classe == Valor("Animacao")
				|| classe == Valor("Mouse")
				|| classe == Valor("Som")
				|| classe == Valor("AreaClicavel"))
			{
				// ok
			} else {
				Debug::msg(WARN, "ScriptDinamica::geraSinfonia:: ainda não suporta esta"
						" classe: '" + grupoEstado.getCampo("Classe")->valor() + "'");
			}

			novoEstado->defineComentario(grupoEstado.getCampo("Descricao")->valor());
			novoEstado->externo(!grupoEstado.getCampo("Externo")->semValor());
			string idEstado = grupoEstado.getCampo("Id")->valor();

            if (grupoEstado.getGrupo("Atributos")->no() != NULL){
                NoXML* noAtributos = grupoEstado.getGrupo("Atributos")->no();      
                NoXML* noAtributoAtual = noAtributos->primeiroFilho();
                
                while (noAtributoAtual != NULL){                                
					char* campos[] = {"Id", "Nome", "Principal"};
					char* grupos[] = {"Parametros"};
                    GrupoXML grupoAtributo (noAtributoAtual,campos,3,grupos,1);
					Valor nomeAtributo(Multifuncional::CAMPO_PRINCIPAL);

					if (grupoAtributo.getCampo("Principal")->semValor()) {
						nomeAtributo = Valor(grupoAtributo
								.getCampo("Nome")->valor());
					} else {
 						nomeAtributo.adicionaApelido(
								grupoAtributo.getCampo("Nome")->valor());
					}

					string idAtributo = idEstado + " idAtributo: "
							+ grupoAtributo.getCampo("Id")->valor();

					this->pAtributo.insere(idAtributo, nomeAtributo.valor());
					novoEstado->atribui(Irrelevante(), this->pTempo, nomeAtributo);

                    if (grupoAtributo.getGrupo("Parametros")->no() != NULL){                                                                 
                        NoXML* noParametros = grupoAtributo.getGrupo("Parametros")->no();
                        NoXML* noParametroAtual = noParametros->primeiroFilho();
                        
                        while (noParametroAtual != NULL){
                     
							char* campos[] = {"Id", "Nome", "ValorInicial"};
							char* grupos[] = {"Apelidos"};
                            GrupoXML grupoParametro (noParametroAtual,campos,3,grupos,1);

							string idParametro = idAtributo + " idParametro: "
									+ grupoParametro.getCampo("Id")->valor();

							this->pParametro.insere(idParametro,
									grupoParametro.getCampo("Nome")->valor());

							Valor possibilidade(
									grupoParametro.getCampo("Nome")->valor(), true);

							if (!grupoParametro.getCampo("ValorInicial")->semValor()) {
								// atribuindo valor inicial

								string v = grupoParametro
										.getCampo("Nome")->valor();

								Valor aAtribuir = Valor(Irrelevante());

								if (Valor(v).pareceSerString()) {
									aAtribuir = Valor(v, true);
								} else {
									aAtribuir = Valor(v);
								}

								novoEstado->atribui(aAtribuir,
										this->pTempo, nomeAtributo);
							}

                            if (grupoParametro.getGrupo("Apelidos")->no() != NULL){
                                NoXML* noApelidos = grupoParametro
										.getGrupo("Apelidos")->no();

                                NoXML* noApelidoAtual = noApelidos->primeiroFilho();
                                
                                while (noApelidoAtual != NULL){                                         
									char* campos[] = {"Id", "Nome"};
                                    GrupoXML grupoApelido (noApelidoAtual, campos,2);
									possibilidade.adicionaApelido(
											grupoApelido.getCampo("Nome")->valor());

                                    noApelidoAtual = noApelidoAtual->proximoNo();
                                }
                            }

							if (!grupoEstado.getCampo("SomenteEsses")->semValor()) {
								novoEstado->universoParaModificar(nomeAtributo)
										.adicionaPossibilidade(possibilidade);
							}

                            noParametroAtual = noParametroAtual->proximoNo();
                        }
                    }
                
                    noAtributoAtual = noAtributoAtual->proximoNo();
                }
            }

			if (!this->pRecarregando
				|| !this->pSinfonia->mediadorDeEstados()
				.existeEstado(novoEstado->nomeCompleto()))
			{
				this->pSinfonia->adicionaEstado(novoEstado);
			} else {
				delete novoEstado;
			}

			// recuperando-o de volta:
			novoEstado = (Estado*) & this->pSinfonia
					->estados().estado(novoEstado->nomeCompleto());

			// estado do evento atual:
			Estado* estadoDoEventoAtual = (Estado*) & this->pSinfonia
					->estados().estadoDoEventoAtual(novoEstado->nomeCompleto());

			this->pEstados.insere(idEstado, novoEstado);
			this->pEstadosAtuais.insere(idEstado, estadoDoEventoAtual);

			if (!this->pRecarregando) { // ao recarregar, não muda estados especiais
				if (classe == Valor("Timer")) {
					// Ligando o timer de fato:

					try {
						Timer* novoTimer = new Timer(
								this->pTempo, this->pSinfonia->estados(), novoEstado);

						this->pSinfonia->adicionaGeradorDeEventosEspecial(
								novoTimer, true);
					} catch (const ImpossivelCriarTimerExcecao& icte) {
						Debug::msg(ERRO, "Ignorando erro em ScriptDinamica:: " + icte);
					}
				} else if (classe == Valor("Animacao")) {
					// Associando a animação:

					try {
						AnimacaoBiblia* novaAnimacao = new AnimacaoBiblia(
								this->pSinfonia->estados(), this->pVisual,
								novoEstado);

						this->pSinfonia->adicionaGeradorDeEventosEspecial(
								novaAnimacao, true);
					} catch (const ImpossivelCriarAnimacaoBibliaExcecao& icabe) {
						Debug::msg(ERRO, "Ignorando erro em ScriptDinamica:: " + icabe);
					}

				} else if (classe == Valor("Som")){

					try {
						SomBiblia* novoSom = new SomBiblia(
							this->pSinfonia->estados(),
							this->pResultadoSonoro,
							this->pCarregadorDeSom,
							this->pVisual.tempo(),
							novoEstado);

						this->pSinfonia->adicionaGeradorDeEventosEspecial(novoSom, true);

					} catch (const ImpossivelCriarAnimacaoBibliaExcecao& icsbe){
						Debug::msg(ERRO, "Ignorando erro em ScriptDinamica:: " + icsbe);
					}

				} else if (classe == Valor("Mouse")) {
					// Criando o mouse:

					try {
						MouseBiblia* novoMouse = new MouseBiblia(
								this->pSinfonia->estados(), this->pVisual.tempo(),
								novoEstado);

						this->pSinfonia->adicionaGeradorDeEventosEspecial(
								novoMouse, true);
					} catch (const ImpossivelCriarMouseBibliaExcecao& icmbe) {
						Debug::msg(ERRO, "Ignorando erro em ScriptDinamica:: " + icmbe);
					}

				} else if (classe == Valor("AreaClicavel")) {
					// Criando uma área clicável:

					try {
						AreaClicavel* novaArea = new AreaClicavel(
								this->pSinfonia->estados(), this->pVisual.tempo(),
								novoEstado);

						this->pSinfonia->adicionaGeradorDeEventosEspecial(
								novaArea, true);
					} catch (const ImpossivelCriarAreaClicavelExcecao& icace) {
						Debug::msg(ERRO, "Ignorando erro em ScriptDinamica:: " + icace);
					}		
				}
			}
        }

        percorreGruposParaEstados (no->proximoNo());
    }
}

void ScriptDinamica::percorreGruposParaEventos(NoXML* no){

    if (no != NULL){

        if (no->nome().compare("Grupo") == 0){            
            
			char* campos[] = {"Id", "Nome", "Descricao"};
            GrupoXML grupoXML (no,campos,3);

			this->pGrupo.adiciona(Valor(grupoXML.getCampo("Nome")->valor()).valor());
            percorreGruposParaEventos (no->primeiroFilho());
            this->pGrupo.remove(this->pGrupo.tamanho() - 1);

		}else if (no->nome().compare("Estado") == 0){

            char* campos[] = {"Id", "Nome", "Classe", "Descricao", "Externo"};
			char* grupos[] = {"Atributos", "Eventos"};

            GrupoXML grupoEstado (no,campos,5,grupos,2);

            if (grupoEstado.getGrupo("Eventos")->no() != NULL){
                NoXML* noEventos = grupoEstado.getGrupo("Eventos")->no();            
                NoXML* noEventoAtual = noEventos->primeiroFilho();
                percorreGruposParaEventos (noEventoAtual);
            }

        }else if (no->nome().compare("Evento") == 0){        
            
			char* campos[] = {"Id", "Nome", "Intermediario", "IdEstado",
					"IdAtributo", "Acao", "Externo"};

			char* grupos[] = {"Estado_Dependente"};

            GrupoXML grupoEvento (no, campos, 7, grupos, 1);
                        
			Evento* novoEvento = NULL;

            if (!grupoEvento.getCampo("Intermediario")->semValor()
				|| grupoEvento.getCampo("IdAtributo")->semValor())
			{
				// É intermediário
				novoEvento = new Evento(Valor(grupoEvento.getCampo("Nome")->valor()));
			} else {
				string idEstado = grupoEvento.getCampo("IdEstado")->valor();
				Estado* estado = this->pEstados[idEstado];

				string idAtributo = idEstado + " idAtributo: "
						+ grupoEvento.getCampo("IdAtributo")->valor();

				string atributo = this->pAtributo[idAtributo];
				string acao = grupoEvento.getCampo("Acao")->valor();

				Identificacao acaoProcessada((acao.compare("=") != 0)
						?Identificacao(acao):ModificadorDeEstado::APENAS_ATRIBUI);

				Valor nomeCompleto = estado->nomeCompleto();
				Valor nomeDoEstado = estado->nome();
				ModificadorDeEstado mde(nomeCompleto, acaoProcessada);
				mde.defineCampo(atributo);

				NoXML * noEstadoDependente = grupoEvento
						.getGrupo("Estado_Dependente")->no();
 
				string campo, nome;
				Estado* estadoDependente = carregaEstadoDependente(
						noEstadoDependente, campo, nome);

				mde.adicionaParametro(EstadoAlvo(estadoDependente, campo));

				novoEvento = new Evento(nomeDoEstado, mde);
            }

			if (!grupoEvento.getCampo("Externo")->semValor()) {
				novoEvento->especial(true);
			}

			novoEvento->grupo(Valor(this->grupo()));
			this->pLixoEventosTemporarios.adiciona(novoEvento);

			string idEvento = grupoEvento.getCampo("Id")->valor();
			this->pEventos.insere(idEvento, novoEvento);
		}

        percorreGruposParaEventos (no->proximoNo());
    }
}

void ScriptDinamica::percorreGruposParaDinamica(NoXML* no) {
    if (no != NULL){		
		if (no->nome().compare("Grupo") == 0){            
            
			char* campos[] = {"Id", "Nome", "Descricao"};
            GrupoXML grupoXML (no,campos,3);

			this->pGrupo.adiciona(Valor(grupoXML.getCampo("Nome")->valor()).valor());
            percorreGruposParaDinamica (no->primeiroFilho());
            this->pGrupo.remove(this->pGrupo.tamanho() - 1);

        } else if (no->nome().compare("Dinamica") == 0){  
            // Dinâmica     

			char* campos[] = {"Id", "Nome", "Desabilitada"};
			char* grupos[] = {"Eventos_Disparadores", "Condição", "Eventos_Gerados",
							  "Eventos_Gerados_Senão"};

            GrupoXML grupoDinamica (no,campos,3,grupos,4);                               
 
			if (!grupoDinamica.getCampo("Desabilitada")->semValor()) {
				Debug::msg(INFO, "Carregamento da Sinfonia: A Situação '"
						+ grupoDinamica.getCampo("Nome")->valor()
						+ "' está desabilitada.");
			} else {
				Situacao* novaSituacao;
				novaSituacao = new Situacao(grupoDinamica.getCampo("Nome")->valor());

//				Debug::msg(INFO, "--- eventos disparadores");

				//EVENTOS DISPARADORES
				//*********************************************************************************
				NoXML* noEvento = grupoDinamica
						.getGrupo("Eventos_Disparadores")->no()->primeiroFilho();
 
				bool qualquerUmDosEventos = false;

				if (noEvento == NULL) {
					// se não houver evento nenhum é porque qualquer um dos eventos
					// relacionados a qualquer uma das condições deverão ser levados em conta
					qualquerUmDosEventos = true;
				}

				while (noEvento != NULL){
                    
					char* campos[] = {"Id", "IdEvento"};
					GrupoXML grupoEventoAss (noEvento,campos,2);
					
					novaSituacao->adicionaEvento(*(this->pEventos[
							grupoEventoAss.getCampo("IdEvento")->valor()]));                         

					noEvento = noEvento->proximoNo();
				}

//				Debug::msg(INFO, "--- condição");

				//*********************************************************************************
				// CONDIÇÃO

				Lista<string> estadosRelacionados;
				Condicao* novaCondicao = carregaCondicao (
						grupoDinamica.getGrupo("Condição")->no(), estadosRelacionados,
						grupoDinamica.getCampo("Nome")->valor());

				novaSituacao->defineCondicao(*novaCondicao);
				delete novaCondicao;

				if (qualquerUmDosEventos) {
//					Debug::msg(INFO, "--- 'qualquer um dos' na situação " + *novaSituacao);

					for (int i = 0; i < estadosRelacionados.tamanho(); i++) {
						if (estadosRelacionados[i].compare("") != 0) {
							novaSituacao->adicionaEvento(Evento(estadosRelacionados[i]));
//							Debug::msg(INFO, "--- estado relacionado: " + estadosRelacionados[i]);
						}
					}

//					Debug::msg(INFO, "--- situação depois de adicionar: " + *novaSituacao);
				}

//				Debug::msg(INFO, "--- eventos gerados");

				//EVENTOS GERADOS
				//*********************************************************************************
				noEvento = grupoDinamica.getGrupo("Eventos_Gerados")->no()->primeiroFilho();
                
				while (noEvento != NULL){
                    
					char* campos[] = {"Id", "IdEvento"};
					GrupoXML grupoEventoAss (noEvento,campos,2);
					
					novaSituacao->adicionaEventoQueGera(*(this->pEventos[
							grupoEventoAss.getCampo("IdEvento")->valor()]));                      

					noEvento = noEvento->proximoNo();
				}
				//*********************************************************************************
            
//				Debug::msg(INFO, "--- eventos gerados senão");

				//EVENTOS GERADOS SENÃO
				//*********************************************************************************
				noEvento = grupoDinamica.getGrupo("Eventos_Gerados_Senão")->no()->primeiroFilho();
                
				while (noEvento != NULL){
					
					char* campos[] = {"Id", "IdEvento"};
					GrupoXML grupoEventoAss (noEvento, campos,2);
					
					novaSituacao->adicionaEventoQueGeraSenao(*(this->pEventos[
							grupoEventoAss.getCampo("IdEvento")->valor()]));

					noEvento = noEvento->proximoNo();
				}
				//*********************************************************************************

//				Debug::msg(INFO, "--- antes de adicionar");

				this->pSinfonia->adicionaSituacao(novaSituacao);

//				Debug::msg(INFO, "--- adicionou");
			}
		}

		percorreGruposParaDinamica (no->proximoNo());
	}
}

Condicao* ScriptDinamica::carregaCondicao(NoXML* noCondicao,
		Lista<string>& estadosRelacionados, string nomeDaSituacao)
{
    char* campos [] = {"Id", "Tipo_Condição", "Modificador", "Operador", "Operador_Booleano"};
    char* grupos [] = {"Estados_Dependentes", "Condições"};

    GrupoXML grupoCondicao (noCondicao,campos,5,grupos,2);
	Condicao* novaCondicao = NULL;
                                             
    if (grupoCondicao.getCampo("Tipo_Condição")->valor().compare("Comparação") == 0){
        
        NoXML * noEstadoDependente = grupoCondicao.getGrupo("Estados_Dependentes")->no()->primeiroFilho();
     
		string campo1, campo2, nome1, nome2;
        Estado* estado1 = carregaEstadoDependente (noEstadoDependente, campo1, nome1);
        Estado* estado2 = carregaEstadoDependente (noEstadoDependente->proximoNo(), campo2, nome2);

		bool existe = false;
		int i;

		for (i = 0; i < estadosRelacionados.tamanho() && !existe; i++) {
			if (nome1.compare(estadosRelacionados[i]) == 0) {
				existe = true;
			}
		}

		if (!existe) {
			estadosRelacionados.adiciona(nome1);
		}

		existe = false;

		for (i = 0; i < estadosRelacionados.tamanho() && !existe; i++) {
			if (nome2.compare(estadosRelacionados[i]) == 0) {
				existe = true;
			}
		}
		
		if (!existe) {
			estadosRelacionados.adiciona(nome2);
		}

		string operador = grupoCondicao.getCampo("Operador")->valor();
		novaCondicao = new CondicaoDeComparacao(EstadoAlvo(estado1, campo1),
				operador, EstadoAlvo(estado2, campo2));

    }else if (grupoCondicao.getCampo("Tipo_Condição")->valor().compare("Composta") == 0){
                    
        Valor ligacao(grupoCondicao.getCampo("Operador_Booleano")->valor());
        
        NoXML* noCondicaoComposta = grupoCondicao.getGrupo("Condições")->no()->primeiroFilho();
        
		Condicao* primeiraCondicao = NULL;

		if (noCondicaoComposta != NULL) {
			primeiraCondicao = carregaCondicao (
					noCondicaoComposta, estadosRelacionados, nomeDaSituacao);

			novaCondicao = new CondicaoComposta(*primeiraCondicao);
			delete primeiraCondicao;

			noCondicaoComposta = noCondicaoComposta->proximoNo();
		}

        while (noCondicaoComposta != NULL){
        
            Condicao* outraCondicao = carregaCondicao (noCondicaoComposta, estadosRelacionados, nomeDaSituacao);
			
			if (ligacao != Valor("and") && ligacao != Valor("or")
				&& ligacao != Valor("dif") && ligacao != Valor("xor")
				&& ligacao != Valor("eq"))
			{
				Debug::msg(ERRO, "Erro ao carregar Script! O operador '"
						+ ligacao + "'"
						" não pôde ser reconhecido. Ele não é AND, OR,"
						" DIF, XOR nem EQ."
						" Colocando por padrão 'AND'..."
						" Corrija isto! Situacao relacionada: '"
						+ nomeDaSituacao + "'");
			}
			
			((CondicaoComposta*) novaCondicao)->adiciona(
					ligacao == Valor("and")?AND
					:ligacao == Valor("or")?OR
					:ligacao == Valor("xor")?XOR
					:ligacao == Valor("eq")?EQ
					:ligacao == Valor("dif")?DIF:AND, *outraCondicao);

			delete outraCondicao;
            noCondicaoComposta = noCondicaoComposta->proximoNo();        
        }
	}

	if (novaCondicao == NULL) {
		novaCondicao = new Boleana(true);
	}

	if (!grupoCondicao.getCampo("Modificador")->semValor()) {
		// NOT:
		Condicao* novaCondicaoModificada = new CondicaoModificadora(*novaCondicao);
		delete novaCondicao;
		novaCondicao = novaCondicaoModificada;
	}

	return novaCondicao;
}


Estado* ScriptDinamica::carregaEstadoDependente(
		NoXML* noEstado, string& atributo, string& nomeAAtualizar)
{
    char* campos[] = {"Id"};
	char* grupos[] = {"Estados_Compostos"};

    GrupoXML grupoEstadoDep (noEstado, campos,1,grupos,1);
    NoXML* noEstadoComposto = grupoEstadoDep.getGrupo("Estados_Compostos")->no()->primeiroFilho();
	string operadorAnterior = "_nenhum";
	Estado* aRetornar = NULL;

    while (noEstadoComposto != NULL){
 
		char* campos[] = {"Id", "Operador", "ValorAtual", "Constante",
				"Valor", "IdEstado", "IdAtributo", "IdParametro"};        

		GrupoXML grupoEstadoComposto (noEstadoComposto, campos,8);
		Estado* estadoAtual;

		if (!grupoEstadoComposto.getCampo("Constante")->semValor()) {
			string v = grupoEstadoComposto.getCampo("Valor")->valor();
			Valor valor = Valor(Irrelevante());

			if (Valor(v).pareceSerString()) {
				valor = Valor(v, true);
			} else {
				valor = Valor(v);
			}

			//grupoEstadoComposto.getCampo("Valor")->valor();
			estadoAtual = (Estado*) & (this->sinfonia().estados()
					.estadoConstante(valor));

			atributo = Multifuncional::CAMPO_PRINCIPAL.valor();

		} else if (!grupoEstadoComposto.getCampo("IdParametro")->semValor()
				&& !grupoEstadoComposto.getCampo("IdAtributo")->semValor())
		{
			string idEstado = grupoEstadoComposto.getCampo("IdEstado")->valor();
			string idAtributo = idEstado + " idAtributo: "
					+ grupoEstadoComposto.getCampo("IdAtributo")->valor();

			string idParametro = idAtributo + " idParametro: "
					+ grupoEstadoComposto.getCampo("IdParametro")->valor();

			string valor = this->pParametro[idParametro];
			Valor aAtribuir = Valor(Irrelevante());

			if (Valor(valor).pareceSerString()) {
				aAtribuir = Valor(valor, true);
			} else {
				aAtribuir = Valor(valor);
			}
			
			estadoAtual = (Estado*) & (this->sinfonia()
					.estados().estadoConstante(aAtribuir));

			atributo = Multifuncional::CAMPO_PRINCIPAL.valor();

		} else if (!grupoEstadoComposto.getCampo("IdEstado")->semValor()) {
			string idEstado = grupoEstadoComposto.getCampo("IdEstado")->valor();

			if (grupoEstadoComposto.getCampo("ValorAtual")->semValor()) {
				estadoAtual = this->pEstados[idEstado];
			} else {
				estadoAtual = this->pEstadosAtuais[idEstado];
			}

			nomeAAtualizar = this->pEstados[idEstado]->nomeCompleto().emString();

			if (grupoEstadoComposto.getCampo("IdAtributo")->semValor()) {
				atributo = Multifuncional::CAMPO_PRINCIPAL.valor();
			} else {
				string idEstado = grupoEstadoComposto.getCampo("IdEstado")->valor();
				string idAtributo = idEstado + " idAtributo: "
						+ grupoEstadoComposto.getCampo("IdAtributo")->valor();

				atributo = this->pAtributo[idAtributo];
			}
		} else {
			Debug::msg(ERRO, "ERRO FATAL: Nunca devia ter entrado aqui!"
				" Informe o código 120056.");
		}

		if (aRetornar != NULL) {
			// não é a primeira vez que está passando aqui
			((EstadoDependente*) aRetornar)->adicionaEstado(
					operadorAnterior, EstadoAlvo(estadoAtual, atributo));
		} else {
			// primeira vez
			if (noEstadoComposto->proximoNo() != NULL) {
				// se tem próximo, é um estado dependente
				aRetornar = this->sinfonia().estados()
						.criaEstadoDependente(estadoAtual, atributo);
			} else {
				aRetornar = estadoAtual;
			}
		}

        operadorAnterior = grupoEstadoComposto.getCampo("Operador")->valor();
        noEstadoComposto = noEstadoComposto->proximoNo();
    }

	return aRetornar;
}
