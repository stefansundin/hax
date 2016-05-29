-- If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.
-- {20,48,52}, {24,45,51}, {30,40,50}
-- For which value of p ≤ 1000, is the number of solutions maximised?

-- p = a+b+c
-- a^2 + b^2 = c^2
-- b = p-a-c
-- a^2 + (p-a-c)^2 = c^2, solve c
-- c = - (2a^2-2ap+p^2) / (2a-2p)    a != p

import Data.List
import Data.Ord

maxi xs = maximumBy (comparing fst) (zip xs [0..])

count [] = 0
count (x:xs)
  | x == True = 1 + count xs
  | otherwise = count xs


solve_c p a =
  - (2*a^2-2*a*p+p^2) `div` (2*a-2*p)

is_right_triangle a b c =
  a^2 + b^2 == c^2

is_triangle p a =
  let
    c = solve_c p a
    b = p - a - c
  in a < b && p == a+b+c && is_right_triangle a b c

triangles_for_p p =
  count (map (is_triangle p) [1..(p `div` 2)])

main = do
  print (maxi (map triangles_for_p [0..1000]))
