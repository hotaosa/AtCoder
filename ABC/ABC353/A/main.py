n = int(input())
h = list(map(int, input().split()))

res = -1
for i in range(n - 1, 0, -1):
    if h[i] > h[0]:
        res = i + 1

print(res)
