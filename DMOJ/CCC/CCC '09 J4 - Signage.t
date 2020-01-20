function full (s : string, w : int) : string
    var t : string
    var i : int
    i := 1
    t := s
    if index (t, ".") > 0 then
        loop
            exit when length (t) = w

            loop
                exit when t (i) = "."
                i := i + 1
                if i > length (t) then
                    i := 1
                end if
            end loop

            t  := t (1 .. i) + "." + t (i + 1 .. *)

            loop
                exit when t (i) not = "."
                i := i + 1
                if i > length (t) then
                    i := 1
                end if
            end loop
        end loop
    else

        loop
            exit when length (t) = w
            t := t + "."
        end loop
    end if
    result t
end full

var words : array 1 .. 6 of string
var w, i, space : int
var s : string

words (1) := "WELCOME"
words (2) := "TO"
words (3) := "CCC"
words (4) := "GOOD"
words (5) := "LUCK"
words (6) := "TODAY"

get w

s := words (1)
i := 2

loop
    exit when i > 6

    loop
        exit when i > 6 or length (s) + length (words (i)) + 1 > w
        s := s + "." + words (i)
        i := i + 1
    end loop

    put full (s, w)

    if i <= 6 then
        s := words (i)
    else
        s := ""
    end if

    i := i + 1
end loop

if length (s) > 0 then
    put full (s, w)
end if