(define vogais "aeiou")
(define consoantes "bcdfghjlmnpqrstvxz")
(define outros "kyw")
(define pontuacao "!.,:;?")
(define simbolos "@#$%&*()-+/|\\{}[]'\"<>")
(define numeros "1234567890")

; (define (make-counter)
;   (let ((count 0))
;     (lambda ()
;       (set! count (+ count 1))
;       count)))  ; exemplo de closure!!

(define
  (trata-ch ch1 ch2)
  (integer->char (+ (char->integer ch1) (char->integer ch2))))
  
(define gatimonha2
  (lambda (texto senha p)
    (if (eq? texto '()) '()
        (cons
         (trata-ch (car texto) (string-ref senha p))
         (gatimonha2 (cdr texto) senha
                     (if (= p (- (string-length senha) 1))
                         0 (+ 1 p)))))))
  
(define gatimonha
  (lambda (texto senha)
    (list->string
     (gatimonha2 (string->list texto) senha 0))))

(gatimonha "bla blu" "pato")