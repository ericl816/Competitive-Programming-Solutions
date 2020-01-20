import sys
input = sys.stdin.readline

words = list(input().split())
for i in range(len(words)):
    if words[i][0].isupper() and i != 0:
        words[i - 1] = words[i - 1] + '.'
words[len(words) - 1] = words[len(words) - 1] + '.'
print(' '.join(words))