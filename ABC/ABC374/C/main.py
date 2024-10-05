n = int(input())
k = list(map(int, input().split()))

res = 1 << 30
for b in range(1 << n):
    x = 0
    y = 0
    for i in range(n):
        if b >> i & 1:
            x += k[i]
        else:
            y += k[i]
    res = min(res, max(x, y))

print(res)
