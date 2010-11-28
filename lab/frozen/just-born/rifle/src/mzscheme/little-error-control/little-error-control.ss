; Bom para ser usado somente em controle interno de erro, ou seja, como debug

(load "../little-type/little-type.ss")

(define NO_MESSAGE_ERROR "<no message>")

;(make-error 'error-name "message")
(define-syntax make-error
  (syntax-rules ()
    ((make-error error-name)
     (make-little-object 'error error-name NO_MESSAGE_ERROR))
    ((make-error error-name message)
     (make-little-object 'error error-name message))))

;(error? obj)
(define-syntax error?
  (syntax-rules ()
   ((error? obj)
    (little-object obj is? 'error))))

; veja validate
(define validate-in-loop
  (lambda l
    (let ((cabeca (force (car l))))
      (if (error? cabeca)
          cabeca
          (if (null? (cdr l))
              #t
              (eval `(validate-in-loop ,@(cdr l))))))))

; e.g.: (validate (boolean? #t) (pair? (cons 'a 'b)) (boolean? 10)) ; para muitas verificações
; e.g.: (validate boolean? #t) ; quando é um só valor!
; retorna um little-type de 'unexpected-param caso tenha ocorrido algum erro ou #t caso tenha corrido tudo bem
(define-syntax validate
  (syntax-rules ()
    ((validate function obj)
     (if (function obj) #t
         (make-error 'unexpected-parameter
                     (string-append (symbol->string 'function) " is expected"))))     
    ((validate (function obj))
     (if (function obj) (delay #t)
         (delay (make-error 'unexpected-parameter
                     (string-append (symbol->string 'function) " is expected")))))
    ((validate (function obj) ...)
      (validate-in-loop (validate (function obj)) ...))))
