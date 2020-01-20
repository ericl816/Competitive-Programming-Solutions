def units(b,p):
    u = min(blood[b], patients[p])
    blood[b] = blood[b] - u
    patients[p] = patients[p] - u 
    return u

line = raw_input()
blood = []
for i in range (0,7):
    space = line.find(" ")
    blood.append(eval(line[0:space]))
    line = line[space+1:]
blood.append(eval(line))    

line = raw_input()
patients = []
for i in range (0,7):
    space = line.find(" ")
    patients.append(eval(line[0:space]))
    line = line[space+1:]
patients.append(eval(line))    

holdpatients = list(patients)
holdblood = list(blood)

total = 0

total = total + units(0,0)

total = total + units(1,1) + units(0,1)

total = total + units(2,2) + units(0,2)

total = total + units(4,4) + units(0,4)

total = total + units(3,3) + units(1,3) 

total = total + units(5,5) + units(1,5)

total = total + units(2,3) + units(0,3) 

total = total + units(4,5) + units(0,5)

total = total + units(6,6) + units(4,6) + units(2,6) + units(0,6)

total = total + units(7,7) + units(6,7) + units(5,7) + units(4,7) + units(3,7) + units(2,7) + units(1,7) + units(0,7)


patients = holdpatients
blood = holdblood

total2 = 0

total2 = total2 + units(0,0)

total2 = total2 + units(1,1) + units(0,1)

total2 = total2 + units(2,2) + units(0,2)

total2 = total2 + units(4,4) + units(0,4)

total2 = total2 + units(3,3) + units(2,3)

total2 = total2 + units(5,5) + units(4,5)

total2 = total2 + units(1,3) + units(0,3) 

total2 = total2 + units(1,5) + units(0,5)

total2 = total2 + units(6,6) + units(4,6) + units(2,6) + units(0,6)

total2 = total2 + units(7,7) + units(6,7) + units(5,7) + units(4,7) + units(3,7) + units(2,7) + units(1,7) + units(0,7)


print max (total, total2)