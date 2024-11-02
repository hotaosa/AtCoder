a = list(map(int, input().split()))
print(sum(a.count(i) // 2 for i in range(5)))
