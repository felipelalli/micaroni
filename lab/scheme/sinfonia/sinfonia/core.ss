#lang r6rs
(library (core)
  (export)
  (import (rnrs base (6))
          (functions-group core))
  
  ; State
  (define state
    (let
        ((id 9999999)
         (value 'NULL)
         (set 'DEFINIR)
         (extern #f)
         (last-change #f))
      (make-functions-group
       <params>
       ('get-id id)
       ('get-value value)
       ('get-set set)
       ('extern? extern)
       ('get-last-change last-change)
       ('apply!
        (disjoint <params> into (event)
                  event)))))
        
)