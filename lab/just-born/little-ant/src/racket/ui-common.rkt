#lang racket

(provide ui-init tr)

; Tools
(require "tools/i18n.rkt")
(require "tools/properties-reader.rkt")

(define (ui-init)
  (declare-bundle! `(default . (pt br))
                   (read-properties-file "../../res/pt-BR.properties"))

  (declare-bundle! `(default . ())
                   (read-properties-file "../../res/en-US.properties"))) 

