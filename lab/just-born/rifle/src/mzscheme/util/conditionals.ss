(load "../little-error-control/little-error-control.ss")

; Verifica se n está entre a e b:
; (between n a b)
;
; Exemplos:
; (between 2 1 3) => #t
; (between 4 1 3) => #f
; (between 3 1 3) => #t
(define-syntax between?
  (syntax-rules ()
    ((between? n a b) (and (>= n a) (<= n b)))))

; Verifica se um número está dentro de um intervalo e, se sim, executa o corpo:
; (validate-range n a b corpo ...) ; a <= n <= b
;
; (validate-range 0 1 10 (display "oi") (display " tchau!"))
;     => (erro fora-do-intervalo "0 deveria estar entre 1 e 10")
;
; (validate-range 2 1 10 (display "oi") (display " tchau!"))
;     => oi tchau!
(define-syntax validate-range
  (syntax-rules ()
    ((valida-intervalo n a b) (between? n a b))
    ((valida-intervalo n a b body ...)
     (if (not (between? n a b))
         (make-error 'out-of-range
                    (string-append
                     (number->string n)
                     " must be between "
                     (number->string a) " and " (number->string b)))
         ;else
         (begin body ...)))))

