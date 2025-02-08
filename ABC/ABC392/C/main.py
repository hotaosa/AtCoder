n = int(input())
p = list(map(int, input().split()))
q = list(map(int, input().split()))

res = [0] * n
for i in range(n):
    res[q[i] - 1] = q[p[i] - 1]
print(*res)
