n, q = map(int, input().split())
dx = {'R':1, 'L':-1, 'U':0, 'D':0}
dy = {'R':0, 'L':0, 'U':1, 'D':-1}
a = [(n - i, 0) for i in range(n)]

for _ in range(q):
    t, c = input().split()
    if t == '1':
        x, y = a[-1]
        x += dx[c]
        y += dy[c]
        a.append((x, y))
    else:
        print(*a[-int(c)])