;zeller.ss
(define (day-of-week)
 (zeller dd
      (cond((< mm 3)(+ mm 10))(else (- mm 2)))
      (remainder (cond((< mm 3)(- yyyy 1)) (else yyyy)) 100)
      (quotient (cond((< mm 3)(- yyyy 1)) (else yyyy)) 100)
 )
)
(define (zeller d m y c)
 (neg-to-pos (remainder (+ d y
                          (quotient (-(* 26 m)2) 10)
                          (quotient y 4)
                          (quotient c 4)
                          (* 2(- c))
                       )
            7)
 )
)
(define (neg-to-pos d)
 (cond((< d 0)(+ d 7))
      (else d)
 ) 
)



(define (birthday dw)
;                  ^{0,...,6}
 (display "Your were born on ")
    (display
     (cond((= dw 1)"Monday ")
          ((= dw 2)"Tuesday ")
          ((= dw 3)"Wednesday ")
          ((= dw 4)"Thursday ")
          ((= dw 5)"Friday ")
          ((= dw 6)"Saturday ")
          (else "Sunday ") ))
  (display dd)(display ".")
  (display mm)(display ".")
 yyyy
)
(define dd 31)
(define mm 12)
(define yyyy 2021)
(birthday (day-of-week))