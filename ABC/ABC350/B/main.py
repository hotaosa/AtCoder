n, q = map(int, input().split())
res = [1] * n
for t in map(int, input().split()):
    res[t - 1] ^= 1
print(sum(res))