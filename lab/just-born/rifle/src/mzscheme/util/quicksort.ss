; quicksort in scheme

; given list '(7 3 9 6 5 3 2 7 6) -> return sorted list

; pivot function returns the pivot - first element out of order.
; returns 'done if no pivot (means list already sorted)

; partition function takes pivot, list and returns a pair of lists of the
; form '((4 3 6) (8 9 7))

; given:
; (append '(1 2) '(3 4)) --> (1 2 3 4)
; (member 1 '(3 1 2)) --> #t  (or actually, the rest of the list)

(define pivot (lambda (l funcao-menor funcao-igual)
  (cond ((null? l) 'done)
	((null? (cdr l)) 'done)
        ((or (funcao-menor (car l) (cadr l))
             (funcao-igual (car l) (cadr l)))
         (pivot (cdr l) funcao-menor funcao-igual))
	(#t (car l)))))

; usage: (partition 4 '(6 4 2 1 7) () () < =) -> returns partitions
(define partition (lambda (piv l p1 p2 funcao-menor funcao-igual)
  (if (null? l) (list p1 p2)
     (if (funcao-menor (car l) piv)
         (partition piv (cdr l) (cons (car l) p1) p2 funcao-menor funcao-igual)
	 (partition piv (cdr l) p1 (cons (car l) p2) funcao-menor funcao-igual)))))

; (quicksort '(3 8 5 4 8 2 4 1 9 4) < =)
(define (quicksort l funcao-menor funcao-igual)
 (let ((piv (pivot l funcao-menor funcao-igual)))
   (if (equal? piv 'done) l
     (let ((parts (partition piv l () () funcao-menor funcao-igual)))
       (append (quicksort (car parts) funcao-menor funcao-igual) 
               (quicksort (cadr parts) funcao-menor funcao-igual))))))
