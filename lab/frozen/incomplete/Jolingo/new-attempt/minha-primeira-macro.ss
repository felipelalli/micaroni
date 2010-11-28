;(define-syntax banana
;  (syntax-rules (cu)
;    ((banana) "verde!")
;    ((banana p) (if (number? p) (+ 1 p) (display p)))
;    ((banana a b (cu) c)
;     (+ a b c))
;    ((banana a b ...)
;     (begin (display (* a b ...)) (display " ") (banana a 0 (cu) 0)))))

;(define-syntax banana
;  (syntax-rules (cu buça)
;    ((banana) "verde!")
;    ((banana cu a b ...) "bu bu bundão!")
;    ((banana buça a b ...) "buceta!")    
;    ((banana a) (if (number? a) 'number 'not-number ))
;    ((banana a b) (list (banana a) (banana b)))
;    ((banana a b ...) (cons (banana a) (banana b ...)) )
;    ))

(define-syntax banana
  (syntax-rules ()
    ((banana (a b c) ...) (list (+ a ...) (+ b ...) (+ c ...)) )
    ))

;mapa:
(assv 'b '((a . 3) (b . 7) (c . 13)))

