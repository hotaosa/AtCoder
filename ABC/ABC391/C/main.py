n, q = [int(x) for x in input().split()]

cnt = [1] * (n + 1)
pos = [i for i in range(n + 1)]

res = 0
while q:
    q -= 1
    query = input()
    if query[0] == "1":
        _, p, h = [int(x) for x in query.split()]
        if cnt[pos[p]] == 2:
            res -= 1
        cnt[pos[p]] -= 1
        pos[p] = h
        if cnt[h] == 1:
            res += 1
        cnt[h] += 1
    else:
        print(res)
