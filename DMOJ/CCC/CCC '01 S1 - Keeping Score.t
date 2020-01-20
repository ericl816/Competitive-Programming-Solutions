procedure Points (var s : string, var p : int)
    var i : int
    i := 1
    p := 0
    loop
        exit when i > length (s) or s (i) = "C" or s (i) = "D" or s (i) =
            "H" or s (i) = "S"
        put s (i), " " ..
        if s (i) = "J" then
            p := p + 1
        elsif s (i) = "Q" then
            p := p + 2
        elsif s (i) = "K" then
            p := p + 3
        elsif s (i) = "A" then
            p := p + 4
        end if
        i := i + 1
    end loop
    if i = 1 then
        p := p + 3
    elsif i = 2 then
        p := p + 2
    elsif i = 3 then
        p := p + 1
    end if
    s := s (i .. *)
end Points

var p, tp : int
var s : string

get s

tp := 0
put ""
put "Cards Dealt                       Points"

s := s (2 .. *)
put "Clubs " ..
Points (s, p)

put p : 2
tp := tp + p

s := s (2 .. *)
put "Diamonds " ..
Points (s, p)

put p : 2
tp := tp + p

s := s (2 .. *)
put "Hearts " ..
Points (s, p)

put p : 2
tp := tp + p

s := s (2 .. *)
put "Spades " ..
Points (s, p)

put p : 2
tp := tp + p

put "                              Total ", tp : 2