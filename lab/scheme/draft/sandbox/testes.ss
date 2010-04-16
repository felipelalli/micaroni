#lang scheme

(require scheme/class scheme/gui/base)
  (define f (new frame% [label "My Art"]
                        [width 300]
                        [height 300]
                        [alignment '(center center)]))
  
  