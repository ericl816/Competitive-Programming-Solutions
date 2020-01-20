word = raw_input()

consonant =     "bcdfghjklmnpqrstvwxyz"
closestVowel =  "aaeeeiiiiooooouuuuuuu"
nextConsonant = "cdfghjklmnpqrstvwxyzz"

newWord = ""
for i in range(len(word)):
    j = consonant.find (word[i])
    newWord = newWord + word[i]  
    if j > -1:                   
        newWord = newWord + closestVowel [j] + nextConsonant[j]

print newWord