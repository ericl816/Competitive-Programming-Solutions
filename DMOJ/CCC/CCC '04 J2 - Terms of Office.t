var cy, fy,m,t,c,d: int

get cy

get fy
m:=0
t:=0
c:=0
d:=0
for y: cy .. fy
    if m = 0 and t = 0 and c = 0 and d = 0 then
        put "All positions change in year ", y
    end if    
    m := (m+1) mod 4
    t := (t+1) mod 2
    c := (c+1) mod 3
    d := (d+1) mod 5
end for