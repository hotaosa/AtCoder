# Dijcstra

import heapq

n, m = map(int, input().split())
a = list(map(int, input().split()))

graph = [[] for _ in range(n)]
for _ in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    if a[u] <= a[v]:
        graph[u].append(v)
    if a[v] <= a[u]:
        graph[v].append(u)

dist = [0] * n
dist[0] = 1

pque = []
heapq.heappush(pque, (a[0], -1, 0))
while len(pque) > 0:
    _, dv, v = heapq.heappop(pque)
    if -dv < dist[v]:
        continue
    for nv in graph[v]:
        add = 1 if a[nv] > a[v] else 0
        if dist[nv] < dist[v] + add:
            dist[nv] = dist[v] + add
            heapq.heappush(pque, (a[nv], -dist[nv], nv))

print(dist[-1])
