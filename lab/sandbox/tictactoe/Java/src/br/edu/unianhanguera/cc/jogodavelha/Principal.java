package br.edu.unianhanguera.cc.jogodavelha;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Principal {
    public static void main(String[] args) {
        boolean saiu = false;
        JogoDaVelha jogo = new JogoDaVelha();

        BufferedReader br = new BufferedReader(
                new InputStreamReader(System.in));        
        
        int linha, coluna;
        
        while (!saiu) {
            boolean erro;
            
            do {
                String vezDe = jogo.getTabuleiro()
                            .jogadorEmString(jogo.getVezDe());
                
                jogo.getTabuleiro().exibeEmASCII();
                System.out.println("\nVez de: " + vezDe);
                
                erro = false;
                
                try {
                    System.out.print("Digite a linha (1-3): ");
                    String s = br.readLine();
                    linha = Integer.parseInt(s);

                    System.out.print("Digite a coluna (1-3): ");
                    s = br.readLine();
                    coluna = Integer.parseInt(s);            

                    Resultado r = jogo.joga(linha-1, coluna-1);

                    if (r.equals(Resultado.GANHOU)) {
                        jogo.getTabuleiro().exibeEmASCII();
                        System.out.println(vezDe + " ganhou o jogo!");
                        saiu = true;
                    } else if (r.equals(Resultado.DEU_VELHA)) {
                        jogo.getTabuleiro().exibeEmASCII();
                        System.out.println("Deu velha!");
                        saiu = true;                        
                    }
                } catch (JogadaInvalida e) {
                    System.err.println("Jogada inválida: " + e.getMessage());
                    erro = true;
                } catch (Exception e) {
                    e.printStackTrace();
                }
            } while (erro);
        }
    }
}
