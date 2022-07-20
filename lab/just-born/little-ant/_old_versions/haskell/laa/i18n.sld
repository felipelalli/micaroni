(define-library (laa i18n)
  (import (scheme base)
          (srfi 28)
          (srfi 69))
  (export make-i18n)
  (begin
    (define (make-i18n resource-file language)
      (let ((dic (alist->hash-table resource-file)))
        (lambda (key)
          (hash-table-ref dic
                          (string->symbol (format "~a.~a" language key))))))))
