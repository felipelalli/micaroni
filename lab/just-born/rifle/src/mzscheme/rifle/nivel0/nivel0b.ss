(load "../../util/table-true.ss")
(load "../../little-type/little-type.ss")

(define-syntax simbolo-IPA?
  (syntax-rules ()
    ((simbolo-IPA? ch)
     (let
         ((simbolos-possiveis
           (make-immutable-hash-table
            (str->assoc
             (letrec
                 (
                  (numbers->string
                   (lambda (list-of-numbers)
                     (if (null? list-of-numbers)
                         "" (string-append
                             (string (integer->char (car list-of-numbers)))
                             (numbers->string (cdr list-of-numbers))))))

                  (simbolos-IPA (load "ipa.dat")))

               (numbers->string simbolos-IPA))))))

       (if (not (char? ch))
         #f (hash-table-get
             simbolos-possiveis
             (char->integer ch) #f))))))

(define string-IPA?
  (lambda (string)
    (if (= (string-length string) 0)
        #t
        (and
         (simbolo-IPA? (string-ref string 0))
         (string-IPA? (substring string 1 (string-length string)))))))

(define-syntax nivel0b?
  (syntax-rules ()
    ((nivel0b? obj)
     (little-object obj is? 'nivel0b))))

(define-syntax string->nivel0b
  (syntax-rules ()
    ((string->nivel0a str)
     (if (not (string? str))
         #f
         (if (not (string-IPA? str))
             #f                  
             (make-little-object 'nivel0a str))))))

(define-syntax nivel0b->string
  (syntax-rules ()
    ((nivel0b->string obj)
     (if (not (nivel0b? obj))
         #f (content-of obj)))))

