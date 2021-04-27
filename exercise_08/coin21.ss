; coin21
; Епанешников М80-206Б-19

(define VARIANT 9)
(define LAST-DIGIT-OF-GROUP-NUMBER 6)
(define KINDS-OF-COINS 7)

(define (first-denomination kinds-of-coins)
  (cond((= kinds-of-coins 1) 1)
       (else (cond((= kinds-of-coins 2) 2)
       (else (cond((= kinds-of-coins 3) 3)
       (else (cond((= kinds-of-coins 4) 5)
       (else (cond((= kinds-of-coins 5) 10)
       (else (cond((= kinds-of-coins 6) 15)
       (else (cond((= kinds-of-coins 7) 20)
       (else 0))))))))))))))
)


(define (AND3? x? y? z?) 
     ( = 1 (cond(x? (cond(y? (cond(z? 1) (else 0))) (else 0))) (else 0)))
)

(define (AND2? x? y?)   
  ( = 1 (cond(x? (cond(y? 1) (else 0))) (else 0)))
)

(define (MORE? x y)
    (AND2? (not (< x y)) (not (= x y)))
)


(define (count-change amount)
  (display "______")
  (newline)
  (display " amount: ")
  (newline)
  (display "KINDS-OF-COINS: ")
  (display KINDS-OF-COINS)
  (newline)
  (let(
       (largest-coin (first-denomination KINDS-OF-COINS))
      )
      (display "largest-coin: ")
      (display largest-coin)
      (newline)
      (cond((AND3? (MORE? amount 0) (MORE? KINDS-OF-COINS 0) (MORE? largest-coin 0))
         (let()
           (display "List of coin denominations: ")
           (denomination-list KINDS-OF-COINS)
           (display "count-change= ")
           (cc amount KINDS-OF-COINS)
         ))
         (else (let()
           (display "Improrer parametr value!")
           (newline)
           (display "count-change =") -1))
      )
   )
)

(define (pier? x? y?)
  (not (OR? x? y?))
)


(define (OR? x? y?)
    (not(AND2? (not x?) (not y?)))
)


(define (cc amount kinds-of-coins)
  (cond( (= amount 0) 1)
       (else (cond((pier? (< amount 0) (= kinds-of-coins 0))
        (+ (cc amount (- kinds-of-coins 1))
           (cc (- amount (first-denomination kinds-of-coins)) kinds-of-coins)))
        (else 0))))
)

(define (denomination-list kinds-of-coins)
  (cond((= kinds-of-coins 0) (let() (newline) 0))
     (else (let()
       (display (first-denomination kinds-of-coins))
       (display " ")
       (denomination-list (- kinds-of-coins 1))
     )))
)


(define (GR-AMOUNT)
  (remainder (+ (* 100 LAST-DIGIT-OF-GROUP-NUMBER) VARIANT) 231)
)

(display "Variant ")
(display VARIANT)
(newline)
(newline)
(display (count-change 100))
(newline)
(display (count-change (GR-AMOUNT)))
(newline)
(set! KINDS-OF-COINS 13)
(display (count-change 100))
(newline)
(display "(c) Epaneshnikov V.S. 2021")
(newline)