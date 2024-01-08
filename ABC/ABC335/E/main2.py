# UnionFind

class UnionFind():
    def __init__(self, n):
        self.n = n
        self.par = [-1] * n
        self.siz = [1] * n

    def merge(self, x, y):
        x = self.leader(x)
        y = self.leader(y)
        if (x == y):
            return False
        if (self.siz[x] < self.siz[y]):
            x, y = y, x
        self.siz[x] += self.siz[y]
        self.par[y] = x

    def leader(self, x):
        if self.par[x] == -1:
            return x
        else:
            self.par[x] = self.leader(self.par[x])
            return self.par[x]

n, m = map(int, input().split())
a = list(map(int, input().split()))
u = [0] * m
v = [0] * m

uf = UnionFind(n)

for i in range(m):
    u[i], v[i] = map(int, input().split())
    u[i] -= 1
    v[i] -= 1
    if a[u[i]] == a[v[i]]:
        uf.merge(u[i], v[i])

graph = [[] for _ in range(n)]
for i in range(m):
    lu = uf.leader(u[i])
    lv = uf.leader(v[i])
    if a[lu] < a[lv]: graph[lu].append(lv)
    if a[lv] < a[lu]: graph[lv].append(lu)

dist = [0] * n
dist[uf.leader(0)] = 1
o = [i for i in range(n)]
o = sorted(o, key=lambda x: a[x])

for v in o:
    if uf.leader(v) != v or dist[v] == 0: continue
    for nv in graph[v]:
        add = 1 if a[nv] > a[v] else 0
        dist[nv] = max(dist[nv], dist[v] + add)

print(dist[uf.leader(n - 1)])
