/*
 * $RCSfile: Caixa.h,v $
 * $Date: 2004/02/26 18:49:18 $
 * $Revision: 1.7 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Caixa_h)
#define Caixa_h

#include "biblia/armazenamento/volatil/carcacas/MapaHash.h"
#include "biblia/armazenamento/eterno/EternoExcecao.h"
#include "biblia/armazenamento/eterno/empacotamento/PacoteSelado.h"

using namespace biblia::armazenamento::eterno;
using namespace biblia::armazenamento::volatil::carcacas;

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace empacotamento {

		/**
		 * Uma caixa cont�m v�rios pacotes selados.
		 * Esta caixa guarda refer�ncias para pacotes
		 * selados que devem ser criados/deletados
		 * de fora. Esta classe n�o pode se responsabilizar
		 * por esse controle de mem�ria porque caixas
		 * diferentes podem conter o mesmo pacote selado.
		 * <p>
		 * Escolheu-se o nome "caixa" por se entender
		 * que geralmente uma "caixa" � maior que um "pacote" e
		 * neste caso espec�fico uma Caixa cont�m diversos Pacotes.
		 * <p>
		 * Do dicion�rio Aur�lio:
		 *  <p>
			<b>pacote</b> . [Dim. de paca1 (q. v.).] S. m. 1. Pequeno ma�o ou pequeno embrulho: um pacote de dinheiro; um pacote de papel
			pardo. 2. O conjunto de unidades contidas num pacote (1): Um pacote de cigarros cont�m dez ma�os. 3. P. ext. Bras.
			Qualquer coisa semelhante a pacote (1); combina��o de elementos que se relacionam, e que s�o tomados como um todo: Os
			agentes de viagem oferecem excelente pacote para f�rias na Bahia. 4. Fig. Logro, embuste, engano. 5. Market. Conjunto de
			itens relacionados, como, p. ex., programas de TV ou servi�os tur�sticos, comercializados como um todo, usualmente com
			desconto. 6. Bras. Grande quantidade de mercadoria negociada em conjunto e, ger., em transa��o vultosa. 7. Bras. Pop.
			Conjunto de medidas governamentais, sobretudo na �rea econ�mica, adotadas simultaneamente: Espera-se para amanh� novo
			pacote na �rea econ�mica. 8. Inform. Bloco de informa��o preparado para trafegar numa rede de computadores, com um
			cabe�alho que identifica a sua origem e o seu destino; datagrama. [Cf. comuta��o de pacotes.] ~ V. pacotes. Pacote de
			ondas. F�s. 1. Conjunto finito de ondas que transporta energia de um para outro ponto do espa�o; grupo de onda, trem de
			onda. Ir no pacote. Bras. G�r. 1. Ser enganado; deixar-se lograr.
			<p>
		    <b>caixa</b> . [Do lat. capsa , pelo cat. caixa.] S. f. 1. Recipiente ou recept�culo de madeira, papel�o, metal, ou outro
			material, com tampa ou sem ela, com faces geralmente retangulares ou quadradas, como uma arca, um cofre, um estojo, etc.
			[Aum. irreg.: caix�o; dim. irreg.: caixeta, caixote, caixola.] 2. O conte�do de uma caixa: Tomou uma caixa de inje��es. 3.
			Pe�a ou objeto que resguarda ou cont�m outra pe�a ou objeto: caixa de marchas; caixa de engrenagens. 4. Se��o de bancos,
			casas comerciais, reparti��es p�blicas, etc., destinada a efetuar pagamentos ou recebimentos de dinheiro, cheques,
			valores, etc. 5. P. ext. Local onde trabalha o encarregado dessas opera��es. 6. Cont. T�tulo da conta que registra o
			movimento de dinheiro. 7. Econ. Disponibilidade em dinheiro; encaixe: A empresa aplica seus excedentes de caixa no mercado
			financeiro. 8. Eng. Parte da estrada onde se lan�a a brita. 9. Jur. Com. Armador-gerente. 10. Designa��o comum a v�rios
			instrumentos de percuss�o do g�nero tambor (q. v.): O menino tocava caixa na banda do col�gio. 11. Teatr. V. palco (3).
			12. Tip. Cada uma das gavetas do cavalete, divididas horizontalmente em duas se��es (caixa alta e caixa baixa),
			subdividindo-se estas em v�rios caixotins, onde se distribuem os tipos, separados por sortes. 13. V. caixote (3). 14. Lus.
			Edit. Boxe (6). � S. m. 15. Livro comercial auxiliar onde se registram entradas e sa�das de dinheiro. � S. 2 g. 16. Pessoa
			que tem a seu cargo a caixa (4). [Cf. cacha, do v. cachar e s. f., e caxa.] Caixa ac�stica. 1. Eletr�n. Sonofletor (q.
			v.). Caixa alta. Tip. 1. Se��o superior da caixa tipogr�fica, em cujos caixotins se distribuem as letras mai�sculas. [Cf.
			caixa-alta.] Caixa aspirante. Ind. Pap. 1. Cada um dos aparelhos colocados por baixo da tela da m�quina de papel, para
			apressar, por meio de suc��o, a secagem da folha; caixa de suc��o, caixa-bomba. Caixa autom�tico. 1. V. caixa eletr�nico.
			Caixa baixa. Tip. 1. Se��o inferior da caixa tipogr�fica, em cujos caixotins se distribuem as letras min�sculas. [Cf.
			caixa-baixa.] Caixa cega. Tip. 1. A que n�o tem subdivis�es, usada para guardar clich�s ou tipos de grande corpo. Caixa
			chata. 1. V. tarol. Caixa clara. 1. Tambor (3) de fuste m�dio, com bord�es na membrana inferior, o que lhe confere uma
			sonoridade vibrante, e cujo registro (contralto ou soprano) depende das dimens�es do instrumento; caixa de guerra, tambor
			de guerra. [Cf. tarol.] Caixa craniana. Anat. 1. Por��o �ssea da cabe�a que cont�m o enc�falo. Caixa das almas. 1. Pequeno
			cofre, nas igrejas ou noutros locais, onde se depositam esmolas. Caixa de ar. 1. Espa�o ventilado que fica entre o solo e
			o soalho de um edif�cio; por�o. Caixa de brancos. Tip. 1. Caixa tipogr�fica para guardar espa�aria; caixa de espa�os.
			Caixa de cambas. Tip. 1. Parte da linotipo onde fica o conjunto das cambas que acionam o mecanismo de escape. Caixa de
			c�mbio. Mec. 1. V. caixa de marchas. Caixa de cena. Teatr. 1. V. palco (3). Caixa de descarga. 1. Pequeno dep�sito,
			embutido ou simplesmente fixado na parede, ou apoiado no aparelho sanit�rio, e destinado � reten��o da �gua da lavagem das
			bacias de privadas. Caixa de di�logo. 1. Inform. Numa interface gr�fica, janela apresentada por programa para solicitar
			informa��es a serem fornecidas pelo usu�rio. Caixa de distribui��o. Tip. 1. Caixa seletora (q. v.). Caixa de emendas. Tip.
			1. Pequena caixa tipogr�fica onde se transporta o material necess�rio a emendas de m�quina; caixotim de corre��o. Caixa de
			entrada. Ind. Pap. 1. Recipiente que, constituindo o primeiro elemento da m�quina de papel, recebe a massa sa�da do
			depurador e a despeja, de modo regular e cont�nuo, sobre a mesa de fabrica��o, onde come�a a formar-se a folha. Caixa de
			escada. Arquit. 1. Espa�o ocupado por uma escada, desde o pavimento inferior at� o �ltimo pavimento; bomba. Caixa de
			espa�os. Tip. 1. Caixa de brancos. Caixa de gr�o. 1. C�mara de madeira usada no processo de gravura a �gua-tinta, e dentro
			da qual se faz circular resina em p�, que depois se deixa lentamente pousar sobre a placa, em camada mais ou menos
			rarefeita, para obten��o do meio-tom. Caixa de guerra. 1. V. caixa clara. 2. V. caixa de rufo. Caixa de marchas. Mec. 1.
			Conjunto de engrenagens que permitem a varia��o adequada das marchas de um ve�culo; caixa de mudan�as, caixa de c�mbio,
			caixa de velocidades: "Ent�o o 'Hudson' volveu a dar preju�zo, .... rebentava diariamente as c�maras-de-ar, .... a caixa
			de marchas estava desarranjada..." (Jorge de Lima, Salom�o e as Mulheres, p. 115.) Caixa de matrizes. Tip. 1. Caixilho
			m�vel de metal que encerra as matrizes da monotipo. Caixa de mudan�as. Mec. 1. V. caixa de marchas. Caixa de m�sica. 1.
			Instrumento mec�nico, geralmente de pequenas dimens�es, que, posto em movimento, executa uma ou mais melodias. Caixa de
			navalhas. Tip. 1. V. bloco de navalhas. Caixa de pesos. F�s. 1. Conjunto de pesos aferidos, destinados a servir de padr�es
			de compara��o nas pesadas, e que de ordin�rio s�o calibrados em massa. Caixa de reserva. Tip. 1. V. caixa de sobras. Caixa
			de resson�ncia. 1. Nos teatros e salas de concerto, espa�o vazio, em geral debaixo da orquestra, deixado pelos arquitetos
			para refor�o dos sons. 2. O corpo principal da maior parte dos instrumentos de corda. Caixa de rufo. 1. Tambor surdo de
			tipo m�dio e fuste mais alto que a caixa clara; caixa de guerra, tambor militar. Caixa de sobras. Tip. 1. Grande caixa
			tipogr�fica, que serve de dep�sito para reabastecimento das caixas comuns; caixa de sortes, caixa de reserva. Caixa de
			sorte. Tip. 1. V. caixa de sobras. Caixa de suc��o. Ind. Pap. 1. V. caixa aspirante. Caixa de teatro. Teatr. 1. V. palco
			(3). Caixa de transfer�ncia. Tip. 1. Parte da linotipo onde a linha de matrizes passa do primeiro para o segundo elevador.
			[V. caixa seletora.] Caixa de velocidades. Mec. 1. V. caixa de marchas. Caixa do catarro. Bras. Pop. 1. Os pulm�es. Caixa
			do expulsor. Tip. 1. Parte da linotipo onde se movem as l�minas que transferem ao gale�o as linhas fundidas. Caixa dois.
			Com. Ind. 1. Controle de recursos desviados da escritura��o legal, com o objetivo de soneg�-los � tributa��o fiscal. [Cf.
			economia invis�vel e contabilidade paralela.] Caixa do molde. Tip. 1. Abertura do molde das m�quinas compositoras, onde se
			fundem os tipos ou as linhas-blocos. Caixa do palco. Teatr. 1. V. bastidores (2). Caixa dos espa�adores. Tip. 1. Conjunto
			de pe�as da linotipo que recebem os espa�adores, coletados pela pin�a (8), e os transferem ao componedor. Caixa do teatro.
			Teatr. 1. V. palco (3). Caixa do t�mpano. Anat. 1. Em cada ouvido, a parte situada entre a membrana do t�mpano e a parede
			externa do labirinto. Caixa do tinteiro. Art. Gr�f. 1. A parte principal do tinteiro das prensas: esp�cie de calha
			met�lica dentro da qual gira um cilindro de a�o que distribui a tinta ao rolo tomador. Caixa econ�mica. 1. Estabelecimento
			banc�rio governamental, inicialmente concebido com o objetivo de captar pequenas poupan�as. 2. Turfe. G�r. Cavalo que
			chega seguidamente entre os primeiros colocados, levantando para seu propriet�rio boa soma de dinheiro em pr�mios. Caixa
			eletr�nico. 1. Designa��o popular do equipamento que, conectado a um sistema de computador, presta servi�os banc�rios a
			usu�rios atrav�s de comunica��o interativa; caixa autom�tico. [Geralmente fornece o saldo e dinheiro vivo e atualiza conta
			banc�ria.] Caixa grande. 1. V. bombo (1). Caixa pequena. Bras. 1. O total da moeda manual de uma firma, que � utilizado em
			emerg�ncias ou para gastos e compras de pequeno vulto. Caixa postal. 1. Pequena caixa ou nicho, com porta e chave, nas
			ag�ncias postais, onde se deposita a correspond�ncia destinada a pessoa, institui��o ou empresa locat�ria da caixa. [Sin.
			(lus.): apartado.] Caixa registradora. 1. V. m�quina registradora. Caixas de resson�ncia. E. Ling. 1. V. resson�ncia (5).
			Caixa seletora. Tip. 1. No distribuidor da linotipo, a parte onde se processa a passagem das matrizes do segundo elevador
			para os fusos distribuidores; caixa de distribui��o. [V. caixa de transfer�ncia.] Caixa surda. 1. V. tambor surdo. Caixa
			tor�cica. Anat. 1. Gaiola tor�cica (q. v.). Bater caixa. Bras. 1. Anunciar fato auspicioso. 2. Contar vantagens. De caixa
			alta. Bras. G�r. 1. Com muito dinheiro: Hoje pago tudo: estou de caixa alta. De caixa baixa. Bras. G�r. 1. Com pouco
			dinheiro: Agora ando de caixa baixa. Em caixa. 1. Diz-se de import�ncia monet�ria prontamente dispon�vel: dinheiro em
			caixa.
        */
		class Caixa: public Objeto {
			private:
				MapaHash<PacoteSelado*> Caixa::pPacotes;

			public:
				Caixa::Caixa();
				virtual Caixa::~Caixa();

				/**
				 * Adiciona os pacotes de uma caixa alheia
				 * a esta, substituindo (por padr�o) os
				 * pacotes desta.
				 * <p>
				 * Sempre que cab�vel prefira passar
				 * <b>false</b> para o par�metro substituindo
				 * porque � um fator de seguran�a adicional.
				 *
				 * @throws PacotesRepetidosExcecao
				 *         caso 'substituindo' seja false.
				 */
				virtual Caixa& Caixa::colocaPacotesDe(
						const Caixa&, bool substituindo = true);

				virtual Caixa& Caixa::coloca(
						const PacoteSelado&,
						bool substituindo = true);

				virtual const bool Caixa::haPacote(
						const Identificacao&) const;

				virtual const PacoteSelado& Caixa::pacote(
						const Identificacao&) const;

				virtual PacoteSelado& Caixa::pacote(
						const Identificacao&);

				virtual Caixa& Caixa::someComPacote(
						const Identificacao&);

				virtual Caixa& Caixa::esvazia();

				/**
				 * Uma lista de 'selos'
				 * que deve ser apagada
				 * de fora.
				 */
				virtual const Lista<Identificacao>*
						Caixa::selosDosPacotes() const;

				/**
				 * Informa��o adicional.
				 */
				virtual const int Caixa::quantosPacotes() const;

				// Objeto:
				virtual std::string Caixa::emString() const;
		};
	  }
	}
  }
}

#endif /* Caixa_h */
