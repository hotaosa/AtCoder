import numpy as np

h, w = map(int, input().split())
s = np.array([[c for c in input()] for _ in range(h)])
rows, columns = np.where(s == "#")
r1 = rows.min()
r2 = rows.max() + 1
c1 = columns.min()
c2 = columns.max() + 1

print("No" if np.any(s[r1:r2, c1:c2] == ".") else "Yes")
