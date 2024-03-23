n, k = map(int, input().split())
a = list(map(int, input().split()))

se = set()
res = k * (k + 1) // 2
for b in a:
    if b <= k and not b in se:
        res -= b
    se.add(b)

print(res)