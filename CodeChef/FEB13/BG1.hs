import Data.List

changetostring :: String -> Int
changetostring xs = let uniq = nub xs 
                       in sum $ map (\x -> (x + 1) `div` 2) $ map (\x -> length $ elemIndices x xs) uniq

mainloop :: Int -> IO ()
mainloop 0 = return ()
mainloop xs = do
	 y <- getLine
	 putStrLn $ show $ changetostring y
	 mainloop $ xs - 1 
main = do 
         nooftests <- readLn
	 mainloop nooftests
       