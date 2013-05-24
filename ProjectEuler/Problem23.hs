import Data.List

isqrt = floor . sqrt . fromIntegral

divisors x = filter (\y -> if ((x `mod` y) == 0) then True else False) [2..(isqrt x)]

sumDivisors x = 1 + (foldl (\acc y -> acc + y + if (x `div` y == y) then 0 else x `div` y) 0 $ divisors x)

abundant x = filter (\y -> if ( sumDivisors y > y) then True else False) [x,x-1..11]

sumAbundant n = nub $ [ x + y | x<- abundant n , y<- abundant n, x + y < n]

main =  do
     	print $ isqrt 49 
     	--print $ drop 10 $ filter odd $ abundant 30000
	print $ take 10 $ sumAbundant 28123
	
       --
       --print $ sum $ map sumDivisors [2..10000]
       --print $ take 10 $ sumAbundant 29000