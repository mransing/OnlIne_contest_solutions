isPalindrome :: Int -> Bool
isPalindrome n = p == reverse p where p = show n
                                      
maxpalin :: Int
maxpalin = maximum $ filter isPalindrome [x*y| x <- [999,998..100], y <- [999,998..100] ]

main = do print (maxpalin , foldl1 lcm [1..20])