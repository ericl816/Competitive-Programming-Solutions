var n : int
var ns, nv, no : int
var s, v, o : array 1 .. 20 of string

get n
for i : 1 .. n
    get ns
    get nv
    get no
    for j : 1 .. ns
        get s (j) : *
    end for
    for j : 1 .. nv
        get v (j) : *
    end for
    for j : 1 .. no
        get o (j) : *
    end for
    for j : 1 .. ns
        for k : 1 .. nv
            for m : 1 .. no
                put s (j), " ", v (k), " ", o (m), "."
            end for
        end for
    end for
    put ""
end for