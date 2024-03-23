n = int(input())
a = list(map(int, input().split()))
print(*[a[i] * a[i + 1] for i in range(n - 1)])