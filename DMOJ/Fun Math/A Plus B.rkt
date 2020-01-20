#lang racket
(for ([i (read)])
  (define a (read))
  (define b (read))
  (displayln (+ a b)))