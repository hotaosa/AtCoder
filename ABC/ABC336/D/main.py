n = int(input())
a = list(map(int, input().split()))

dp1 = [0] * n
dp2 = [0] * n
dp1[0] = dp2[n - 1] = 1

for i in range(1, n):
    dp1[i] = min(dp1[i - 1] + 1, a[i])
for i in range(n - 2, 0, -1):
    dp2[i] = min(dp2[i + 1] + 1, a[i])

res = 0
for i in range(n):
    res = max(res, min(dp1[i], dp2[i]))

print(res)