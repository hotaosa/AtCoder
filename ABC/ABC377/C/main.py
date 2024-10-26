diff_r = [-2, -2, -1, -1, 1, 1, 2, 2]
diff_c = [-1, 1, -2, 2, -2, 2, -1, 1]

s = set()
n, m = map(int, input().split())
for _ in range(m):
    r, c = map(int, input().split())
    s.add((r, c))
    for dr, dc in zip(diff_r, diff_c):
        nr = r + dr
        nc = c + dc
        if nr > 0 and nr <= n and nc > 0 and nc <= n:
            s.add((nr, nc))

print(n * n - len(s))
