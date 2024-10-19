n, c = map(int, input().split())

res = 0
prev = -c
for t in map(int, input().split()):
    if t >= prev + c:
        res += 1
        prev = t

print(res)
