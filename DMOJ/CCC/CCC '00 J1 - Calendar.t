var s, n : int

get s
put ""

get n
put ""
put "Sun Mon Tue Wed Thr Fri Sat"
for i : 1 .. s - 1
    if i = 1 then
        put "   " ..
    else
        put "    " ..
    end if
end for

for i : 1 .. n
    if s = 1 then
        put i : 3 ..
    else
        put i : 4 ..
    end if
    s := s + 1
    if s > 7 then
        put ""
        s := 1
    end if
end for