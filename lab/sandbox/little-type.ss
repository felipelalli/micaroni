; Esta macro cria objetos que são no seguinte formato:
; (make-little-object 'nome-do-tipo [<conteúdo>] ...)
; ('nome-do-tipo [<conteúdo>] ...)
(define-syntax make-little-object
  (syntax-rules ()
    ((make-little-object type-name ...)
     (list type-name ...))))

; (content-of obj)
; retorna o conteúdo do objeto
(define-syntax content-of
  (syntax-rules ()
    ((content-of obj)
     (cdr obj))))

; Função que verifica se um determinado objeto é do tipo passado
; como parâmetro. Deve ser usada assim:
; (little-object objeto is? 'nome-do-tipo)
(define-syntax little-object
  (syntax-rules (is?)
    ((little-object obj is? type)
     (if (not (pair? obj))
         #f (eq? (car obj) type)))))
