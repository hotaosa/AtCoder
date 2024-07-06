n, k = map(int, input().split())
a = sorted(list(map(int, input().split())))

l = n - k
res = a[-1] - a[0]
for i in range(k + 1):
    res = min(res, a[i + l - 1] - a[i])

print(res)
