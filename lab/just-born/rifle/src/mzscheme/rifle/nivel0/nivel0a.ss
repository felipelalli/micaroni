(load "../../little-type/little-type.ss")

(define-syntax nivel0a?
  (syntax-rules ()
    ((nivel0a? obj)
     (little-object obj is? 'nivel0a))))

(define-syntax string->nivel0a
  (syntax-rules ()
    ((string->nivel0a str)
     (if (not (string? str))
         #f (make-little-object 'nivel0a str)))))

(define-syntax nivel0a->string
  (syntax-rules ()
    ((nivel0a->string obj)
     (if (not (nivel0a? obj))
         #f (content-of obj)))))