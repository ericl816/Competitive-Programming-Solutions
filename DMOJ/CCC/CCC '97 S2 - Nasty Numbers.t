function nasty (x : int) : boolean
    var f1, f2 : int
    var s : real := sqrt (x)
    var diff : int

    f1 := 1
    loop
        exit when f1 > s
      
        loop
            exit when f1 > s or x mod f1 = 0
            f1 := f1 + 1
        end loop
        if f1 < s then
            diff := (x div f1) - f1
            f2 := f1 + 1
        
            loop
                loop
                    exit when f2 > s or x mod f2 = 0
                    f2 := f2 + 1
                end loop
                exit when f2 > s or (x div f2) + f2 <= diff
                f2 := f2 + 1
            end loop
            
            if f2 < s and x div f2 + f2 = diff then
                result true
            end if
        end if
        
        f1 := f1 + 1
    end loop
    
    result false
end nasty

var n, x : int

get  n
for i : 1 .. n
    get  x
    if nasty (x) then
        put x, " is nasty"
        
    else
        put x, " is not nasty"
    end if
end for