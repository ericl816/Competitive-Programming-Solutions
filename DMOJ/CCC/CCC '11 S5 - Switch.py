def switchOff(x):
    x = x.replace ("1111111","0000000")
    x = x.replace ("111111","000000")
    x = x.replace ("11111","00000")
    x = x.replace ("1111","0000")
    return x

def done(x):
    return x.find("1") < 0

def turnOnNext(x):
    left = x.find("10")
    if left >= 0:
        leftPosition = left + 1
        leftSize = 0
        while left >= 0 and x[left] == "1":
            left = left - 1
            leftSize = leftSize + 1
    else:
        leftPosition = -1
        leftSize = 99999

    right = x.rfind("01")
    if right > 0:
        rightPosition = right
        rightSize = 0
        right = right + 1
        while right < len(x) and x[right] == "1":
            right = right + 1
            rightSize = rightSize + 1
    else:
        rightPosition = -1
        rightSize = 99999
    if leftPosition > 0:
        if leftSize <= rightSize:
            x = x[0:leftPosition] +  "1" + x[leftPosition+1:]
        else:
            x = x[0:rightPosition] +  "1" + x[rightPosition+1:]
    else:
        x = x[0:rightPosition] +  "1" + x[rightPosition+1:]
    return x

K = int(input())
lights = ""
for i in range(0,K):
    lights = lights + str(raw_input())

count = 0
while not done(lights):
    lights = turnOnNext(lights)
    count = count + 1
    lights = switchOff(lights)
    
print count