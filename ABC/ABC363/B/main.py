n, t, p = map(int, input().split())
l = list(reversed(sorted(list(map(int, input().split())))))
print(max(0, t - l[p - 1]))
