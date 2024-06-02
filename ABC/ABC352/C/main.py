n = int(input())
a = [0] * n
b = [0] * n

for i in range(n):
    a[i], b[i] = map(int, input().split())

print(sum(a) + max([y - x for x, y in zip(a, b)]))
