#lang racket
(define x (read))
(define y (read))
(cond
  [(and (positive? x) (positive? y)) 1]
  [(and (positive? x) (negative? y)) 4]
  [(and (negative? x) (negative? y)) 3]
  [(and (negative? x) (positive? y)) 2]
)