-- ilo x = foldr (*) 1 x

-- [ (a,b,c) | c <- [1..20], b <- [1..20], a <- [1..20], a^2 + b^2 == c^2 ]

--zad5
silnia1 x = product [1..x]
silnia = map silnia1 (filter (even) [1..20])


--zad 6
pol6 = map (\x -> x*x) [1 .. z]
        where z = 20

kwadrat = map (\x -> x^2) [0..20]

--zad7
weirdNubmerNotLazy = maximum list
    where list = filter (\x -> mod x 3829 == 0) [1000000, 999999..0]

weirdNuumber = filter (\x -> mod x 3829 == 0) [1000000, 999999..] !! 0

--zad8
zad8 = length lista
    where lista = map(\x -> x*x) [1.2 .. 10000]