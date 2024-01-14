n = int(input())
n = ~n
res = 0
while n & 1:
    res += 1
    n >>= 1
print(res)