var x, m, n : int
get x
get m
n := 1
loop 
    exit when n >= m or x * n mod m = 1 
    n := n + 1
    end loop
    put ""
    if n >= m then
    put "No such integer exists."
    else 
       put n
       end if