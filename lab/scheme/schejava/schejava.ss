#lang r6rs

(import (rnrs base)
        (rnrs io simple))

; see EXAMPLE on bottom of this source code
; TODO: make levels (to indent code)
(define java-code
  (lambda args
    (if (null? args)
        "" (string-append
            (car args)
            (apply java-code (cdr args))))))

(define body
  (lambda args
    (apply java-code args)))

; AUX
; (name oi tchau) => "oitchau"
(define-syntax name
  (syntax-rules ()
    ((_ x ...)
     (java-code (symbol->string 'x) ...))))

; AUX
; (separate-by-comma "a" "b" "c") => "a, b, c"
(define separate-by-comma
  (lambda ii
    (if (null? ii)
        "" (java-code
            (car ii)
            (if (null? (cdr ii))
                "" (java-code
                    ", " (apply separate-by-comma
                                (cdr ii))))))))

; (package (name br.eti.fml.petromass))
(define package
  (lambda (name)
    (java-code
     "package "
     name ";"
     (string #\newline #\newline))))

;(import (name br.eti.fml.lock.LockServer)
;        (name br.eti.fml.petromass.io.PetroMassIODefault)
;        (name br.eti.fml.petromass.ui.JMain))
(define import
  (lambda names
    (java-code
     (if (null? names)
         (string #\newline)
         (java-code
          "import "
          (car names) ";"
          (string #\newline)
          (apply import (cdr names)))))))

; (main body ...)
(define-syntax main
  (syntax-rules ()
    ((_ body ...)
     (java-code
      "public static void main(String[] args) {"
      body ...
      "}"))))

;(class public Main
;  (java-code body ...))
;
;(class public Main implements (NoObfuscation Aba)
;  (java-code body ...))
;
;(class public Main extends Object
;  (java-code body ...))
;
;(class public Main implements (NoObfuscation Aba) extends Object
;  (java-code body ...))
(define-syntax class
  (syntax-rules (implements extends)
    ((_ level Name body) ; ommit all
     (class level Name implements () extends Object body))
    ((_ level Name implements (interfaces ...) body) ; ommit extends
     (class level Name implements (interfaces ...) extends Object body))
    ((_ level Name extends X body) ; ommit implements
     (class level Name implements () extends X body))
    ((_ level Name implements (interfaces ...) extends X body) ; all
     (letrec         
          ((java-implements
           (lambda ii
             (if (null? ii)
                 "" (java-code
                     " implements "
                     (apply separate-by-comma ii)))))
          
          (java-extends
           (lambda (cc)
             (java-code " extends " cc))))

       (java-code
        (name level)
        " " (name Name)
        (java-implements (name interfaces) ...)
        (java-extends (name X))
        " {"
        (string #\newline)
        body
        (string #\newline)
        "}")))))

;; EXAMPLE

(display
 (java-code
  (package (name br.eti.fml.petromass))
  (import (name br.eti.fml.lock.LockServer)
          (name br.eti.fml.petromass.io.PetroMassIODefault)
          (name br.eti.fml.petromass.ui.JMain))
  (class public Main implements (NoObfuscation Aba)
    (body
     (main)))))
