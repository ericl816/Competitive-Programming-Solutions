var start, stop : int
var i, j : int 
var r, c : int 
var k : int 

get start

get stop


r := 12
c := 20
k := 0
i := start
loop
    exit when i > stop
    k := k + 1

    j := 1
    loop
        exit when j > k or i > stop
        put i : 3 ..
        r := r + 1
        j := j + 1
        i := i + 1
    end loop

    j := 1
    loop
        exit when j > k or i > stop
        put i : 3 ..
        c := c + 3
        j := j + 1
        i := i + 1
    end loop

    k := k + 1

    j := 1
    loop
        exit when j > k or i > stop
        put i : 3 ..
        r := r - 1
        j := j + 1
        i := i + 1
    end loop

    j := 1
    loop
        exit when j > k or i > stop
        put i : 3 ..
        c := c - 3
        j := j + 1
        i := i + 1
    end loop
end loop