#lang r6rs
(library (core)
  (export make-functions-group
          disjoint)
  (import (rnrs base)
          (rnrs hashtables))

; Example:
; (make-eq-hashtable-done ('key1 'value1) ('key2 'value2) ...)
(define-syntax make-eq-hashtable-done
  (syntax-rules ()
    ((_ (key content) ...)
     (let ((tab (make-eq-hashtable)))
       (hashtable-set! tab key content) ...
       tab))))

; Example:
; (make-functions-group <params> ('<field1> <body> ...)
;                                ('<field2> <body> ...) ...)
; How to use after:
; (<functions-group> 'field1 params ...)
(define-syntax make-functions-group
  (syntax-rules ()
    ((_ <params> (function-name <body> ...) ...)
     (let [(tab
            (make-eq-hashtable-done
             (function-name (lambda (<params>) <body> ...)) ...))
          ]
       (lambda params
         ((hashtable-ref tab (car params) 'function-not-found)
          (cdr params)))))))

; <params> must be a list
; Use like this:
; (disjoint <params> into (a b c ...)
;   body ...)
(define-syntax disjoint
  (syntax-rules (into)
    ((_ <params> into (p ...) body ...)
     (apply (lambda (p ...) body ...) <params>))))

; Example:
;(define a (make-functions-group
;           <params>
;           ('id <params>)
;           ('get-value "oi")))
;
;(a 'id 1 2) => (list 1 2)
;
;(define b (make-functions-group
;           <params>
;           ('sum (disjoint <params> into (a b)
;              (+ a b)))))
)