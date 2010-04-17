(load "../struct/struct.ss")
(load "label.ss")
(load "value.ss")

;(make-state label absolute-label value extern? immutable?)
; estrutra:
; 'label -> label?
; 'absolute-label -> label?
; 'value -> value?
; 'extern? -> boolean?
; 'immutable? -> boolean?
; 'last-change -> number? (current-inexact-milliseconds)
; 'birth -> number? (current-inexact-milliseconds)
;
;(define cor (make-state "vermelho" (label "modelos" "cor" "vermelho") 30/100 #f #f))
(define-syntax make-state
  (syntax-rules ()
    ((make-state l al va e i)
     (let ((v (validate (label? l) (label? al)
               (value? va) (boolean? e)
               (boolean? i)))
           (now (current-inexact-milliseconds)))
       (if (error? v)
           v
           (let ((new-state (new-struct 'state)))
             (set-value! new-state 'label l)
             (set-value! new-state 'absolute-label al)
             (set-value! new-state 'value va)
             (set-value! new-state 'extern? e)
             (set-value! new-state 'immutable? i)
             (set-value! new-state 'last-change now)
             (set-value! new-state 'birth now)
             new-state))))))

(define-syntax state?
  (syntax-rules ()
    ((state? s) (little-object s is? 'state))))

(define-syntax state-get-value
  (syntax-rules ()
    ((state-get-value state)
     (get-value state 'value))))

; (state-apply state 'function params ...)
; (state-apply state '+ 1) ; soma um
(define-syntax state-apply
  (syntax-rules ()
    ((state-apply state function params ...)
     ((eval function) (state-get-value state) params ...))))

;(state:= cor 20)
(define-syntax state:=
  (syntax-rules ()
    ((state:= state new-value)
     (begin
       (set-value! state 'value new-value)
       (set-value! state 'last-change (current-inexact-milliseconds))))))

;(state-apply:= cor '+ 20)
(define-syntax state-apply:=
  (syntax-rules ()
    ((state-apply:= state function params ...)
     (let
         ((result (state-apply state function params ...)))
       (state:= state result)))))
