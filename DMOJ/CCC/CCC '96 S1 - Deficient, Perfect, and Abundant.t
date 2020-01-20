function sumFactors (x : int) : int
    var sum : int
    sum := 0
    for f : 1 .. x - 1
        if x mod f = 0 then
            sum := sum + f
        end if
    end for
    result sum
end sumFactors

var n : int
var x : int
var sum : int

get  n
for i : 1 .. n
    get x
    sum := sumFactors (x)
    if sum < x then
        put x, " is a deficient number."

    elsif x = sum then
        put x, " is a perfect number."
     
    else
        put x, " is an abundant number."
       
    end if
end for