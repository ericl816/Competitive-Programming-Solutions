var a, b, c, d, s : int
var nikkySteps, nikkyDistance : int
var byronSteps, byronDistance : int
var next, sgn : int

get a, b, c, d, s

nikkySteps := 0
nikkyDistance := 0
next := a
sgn := 1
loop
    exit when nikkySteps + next >= s
    nikkySteps := nikkySteps + next
    nikkyDistance := nikkyDistance + sgn * next
    if sgn = 1 then
	next := b
    else
	next := a
    end if
    sgn := sgn * -1
end loop
nikkyDistance := nikkyDistance + sgn * (s - nikkySteps)

byronSteps := 0
byronDistance := 0
next := c
sgn := 1
loop
    exit when byronSteps + next >= s
    byronSteps := byronSteps + next
    byronDistance := byronDistance + sgn * next
    if sgn = 1 then
	next := d
    else
	next := c
    end if
    sgn := sgn * -1
end loop
byronDistance := byronDistance + sgn * (s - byronSteps)

if nikkyDistance > byronDistance then
    put "Nikky"
elsif nikkyDistance < byronDistance then
    put "Byron"
else
    put "Tied"
end if