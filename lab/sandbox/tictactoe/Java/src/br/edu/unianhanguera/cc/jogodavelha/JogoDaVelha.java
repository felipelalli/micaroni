package br.edu.unianhanguera.cc.jogodavelha;

/**
 * É possível derivar desta classe para criar
 * outro tipo de regra para o jogo da velha.
 */
public class JogoDaVelha {
    private Tabuleiro tabuleiro;
    private Jogador vezDe;
    private int jogada = 0;
    
    public JogoDaVelha() {
        this.tabuleiro = new Tabuleiro(3);
        this.vezDe = Jogador.X;
    }

    public Resultado joga(int linha, int coluna) throws JogadaInvalida {
        this.getTabuleiro().coloca(this.getVezDe(), linha, coluna);
        this.jogada++;
        Resultado resultado = Resultado.NADA_ACONTECEU;
        
        boolean ganhou
                 = this.ganhou(0, 0, 1, 1) // diagonal principal
                || this.ganhou(0, 2, 1, -1) // diagonal invertida
                || this.ganhou(0, 0, 1, 0) // coluna 0
                || this.ganhou(0, 1, 1, 0) // coluna 1
                || this.ganhou(0, 2, 1, 0) // coluna 2
                || this.ganhou(0, 0, 0, 1) // linha 0
                || this.ganhou(1, 0, 0, 1) // linha 1
                || this.ganhou(2, 0, 0, 1); // linha 2

        if (ganhou) {
            resultado = Resultado.GANHOU;
        } else { // verifica se deu velha
            int tam = this.getTabuleiro().getTamanho();

            if (this.jogada >= (tam * tam)) {
                resultado = Resultado.DEU_VELHA;
            }
        }
        
        if (this.getVezDe().equals(Jogador.X)) {
            this.vezDe = Jogador.O;
        } else {
            this.vezDe = Jogador.X;
        }
        
        return resultado;
    }
    
    public Jogador getVezDe() {
        return vezDe;
    }

    public Tabuleiro getTabuleiro() {
        return tabuleiro;
    }

    /**
     * Faz a verificação de um determinado ponto
     * do tabuleiro, andando de passo-a-passo até
     * o fim do tabuleiro.
     * 
     * @param linhaInicial por onde começará o teste
     * @param colunaInicial por onde começará o teste
     * @param passoLinha pode ser 0, +1 ou -1
     * @param passoColuna pode ser 0, +1 ou -1
     * @return se ganhou ou não
     */
    private boolean ganhou(
            int linhaInicial, int colunaInicial,
            int passoLinha, int passoColuna)
    {       
        boolean ganhou = true;
        boolean terminou = false;
        int tamanho = this.getTabuleiro().getTamanho();

        int linha = linhaInicial;
        int coluna = colunaInicial;
        
        // Verifica diagonal principal:
        while (ganhou && !terminou) {
           
            Jogador elemento = this.tabuleiro
                    .pegaPelaPosicao(linha, coluna);
            
            if (!elemento.equals(this.getVezDe())) {
                ganhou = false;
            }

            linha += passoLinha;
            coluna += passoColuna;

            // se já saiu do tabuleiro é porque terminou
            if (linha >= tamanho || coluna >= tamanho
                || linha < 0 || coluna < 0)
            {
                terminou = true;
            }
        }
        
        return ganhou;
    }

}
