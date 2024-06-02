n, m = map(int, input().split())
a = list(map(int, input().split()))

for _ in range(n):
    x = list(map(int, input().split()))
    for i in range(m):
        a[i] -= x[i]

for b in a:
    if b > 0:
        print('No')
        exit()

print('Yes')