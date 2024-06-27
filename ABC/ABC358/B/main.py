n, a = map(int, input().split())

res = 0
for t in list(map(int, input().split())):
    res = max(res, t) + a
    print(res)
