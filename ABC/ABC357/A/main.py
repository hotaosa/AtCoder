from itertools import accumulate
from bisect import bisect_right

n, m = map(int, input().split())
h = list(accumulate(map(int, input().split())))
print(bisect_right(h, m))
