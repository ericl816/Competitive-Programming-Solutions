import sys
input = sys.stdin.readline

wordslist = list(input().split())
for i in range(len(wordslist)):
    if i != 0 and wordslist[i][0].isupper():
        wordslist[i - 1] = wordslist[i - 1] + '.'
wordslist[-1] = wordslist[-1] + '.'
print(' '.join(wordslist))