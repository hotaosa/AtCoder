n = int(input())
li = []

for _ in range(n):
    l, r = map(int, input().split())
    li.append((l, 0))
    li.append((r, 1))

li = sorted(li)
res = 0
cur = 0
for _, v in li:
    if v:
        cur -= 1
        res += cur
    else:
        cur += 1

print(res)