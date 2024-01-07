n = int(input())
res = [[0] * n for _ in range(n)]
res[n // 2][n // 2] = 'T'
res[0][0] = 1

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

x, y, d = 0, 0, 0
for i in range(2, n * n):
    nx = x + dx[d]
    ny = y + dy[d]
    if nx < 0 or nx >= n or ny < 0 or ny >= n or res[nx][ny] != 0:
        d = (d + 1) % 4
        nx = x + dx[d]
        ny = y + dy[d]
    res[nx][ny] = i
    x = nx
    y = ny

for r in res:
    print(*r)