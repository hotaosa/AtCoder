from collections import deque

n = int(input())
a = list(map(int, input().split()))

dq = deque()
for x in a:
    dq.append(x)
    while len(dq) > 1 and dq[-1] == dq[-2]:
        dq.pop()
        dq[-1] += 1

print(len(dq))
