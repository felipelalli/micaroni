(define tabuleiro-velha
  #(#(- - -)
    #(- - -)
    #(- - -)))

(define jogada-atual 0)

(define
  (valida-jogada linha coluna)
  (cond ((or (< linha 0) (> linha 2)) #f)
        ((or (< coluna 0) (> coluna 2)) #f)
        (else #t)))

; retorna o próprio jogador caso seja verdadeiro
(define
  (verifica-em-posicao tabuleiro jogador linha coluna)
  (cond
    ((not (valida-jogada linha coluna)) #f)
    ((eq?
      (vector-ref
       (vector-ref tabuleiro linha) coluna) jogador) jogador)
    (else #f)))

(define
  (verifica-em-direcao
   tabuleiro jogador linha coluna dir-linha dir-coluna)
  (begin
    (if
     (not (valida-jogada linha coluna)) #t
     (and
      (verifica-em-posicao tabuleiro jogador linha coluna)
      (verifica-em-direcao
       tabuleiro jogador
       (+ linha dir-linha)
       (+ coluna dir-coluna) dir-linha dir-coluna)))))

(define
  verifica-tudo
  (lambda
      (jogador tabuleiro)
        (or
         (verifica-em-direcao tabuleiro jogador 0 0 1 1)
         (verifica-em-direcao tabuleiro jogador 0 2 1 -1)
         (verifica-em-direcao tabuleiro jogador 0 0 1 0)
         (verifica-em-direcao tabuleiro jogador 0 1 1 0)
         (verifica-em-direcao tabuleiro jogador 0 2 1 0)
         (verifica-em-direcao tabuleiro jogador 0 0 0 1)
         (verifica-em-direcao tabuleiro jogador 1 0 0 1)
         (verifica-em-direcao tabuleiro jogador 2 0 0 1))))

(define
  (ganhou? tabuleiro)
  (cond
   ((verifica-tudo 'x tabuleiro) 'x)
   ((verifica-tudo 'o tabuleiro) 'o)
   (else #f)))

(define
  (deu-velha? tabuleiro)
  (>= jogada-atual 9))

(define joga
  (lambda (tabuleiro jogador linha coluna)
    (cond
      ((not (valida-jogada linha coluna)) #f)
      (else
       (if (not
            (verifica-em-posicao tabuleiro '- linha coluna))
           #f
           (begin
             (vector-set!
              (vector-ref tabuleiro linha)
              coluna
              jogador)
             (set! jogada-atual (+ 1 jogada-atual))
             tabuleiro))))))

(define
  (exibe tabuleiro)
  (begin
    (display "\n1. ")
    (display (vector-ref tabuleiro 0))
    (display "\n2. ")
    (display (vector-ref tabuleiro 1))
    (display "\n3. ")    
    (display (vector-ref tabuleiro 2))))

(let inicio ((atual 'x))
  (exibe tabuleiro-velha)
  (if (not
       (joga tabuleiro-velha atual
             (begin
               (display "\nVez do jogador \"")
               (display atual)
               (display "\"\nLinha: ")
               (- (read) 1))
             (begin
               (display "Coluna: ")
               (- (read) 1))))
      (begin
        (display "Jogada inválida!")
        (inicio atual))
      (begin
        (let
            ((ganhou (ganhou? tabuleiro-velha))
             (velha (deu-velha? tabuleiro-velha)))
          (if (or ganhou velha)
              (cond
                (ganhou
                  (begin
                    (display "O jogador \"")
                    (display ganhou)
                    (display "\" ganhou o jogo!")))
                (velha
                  (begin
                    (display "Deu velha!"))))
              (inicio ; senao comeca de novo
               (cond
                 ((eq? atual 'x) 'o)
                 ((eq? atual 'o) 'x))))))))