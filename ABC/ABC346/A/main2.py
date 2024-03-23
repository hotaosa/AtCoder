import numpy as np
n = int(input())
a = np.array(map(int, input().split()))
b = a[:-1] * a[1:]
print(*b)