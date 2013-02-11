pythotriplet = [ a * b * (1000 - a -b) | a <- [ 1..500], b <-[1..500], 
                 a * a + b * b == (1000 - a -b)*(1000-a-b)]

main = do print $ let p = sum [1..100]
                      q = sum [ x * x | x <- [1..100] ]
                   in p * p - q 
          print pythotriplet
