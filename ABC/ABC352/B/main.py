from collections import deque

s = deque(list(input()))
t = input()

res = []
for i in range(len(t)):
    if t[i] == s[0]:
        res.append(i + 1)
        s.popleft()

print(*res)