(load "../util/quicksort.ss")

; Tipo de retorno:

;(append
; (append (list "Time" PG J V SG GP)     ; rodada 1
;         (list "Time2" PG J V SG GP))
; (append (list ...))                    ; rodada 2
; )

(define rodada
  (lambda (numero jogos)
    numero))

(define campeonato
  (lambda rodadas
    rodadas))

(define jogos
  (lambda jogos
    jogos))

(define-syntax cronometra
  (syntax-rules ()
    ((cronometra oque)
     (let
         ((inicio (current-inexact-milliseconds)))
       oque
       (- (current-inexact-milliseconds) inicio)))))
                        

; (list (list TIME PG J V SG GP) (list TIME2 PG J V SG GP))
(define jogo
  (lambda (time1 gols1 time2 gols2)
    (let
        ((vitoria
          (lambda (gols1 gols2)
            (if (> gols1 gols2) 1 0)))
         (pontos
          (lambda (gols1 gols2)
            (if (< gols1 gols2) 0 (if (= gols1 gols2) 1 3)))))

      (list
       (list time1 (pontos gols1 gols2)
             1 (vitoria gols1 gols2)
             (- gols1 gols2) gols1)
       (list time2 (pontos gols2 gols1)
             1 (vitoria gols2 gols1)
             (- gols2 gols1) gols2)))))

(let
    ((JUV "Juventus")
     (NOR "Noroeste")
     (AAPP "Ponte Preta")
     (ITU "Ituano")
     (RC "Rio Claro")
     (PAU "Paulista")
     (MIR "Mirassol")
     (BAR "Barueri")
     (POR "Portuguesa")
     (SAN "Santos")
     (RP "Rio Preto")
     (SC "São Caetano")
     (PAL "Palmeiras")
     (SER "Sertãozinho")
     (GUARA "Guaratinguetá")
     (SPFC "São Paulo")
     (COR "Corinthians")
     (GUARANI "Guarani")
     (BRA "Bragantino")
     (MAR "Marília"))

  (campeonato
   (rodada 1
           (jogos
            (jogo JUV 1 NOR 1)
            (jogo AAPP 4 ITU 2)
            (jogo RC 2 PAL 0)
            (jogo MIR 2 BAR 1)
            (jogo POR 2 SAN 0)
            (jogo RP 2 SC 2)
            (jogo PAL 3 SER 1)
            (jogo GUARA 1 SPFC 2)
            (jogo COR 3 GUARANI 0)
            (jogo BRA 0 MAR 2)))
   (rodada 2
           (jogos
            (jogo BAR 2 RC 0)
            (jogo ITU 1 POR 0)
            (jogo PAL 1 AAPP 2)
            (jogo SER 2 MIR 0)
            (jogo SAN 0 PAL 0)
            (jogo SPFC 1 RP 0)
            (jogo NOR 0 GUARA 1)
            (jogo GUARANI 0 BRA 2)
            (jogo MAR 4 JUV 0)
            (jogo SC 3 COR 1)))
   )
)
