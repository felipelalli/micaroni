#lang racket

(provide read-char-block)

(require ffi/unsafe
         ffi/unsafe/define)

(define-ffi-definer read-char-block-define (ffi-lib "read-char-block"))

(read-char-block-define read_char_block (_fun _int -> _wchar))

(define (read-char-block)
  (integer->char (read_char_block 0)))
