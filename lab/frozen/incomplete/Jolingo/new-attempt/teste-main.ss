(let () (load "teste-module.ss")
  eneas)

;eneas

(call-with-current-continuation
 (lambda (a) (+ 1 1) (a 80) (+ 2 2)))

