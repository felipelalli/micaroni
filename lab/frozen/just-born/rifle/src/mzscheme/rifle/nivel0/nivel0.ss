(load "nivel0a.ss")
(load "nivel0b.ss")

(define-syntax nivel0?
  (syntax-rules ()
    ((nivel0? obj)
     (little-object obj is? 'nivel0))))

(define cria-nivel0
  (lambda (obj-nivel0a obj-nivel0b)
    (if (and (or (nivel0a? obj-nivel0a) (eq? obj-nivel0a #f))
             (or (nivel0b? obj-nivel0b) (eq? obj-nivel0b #f)))
        (make-little-object 'nivel0
                         (cons obj-nivel0a obj-nivel0b))
        #f)))



