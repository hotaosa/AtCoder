n = int(input())
a = sorted(list(map(int, input().split())))

res = 0
while a[-2] > 0:
    res += 1
    a[-1] -= 1
    a[-2] -= 1
    a.sort()

print(res)
