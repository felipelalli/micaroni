/**
 * $RCSfile: Sinfonia.h,v $
 * $Date: 2005/03/31 23:45:26 $
 * $Revision: 1.30 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_SINFONIA_H__F620F6CB_039E_4BB4_B2BD_52154D013071__INCLUDED_)
#define AFX_SINFONIA_H__F620F6CB_039E_4BB4_B2BD_52154D013071__INCLUDED_

#include <biblia/basico/Objeto.h>
#include <biblia/basico/Excecao.h>
using namespace biblia::basico;

#include <biblia/util/Debug.h>
#include <biblia/util/Lixeira.h>
using namespace biblia::util;

#include <biblia/tempo/Cronometro.h>
#include <biblia/tempo/UniversoDeTempo.h>
using namespace biblia::tempo;

#include <biblia/fluxo/Thread.h>
#include <biblia/fluxo/Semaforo.h>
#include <biblia/fluxo/Executavel.h>
using namespace biblia::fluxo;

#include <biblia/armazenamento/volatil/primitivos/Inteiro.h>
using namespace biblia::armazenamento::volatil::primitivos;

#include <biblia/armazenamento/volatil/carcacas/Lista.h>
#include <biblia/armazenamento/volatil/carcacas/MapaHash.h>
using namespace biblia::armazenamento::volatil::carcacas;

#include "biblia/dinamicas/sinfonia/Genesis.h"
#include "biblia/dinamicas/sinfonia/Concretizador.h"
#include "biblia/dinamicas/sinfonia/SinfoniaExcecao.h"
#include "biblia/dinamicas/sinfonia/MediadorDeEstados.h"
#include "biblia/dinamicas/sinfonia/ModificadorDeEstado.h"
#include "biblia/dinamicas/sinfonia/GeradorDeEventosEspecial.h"
#include "biblia/dinamicas/sinfonia/GeradorDeEventosDependente.h"
#include "biblia/dinamicas/sinfonia/OuvidorDosGeradoresDeEventos.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	class Genesis;

    /**
	 * @see Sinfonia#Sinfonia
	 */
	class GenesisNaoDefinidoExcecao: public SinfoniaExcecao {};

	/**
	 * <p><b><font size=+1>Classe Principal.</font></b>
	 * <p>
	 * Realiza a {@link GeradorDeEventosDependente mudan�a}
	 * e a {@link Concretizador execu��o} de determinados
	 * {@link MediadorDeEstados estados}.
	 *
	 * @version $Revision: 1.30 $, $Date: 2005/03/31 23:45:26 $ (GMT-3)
	 * @author <a href="mailto:micaroni@gmail.com?subject=$RCSfile: Sinfonia.h,v $">Felipe Micaroni Lalli</a>
	 * @author modificado por $Author: felipelalli $
	 *
	 * @see Genesis
	 * @see Estado
	 * @see Evento
	 * @see MediadorDeEstados
	 * @see Concretizador
	 * @see RegraDeEstados
	 * @see GeradorDeEventosDependente
	 * @see GeradorDeEventosEspecial
	 * @see ScriptDinamica
	 */
	class Sinfonia: public GeradorDeEventos {
		private:
			MediadorDeEstados pEstados;
			GeradorDeEventosDependente pDependentes; // � um GeradorDeEventos
			Concretizador* pConcretizador; // � um GeradorDeEventos
			MapaHash<Lista<GeradorDeEventosEspecial*> > pGeradoresPontuais;
			Lista<GeradorDeEventosEspecial*> pGeradores;
			Lista<Thread*> pThreads;

			Cronometro pQuantoTempoExecutando;
			Semaforo pEsperarAcabar;
			Semaforo pEsperarExecutar;
			const UniversoDeTempo& pTempo;
			bool pExecutou;

			/**
			 * Usado para o recarregamento on-line.
			 */
			Genesis* pGenesis;

			Lixeira pLixo;
			Lixeira pLixoSituacoes; // Din�mica
			Lixeira pLixoThreads;
			Lixeira pLixoOuvidores;

			/**
			 * Proibido.
			 */
			Sinfonia(const Sinfonia& s)
				:GeradorDeEventos(pEstados, true),
				 pEstados(s.pTempo),
				 pDependentes(pEstados),
				 pConcretizador(NULL), pGeradores(),
			     pLixo(), pQuantoTempoExecutando(s.pTempo, false),
				 pThreads(), pEsperarAcabar(1),
				 pEsperarExecutar(0), pTempo(s.pTempo)
			{}

		protected:
			/**
			 * Pega para si a responsabilidade de deletar
			 * o {@link GeradorDeEventos} passado.
			 */
			virtual Sinfonia& adicionaGeradorDeEventos(GeradorDeEventos* ge);

			/**
			 * {@link GeradorDeEventosDependente Din�mica}
			 * da Sinfonia.
			 *
			 * @see GeradorDeEventosDependente
			 */
			virtual GeradorDeEventosDependente& dinamicaParaModificar();

			/**
			 * {@link Concretizador} da Sinfonia.
			 *
			 * @see Concretizador
			 */
			virtual Concretizador& concretizador();

			/**
			 * {@link Estado}s da Sinfonia.
			 *
			 * @see MediadorDeEstados
			 */
			virtual MediadorDeEstados& estadosParaModificar();

			// Procedimentos:

			virtual Sinfonia& inicializa();
			virtual Sinfonia& recarrega();

		public:
			// Estados Reservados

			/**
			 * Nome do Estado reservado que indica
			 * que a Sinfonia est� ligada, definido como
			 * <b>Sinfonia.Reservados.ligada</b>.
			 */
			static const Valor LIGADA;

			/**
			 * Nome do Estado reservado que indica
			 * que a Sinfonia est� recarregando, definido como
			 * <b>Sinfonia.Reservados.recarregando</b>.
			 *
			 * Defina-o como verdadeiro quando quiser que a Sinfonia
			 * seja recarregada.
			 */
			static const Valor RECARREGANDO;

			// Construtor / Destrutor

			/**
			 * Cria uma Sinfonia vazia, ela deve
			 * ser definida pelas fun��es
			 * {@link #adicionaGeradorDeEventosEspecial},
			 * {@link #adicionaResultado},
			 * {@link #adicionaSituacao}
			 * e {@link #adicionaEstado}.
			 *
			 * Utilize alguma classe derivada de {@link Genesis}
			 * para poder criar uma Sinfonia completa.
			 *
			 * @param genesis Par�metro opcional que serve para
			 *        fazer com que a Sinfonia possa ser recarregada
			 *        em tempo de execu��o. Caso ele n�o seja definido,
			 *        o comando especial lan�ado pelo evento de nome
			 *        {@link Sinfonia#RECARREGANDO} lan�ar� a exce��o
			 *        {@link GenesisNaoDefinidoExcecao}.
			 */
			Sinfonia(const UniversoDeTempo& u, Genesis* genesis = NULL);
			virtual ~Sinfonia();

			// Fun��es de defini��o

			/**
			 * N�o pega para si a responsabilidade de apagar.
			 *
			 * @see Sinfonia#Sinfonia
			 */
			virtual Sinfonia& defineGenesisParaRecarregamento(Genesis* genesis);

			/**
			 * Adiciona algum {@link GeradorDeEventosEspecial}
			 * que captura os {@link Evento}s da Sinfonia e manda
			 * pro Software realizar alguma coisa, podendo gerar
			 * ainda Eventos para a Sinfonia. <b>Importante:
			 * por padr�o, a Sinfonia n�o executar� esses
			 * {@link GeradorDeEventosEspecial
			 * geradores especiais}, eles dever�o ser executados externamente
			 * de alguma forma. Se quiser que a Sinfonia o execute uma vez em thread
			 * voc� deve passar "true" no par�metro "executarUmaVezEmThread".</b>
			 *
			 * @param gee Esta classe pegar� para si a responsabilidade
			 *          de deletar o {@link GeradorDeEventosEspecial
			 *          gerador de eventos especial} passado.
			 *
			 * @see GeradorDeEventosEpecial
			 */
			virtual Sinfonia& adicionaGeradorDeEventosEspecial(
					GeradorDeEventosEspecial* gee,
					const bool& executarUmaVezEmThread = false);

			/**
			 * Adiciona uma {@link Situacao Situa��o} ao
			 * {@link GeradorDeEventosDependente} atrelado
			 * � Sinfonia.
			 *
			 * @param s Esta classe pegar� para si a responsabilidade
			 *          de deletar a situa��o passada.
			 *
			 * @see GeradorDeEventosDependente#adicionaSituacao
			 * @see Situacao
			 */
			virtual Sinfonia& adicionaSituacao(const Situacao* s);

			/**
			 * Adiciona algum {@link Resultado}
			 * que ser� executado sempre que a {@link Situacao situa��o}
			 * atrelada a {@link Resultado ele} ocorrer.
			 *
			 * @param r Esta classe pegar� para si a responsabilidade
			 *          de deletar o {@link Resultado} passado.
			 *
			 * @see Concretizador#adiciona
			 * @see Resultado
			 */
			virtual Sinfonia& adicionaResultado(Resultado* r);

			/**
			 * Zera a din�mica da Sinfonia.
			 */
			virtual Sinfonia& zeraDinamica();

			/**
			 * Adiciona um {@link Estado}
			 * no {@link MediadorDeEstados}
			 * desta Sinfonia.
			 *
			 * @param e Esta classe pegar� para si a responsabilidade
			 *          de deletar o {@link Estado} passado.
			 *
			 * @see MediadorDeEstados#adicionaEstado
			 * @see Estado
			 */
			virtual Sinfonia& adicionaEstado(Estado* e);

			/**
			 * Utiliza os recursos internos para fazer rodar
			 * um execut�vel passado uma vez em {@link Thread}.
			 * Cuidado para n�o chamar essa fun��o duas vezes, se voc�
			 * passar <b>true</b> no par�metro <b>executarUmaVezEmThread</b>
			 * na fun��o {@link #adicionaGeradorDeEventosEspecial}
			 * esta fun��o j� ser� chamada automaticamente.
			 *
			 * @see #adicionaGeradorDeEventosEspecial
			 */
			virtual Sinfonia& fazRodarUmaVezEmThread(
					Executavel& e, const string& nome);

			// Fun��es de uso

			/**
			 * {@link Estado}s da Sinfonia.
			 *
			 * @see MediadorDeEstados
			 */
			virtual const MediadorDeEstados& estados() const;

			/**
			 * {@link GeradorDeEventosDependente Din�mica}
			 * da Sinfonia.
			 *
			 * @see GeradorDeEventosDependente
			 */
			virtual const GeradorDeEventosDependente& dinamica() const;

			// A��es:
			/**
			 * Simplesmente lan�a o evento
			 * {@link #RECARREGANDO Sinfonia::RECARREGANDO(V)} para
			 * si mesma.
			 */
			virtual Sinfonia& lancaEventoParaRecarregar();

			/**
			 * Inicia todo o processo da Sinfonia. Fica executando
			 * em loop enquanto o estado reservado {@link #LIGADA}
			 * for verdadeiro.
			 * <p>
			 *     1. {@link GeradorDeEventosEspecial
			 *         recebe de geradores de eventos especiais}.
			 * <br>2. {@link GeradorDeEventosDependente din�mica dos estados}.
			 * <br>3. {@link MediadorDeEstados mediador de estado}.
			 * <br>4. {@link GeradorDeEventosEspecial manda para
			 *         geradores de eventos especiais}.
			 * <br>5. {@link Concretizador concretizador}.
			 */
			virtual GeradorDeEventos& captaEGeraEmLoop();

			// Objeto:
			/**
			 * Retorna o momento que esta Sinfonia foi
			 * criada, todos os estados e todos as situa��es.
			 */
			virtual string emString() const;
	};
  }
 }
}

#endif // !defined(AFX_SINFONIA_H__F620F6CB_039E_4BB4_B2BD_52154D013071__INCLUDED_)
