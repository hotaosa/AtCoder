import numpy as np

n = int(input())
a_s = [input().split() for _ in range(n)]

res_l = int(np.sum(np.abs(np.diff(np.array([int(x[0]) for x in a_s if x[1] == "L"])))))
res_r = int(np.sum(np.abs(np.diff(np.array([int(x[0]) for x in a_s if x[1] == "R"])))))
print(res_l + res_r)
