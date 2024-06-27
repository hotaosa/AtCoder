n = int(input())
a = list(map(int, input().split()))

res = 0
for i in range(1, 2 * n - 1):
    if a[i - 1] == a[i + 1]:
        res += 1

print(res)
