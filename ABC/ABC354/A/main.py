h = int(input())

x = 0
res = 0

while x <= h:
    x += 1 << res
    res += 1

print(res)