m = int(input())

database = []
time = -1
for i in range(m):
    line = raw_input().split()
    letter = line[0]
    friend = int(line[1])

    if letter == "W":
        time = time + friend - 1   
                                   
    else:
        time = time + 1

    if letter != "W":

        found = False
        k = 0
        while not found and k < len(database):
            if friend == database[k][0]:
                found = True
            else:
                k = k + 1

        if letter == "R":       
          
            if found:
                database[k][1] = time
            else:
                database.append ([friend, time, 0])
        elif letter == "S":

            database[k][2] = database[k][2] + (time - database[k][1])
            database[k][1] = -1

for i in range(len(database)-1):
    for j in range(i+1, len(database)):
        if database[i][0] > database[j][0]:
            temp = database[i]
            database[i] = database[j]
            database[j] = temp

for i in range(len(database)):
    if database[i][1] == -1:
        print database[i][0], database[i][2]
    else:
        print database[i][0], -1