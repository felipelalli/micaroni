package br.edu.unianhanguera.cc.jogodavelha;

public class Tabuleiro {
    private Jogador[][] tabuleiro;

    public Tabuleiro(int tamanho) {
        this.tabuleiro = new Jogador[tamanho][tamanho];
        this.zera();
    }

    public void exibeEmASCII() {
        for (int linha = 0; linha < this.getTamanho(); linha++) {
            System.out.print((linha + 1) + ": ");
            
            for (int coluna = 0; coluna < this.getTamanho(); coluna++) {
                System.out.print("["
                        + this.jogadorEmString(
                            this.pegaPelaPosicao(linha, coluna)) + "]");
            }   

            System.out.println();
        }
    }
    
    public Jogador pegaPelaPosicao(int linha, int coluna) {
        return this.tabuleiro[linha][coluna];
    }
    
    public int getTamanho() {
        return this.tabuleiro.length;
    }

    public String jogadorEmString(Jogador j) {
        if (j.equals(Jogador.O)) {
            return "O";
        } else if (j.equals(Jogador.X)) {
            return "X";
        } else {
            return " ";
        }
    }
    
    private void zera() {
        for (int linha = 0; linha < this.getTamanho(); linha++) {
            for (int coluna = 0; coluna < this.getTamanho(); coluna++) {
                this.tabuleiro[linha][coluna] = Jogador.VAZIO;
            }
        }
    }

    /**
     * Coloca numa determinada posição verificando apenas
     * se está dentro do tabuleiro e se não há alguma jogada
     * no mesmo local. Não faz verificação de ganhador.
     * 
     * @param j Qual jogador
     * @see RegrasDaVelha
     */
    public void coloca(Jogador j, int linha, int coluna)
            throws JogadaInvalida
    {
        if (linha >= this.getTamanho() || linha < 0
            || coluna >= this.getTamanho() || coluna < 0)
        {
            throw new JogadaInvalida("Fora do tabuleiro");
        }
        
        Jogador atual = this.pegaPelaPosicao(linha, coluna);
        
        if (!atual.equals(Jogador.VAZIO)) {
            throw new JogadaInvalida("Já existe uma jogada neste local");
        } else {
            this.tabuleiro[linha][coluna] = j;
        }
    }
}
