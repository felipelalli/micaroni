;;
;; This Emacs config file is not 100% organized yet but I hope it can be useful to someone.
;;
;; INSTRUCTION:
;;
;; - Copy vars.el.example to ~/.emacs.d/vars.el
;; - Edit vars.el and insert your credentials.
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
 '(debug-on-error t)
 '(package-selected-packages
   (quote
    (org-plus-contrib use-package ox-gfm org-pomodoro htmlize)))
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
      ("DOING" . "white")))))
 '(show-paren-mode t)
 '(visual-line-mode t t))

(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(default ((t (:inherit nil :stipple nil box nil :strike-through nil :overline nil :underline nil :slant normal :weight normal :height 140 :width normal :foundry "apple" :family "Ubuntu Mono")))))

;; Adding transparency variable
(set-frame-parameter (selected-frame) 'alpha '(90 . 85))
(add-to-list 'default-frame-alist '(alpha . (90 . 85)))

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
         '(90 . 85) '(100 . 100)))))

; It can be useful if your wallpaper is NSFW
(global-set-key (kbd "C-c t") 'toggle-transparency)

; Font size
(set-face-attribute 'default nil :height 170)

; Colorize source code inside orgmode
(setq org-src-fontify-natively t)

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

; ht (hash table)
(setq load-path (cons (expand-file-name "lib/ht.el" user-emacs-directory) load-path))
(require 'ht)

; emacs-emojify
(setq load-path (cons (expand-file-name "lib/emacs-emojify" user-emacs-directory) load-path))
(require 'emojify)
(add-hook 'after-init-hook #'global-emojify-mode)
(setq emojify-display-style 'image)

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

(defun org-gcal-fetch-and-sync ()
       "Fetch and sync values from Google Calendar."
       (org-gcal-fetch)
       (org-gcal-fetch) ; there is a bug where the fetch should be called twice.
       (org-gcal-sync))

(run-with-timer 0 (* 30 60) 'org-gcal-fetch-and-sync) ; automatically sync each 30 min.

; Enabling habits on orgmode
(require 'org)
(require 'org-install)
(require 'org-habit)
(add-to-list 'org-modules "org-habit")
(setq org-habit-preceding-days 60
      org-habit-following-days 7
      org-habit-graph-column 80
      org-habit-show-habits-only-for-today t
      org-habit-show-all-today nil)

; Other useful libraries
(require 'request)
(require 'alert)
(require 'ox-org)

; Mind map
(load (expand-file-name "lib/org-mind-map.el" user-emacs-directory))
  (setq org-mind-map-engine "dot")       ; Default. Directed Graph
  ;; (setq org-mind-map-engine "neato")  ; Undirected Spring Graph
  ;; (setq org-mind-map-engine "twopi")  ; Radial Layout
  ;; (setq org-mind-map-engine "fdp")    ; Undirected Spring Force-Directed
  ;; (setq org-mind-map-engine "sfdp")   ; Multiscale version of fdp for the layout of large graphs
  ;; (setq org-mind-map-engine "twopi")  ; Radial layouts
  ;; (setq org-mind-map-engine "circo")  ; Circular Layout

; Open URL on Google Chrome by default
(setq browse-url-browser-function 'browse-url-chromium)

; org-sort-tasks
(setq load-path (cons (expand-file-name "lib/org-sort-tasks" user-emacs-directory) load-path))
(require 'org-sort-tasks)

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

;; Fix mouse wheel
(global-set-key (kbd "C-M-(") (kbd "<mouse-4>"))
(global-set-key (kbd "C-M-)") (kbd "<mouse-5>"))

(eval-after-load "org"
 '(require 'ox-md nil t))

;;
;; Tip from https://emacs.stackexchange.com/a/29877/17985
;;
(defun region-bytes ()
  (interactive)
  (let ((strg  (if (use-region-p)
                   (buffer-substring-no-properties (region-beginning) (region-end))
                 "")))
    (message "Region has %d bytes" (string-bytes strg))))

;; Ignore modification-time-only changes in files, i.e. ones that
;; don't really change the contents.  This happens often with
;; switching between different VC buffers.
;; Tip from https://stackoverflow.com/a/29556894/450148

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

; Beautify orgmode
; Tips from: https://zzamboni.org/post/beautifying-org-mode-in-emacs/
;            http://www.howardism.org/Technical/Emacs/orgmode-wordprocessor.html
;(setq org-hide-emphasis-markers t)

(setq show-trailing-whitespace t)

; Auto backup:

(setq vc-make-backup-files t)

(setq version-control t ;; Use version numbers for backups.
      kept-new-versions 10 ;; Number of newest versions to keep.
      kept-old-versions 0 ;; Number of oldest versions to keep.
      delete-old-versions t ;; Don't ask to delete excess backup versions.
      backup-by-copying t) ;; Copy all files, don't rename them.

;; Default and per-save backups go here:
(setq backup-directory-alist '(("" . "~/.emacs.d/backup/per-save")))

(defun force-backup-of-buffer ()
  ;; Make a special "per session" backup at the first save of each
  ;; emacs session.
  (when (not buffer-backed-up)
    ;; Override the default parameters for per-session backups.
    (let ((backup-directory-alist '(("" . "~/.emacs.d/backup/per-session")))
          (kept-new-versions 3))
      (backup-buffer)))
  ;; Make a "per save" backup on each save.  The first save results in
  ;; both a per-session and a per-save backup, to keep the numbering
  ;; of per-save backups consistent.
  (let ((buffer-backed-up nil))
    (backup-buffer)))

(add-hook 'before-save-hook  'force-backup-of-buffer)

(setq org-pomodoro-ticking-sound-p nil)
(setq-default indent-tabs-mode nil)

(require 'ox-taskjuggler)
