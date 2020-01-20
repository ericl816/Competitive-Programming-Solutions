N = int(input())
studentResponses = []
for i in range (0, N):
    studentResponses.append(raw_input())
correctAnswers = []
for i in range (0, N):
    correctAnswers.append(raw_input())

score = 0
for i in range (0, N):
    if studentResponses[i] == correctAnswers[i]:
        score = score + 1
print score