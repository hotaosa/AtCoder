m = int(input())

cnt = 0
cur = 1
while cur * 3 <= m:
    cnt += 1
    cur *= 3

res = []
while m:
    while cur <= m:
        res.append(cnt)
        m -= cur
    cnt -= 1
    cur //= 3

print(len(res))
print(*res)
