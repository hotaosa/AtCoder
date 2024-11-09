from itertools import groupby

n, k = map(int, input().split())

res = 0
for key, val in groupby(input()):
    if key == "O":
        res += len(list(val)) // k

print(res)
