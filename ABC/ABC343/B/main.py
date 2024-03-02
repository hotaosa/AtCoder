n = int(input())
g = []
for _ in range(n):
    a = list(map(int, input().split()))
    g.append([i + 1 for i in range(n) if a[i]])

for ng in g:
    print(*ng)