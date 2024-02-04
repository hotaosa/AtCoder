h, w, n = map(int, input().split())
grid = [[0] * w for _ in range(h)]

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

r = 0
c = 0
dir = 0

for _ in range(n):
    if grid[r][c]:
        dir = (dir + 3) % 4
    else:
        dir = (dir + 1) % 4
    grid[r][c] ^= 1
    r = (r + dr[dir] + h) % h
    c = (c + dc[dir] + w) % w

for i in range(h):
    print(''.join(str(c).replace('0', '.').replace('1', '#') for c in grid[i]))