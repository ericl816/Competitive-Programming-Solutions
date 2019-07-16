var N, K : int 
get N
get K
if N < K then
put K - N
else 
put min(N mod K, K - (N mod K))
end if 
