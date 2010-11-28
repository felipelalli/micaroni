(load "../little-type/little-type.ss")

(define-syntax TODO
  (syntax-rules ()
    ((TODO message)
     (make-little-object 'TODO message))))

(define-syntax TODO?
  (syntax-rules ()
   ((TODO? obj)
    (little-object obj is? 'TODO))))