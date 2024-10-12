import math

n = int(input())
x = [0.0] * (n + 2)
y = [0.0] * (n + 2)

for i in range(1, n + 1):
    x[i], y[i] = map(float, input().split())

res = 0.0
for i in range(1, n + 2):
    dx = x[i] - x[i - 1]
    dy = y[i] - y[i - 1]
    res += math.sqrt(dx * dx + dy * dy)

print(res)
