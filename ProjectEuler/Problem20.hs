import Data.Char

n = 100
p = product [1..100]
mc = show p
mi = map digitToInt mc
main = print (sum mi)
