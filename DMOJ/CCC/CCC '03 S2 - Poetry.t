var n : int
var a, b, c, d : string

function lastSyllable (s : string) : string
    var i : int
    var vowels : string := "aeiou "
    i := length (s)
    loop
        exit when i = 0 or index (vowels, s (i)) > 0
        i := i - 1
    end loop
    if i = 0 or s (i) = " " then
        result s (i + 1 .. *)
    else
        result s (i .. *)
    end if
end lastSyllable

function toLower (s : string) : string
    var t : string := ""
    for i : 1 .. length (s)
        if s (i) < "A" or s (i) > "Z" then
            t := t + s (i)
        else
            t := t + chr (ord (s (i)) - ord ('A') + ord ('a'))
        end if
    end for
    result t
end toLower

get n
for i : 1 .. n
    get a : *
    get b : *
    get c : *
    get d : *
    a := lastSyllable (toLower (a))
    b := lastSyllable (toLower (b))
    c := lastSyllable (toLower (c))
    d := lastSyllable (toLower (d))
    if a = b and b = c and c = d then
        put "perfect"
    elsif a = b and c = d then
        put "even"
    elsif a = c and b = d then
        put "cross"
    elsif a = d and b = c then
        put "shell"
    else
        put "free"
    end if
end for