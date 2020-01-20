var a, l, w : int
loop
    get a
    exit when a = 0
    l := round (sqrt (a))
    loop
        exit when a mod l = 0
        l := l - 1
    end loop
    w := a div l
    put "Minimum perimeter is ", 2 * l + 2 * w, " with dimensions ", w, 
        " X ", l
    put ""
end loop