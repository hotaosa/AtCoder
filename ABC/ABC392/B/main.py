n, m = map(int, input().split())
a = list(map(int, input().split()))
print(n - m)
print(*set([i + 1 for i in range(n)]).difference(a))
