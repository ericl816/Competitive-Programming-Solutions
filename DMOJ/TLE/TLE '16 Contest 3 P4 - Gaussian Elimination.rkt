#lang racket
(define n (read))
(define m (read))
(cond
  [(= 1 n) (printf "First")]
  [(= 1 m) (printf "First")]
  [(even? (+ n m)) (printf "Second")]
  [else (printf "First")]
 )