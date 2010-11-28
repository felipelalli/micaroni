(load "../util/TODO.ss")
(load "../util/conditionals.ss")

; Deve ser usado assim:
; (cria-nivel 0a)
; (cria-nivel 0b)
; (cria-nivel 0)
; (cria-nivel 1)
; (cria-nivel 2)

(define-syntax cria-nivel
  (syntax-rules (0a 0b)
    ((cria-nivel 0a)
     (TODO "a fazer nível 0a"))

    ((cria-nivel 0b)
     (TODO "a fazer nível 0b"))

    ((cria-nivel n)
     (validate-range
      n 0 2
      (case n
        ((0) (TODO "a fazer nível 0"))
        ((1) (TODO "a fazer nível 1"))
        ((2) (TODO "a fazer nível 2")))))


    ))


(define n0a
  (cria-nivel 0a))
