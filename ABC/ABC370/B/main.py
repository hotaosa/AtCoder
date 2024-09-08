def decrease(x):
    return int(x) - 1


n = int(input())
a = [list(map(decrease, input().split())) for _ in range(n)]

e = 0
for i in range(0, n):
    if i >= e:
        e = a[i][e]
    else:
        e = a[e][i]

print(e + 1)
