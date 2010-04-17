package br.edu.unianhanguera.cc.jogodavelha;

/**
 * � invocada quando a jogada � feita fora do tabuleiro
 * ou sobre algu�m que j� exista.
 */
public class JogadaInvalida extends Exception {
    public JogadaInvalida(String mensagem) {
        super(mensagem);
    }
}
