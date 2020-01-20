var burger, side, drink, dessert : int
var calorie : int

get burger

get side

get drink

get dessert

if burger = 1 then
    calorie := 461
elsif burger = 2 then
    calorie := 431
elsif burger = 3 then
    calorie := 420
else
    calorie := 0
end if

if side = 1 then
    calorie := calorie + 100
elsif side = 2 then
    calorie := calorie + 57
elsif side = 3 then
    calorie := calorie + 70
else
    calorie := calorie + 0
end if

if drink = 1 then
    calorie := calorie + 130
elsif drink = 2 then
    calorie := calorie + 160
elsif drink = 3 then
    calorie := calorie + 118
else
    calorie := calorie + 0
end if

if dessert = 1 then
    calorie := calorie + 167
elsif dessert = 2 then
    calorie := calorie + 266
elsif dessert = 3 then
    calorie := calorie + 75
else
    calorie := calorie + 0
end if

put ""
put "Your total Calorie count is ", calorie, "."