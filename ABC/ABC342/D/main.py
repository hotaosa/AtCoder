import math

def fact_xor(x):
    if x == 0:
        return 0
    ret = 1
    for y in range(2, math.ceil(math.sqrt(x)) + 1):
        cnt = 0
        while x % y == 0:
            cnt ^= 1
            x //= y
        if cnt:
            ret *= y
    if x > 1:
        ret *= x
    return ret

n = int(input())
a = list(map(fact_xor, list(map(int, input().split()))))

mp = dict()
cnt_zero = 0
res = 0
for i, b in enumerate(a):
    if b == 0:
        cnt_zero += 1
        res += i
        continue

    res += cnt_zero
    if b in mp:
        res += mp[b]
        mp[b] += 1
    else:
        mp[b] = 1

print(res)
