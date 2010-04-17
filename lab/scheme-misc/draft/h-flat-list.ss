(load "little-type.ss")

(define-syntax
  h-flat-list
  (syntax-rules ()
    ((h-flat-list c ...)
     (make-little-object 'h-flat-list c ...))))

; <select size="2"><option>2</option><option>4</option></select>
;(h-flat-list->html (h-flat-list 5 "a" "b" "c"))

(define (h-flat-list->html obj)
  (eval `(h-flat-list->html2 ,@(content-of obj))))

(define h-flat-list->html2
  (letrec
      (
        (option-element
         (lambda (elements)
           (if (null? elements)
               ""
               (string-append
                "<option>"
                (car elements)
                "</option>"
                (option-element (cdr elements)))))))
    (lambda (size . elements)
      (string-append
       "<select size=\""
       (number->string size)
       "\">"
       (option-element elements)
       "</select>"))))
