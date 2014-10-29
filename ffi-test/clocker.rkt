#lang racket

(require ffi/unsafe
         ffi/unsafe/define)

(define-ffi-definer define-libc (ffi-lib "libc"))
(define-ffi-definer define-grinder (ffi-lib "libgrind"))
(define-ffi-definer define-sleeper (ffi-lib "libsleeper"))

(define-grinder grind (_fun -> _int))
(define-grinder grind2 (_fun -> _int))
(define-sleeper sleeper (_fun _uint -> _uint))

(define-cstruct _TMS ([utime  _ulong]
                      [stime  _ulong]
                      [cutime _ulong]
                      [cstime _ulong]))

(define (display-tms tms)
  (printf "~a:~a:~a:~a~n"
          (TMS-utime tms)
          (TMS-stime tms)
          (TMS-cutime tms)
          (TMS-cstime tms)))

(define-libc times (_fun _TMS-pointer/null -> _TMS))

(define start
  (times #f))
(displayln (grind2))
(define end
  (times #f))

(display-tms start)
(display-tms end)
