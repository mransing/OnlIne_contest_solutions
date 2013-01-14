import Data.Bits
import Data.Int
import Control.Monad

nbits :: Int -> Int
nbits 0 = 0
nbits n = 1 + nbits (n .&. (n-1))

main = do 
        nTests <- readLn 
        replicateM_ nTests $ do 
         y <- readLn 
         print $ ((y `div` 2048::Int) + nbits (y `mod` 2048::Int))  