(import (scheme base)
        (scheme write)
        (scheme file)
        (scheme load)
        (laa i18n))

(define tr (make-i18n (load "res/dic.scm") "pt"))

(display (tr "intro1"))
(newline)


