; use like this:
; (/* content ... */ <default-return>)
; or
; (/* content ... */) => #f
(define-syntax /*
  (syntax-rules (*/)
    ((/* body ... */) #f)
    ((/* body ... */ r) r)))