n, m = map(int, input().split())
g = [set([i]) for i in range(n)]
res = 0
for _ in range(m):
    u, v = map(int, input().split())
    if v - 1 in g[u - 1]:
        res += 1
    g[u - 1].add(v - 1)
    g[v - 1].add(u - 1)

print(res)
