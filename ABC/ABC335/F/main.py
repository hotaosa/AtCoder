mod = 998244353
n = int(input())
a = list(map(int, input().split()))

siz = int(n ** 0.5)
dp1 = [0] * n
dp2 = [[0] * i for i in range(siz)]

dp1[0] = 1
for i in range(0, n):
    for j in range(1, siz):
        dp1[i] += dp2[j][i % j]
        dp1[i] %= mod
    if a[i] >= siz:
        for j in range(i + a[i], n, a[i]):
            dp1[j] += dp1[i]
            dp1[j] %= mod
    else:
        dp2[a[i]][i % a[i]] += dp1[i]
        dp2[a[i]][i % a[i]] %= mod

print(sum(dp1) % mod)
