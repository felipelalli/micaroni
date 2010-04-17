(load "../little-error-control/little-error-control.ss")

(define-syntax make-irrelevant-value
  (syntax-rules ()
    ((make-irrelevant-value) 'irrelevant)))

(define-syntax irrelevant?
  (syntax-rules ()
    ((irrelevant? a) (eq? (make-irrelevant-value)))))

;é valor quando é boleano, número, string ou irrelevante
(define-syntax value?
  (syntax-rules ()
    ((value? a)
     (or (boolean? a) (number? a) (string? a) (irrelevant? a)))))

; converte um valor em string, de forma que o processo inverso seja válido
(define value->string
  (lambda (v)
    (let ((r (validate value? v)))
      (if (error? r)
          r
          (if (irrelevant? v)
              "I"
              (if (boolean? v)
                  (if v "T" "F")
                  (if (number? v)
                      (string-append "N" (number->string v))
                      (if (string? v)
                          (string-append "S" v) "I"))))))))

; converte uma string em value, de forma que o processo inverso seja válido
(define string->value
  (lambda (s)
    (let ((r (validate string? s)))
      (if (error? r)
          r
          (if (= (string-length s) 0)
              (make-irrelevant-value)
              (let ((first (make-string 1 (string-ref s 0))))
                (if (string=? first "T")
                    #t
                    (if (string=? first "F")
                        #f
                        (if (string=? first "N")
                            (string->number (substring s 1 (string-length s)))
                            (if (string=? first "S")
                                (substring s 1 (string-length s))
                                (make-irrelevant-value)))))))))))
