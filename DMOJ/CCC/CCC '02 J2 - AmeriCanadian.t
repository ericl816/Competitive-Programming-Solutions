function convert (s : string) : string
    if length (s) > 4 then
        if s (* - 1.. *) = "or" and
                not (s (* - 2) = "a"
                or s (* - 2) = "e"
                or s (* - 2) = "i"
                or s (* - 2) = "o"
                or s (* - 2) = "u"
                or s (* - 2) = "y") then
            result s (1 .. * - 2) + "our"
        else
            result s
        end if
    else
        result s
    end if
end convert


var s : string

loop
    get s
    exit when s = "quit!"
    put convert (s)
end loop