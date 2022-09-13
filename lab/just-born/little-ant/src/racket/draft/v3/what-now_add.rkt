#lang racket/base

(provide process-command-line summary)

(define summary "Add something.")

; Remove to prevent direct execution.
(module+ main (void (process-command-line)))

; Do not change anything below if you only want subcommands.
(require racket/cmdline
         racket/runtime-path
         (only-in mzlib/etc this-expression-file-name)
         natural-cli)

(define program-name (get-program-name (this-expression-file-name)))
(define-runtime-path cli-directory ".")

(define (what-now_add a)
  (displayln "Will add")
  (displayln a)
  (displayln "\e[49m \e[38;5;38;48;5;44m▄\e[38;5;174;48;5;38m▄\e[38;5;174;49m▄\e[49m \e[m
\e[49;38;5;33m▀\e[38;5;168;48;5;33m▄\e[38;5;168;48;5;168m▄\e[38;5;25;48;5;24m▄\e[49;38;5;25m▀\e[m
\e[49m  \e[49;38;5;25m▀\e[49;38;5;26m▀\e[49m \e[m"))

(define (process-command-line)
  (define-values (finish-expr arg-strings-expr help-expr unknown-expr)
    (make-subcommand-handlers cli-directory program-name))
  (command-line #:program program-name
                ;#:handlers finish-expr arg-strings-expr help-expr unknown-expr
                #:usage-help "test"
                #:args (a)
                (what-now_add a)
                ))
