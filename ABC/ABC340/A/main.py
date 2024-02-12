a, b, d = map(int, input().split())
res = [x for x in range(a, b + 1, d)]
print(*res)