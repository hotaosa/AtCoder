import numpy as np
from itertools import groupby

n = int(input())
a = list(map(int, input().split()))
d = np.diff(a)

res = n * 2 - 1
for key, group in groupby(d):
    cnt = sum(1 for _ in group)
    res += cnt * (cnt - 1) // 2

print(res)
