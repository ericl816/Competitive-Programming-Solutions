function gcd (m, n : int) : int
    if n = 0 then
        result m
    else
        result gcd (n, m mod n)
    end if
end gcd

var num, den, hold : int

get num

get den
hold := num
num := num div gcd (num, den)
den := den div gcd (hold, den)
if num > den then
    put num div den, " " ..
end if
if num mod den > 0 then
    put num mod den, "/", den
end if