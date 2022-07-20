(import (scheme base)
        (scheme file)
        (scheme load)
        (laa i18n)
        (laa io screen))

(define tr (make-i18n (load "res/dic.scm") "pt"))

(if (equal? output-type 'screen)
    (say "
        \\/
  ___  _@@
 (___)(_)
 //|| ||
"))

(say (tr "intro1"))
