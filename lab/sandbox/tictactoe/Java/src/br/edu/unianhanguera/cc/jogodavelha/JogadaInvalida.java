package br.edu.unianhanguera.cc.jogodavelha;

/**
 * É invocada quando a jogada é feita fora do tabuleiro
 * ou sobre alguém que já exista.
 */
public class JogadaInvalida extends Exception {
    public JogadaInvalida(String mensagem) {
        super(mensagem);
    }
}
