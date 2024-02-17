import math

n, m, k = map(int, input().split())
lsm = n // math.gcd(n, m) * m

l = 0
r = int(1e20)
while r - l > 1:
    x = (l + r) // 2
    cnt = x // n + x // m - x // lsm * 2
    if cnt >= k:
        r = x
    else:
        l = x

print(r)
