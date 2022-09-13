#lang racket

; GUI
(require racket/gui/base)
(require framework)
(require framework/splash)
(require rsvg) ; to load SVG

; SRFI
(require srfi/2)  ; and-let*

; Common UI
(require "ui-common.rkt")
(ui-init)

; Constants
(define *SPLASH-WIDTH* 400)
(define *SPLASH-TIME-SEC* 1.5)

(let ((start-time (current-seconds))
      (app-name (tr 'app-name))
      (splash-bitmap (load-svg-from-file "../../res/splash.svg"))
      (ico (load-svg-from-file "../../res/ico.svg")))
  (set-splash-progress-bar?! #f)
  (start-splash splash-bitmap
                app-name *SPLASH-WIDTH*
                #:allow-funny? #t
                #:frame-icon ico)
  (application:current-app-name app-name)

  (sleep (max 0 (- *SPLASH-TIME-SEC* (- (current-seconds) start-time))))
  (shutdown-splash)
  (close-splash)
  (and-let* ((frame (new frame% [label app-name]
                                [alignment '(center center)]
                                [width 800]
                                [height 600]))
             (msg (new message% [parent frame]
                                [label "No events so far..."]))
             (new button% [parent frame]
                          [label "Click Me"]
                          [callback (lambda (button event)
                                      (send msg set-label "Button click"))]))

      (send frame show #t)
    ))
