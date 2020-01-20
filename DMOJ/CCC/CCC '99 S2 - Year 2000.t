var n : int
var line : string

function dn (s : string (1)) : boolean
    if s >= "a" and s <= "z" or
            s >= "A" and s <= "Z" or
            s >= "0" and s <= "9" then
        result true
    else
        result false
    end if
end dn

procedure dmy (i : int, var s : string)
    if i > 1 and dn (s (i - 1)) then

    elsif i + 8 <= length (s) and dn (s (i + 8)) then

    elsif i + 7 > length (s) then

    elsif strintok (s (i .. i + 1)) and strint (s (i .. i + 1)) >= 1 and
            strint (s (i .. i + 1)) <= 31 and
            s (i + 2) = "/" and
            strintok (s (i + 3 .. i + 4)) and strint (s (i + 3 .. i + 4)) >=
            1 and strint (s (i + 3 .. i + 4)) <= 12 and
            s (i + 5) = "/" and
            strintok (s (i + 6 .. i + 7)) and strint (s (i + 6 .. i + 7)) >=
            0 and strint (s (i + 6 .. i + 7)) <= 99 then
        if strint (s (i + 6 .. i + 7)) < 25 then
            s := s (1 .. i + 5) + "20" + s (i + 6 .. *)
        else
            s := s (1 .. i + 5) + "19" + s (i + 6 .. *)
        end if
    end if
end dmy

procedure ymd (i : int, var s : string)
    if i > 1 and dn (s (i - 1)) then

    elsif i + 8 <= length (s) and dn (s (i + 8)) then

    elsif i + 7 > length (s) then

    elsif strintok (s (i .. i + 1)) and strint (s (i .. i + 1)) >= 0 and
            strint (s (i .. i + 1)) <= 99 and
            s (i + 2) = "." and
            strintok (s (i + 3 .. i + 4)) and strint (s (i + 3 .. i + 4)) >=
            1 and strint (s (i + 3 .. i + 4)) <= 12 and
            s (i + 5) = "." and
            strintok (s (i + 6 .. i + 7)) and strint (s (i + 6 .. i + 7)) >=
            1 and strint (s (i + 6 .. i + 7)) <= 31 then
        if strint (s (i .. i + 1)) < 25 then
            s := s (1 .. i - 1) + "20" + s (i .. *)
        else
            s := s (1 .. i - 1) + "19" + s (i .. *)
        end if
    end if
end ymd

procedure mdy (i : int, var s : string)
    if i > 1 and dn (s (i - 1)) then

    else
        var x : int
        if i + 6 <= length (s) and s (i .. i + 6) = "January" then
            x := i + 7
        elsif i + 7 <= length (s) and s (i .. i + 7) = "February" then
            x := i + 8
        elsif i + 4 <= length (s) and s (i .. i + 4) = "March" then
            x := i + 5
        elsif i + 4 <= length (s) and s (i .. i + 4) = "April" then
            x := i + 5
        elsif i + 2 <= length (s) and s (i .. i + 2) = "May" then
            x := i + 3
        elsif i + 3 <= length (s) and s (i .. i + 3) = "June" then
            x := i + 4
        elsif i + 3 <= length (s) and s (i .. i + 3) = "July" then
            x := i + 4
        elsif i + 5 <= length (s) and s (i .. i + 5) = "August" then
            x := i + 6
        elsif i + 8 <= length (s) and s (i .. i + 8) = "September" then
            x := i + 9
        elsif i + 6 <= length (s) and s (i .. i + 6) = "October" then
            x := i + 7
        elsif i + 7 <= length (s) and s (i .. i + 7) = "November" then
            x := i + 8
        elsif i + 7 <= length (s) and s (i .. i + 7) = "December" then
            x := i + 8
        else
            x := 99999
        end if
        if x + 7 <= length (s) and dn (s (x + 7)) then

        elsif x + 6 > length (s) then

        elsif s (x) = " " and
                strintok (s (x + 1 .. x + 2)) and strint (s (x + 1 .. x +
                2)) >= 1 and
                strint (s (x + 1 .. x + 2)) <= 31 and
                s (x + 3 .. x + 4) = ", " and
                strintok (s (x + 5 .. x + 6)) and strint (s (x + 5 .. x +
                6)) >= 0 and strint (s (x + 5 .. x + 6)) <= 99 then
            if strint (s (x + 5 .. x + 6)) < 25 then
                s := s (1 .. x + 4) + "20" + s (x + 5 .. *)
            else
                s := s (1 .. x + 4) + "19" + s (x + 5 .. *)
            end if
        end if
    end if
end mdy

get n
for i : 1 .. n
    get line : *
    var j : int := 1
    loop
        exit when j >= length (line)
        dmy (j, line)
        ymd (j, line)
        mdy (j, line)
        j := j + 1
    end loop
    put line
end for