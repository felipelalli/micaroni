#lang r5rs

(define identity
  (lambda (x) x))

(define self-app
  (lambda (s)
    (s s)))

(define fn-app-fn ; apply in the book
  (lambda (func)
    (lambda (arg)
      (func arg))))

(define identity2
  (lambda (x)
    (fn-app-fn identity) x))

(define self-app2
  (lambda (s)
    ((fn-app-fn s) s)))

(define select-first
  (lambda (first)
    (lambda (second)
      first)))

(define select-second
  (lambda (first)
    (lambda (second)
      second)))

(define make-pair
  (lambda (first)
    (lambda (second)
      (lambda (func)
        ((func first) second)))))

