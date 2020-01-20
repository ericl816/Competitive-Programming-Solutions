var x, a, b, c : int
var count : int := 0

get x
put ""

get a
put ""

get b
put ""

get c
put ""

loop
    exit when x = 0
    x := x - 1
    count := count + 1
    a := a + 1
    if a = 35 then
        a := 0
        x := x + 30
    end if
    exit when x = 0
    x := x - 1
    count := count + 1
    b := b + 1
    if b = 100 then
        b := 0
        x := x + 60
    end if
    exit when x = 0
    x := x - 1
    count := count + 1
    c := c + 1
    if c = 10 then
        c := 0
        x := x + 9
    end if
end loop

put "Martha plays ", count, " times before going broke."