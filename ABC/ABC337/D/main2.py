import numpy as np

def solve(s, k):
    ret = k + 1
    for v in s:
        cs = np.cumsum(v)
        if len(v) >= k:
            ret = min(ret, cs[k - 1])
            for i in range(k, len(v)):
                ret = min(ret, cs[i] - cs[i - k])
    return ret

h, w, k = map(int, input().split())
inf = k + 1

s = np.zeros((h, w))
for i in range(h):
    str = input()
    for j in range(w):
        if str[j] == 'x':
            s[i][j] = inf
        elif str[j] == '.':
            s[i][j] = 1

res = min(solve(s, k), solve(np.transpose(s), k))
print(int(res) if res < inf else '-1')