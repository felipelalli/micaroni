(define-syntax for
  (syntax-rules ()
    ((for (a init) cond inc body ...)
     (let continue ((a init))
       (if cond
           (begin
             (begin
               body ...)
             (set! a inc)
             (continue a)))))))

(for (x 0) (<= x 100) (+ x 1)
     (display x)
     (display "\n"))



