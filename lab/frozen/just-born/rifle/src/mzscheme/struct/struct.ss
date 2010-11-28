(load "../little-error-control/little-error-control.ss")

; (new-struct 'nome-do-tipo)
(define-syntax new-struct
  (syntax-rules ()
    ((new-struct type-name)
     (make-little-object type-name (make-hash-table)))))

; (set-value! struct 'field value)
(define-syntax set-value!
  (syntax-rules ()
    ((set struct field value)
       (hash-table-put! (car (cdr struct)) field value))))

; (get-value struct 'field value)
(define-syntax get-value
  (syntax-rules ()
    ((set struct field)
       (hash-table-get (car (cdr struct)) field
                     (make-error 'field-not-found
                                 (string-append "the field '"
                                                (symbol->string field)
                                                "' isn't found!"))))))

(define print-field
  (lambda (key value)
    (display key)
    (display ":")
    (display value)
    (display "\n")))

(define-syntax struct-debug
  (syntax-rules ()
    ((struct-debug s)
     (hash-table-for-each (car (cdr s)) print-field))))