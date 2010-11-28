; converte uma string tipo "abc" em uma assoc list, tipo "((10 . #t) (20 . #t) (30 . #t))"
; o número 10, 20 e 30 seriam o código de a, b e c.
(define str->assoc
  (lambda (st)
    (letrec
        (
         (lista '())

         (ch->assoc
          (lambda (ch)
            `(,(char->integer ch) . #t)))

         (str->assoc-ls
          (lambda (str)
            (str->assoc-k str 0)
            lista))

         (str->assoc-k
          (lambda (str k)
            (set! lista (append lista (list (ch->assoc (string-ref str k)))))
            (if (< k (- (string-length str) 1))
                (str->assoc-k str (+ 1 k)))))
         )

      (str->assoc-ls st))))

; Exemplo de uso:

;(define letras
;  (make-immutable-hash-table
;     (str->assoc (string-append
;          "abcdefghijklmnopqrstuvwxyz"
;          "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
;          "áàâãäéèêëẽíìîïóòôõöúùûũü"
;          "ÁÁÂÃÄÉÈÊËÊÍÌÎÏÓÒÔÕÖÚÙÛŨÜ"
;          "çÇñÑ-"))
;   ))

; (if (hash-table-get letras (char->integer ch) #f) ...)