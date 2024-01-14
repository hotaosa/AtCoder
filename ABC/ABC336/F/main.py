import queue

def search(s, swap_lists):
    ret = dict()
    ret[s] = 0
    que = queue.Queue()
    que.put(s)
    while que:
        v = que.get()
        dist = ret[v]
        if dist == 10: break
        for swap_list in swap_lists:
            nv = list(v)
            for x, y in swap_list:
                nv[x] = v[y]
            nv = tuple(nv)
            if not nv in ret:
                ret[nv] = dist + 1
                que.put(nv)

    return ret

h, w = map(int, input().split())
n = h * w

s = [0] * n
t = [i for i in range(n)]

for i in range(h):
    tmp = list(map(int, input().split()))
    for j in range(w):
        s[i * w + j] = tmp[j] - 1
s = tuple(s)
t = tuple(t)

swap_lists = []
for sr in range(2):
    for sc in range(2):
        swap_list = []
        for r in range(sr, h - 1 + sr):
            for c in range(sc, w - 1 + sc):
                swap_list.append((r * w + c, (sr + sr + h - 2 - r) * w + sc + sc + w - 2 - c))
        swap_lists.append(swap_list)



dic1 = search(s, swap_lists)
dic2 = search(t, swap_lists)

res = 30
for k in dic1:
    if k in dic2:
        res = min(res, dic1[k] + dic2[k])

print(res if res < 30 else -1)