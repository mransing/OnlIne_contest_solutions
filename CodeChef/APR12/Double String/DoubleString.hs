import Control.Monad
import Data.Bits as B (complement)
import Data.Int
import Data.Bits

main = do 
  noOfTests <- readLn
  replicateM_ noOfTests $ do 
      y <- readLn
      putStrLn $ show (y .&. (complement 1::Int32))
--      putStrLn $ show (if y `mod` 2 == 0 then y else y-1)