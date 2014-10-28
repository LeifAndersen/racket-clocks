#lang racket

(require ffi/unsafe
         ffi/unsafe/define)

(define-ffi-definer define-grinder (ffi-lib "libgrind"))
(define-ffi-definer define-sleeper (ffi-lib "libsleeper"))

(define-grinder grind (_fun -> _int))
(define-grinder grind2 (_fun -> _int))
(define-sleeper sleeper (_fun _uint -> _uint))

(define (time-grinder grind [timer current-process-milliseconds] . args)
  (displayln "Timing:")
  (displayln (apply timer args))
  (displayln (apply timer args))
  (displayln (grind))
  (displayln (apply timer args))
  (displayln (apply timer args))
  (time (grind)))

(define (mysleep)
  (sleeper 2))

(time-grinder grind)
(newline)
(time-grinder grind2)
(newline)
(time-grinder mysleep)

