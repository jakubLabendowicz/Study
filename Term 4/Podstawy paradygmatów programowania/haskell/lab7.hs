module Lab7 where
    -- sign1 x =
    --     if x<0 then -1
    --     else
    --         if x==0 then 0
    --         else 1
    
    -- mul2 1 b = b
    -- mul2 a b = b + mul2 (a-1) b

    -- fact x = case x of
    --     x<0 -> error "mniejsze od zera"
    --     x == 0 -> 1
    --     _ -> x * fact (x-1)

    fact x
        | x<0 = error "mniejsze od zera"
        | x == 0 = 1
        | otherwise = x * fact (x-1)







        --zad 2, 3 str. 61