n, k = map(int, input().split())
a = list(map(int, input().split()))
print(*(a[n - k :] + a[: n - k]))
