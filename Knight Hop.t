var board : array 1 .. 8, 1 .. 8 of int

procedure knightMove (x : int, y : int, steps : int)
    if x > 0 and x <= 8 and y > 0 and y <= 8 and steps < board (x, y) then
        board (x, y) := steps
        knightMove (x - 1, y + 2, steps + 1)
        knightMove (x - 1, y - 2, steps + 1)
        knightMove (x + 1, y + 2, steps + 1)
        knightMove (x + 1, y - 2, steps + 1)
        knightMove (x - 2, y + 1, steps + 1)
        knightMove (x - 2, y - 1, steps + 1)
        knightMove (x + 2, y + 1, steps + 1)
        knightMove (x + 2, y - 1, steps + 1)
    end if
end knightMove


var xStart, yStart : int
var xEnd, yEnd : int

get xStart, yStart, xEnd, yEnd

for i : 1 .. 8
    for j : 1 .. 8
        board (i, j) := 99999
    end for
end for

knightMove (xStart, yStart, 0)

put board (xEnd, yEnd)
