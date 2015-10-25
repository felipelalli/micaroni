(define number-of-games
  (lambda (start payout min-bet all)
    (if (< start min-bet)
        0
        (+ 1 (number-of-games (- start
                                 (* (if all start min-bet)
                                    (- 1 payout)))
                              payout
                              min-bet
                              all)))))

(define hours-playing
  (lambda (start payout min-bet all min-avg)
    (exact->inexact (/ (* (number-of-games
                        start payout min-bet all)
                       min-avg) 60))))