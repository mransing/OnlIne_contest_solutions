phi n = length $ filter (\x -> gcd n x == 1) [1..n-1]
main = do print $ map phi [2..10]