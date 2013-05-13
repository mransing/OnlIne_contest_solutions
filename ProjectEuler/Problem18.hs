import Control.Monad.ST
import Data.Array.ST
import Data.Array.IO

returnPair :: Int -> (Int, Int)
returnPair x = (x ,(x * (x+1) ) `div` 2 )

newList = map returnPair [1..20]

someList = [5,10,15,16,26,36]

getIndex x y = ((x*(x+1)) `div` 2) + y

access arr x y = readArray arr $ getIndex x y

calcPathLeft arr newarr x y = if y == 0 then access arr x y else (access newarr (x-1) (y-1)) + (access arr x y)

calcPathRight arr newarr x y = if (y == x) then access arr x y else (access newarr (x-1) y) + (access arr x y)

calculateBestPath arr newarr x y = do p <- let p1 = calcPathLeft arr newarr x y
                                               p2 = calcPathRight arr newarr x y
                                           in if (p1 < p2) then p2 else p1
                                      writeArray newarr (getIndex x y) p
                                      return newarr
--calc arr newarr n = foldl (\acc x -> let q = ) [1..n]

buildPair x = do arr <- newListArray (0,length x -1) x :: IO (IOArray Int Int)
                 newarr <- newArray (0,length x -1) 0 :: IO (IOArray Int Int)
                 return (arr,newarr)

main = do a <- buildPair someList
          b <- getElems $ fst a
          print b
          print newList
