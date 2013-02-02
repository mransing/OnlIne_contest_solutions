import Data.Char

summult::Int
summult = foldl (\acc x -> if ((x `mod` 3 ==0) || (x `mod` 5 == 0)) then acc + x else acc) 0 [1..999]

main = do print $ (summult, " ", sum $ map digitToInt $ show $ 2 ^ 1000)