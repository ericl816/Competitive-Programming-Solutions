var t, s, h : int

get t

get s

get h
for i : 1 .. t
    put "*" ..
    for j : 1 .. s
        put " " ..
    end for
    put "*" ..
    for j : 1 .. s
        put " " ..
    end for
    put "*"
end for
for i : 1 .. 2 * s + 3
    put "*" ..
end for
put ""
for i : 1 .. h
    for j : 1 .. s + 1
        put " " ..
    end for
    put "*"
end for