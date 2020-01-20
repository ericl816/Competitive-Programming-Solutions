var phrase : string (40)
var letter : char
var x : int
var movements, r, c, newr, newc : int

get phrase : *
movements := 0
r := 1
c := 1
for i : 1 .. length (phrase)
    letter := phrase (i)
    
    if letter >= 'A' and letter <= 'Z' then
        x := ord (letter) - ord ('A') + 1
        newr := (x - 1) div 6 + 1
        newc := (x - 1) mod 6 + 1
    elsif letter = ' ' then
        newr := 5
        newc := 3
    elsif letter = '-' then
        newr := 5
        newc := 4
    elsif letter = '.' then
        newr := 5
        newc := 5
    end if
    movements := movements + abs (newr - r) + abs (newc - c)
    r := newr
    c := newc
end for

movements := movements + abs (newr - 5) + abs (newc - 6)

put movements