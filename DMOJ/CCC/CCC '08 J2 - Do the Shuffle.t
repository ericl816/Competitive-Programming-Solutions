var playlist : string (5)
var button, presses : int

playlist := "ABCDE"
loop

    get button

    get presses
    exit when button = 4 and presses = 1
    for i : 1 .. presses
        if button = 1 then
            playlist := playlist (2 .. 5) + playlist (1)
        elsif button = 2 then
            playlist := playlist (5) + playlist (1 .. 4)
        else
            playlist := playlist (2) + playlist (1) + playlist (3 .. 5)
        end if
    end for
end loop

put playlist (1) + " " + playlist (2) + " " + playlist (3) + " " +
    playlist (4) + " " + playlist (5)