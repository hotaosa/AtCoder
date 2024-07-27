n, x, y = map(int, input().split())

a = sorted(list(map(int, input().split())))
b = sorted(list(map(int, input().split())))

res = n
for _ in range(2):
    sum = 0
    for i in range(1, n + 1):
        sum += a[-i]
        if sum > x:
            res = min(res, i)
            break
    a, b = b, a
    x, y = y, x

print(res)
