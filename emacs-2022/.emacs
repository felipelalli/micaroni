;;
;; INSTRUCTION:
;;
;; - Copy vars.el.example to ~/.emacs.d/vars.el
;; - Edit vars.el and insert your credentials.
;;

(setq HOME (getenv "HOME"))
(setq user-emacs-directory (concat HOME "/.emacs.d/"))
(message "Home dir: %s" user-emacs-directory)

(if (not (file-exists-p (expand-file-name "vars.el" user-emacs-directory)))
    (error "ERROR: The file vars.el is missing. Please see vars.el.example, edit and remove .example extension."))

(load-file (expand-file-name "vars.el" user-emacs-directory))

; External libraries
; ===============

(setq load-path (cons (expand-file-name "lib" user-emacs-directory) load-path))

; packages

(require 'package)
(add-to-list 'package-archives
              '("melpa" . "https://melpa.org/packages/")
              t)

(package-initialize)

; ========================================================

; general configs
(add-hook 'remember-mode-hook 'org-remember-apply-template)
(global-visual-line-mode t)
(put 'erase-buffer 'disabled nil)
(set-cursor-color "#aaaaff")
(set-scroll-bar-mode 'right)
(setenv "SOCKS5_PASSWORD" "")
(setq column-number-mode t)
(setq default-input-method "portuguese-prefix")
(setq inhibit-splash-screen t)
(setq inhibit-startup-message t)
(setq ispell-dictionary "american")
(setq org-list-allow-alphabetical t)
(setq remember-annotation-functions '(org-remember-annotation))
(setq remember-handler-functions '(org-remember-handler))
(setq remember-save-after-remembering t)
(setq show-paren-mode t)
(setq show-paren-style 'expression)
(setq tool-bar-mode nil)
(setq visual-line-mode t)
(setq word-wrap t)
(show-paren-mode t)

; Removing tool-bar and scroll-bar
(menu-bar-mode -1)
(tool-bar-mode -1)

;; ========================================================

;; org-mode custom configs

(setq org-todo-keyword-faces
      '(("CANCELED" . "gray")
        ("UNFINISHED" . "light gray")
        ("WAITING" . "orange")
        ("DELEGATED" . "light gray")
        ("DONE" . "green")
        ("DEPRECATED" . "gray")
        ("POSTPONED" . "gray")
        ("DOING" . "white")
        ("S" . "green")
        ("F" . "red")))

(global-set-key (kbd "C--") 'org-ctrl-c-minus)

; Tip from: https://emacs.stackexchange.com/a/58332/17985
; This opens the agenda by default
(setq enable-local-eval t)
(setq safe-local-eval-forms '((progn (org-agenda-list) (other-window 1))))

; Enabling habits on orgmode
(setq org-modules '(org-habit))

(setq org-habit-preceding-days 40
      org-habit-graph-column 50
      org-habit-following-days 7
      org-habit-show-habits-only-for-today t
      org-habit-show-all-today nil)

; Agenda org-mode
(global-set-key "\C-cl" 'org-store-link)
(global-set-key "\C-ca" 'org-agenda)
(global-set-key "\C-cc" 'org-capture)
(global-set-key "\C-cb" 'org-iswitchb)
(setq org-agenda-include-diary t)
(setq org-agenda-files (list org-file-path))
(setq org-default-notes-file org-remember-file-path)
(setq org-archive-location (concat org-archive-dir-path "/%s_archive::"))

; Colorize source code inside orgmode
(setq org-src-fontify-natively t)

; ========================================================

; Custom font
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(default ((t (:inherit nil :stipple nil box nil :strike-through nil :overline nil :underline nil :slant normal :weight normal :height 160 :width normal :foundry "PfEd" :family "DejaVu Sans Mono"))))
 '(rainbow-delimiters-depth-1-face ((t (:inherit rainbow-delimiters-base-face :foreground "yellow"))))
 '(rainbow-delimiters-depth-2-face ((t (:inherit rainbow-delimiters-base-face :foreground "green"))))
 '(rainbow-delimiters-depth-3-face ((t (:inherit rainbow-delimiters-base-face :foreground "deep sky blue"))))
 '(rainbow-delimiters-depth-4-face ((t (:inherit rainbow-delimiters-base-face :foreground "chocolate"))))
 '(rainbow-delimiters-depth-5-face ((t (:inherit rainbow-delimiters-base-face :foreground "olive drab"))))
 '(rainbow-delimiters-depth-6-face ((t (:inherit rainbow-delimiters-base-face :foreground "hot pink"))))
 '(rainbow-delimiters-depth-7-face ((t (:inherit rainbow-delimiters-base-face :foreground "cyan3"))))
 '(rainbow-delimiters-depth-8-face ((t (:inherit rainbow-delimiters-base-face :foreground "orchid4"))))
 '(rainbow-delimiters-depth-9-face ((t (:inherit rainbow-delimiters-base-face :foreground "orange"))))
 '(rainbow-delimiters-unmatched-face ((t (:inherit rainbow-delimiters-base-error-face :foreground "red")))))

(set-face-attribute 'default nil :height 110)

; ========================================================

; Adding transparency variable
(set-frame-parameter (selected-frame) 'alpha '(92 . 90))
(add-to-list 'default-frame-alist '(alpha . (92 . 90)))

; Toggle transparency function
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
         '(92 . 90) '(100 . 100)))))

; It can be useful if your wallpaper is NSFW
(global-set-key (kbd "C-c t") 'toggle-transparency)

; ========================================================

; Hacks
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

; Tip from https://github.com/hlissner/doom-emacs/issues/3872#issuecomment-684176505
(electric-indent-mode -1)

; Mac OS X path fix
(require 'exec-path-from-shell)
(exec-path-from-shell-initialize)

; Fix SHIFT + arrows and CTRL+arrows inside Linux screen
(define-key input-decode-map "\e[1;2A" [S-up])
(define-key input-decode-map "\e[1;2B" [S-down])
(define-key input-decode-map "\e[1;2C" [S-right])
(define-key input-decode-map "\e[1;2D" [S-left])
(define-key input-decode-map "\e[1;5A" [C-up])
(define-key input-decode-map "\e[1;5B" [C-down])
(define-key input-decode-map "\e[1;5C" [C-right])
(define-key input-decode-map "\e[1;5D" [C-left])

; Fix mouse wheel
(global-set-key (kbd "C-M-(") (kbd "<mouse-4>"))
(global-set-key (kbd "C-M-)") (kbd "<mouse-5>"))

; ========================================================

; Recent files
(require 'recentf)
(recentf-mode 1)
(setq recentf-max-menu-items 25)
(global-set-key "\C-xf" 'recentf-open-files)
(ido-mode)

; ========================================================

; Flyspell
(autoload 'flyspell-mode "flyspell" "On-the-fly spelling checker." t)
(autoload 'flyspell-delay-command "flyspell" "Delay on command." t)
(autoload 'tex-mode-flyspell-verify "flyspell" "" t)

; ========================================================

; Ledger
(require 'ledger-mode)

(defun insert-year-month-for-ledger ()
  "Insert string for today's year-month in Ledger style,
e.g. 2021-09"
  (interactive)                 ; permit invocation in minibuffer
  (insert (format-time-string "%Y-%m")))

(global-set-key "\C-c\C-y" 'insert-year-month-for-ledger)

(autoload 'ledger-mode "ledger-mode" "A major mode for Ledger" t)
(add-to-list 'load-path (expand-file-name "lib/ledger"))
(add-to-list 'auto-mode-alist '("\\.ledger$" . ledger-mode))

; ========================================================

; Docker
(require 'dockerfile-mode)
(add-to-list 'auto-mode-alist '("Dockerfile\\'" . dockerfile-mode))

; ========================================================

; Scheme

; M-x run-scheme -> open zsh shell, and you can open your favorite scheme implementation.
(setq scheme-program-name "zsh")
(require 'racket-mode)
(require 'racket-xp)
    (add-hook 'racket-mode-hook #'racket-xp-mode)

(setq tab-always-indent 'complete)
(require 'scribble-mode)

; Geiser
(setq geiser-active-implementations '(racket guile chicken))

; Rainbow delimiters
(require 'rainbow-delimiters)
(add-hook 'racket-mode-hook 'rainbow-delimiters-mode)
(add-hook 'scheme-mode-hook 'rainbow-delimiters-mode)
(add-hook 'elisp-mode-hook 'rainbow-delimiters-mode)
(add-hook 'emacs-lisp-mode-hook 'rainbow-delimiters-mode)
(add-hook 'rust-mode-hook 'rainbow-delimiters-mode)
(add-hook 'text-mode-hook 'rainbow-delimiters-mode)

; ========================================================

; Auto backup
(setq vc-make-backup-files t)

(setq version-control t ;; Use version numbers for backups.
      kept-new-versions 100 ;; Number of newest versions to keep.
      kept-old-versions 20 ;; Number of oldest versions to keep.
      delete-old-versions t ;; Don't ask to delete excess backup versions.
      backup-by-copying t) ;; Copy all files, don't rename them.

(setq backup-directory-alist `(("" . ,(concat HOME "/.emacs.d/backup/per-save"))))

(defun force-backup-of-buffer ()
  ;; Make a special "per session" backup at the first save of each
  ;; emacs session.
  (when (not buffer-backed-up)
    ;; Override the default parameters for per-session backups.
    (let ((backup-directory-alist `(("" . ,(concat HOME "/.emacs.d/backup/per-session"))))
          (kept-new-versions 3))
      (backup-buffer)))
  ;; Make a "per save" backup on each save.  The first save results in
  ;; both a per-session and a per-save backup, to keep the numbering
  ;; of per-save backups consistent.
  (let ((buffer-backed-up nil))
    (backup-buffer)))

(add-hook 'before-save-hook  'force-backup-of-buffer)

; ========================================================

; Pomodoro
(require 'org-pomodoro)
(setq org-pomodoro-ticking-sound-p nil)
(setq-default indent-tabs-mode nil)

(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(geiser-mode-smart-tab-p t)
 '(package-selected-packages
   '(ledger-import projectile magit-popup magit origami highlight-indentation yaml-mode dracula-theme copilot flycheck-rust flycheck-yaml yasnippet flycheck flymake-easy pomodoro use-package rustic lsp-mode clojure-mode scribble-mode rainbow-delimiters emojify tabbar session pod-mode muttrc-mode mutt-alias markdown-mode initsplit htmlize graphviz-dot-mode geiser folding eproject diminish csv-mode company color-theme-modern browse-kill-ring boxquote bm bar-cursor apache-mode recentf-ext racket-mode org-pomodoro ledger-mode exec-path-from-shell dockerfile-mode))
 '(safe-local-variable-values
   '((org-todo-keyword-faces
      ("CANCELED" . "gray")
      ("UNFINISHED" . "light green")
      ("WAITING" . "orange")
      ("DELEGATED" . "light gray")
      ("DONE" . "green")
      ("DEPRECATED" . "gray")
      ("POSTPONED" . "gray")
      ("DOING" . "white")
      ("S" . "green")
      ("F" . "red"))
     (ledger-schedule-file . "../schedule.ledger")
     (ledger-schedule-file . "schedule.ledger")
     (ledger-reconcile-default-commodity . "R$")
     (ledger-default-date-format . "%Y-%m-%d")
     (org-todo-keyword-faces
      ("CANCELED" . "gray")
      ("UNFINISHED" . "light gray")
      ("WAITING" . "orange")
      ("DELEGATED" . "light gray")
      ("DONE" . "green")
      ("DEPRECATED" . "gray")
      ("POSTPONED" . "gray")
      ("DOING" . "white")
      ("S" . "green")
      ("F" . "red")))))

; ========================================================

(require 'clojure-mode)
(add-to-list 'auto-mode-alist '("\\.edn\\'" . clojure-mode))
(add-to-list 'auto-mode-alist '("\\.clj\\'" . clojure-mode))
(add-to-list 'auto-mode-alist '("\\.clojure\\'" . clojure-mode))

; ========================================================

; emacs-emojify
(require 'emojify)
(add-hook 'after-init-hook #'global-emojify-mode)
(setq emojify-display-style 'image)

; ========================================================

; Extends org-pomodoro. More info:
; https://github.com/marcinkoziej/org-pomodoro/pull/94/files

;;
;; Tip from: https://emacs.stackexchange.com/a/62338/17985
;;
(defun ndk/org-set-effort-in-pomodoros (&optional n)
  "This `fn` facilitate to define efforts in tasks in pomodoros units.
You can use interactively by typing `C-c C-x e` or by sending parameter as `M-3 C-c C-x e`."
  (interactive "P")
  (setq n (or n (string-to-number (read-from-minibuffer "How many pomodoros? " nil nil nil nil "1" nil))))
  (let* ((mins-per-pomodoro (if org-pomodoro-length
                                org-pomodoro-length
                              25)))
    (org-set-effort nil (org-duration-from-minutes (* n mins-per-pomodoro)))))

;;
;; Redefine the key binding `C-c C-x e' which was originally bound to `org-set-effort'
;;  to the pomodoro function
;;
;; See also `ndk/org-set-effort-in-pomodoros` fn for more info.
;;
(define-key org-mode-map (kbd "C-c C-x e") #'ndk/org-set-effort-in-pomodoros)

(desktop-save-mode 1)
(setq tramp-verbose 10)

;; From https://stackoverflow.com/a/34589105/450148
(setq show-trailing-whitespace t)
(setq-default show-trailing-whitespace t)

;; Rust support
(use-package yasnippet
  :ensure t
  :init
    (yas-global-mode 1))

(require 'lsp-mode)
(setq lsp-rust-server 'rust-analyzer)
(require 'rustic)
(use-package flycheck :ensure)

(with-eval-after-load 'rust-mode
  (add-hook 'flycheck-mode-hook #'flycheck-rust-setup)
  (setq flycheck-rust-check-tests t)
  (setq flycheck-cargo-args '("--all-targets" "--all-features"))
  )

(setq flycheck-rust-check-tests nil)
(setq flycheck-rust-crate-type "lib")
(setq flycheck-rust-clippy-executable "/bin/cargo-clippy")

;; Format-all (Format code)
(require 'format-all)

;; Hidding annoying warning messages
(setq warning-minimum-level :emergency)

; To open git-sh
(defun git-sh ()
  "Open git-sh"
  (interactive)
  (let ((buffer (ansi-term "/bin/zsh")))
    (switch-to-buffer buffer)
    (rename-buffer "*git-sh*")
    (term-send-raw-string "git sh\n")))

; Use zsh to "shell"
'(explicit-shell-file-name "/bin/zsh")
'(explicit-zsh-args '("--interactive" "--login"))
'(comint-process-echoes 0)

; Github Co-pilot
(setq load-path (cons (expand-file-name "lib/copilot.el" user-emacs-directory) load-path))
(require 'copilot)

(use-package copilot
  :init
  (add-hook 'prog-mode-hook 'copilot-mode)
  :bind (:map copilot-completion-map
              ("<tab>" . copilot-accept-completion)
              ("TAB" . copilot-accept-completion)
              ("C-<tab>" . copilot-accept-completion-by-word)
              ("C-TAB" . copilot-accept-completion-by-word)))

(setq +company-backend '(company +childframe))

; YAML
(require 'yaml-mode)
(add-to-list 'auto-mode-alist
             '("\\.yml\\'" . yaml-mode)
             '("\\.yaml\\'" . yaml-mode))

(require 'highlight-indentation)
(add-hook 'yaml-mode-hook 'highlight-indentation-mode)

(require 'origami)
(global-origami-mode)
(add-hook 'yaml-mode-hook 'origami-mode)
(define-key origami-mode-map (kbd "<S-iso-lefttab>") 'origami-toggle-node) ; use SHIFT+TAB to open/close node

; Git
;(require 'magit)

; Project
(require 'projectile)
(projectile-mode +1)
(define-key projectile-mode-map (kbd "C-c p") 'projectile-command-map)

(load-theme 'dracula t)
