h, w = map(int, input().split())
si, sj = map(int, input().split())
s = [input() for _ in range(h)]
si -= 1
sj -= 1

mp = "LRUD"
di = [0, 0, -1, 1]
dj = [-1, 1, 0, 0]

for c in input():
    idx = mp.index(c)
    ni = si + di[idx]
    nj = sj + dj[idx]
    if ni >= 0 and ni < h and nj >= 0 and nj < w and s[ni][nj] == ".":
        si = ni
        sj = nj

print(si + 1, sj + 1)
