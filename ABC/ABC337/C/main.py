n = int(input())
nx = [-1] * n

v = -1
a = list(map(int, input().split()))
for i in range(len(a)):
    if (a[i] == -1):
        v = i
    else:
        nx[a[i] - 1] = i

while v != -1:
    print(v + 1, end=' ')
    v = nx[v]
