import Data.Char
import Data.List

wordsWhen     :: (Char -> Bool) -> String -> [String]
wordsWhen p s =  case dropWhile p s of
                      "" -> []
                      s' -> w : wordsWhen p s''
                            where (w, s'') = break p s'

--calcStrVal :: String -> Int
calcStrVal s = foldl (\acc x -> if (x == '\"') then acc else acc + ord(x) - ord('A') + 1) 0 s

main = do
       s1 <- readFile "names.txt"
       print $ take 5 $ wordsWhen (==',') s1
       print $ (calcStrVal "MARY" , calcStrVal "PATRICIA" , calcStrVal "LINDA", calcStrVal "BARBARA", calcStrVal "ELIZABETH")
       print $ foldl (\acc x -> (fst acc + 1,snd acc + (fst acc) * calcStrVal x)) (1,0) $ sort $ wordsWhen (==',') s1
       print $ sum $ map snd $ scanl (\acc x -> (fst acc + 1, fst acc * x)) (1,0) $ map calcStrVal $ sort $ wordsWhen (==',') s1
            