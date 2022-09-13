#lang racket

(provide tr declare-bundle!)
(require "srfi-29.rkt") ; i18n (the default Racket implementation doesn't
                        ; support ~[N]@* tag for positional parameters).

;; tr = translate
(define tr
  (lambda (message-name . args)
    (let ((template (localized-template 'default
                                        message-name)))
      (if (not template)
          (format "<i18n:~a:~a>" message-name args)
          (apply format (cons template args))))))