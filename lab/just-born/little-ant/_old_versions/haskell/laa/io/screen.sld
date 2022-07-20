(define-library (laa io screen)
  (import (scheme base)
          (scheme write))
  (export output-type say)
  (begin
    (define output-type 'screen)

    (define (say something)
      (display (string-append "> " something))
      (newline)
      (newline))))
