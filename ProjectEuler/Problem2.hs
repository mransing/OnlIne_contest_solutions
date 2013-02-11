fibsum :: (Integer,Integer,Integer)
fibsum = foldl (\(a,b,sum) x -> (b, a+b , if(a + b) `mod` 2 == 0 then sum + a + b else sum)) (1,1,0) $ take 32 [1..]

main = do print $ fibsum