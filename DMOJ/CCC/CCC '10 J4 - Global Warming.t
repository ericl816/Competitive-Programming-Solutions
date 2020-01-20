var n, a, b : int
var diff : array 1 .. 19 of int
var pattern : int

loop
    get n
    exit when n = 0

    if n = 1 then
	get a
	put 0
    else

	get a
	for i : 1 .. n - 1
	    get b
	    diff (i) := b - a
	    a := b
	end for

	pattern := 1
	loop
	    a := 1
	    loop
		exit when a + pattern > n - 1 or diff (a) not= diff (a + pattern)
		a := a + 1
	    end loop

	    exit when a + pattern > n - 1

	    pattern := pattern + 1
	end loop
	put pattern
    end if
end loop