/*
 * $RCSfile: Caixa.h,v $
 * $Date: 2004/02/26 18:49:18 $
 * $Revision: 1.7 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
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
		 * Uma caixa contém vários pacotes selados.
		 * Esta caixa guarda referências para pacotes
		 * selados que devem ser criados/deletados
		 * de fora. Esta classe não pode se responsabilizar
		 * por esse controle de memória porque caixas
		 * diferentes podem conter o mesmo pacote selado.
		 * <p>
		 * Escolheu-se o nome "caixa" por se entender
		 * que geralmente uma "caixa" é maior que um "pacote" e
		 * neste caso específico uma Caixa contém diversos Pacotes.
		 * <p>
		 * Do dicionário Aurélio:
		 *  <p>
			<b>pacote</b> . [Dim. de paca1 (q. v.).] S. m. 1. Pequeno maço ou pequeno embrulho: um pacote de dinheiro; um pacote de papel
			pardo. 2. O conjunto de unidades contidas num pacote (1): Um pacote de cigarros contém dez maços. 3. P. ext. Bras.
			Qualquer coisa semelhante a pacote (1); combinação de elementos que se relacionam, e que são tomados como um todo: Os
			agentes de viagem oferecem excelente pacote para férias na Bahia. 4. Fig. Logro, embuste, engano. 5. Market. Conjunto de
			itens relacionados, como, p. ex., programas de TV ou serviços turísticos, comercializados como um todo, usualmente com
			desconto. 6. Bras. Grande quantidade de mercadoria negociada em conjunto e, ger., em transação vultosa. 7. Bras. Pop.
			Conjunto de medidas governamentais, sobretudo na área econômica, adotadas simultaneamente: Espera-se para amanhã novo
			pacote na área econômica. 8. Inform. Bloco de informação preparado para trafegar numa rede de computadores, com um
			cabeçalho que identifica a sua origem e o seu destino; datagrama. [Cf. comutação de pacotes.] ~ V. pacotes. Pacote de
			ondas. Fís. 1. Conjunto finito de ondas que transporta energia de um para outro ponto do espaço; grupo de onda, trem de
			onda. Ir no pacote. Bras. Gír. 1. Ser enganado; deixar-se lograr.
			<p>
		    <b>caixa</b> . [Do lat. capsa , pelo cat. caixa.] S. f. 1. Recipiente ou receptáculo de madeira, papelão, metal, ou outro
			material, com tampa ou sem ela, com faces geralmente retangulares ou quadradas, como uma arca, um cofre, um estojo, etc.
			[Aum. irreg.: caixão; dim. irreg.: caixeta, caixote, caixola.] 2. O conteúdo de uma caixa: Tomou uma caixa de injeções. 3.
			Peça ou objeto que resguarda ou contém outra peça ou objeto: caixa de marchas; caixa de engrenagens. 4. Seção de bancos,
			casas comerciais, repartições públicas, etc., destinada a efetuar pagamentos ou recebimentos de dinheiro, cheques,
			valores, etc. 5. P. ext. Local onde trabalha o encarregado dessas operações. 6. Cont. Título da conta que registra o
			movimento de dinheiro. 7. Econ. Disponibilidade em dinheiro; encaixe: A empresa aplica seus excedentes de caixa no mercado
			financeiro. 8. Eng. Parte da estrada onde se lança a brita. 9. Jur. Com. Armador-gerente. 10. Designação comum a vários
			instrumentos de percussão do gênero tambor (q. v.): O menino tocava caixa na banda do colégio. 11. Teatr. V. palco (3).
			12. Tip. Cada uma das gavetas do cavalete, divididas horizontalmente em duas seções (caixa alta e caixa baixa),
			subdividindo-se estas em vários caixotins, onde se distribuem os tipos, separados por sortes. 13. V. caixote (3). 14. Lus.
			Edit. Boxe (6). • S. m. 15. Livro comercial auxiliar onde se registram entradas e saídas de dinheiro. • S. 2 g. 16. Pessoa
			que tem a seu cargo a caixa (4). [Cf. cacha, do v. cachar e s. f., e caxa.] Caixa acústica. 1. Eletrôn. Sonofletor (q.
			v.). Caixa alta. Tip. 1. Seção superior da caixa tipográfica, em cujos caixotins se distribuem as letras maiúsculas. [Cf.
			caixa-alta.] Caixa aspirante. Ind. Pap. 1. Cada um dos aparelhos colocados por baixo da tela da máquina de papel, para
			apressar, por meio de sucção, a secagem da folha; caixa de sucção, caixa-bomba. Caixa automático. 1. V. caixa eletrônico.
			Caixa baixa. Tip. 1. Seção inferior da caixa tipográfica, em cujos caixotins se distribuem as letras minúsculas. [Cf.
			caixa-baixa.] Caixa cega. Tip. 1. A que não tem subdivisões, usada para guardar clichês ou tipos de grande corpo. Caixa
			chata. 1. V. tarol. Caixa clara. 1. Tambor (3) de fuste médio, com bordões na membrana inferior, o que lhe confere uma
			sonoridade vibrante, e cujo registro (contralto ou soprano) depende das dimensões do instrumento; caixa de guerra, tambor
			de guerra. [Cf. tarol.] Caixa craniana. Anat. 1. Porção óssea da cabeça que contém o encéfalo. Caixa das almas. 1. Pequeno
			cofre, nas igrejas ou noutros locais, onde se depositam esmolas. Caixa de ar. 1. Espaço ventilado que fica entre o solo e
			o soalho de um edifício; porão. Caixa de brancos. Tip. 1. Caixa tipográfica para guardar espaçaria; caixa de espaços.
			Caixa de cambas. Tip. 1. Parte da linotipo onde fica o conjunto das cambas que acionam o mecanismo de escape. Caixa de
			câmbio. Mec. 1. V. caixa de marchas. Caixa de cena. Teatr. 1. V. palco (3). Caixa de descarga. 1. Pequeno depósito,
			embutido ou simplesmente fixado na parede, ou apoiado no aparelho sanitário, e destinado à retenção da água da lavagem das
			bacias de privadas. Caixa de diálogo. 1. Inform. Numa interface gráfica, janela apresentada por programa para solicitar
			informações a serem fornecidas pelo usuário. Caixa de distribuição. Tip. 1. Caixa seletora (q. v.). Caixa de emendas. Tip.
			1. Pequena caixa tipográfica onde se transporta o material necessário a emendas de máquina; caixotim de correção. Caixa de
			entrada. Ind. Pap. 1. Recipiente que, constituindo o primeiro elemento da máquina de papel, recebe a massa saída do
			depurador e a despeja, de modo regular e contínuo, sobre a mesa de fabricação, onde começa a formar-se a folha. Caixa de
			escada. Arquit. 1. Espaço ocupado por uma escada, desde o pavimento inferior até o último pavimento; bomba. Caixa de
			espaços. Tip. 1. Caixa de brancos. Caixa de grão. 1. Câmara de madeira usada no processo de gravura a água-tinta, e dentro
			da qual se faz circular resina em pó, que depois se deixa lentamente pousar sobre a placa, em camada mais ou menos
			rarefeita, para obtenção do meio-tom. Caixa de guerra. 1. V. caixa clara. 2. V. caixa de rufo. Caixa de marchas. Mec. 1.
			Conjunto de engrenagens que permitem a variação adequada das marchas de um veículo; caixa de mudanças, caixa de câmbio,
			caixa de velocidades: "Então o 'Hudson' volveu a dar prejuízo, .... rebentava diariamente as câmaras-de-ar, .... a caixa
			de marchas estava desarranjada..." (Jorge de Lima, Salomão e as Mulheres, p. 115.) Caixa de matrizes. Tip. 1. Caixilho
			móvel de metal que encerra as matrizes da monotipo. Caixa de mudanças. Mec. 1. V. caixa de marchas. Caixa de música. 1.
			Instrumento mecânico, geralmente de pequenas dimensões, que, posto em movimento, executa uma ou mais melodias. Caixa de
			navalhas. Tip. 1. V. bloco de navalhas. Caixa de pesos. Fís. 1. Conjunto de pesos aferidos, destinados a servir de padrões
			de comparação nas pesadas, e que de ordinário são calibrados em massa. Caixa de reserva. Tip. 1. V. caixa de sobras. Caixa
			de ressonância. 1. Nos teatros e salas de concerto, espaço vazio, em geral debaixo da orquestra, deixado pelos arquitetos
			para reforço dos sons. 2. O corpo principal da maior parte dos instrumentos de corda. Caixa de rufo. 1. Tambor surdo de
			tipo médio e fuste mais alto que a caixa clara; caixa de guerra, tambor militar. Caixa de sobras. Tip. 1. Grande caixa
			tipográfica, que serve de depósito para reabastecimento das caixas comuns; caixa de sortes, caixa de reserva. Caixa de
			sorte. Tip. 1. V. caixa de sobras. Caixa de sucção. Ind. Pap. 1. V. caixa aspirante. Caixa de teatro. Teatr. 1. V. palco
			(3). Caixa de transferência. Tip. 1. Parte da linotipo onde a linha de matrizes passa do primeiro para o segundo elevador.
			[V. caixa seletora.] Caixa de velocidades. Mec. 1. V. caixa de marchas. Caixa do catarro. Bras. Pop. 1. Os pulmões. Caixa
			do expulsor. Tip. 1. Parte da linotipo onde se movem as lâminas que transferem ao galeão as linhas fundidas. Caixa dois.
			Com. Ind. 1. Controle de recursos desviados da escrituração legal, com o objetivo de sonegá-los à tributação fiscal. [Cf.
			economia invisível e contabilidade paralela.] Caixa do molde. Tip. 1. Abertura do molde das máquinas compositoras, onde se
			fundem os tipos ou as linhas-blocos. Caixa do palco. Teatr. 1. V. bastidores (2). Caixa dos espaçadores. Tip. 1. Conjunto
			de peças da linotipo que recebem os espaçadores, coletados pela pinça (8), e os transferem ao componedor. Caixa do teatro.
			Teatr. 1. V. palco (3). Caixa do tímpano. Anat. 1. Em cada ouvido, a parte situada entre a membrana do tímpano e a parede
			externa do labirinto. Caixa do tinteiro. Art. Gráf. 1. A parte principal do tinteiro das prensas: espécie de calha
			metálica dentro da qual gira um cilindro de aço que distribui a tinta ao rolo tomador. Caixa econômica. 1. Estabelecimento
			bancário governamental, inicialmente concebido com o objetivo de captar pequenas poupanças. 2. Turfe. Gír. Cavalo que
			chega seguidamente entre os primeiros colocados, levantando para seu proprietário boa soma de dinheiro em prêmios. Caixa
			eletrônico. 1. Designação popular do equipamento que, conectado a um sistema de computador, presta serviços bancários a
			usuários através de comunicação interativa; caixa automático. [Geralmente fornece o saldo e dinheiro vivo e atualiza conta
			bancária.] Caixa grande. 1. V. bombo (1). Caixa pequena. Bras. 1. O total da moeda manual de uma firma, que é utilizado em
			emergências ou para gastos e compras de pequeno vulto. Caixa postal. 1. Pequena caixa ou nicho, com porta e chave, nas
			agências postais, onde se deposita a correspondência destinada a pessoa, instituição ou empresa locatária da caixa. [Sin.
			(lus.): apartado.] Caixa registradora. 1. V. máquina registradora. Caixas de ressonância. E. Ling. 1. V. ressonância (5).
			Caixa seletora. Tip. 1. No distribuidor da linotipo, a parte onde se processa a passagem das matrizes do segundo elevador
			para os fusos distribuidores; caixa de distribuição. [V. caixa de transferência.] Caixa surda. 1. V. tambor surdo. Caixa
			torácica. Anat. 1. Gaiola torácica (q. v.). Bater caixa. Bras. 1. Anunciar fato auspicioso. 2. Contar vantagens. De caixa
			alta. Bras. Gír. 1. Com muito dinheiro: Hoje pago tudo: estou de caixa alta. De caixa baixa. Bras. Gír. 1. Com pouco
			dinheiro: Agora ando de caixa baixa. Em caixa. 1. Diz-se de importância monetária prontamente disponível: dinheiro em
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
				 * a esta, substituindo (por padrão) os
				 * pacotes desta.
				 * <p>
				 * Sempre que cabível prefira passar
				 * <b>false</b> para o parâmetro substituindo
				 * porque é um fator de segurança adicional.
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
				 * Informação adicional.
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
