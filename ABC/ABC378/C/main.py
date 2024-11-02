n = int(input())

d = {}
res = []
for i, a in enumerate(list(map(int, input().split()))):
    res.append(d[a] if a in d else -1)
    d[a] = i + 1

print(*res)
