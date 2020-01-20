var g : array 0 .. 21, 0 .. 21 of boolean
var w, h, cw, ch : int
var c, r, direction : int
var steps : int
var moving : boolean

get w, h, cw, ch, steps

for i : 0 .. 21
    for j : 0 .. 21
        if i >= 1 and i <= h and j >= 1 and j <= w and
                not ( (i <= ch and (j <= cw or j > w - cw)) or
                (i > h - ch and (j <= cw or j > w - cw))) then
            g (i, j) := true
        else
            g (i, j) := false
        end if
    end for
end for

c := cw + 1
r := 1
direction := 0
for i : 1 .. steps
    g (r, c) := false
    moving := true
    if direction = 0 then
        if g (r - 1, c) then
            r := r - 1
            direction := 90
        elsif g (r, c + 1) then
            c := c + 1
            direction := 0
        elsif g (r + 1, c) then
            r := r + 1
            direction := 270
        elsif g (r, c - 1) then
            c := c - 1
            direction := 180
        else
            moving := false
        end if
    elsif direction = 90 then
        if g (r, c - 1) then
            c := c - 1
            direction := 180
        elsif g (r - 1, c) then
            r := r - 1
            direction := 90
        elsif g (r, c + 1) then
            c := c + 1
            direction := 0
        elsif g (r + 1, c) then
            r := r + 1
            direction := 270
        else
            moving := false
        end if
    elsif direction = 180 then
        if g (r + 1, c) then
            r := r + 1
            direction := 270
        elsif g (r, c - 1) then
            c := c - 1
            direction := 180
        elsif g (r - 1, c) then
            r := r - 1
            direction := 90
        elsif g (r, c + 1) then
            c := c + 1
            direction := 0
        else
            moving := false
        end if
    elsif direction = 270 then
        if g (r, c + 1) then
            c := c + 1
            direction := 0
        elsif g (r + 1, c) then
            r := r + 1
            direction := 270
        elsif g (r, c - 1) then
            c := c - 1
            direction := 180
        elsif g (r - 1, c) then
            r := r - 1
            direction := 90
        else
            moving := false
        end if
    end if
    exit when not moving

end for
put c
put r