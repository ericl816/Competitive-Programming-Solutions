function rotatable (xx : int) : boolean
    var a : array 1 .. 5 of int
    var x, i : int
    var okay : boolean := true
    x := xx
    i := 0
    loop
        exit when x = 0
        i := i + 1
        a (i) := x mod 10
        x := x div 10
    end loop
    for j : 1 .. i
        if (a (j) = 0 and a (i - j + 1) = 0) or
                (a (j) = 1 and a (i - j + 1) = 1) or
                (a (j) = 8 and a (i - j + 1) = 8) or
                (a (j) = 9 and a (i - j + 1) = 6) or
                (a (j) = 6 and a (i - j + 1) = 9) then
        else
            okay := false
        end if
    end for
    result okay
end rotatable

var m, n : int
var count : int

get m
put ""

get n
put ""
count := 0

for i : m .. n
    if rotatable (i) then
        count := count + 1
    end if
end for
put count