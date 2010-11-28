(load "../little-error-control/little-error-control.ss")

;(append-with-dot "a" "b" "c" "d") => "a.b.c.d"
(define append-with-dot
  (lambda a
    (if (null? (cdr a))
        (car a)
        (string-append (car a) "."
                       (eval `(append-with-dot ,@(cdr a)))))))

; (label "a") => "a"
; (label 10) => "10"
; (label "a" "b" "c") => "a.b.c"
; (label '("a" "b" "c")) => "a.b.c"
; (equal? (label "a" "b") "a.b") => #t
(define-syntax label
  (syntax-rules ()
    ((label a)
     (if (number? a)
         (number->string a)
         (if (list? a)
             (eval `(label ,@a))
             (if (string? a)
                 a (make-error 'invalid-label)))))
    ((label a ...)
     (append-with-dot a ...))))    

; Verifica se é um label
(define-syntax label?
  (syntax-rules ()
    ((label? a) (not (error? (label a))))))

;(validate-label label body ...)
(define-syntax validate-label
  (syntax-rules ()
    ((validate-label label body ...)
     (if (not (label? label))
         (make-error 'unexpected-param "label is expected")
         body ...))))
