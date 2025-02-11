n, m = [int(x) for x in input().split()]

s = [input() for _ in range(n)]
t = [input() for _ in range(m)]

for i in range(n - m + 1):
    for j in range(n - m + 1):
        if all([s[i + r][j + c] == t[r][c] for r in range(m) for c in range(m)]):
            print(i + 1, j + 1)
            exit()
