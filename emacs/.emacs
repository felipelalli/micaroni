;;
;; This Emacs config file is not 100% organized yet but I hope it can be useful to someone.
;;
;; INSTRUCTION:
;;
;; - Copy vars.el.example to ~/.emacs.d/vars.el
;; - Edit paswords.el and insert your credentials.
;; - Create a symlink ~/.emacs.d/lib -> <micaroni-repo-path>/emacs/lib
;;

(if (not (file-exists-p "~/.emacs.d/vars.el"))
    (error "ERROR: The file vars.el is missing. Please see vars.el.example, edit and remove .example extension."))

(load-file (expand-file-name "vars.el" user-emacs-directory))

(if (not (file-exists-p (expand-file-name "lib/org-gcal.el" user-emacs-directory)))
    (error "ERROR: Files under ~/.emacs.d/lib/* are missing. See \"INSTRUCTIONS\" on Emacs init file."))

; Cosmetic configs
; ================

(setq inhibit-splash-screen t)
(setq inhibit-startup-message t)

;; removing tool-bar and scroll-bar
(tool-bar-mode -1) 
(menu-bar-mode -1)

(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(ansi-color-names-vector
   ["#2d3743" "#ff4242" "#74af68" "#dbdb95" "#34cae2" "#008b8b" "#00ede1" "#e1e1e0"])
 '(column-number-mode t)
 '(custom-enabled-themes (quote (misterioso)))
 '(quack-browse-url-browser-function (quote browse-url-lynx-xterm))
 '(quack-default-program "zsh")
 '(quack-fontify-style nil)
 '(quack-pretty-lambda-p nil)
 '(quack-programs
   (quote
    ("zsh" "bigloo" "csi" "csi -hygienic" "gosh" "gsi" "gsi ~~/syntax-case.scm -" "guile" "kawa" "mit-scheme" "mred -z" "mzscheme" "mzscheme -M errortrace" "rs" "scheme" "scheme48" "scsh" "sisc" "stklos" "sxi")))
 '(quack-remap-find-file-bindings-p nil)
 '(quack-remember-new-programs-p nil)
 '(quack-smart-open-paren-p nil)
 '(quack-switch-to-scheme-method (quote other-window))
 '(safe-local-variable-values
   (quote
    ((org-todo-keyword-faces
      ("CANCELED" . "gray")
      ("UNFINISHED" . "light gray")
      ("WAITING" . "orange")
      ("DELEGATED" . "light gray")
      ("DONE" . "green")
      ("DEPRECATED" . "gray")
      ("DOING" . "white"))
     )))
 '(show-paren-mode t)
 '(visual-line-mode t t))

(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(default ((t (:inherit nil :stipple nil box nil :strike-through nil :overline nil :underline nil :slant normal :weight normal :height 140 :width normal :foundry "apple" :family "Ubuntu Mono")))))

;; Adding transparency variable
(set-frame-parameter (selected-frame) 'alpha '(95 . 85))
(add-to-list 'default-frame-alist '(alpha . (95 . 85)))

;; Toggle transparency function
(defun toggle-transparency ()
  (interactive)
  (let ((alpha (frame-parameter nil 'alpha)))
    (set-frame-parameter
     nil 'alpha
     (if (eql (cond ((numberp alpha) alpha)
                    ((numberp (cdr alpha)) (cdr alpha))
                    ;; Also handle undocumented (<active> <inactive>) form.
                    ((numberp (cadr alpha)) (cadr alpha)))
              100)
         '(95 . 85) '(100 . 100)))))

; It can be useful if your wallpaper is NSFW
(global-set-key (kbd "C-c t") 'toggle-transparency)

; Font size
(set-face-attribute 'default nil :height 170)

; General configs
; ===============

(setq word-wrap t)
(global-visual-line-mode t)
(setq-default word-wrap t)
(setq remember-annotation-functions '(org-remember-annotation))
(setq remember-handler-functions '(org-remember-handler))
(add-hook 'remember-mode-hook 'org-remember-apply-template)
(setq remember-save-after-remembering t)
(ido-mode)

(put 'upcase-region 'disabled nil)

(global-set-key [up] 'previous-logical-line)
(global-set-key [down] 'next-logical-line)
(global-set-key [right] 'forward-char)
(global-set-key [left] 'backward-char)

(global-set-key "\M-[b" 'next-logical-line)
(global-set-key "\M-[a" 'previous-logical-line)
(global-set-key "\M-[c" 'forward-char)
(global-set-key "\M-[d" 'backward-char)

(put 'narrow-to-region 'disabled nil)
(put 'downcase-region 'disabled nil)

;(require 'auto-complete)
;(global-auto-complete-mode)

(show-paren-mode t)
(setq show-paren-style 'expression)
(put 'erase-buffer 'disabled nil)

; Enable client connection
(server-force-delete)
(server-start)

; M-x run-scheme -> open zsh shell, and you can open your favorite scheme implementation.
(setq scheme-program-name "zsh")

; External libraries
; ===============

(setq load-path (cons (expand-file-name "lib" user-emacs-directory) load-path))

; Markdown setup
(autoload 'markdown-mode "markdown-mode" "Major mode for editing Markdown files" t)
(add-to-list 'auto-mode-alist '("\\.markdown\\'" . markdown-mode))
(add-to-list 'auto-mode-alist '("\\.md\\'" . markdown-mode))

; Quack setup
(require 'quack)

; clojure-mode setup
(setq load-path (cons (expand-file-name "lib/clojure-mode-3.0.0" user-emacs-directory) load-path))
(require 'clojure-mode)
(add-to-list 'auto-mode-alist '("\\.edn\\'" . clojure-mode))
(add-to-list 'auto-mode-alist '("\\.clj\\'" . clojure-mode))
(add-to-list 'auto-mode-alist '("\\.clojure\\'" . clojure-mode))

; dash
(setq load-path (cons (expand-file-name "lib/dash-2.8.0" user-emacs-directory) load-path))
(require 'dash)

; cider (nrepls)
(setq load-path (cons (expand-file-name "lib/cider-0.7.0" user-emacs-directory) load-path))
(require 'cider)

; Agenda
(global-set-key "\C-cl" 'org-store-link)
(global-set-key "\C-ca" 'org-agenda)
(global-set-key "\C-cc" 'org-capture)
(global-set-key "\C-cb" 'org-iswitchb)
(setq org-agenda-include-diary t)

; Two mode mode
(require 'two-mode-mode)

(setq default-mode (list "Scheme" 'scheme-mode)
      second-modes (list (list "Java" 
			       "//BeginJava" "//EndJava"
			       'java-mode)))
;;(two-mode-mode)

; Enable package managers

(require 'package)
(add-to-list 'package-archives
	     '("marmalade" .
	       "http://marmalade-repo.org/packages/"))

(add-to-list 'package-archives
             '("melpa-stable" . "http://stable.melpa.org/packages/") t)

(package-initialize)

;; Recent files
(require 'recentf)
(recentf-mode 1)
(setq recentf-max-menu-items 25)
(global-set-key "\C-xf" 'recentf-open-files)

;; Flyspell
(autoload 'flyspell-mode "flyspell" "On-the-fly spelling checker." t)
(autoload 'flyspell-delay-command "flyspell" "Delay on command." t)
(autoload 'tex-mode-flyspell-verify "flyspell" "" t) 

; Ledger
(autoload 'ledger-mode "ledger-mode" "A major mode for Ledger" t)
(add-to-list 'load-path (expand-file-name "lib/ledger"))
(add-to-list 'auto-mode-alist '("\\.ledger$" . ledger-mode))

; Docker
(add-to-list 'load-path (expand-file-name "lib/docker" user-emacs-directory))
(require 'dockerfile-mode)
(add-to-list 'auto-mode-alist '("Dockerfile\\'" . dockerfile-mode))

; Agenda & Orgmode
(setq org-agenda-files (list org-file-path org-gcal-schedule-path))
(setq org-default-notes-file org-remember-file-path)
(setq org-archive-location (concat org-archive-dir-path "/%s_archive::"))

; Google Calendar sync
(require 'org-gcal)

(setq org-gcal-client-id google-agenda-id
      org-gcal-client-secret google-agenda-secret
      org-gcal-file-alist `((,google-email . ,org-gcal-schedule-path)))

; Enabling habits on orgmode
(setq org-modules (cons 'org-habit org-modules))

; Other useful libraries
(require 'request)
(require 'alert)
(require 'ox-org)
(require 'org-mind-map)

; Open URL on Google Chrome by default
(setq browse-url-browser-function 'browse-url-chromium)

; Hacks
; =====

; Mac OS X path fix
(load-file (expand-file-name "lib/exec-path-from-shell.el" user-emacs-directory))
(require 'exec-path-from-shell)
(exec-path-from-shell-initialize)

;; Fix SHIFT+arrows and CTRL+arrows on screen

(define-key input-decode-map "\e[1;2A" [S-up])
(define-key input-decode-map "\e[1;2B" [S-down])
(define-key input-decode-map "\e[1;2C" [S-right])
(define-key input-decode-map "\e[1;2D" [S-left])
(define-key input-decode-map "\e[1;5A" [C-up])
(define-key input-decode-map "\e[1;5B" [C-down])
(define-key input-decode-map "\e[1;5C" [C-right])
(define-key input-decode-map "\e[1;5D" [C-left])

(eval-after-load "org"
 '(require 'ox-md nil t))

;; Ignore modification-time-only changes in files, i.e. ones that
;; don't really change the contents.  This happens often with
;; switching between different VC buffers.

(defun update-buffer-modtime-if-byte-identical ()
  (let* ((size      (buffer-size))
         (byte-size (position-bytes size))
         (filename  buffer-file-name))
    (when (and byte-size (<= size 1000000))
      (let* ((attributes (file-attributes filename))
             (file-size  (nth 7 attributes)))
        (when (and file-size
                   (= file-size byte-size)
                   (string= (buffer-substring-no-properties 1 (1+ size))
                            (with-temp-buffer
                              (insert-file-contents filename)
                              (buffer-string))))
          (set-visited-file-modtime (nth 5 attributes))
          t)))))

(defun verify-visited-file-modtime--ignore-byte-identical (original &optional buffer)
  (or (funcall original buffer)
      (with-current-buffer buffer
        (update-buffer-modtime-if-byte-identical))))
(advice-add 'verify-visited-file-modtime :around #'verify-visited-file-modtime--ignore-byte-identical)

(defun ask-user-about-supersession-threat--ignore-byte-identical (original &rest arguments)
  (unless (update-buffer-modtime-if-byte-identical)
    (apply original arguments)))
(advice-add 'ask-user-about-supersession-threat :around #'ask-user-about-supersession-threat--ignore-byte-identical)
