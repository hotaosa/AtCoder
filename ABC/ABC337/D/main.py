def transpose(li):
    h = len(li)
    w = len(li[0])
    ret = [[0] * h for _ in range(w)]
    for i in range(h):
        for j in range(w):
            ret[j][i] = li[i][j]
    return ret

def slide_sum(li, k):
    if len(li) < k:
        return [1e30]
    cur = 0
    for i in range(k):
        cur += li[i]
    ret = [cur]
    for i in range(k, len(li)):
        cur += li[i] - li[i - k]
        ret.append(cur)
    return ret

def solve(s, k):
    ret = k + 1
    for si in s:
        ss = slide_sum(si, k)
        ret = min(ret, min(ss))
    return ret

h, w, k = map(int, input().split())

inf = k + 1

s = [[0] * w for _ in range(h)]
for i in range(h):
    str = input()
    for j in range(w):
        if str[j] == 'x':
            s[i][j] = inf
        elif str[j] == '.':
            s[i][j] = 1

res = min(solve(s, k), solve(transpose(s), k))
print(res if res < inf else '-1')
