n, l, r = map(int, input().split())
res = [x for x in range(n + 1)]
res[l:r + 1] = reversed(res[l: r + 1])
print(*res[1:])
