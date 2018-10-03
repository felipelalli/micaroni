;; From http://bzg.fr/u/emacs-strip.el / http://bzg.fr/emacs-strip-tease.html / https://gist.github.com/bzg/8578998

;; Prevent the cursor from blinking
(blink-cursor-mode 0)
;; Don't use messages that you don't read
(setq initial-scratch-message "")
(setq inhibit-startup-message t)
;; Don't let Emacs hurt your ears
(setq visible-bell t)

;; You need to set `inhibit-startup-echo-area-message' from the
;; customization interface:
;; M-x customize-variable RET inhibit-startup-echo-area-message RET
;; then enter your username
(setq inhibit-startup-echo-area-message "guerry")

;; This is bound to f11 in Emacs
(toggle-frame-fullscreen) 
;; Who use the bar to scroll?
(scroll-bar-mode 0)

(tool-bar-mode 0)
(menu-bar-mode 0)

;; You can also set the initial frame parameters
;; (setq initial-frame-alist
;;       '((menu-bar-lines . 0)
;;         (tool-bar-lines . 0)))

;; See http://bzg.fr/emacs-hide-mode-line.html
(defvar-local hidden-mode-line-mode nil)
(defvar-local hide-mode-line nil)

(define-minor-mode hidden-mode-line-mode
  "Minor mode to hide the mode-line in the current buffer."
  :init-value nil
  :global nil
  :variable hidden-mode-line-mode
  :group 'editing-basics
  (if hidden-mode-line-mode
      (rotatef hide-mode-line mode-line-format)
    (rotatef mode-line-format hide-mode-line))
  (when (and (called-interactively-p 'interactive)
             hidden-mode-line-mode)
    (run-with-idle-timer
     0 nil 'message
     (concat "Hidden Mode Line Mode enabled.  "
             "Use M-x hidden-mode-line-mode RET to make the mode-line appear."))))

;; Activate hidden-mode-line-mode
(hidden-mode-line-mode 1)

;; Alternatively, you can paint your mode-line in White but then
;; you'll have to manually paint it in black again
;; (custom-set-faces
;;  '(mode-line-highlight ((t nil)))
;;  '(mode-line ((t (:foreground "white" :background "white"))))
;;  '(mode-line-inactive ((t (:background "white" :foreground "white")))))

;; A small minor mode to use a big fringe
(defvar bzg-big-fringe-mode nil)
(define-minor-mode bzg-big-fringe-mode
  "Minor mode to hide the mode-line in the current buffer."
  :init-value nil
  :global t
  :variable bzg-big-fringe-mode
  :group 'editing-basics
  (if (not bzg-big-fringe-mode)
      (set-fringe-style nil)
    (set-fringe-mode
     (/ (- (frame-pixel-width)
           (* 100 (frame-char-width)))
        2))))

;; Now activate this global minor mode
(bzg-big-fringe-mode 1)

;; Use a minimal cursor
;; (setq cursor-type 'hbar)

;; Get rid of the indicators in the fringe
(mapcar (lambda(fb) (set-fringe-bitmap-face fb 'org-hide))
        fringe-bitmaps)

;; Set the color of the fringe
(custom-set-faces
 '(fringe ((t (:background "white")))))

(custom-set-faces
  '(default ((t (:background "black" :foreground "grey"))))
  '(fringe ((t (:background "black")))))

;; Command to toggle the display of the mode-line as a header
(defun mode-line-in-header ()
  (interactive)
  (if (not header-line-format)
      (rotatef header-line-format var)
    (rotatef var header-line-format))
  (force-mode-line-update))
(global-set-key (kbd "C-s-SPC") 'mode-line-in-header)
