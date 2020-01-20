var s : string
var t : int

loop
    get s
    exit when s = "halt"
    t := 0
    for i : 1 .. length (s)
        if index("adgjmptw", s (i)) > 0 then
            t := t + 1
        elsif index ("behknqux", s (i)) > 0 then
            t := t + 2
        elsif index ("cfilorvy", s (i)) > 0 then
            t := t + 3
        elsif index ("sz", s (i)) > 0 then
            t := t + 4
        end if
        if i > 1 and ( (index ("abc", s (i - 1)) > 0 and
                index ("abc", s (i)) > 0) or
                (index ("def", s (i - 1)) > 0 and
                index ("def", s (i)) > 0) or
                (index ("ghi", s (i - 1)) > 0 and
                index ("ghi", s (i)) > 0) or
                (index ("jkl", s (i - 1)) > 0 and
                index ("jkl", s (i)) > 0) or
                (index ("mno", s (i - 1)) > 0 and
                index ("mno", s (i)) > 0) or
                (index ("pqrs", s (i - 1)) > 0 and
                index ("pqrs", s (i)) > 0) or
                (index ("tuv", s (i - 1)) > 0 and
                index ("tuv", s (i)) > 0) or
                (index ("wxyz", s (i - 1)) > 0 and
                index ("wxyz", s (i)) > 0)) then
            t := t + 2
        end if
    end for
    put t
end loop