; (to-html (h-flat-list x x))
; (get-selected-item (h-flat-list ...) obj2 obj3 ...)
; (to-html (h-page ...))
; (call (h-page ...) params)


(define MAIN_PAGE
  (let*
      ((instances-on (h-flat-list 10 "a" "b" "c"))
       (instances-off (h-flat-list 5 "d" "e"))
       (old-instances (h-flat-list 5 "f" "g" "h"))
       (button-create-new (h-button "Create New"))
       (button-open (h-button "Open"))
       (box-instances (h-box instances-on instances-off old-instances))
       (box-buttons (h-box button-create-new button-open)))
    (h-page (params) ; sem nenhum
            (styles
             box-instances "boxi"
             box-buttons "boxb")
            (actions
             (button-create-new
              (call
               CREATE_PAGE))
             (button-open
              (call
               OPEN_PAGE
               (get-selected-item
                instances-on
                instances-off
                old-instances))))
            (body
             box-instances
             box-buttons))))
