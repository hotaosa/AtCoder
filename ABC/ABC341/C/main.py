h, w, n = map(int, input().split())
t = input()
s = [input() for _ in range(h)]

mv = []
for d in t:
    if d == 'L':
        mv.append((0, -1))
    elif d == 'R':
        mv.append((0, 1))
    elif d == 'U':
        mv.append((-1, 0))
    else:
        mv.append((1, 0))

res = 0
for i in range(1, h - 1):
    for j in range(1, w - 1):
        if s[i][j] == '#':
            continue
        r = i
        c = j
        for dr, dc in mv:
            r += dr
            c += dc
            if s[r][c] == '#':
                break

        if s[r][c] == '.':
            res += 1

print(res)
