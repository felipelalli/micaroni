;(define-syntax banana
;  (syntax-rules (zu maçã)
;    ((banana) "verde!")
;    ((banana zu a b ...) "zu zu zulu!")
;    ((banana maçã a b ...) "maçã!")    
;    ((banana a) (if (number? a) 'number 'not-number ))
;    ((banana a b) (list (banana a) (banana b)))
;    ((banana a b ...) (cons (banana a) (banana b ...)) )
;    ))

(define-syntax import-expand
  (syntax-rules ()
    ((import-expand a b ...) (list (quote a) (quote b) ...))))

(define-syntax import
  (syntax-rules (body)
    ((import (a b ...) (body c d ...))
     (list 'load-classes
           (list
            (import-expand a b ...))
           (begin c d ...)))))

(import
   ('(br com proj Class1)
     '(br com proj Class2)
     '(br com util *)
     '(br com jaba baba Class3))
   (body 'corpo))

