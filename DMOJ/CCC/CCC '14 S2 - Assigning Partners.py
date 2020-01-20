n = int(input())

first = raw_input().split()
second = raw_input().split()

i = 0
state = "good"
while i < n and state == "good":
    position = first.index(second[i])
    if first[i] != second[position] or position == i:
        state = "bad"
    i = i + 1
    
print state