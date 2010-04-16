#lang slideshow

(require slideshow/flash)

(define (square n)
    (filled-rectangle n n))

(define (checker p1 p2)
    (let ([p12 (hc-append p1 p2)]
          [p21 (hc-append p2 p1)])
      (vc-append p12 p21)))

(define (savoia x)
  (checker (colorize (square x) "white")
           (colorize (square x) "black")))

(define (chess size)
  (let make-y ((y 4) (imgy 0))
    (if (= y 0)
        imgy
        (begin
          (set! imgy (vc-append imgy
                                (let make-x ((x 4) (imgx 0))
                                  (if (= x 0)
                                      imgx
                                      (begin
                                        (set! imgx (hc-append imgx (savoia size)))
                                        (make-x (- x 1) imgx))))
                ))
          (make-y (- y 1) imgy)))))

