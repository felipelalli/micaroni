#lang racket

(provide read-properties-file)
(require srfi/13)

;;
;; See https://docs.oracle.com/cd/E23095_01/Platform.93/ATGProgGuide/html/s0204propertiesfileformat01.html
;; TODO: escape chars
;;
(define (read-properties-file path)
  (filter-map
   (lambda (line)
     (and (not (or (string-null? (string-trim-both line))
                   (eqv? (string-ref line 0) #\#)
                   (eqv? (string-ref line 0) #\!)))
          (let ((splitted-line (regexp-match #rx"^(.*?)[=|\\:](.*)$"
                                             line)))
            (cons (string->symbol
                   (string-trim-both
                    (second splitted-line)))
                  (string-trim (third splitted-line))))))
   (regexp-split #rx"\n" (file->string path #:mode 'text))))

