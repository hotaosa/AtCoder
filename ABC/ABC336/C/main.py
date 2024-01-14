n = int(input())
n -= 1
if n == 0:
    print(0)
    exit()

res = []
while n:
    res.append(2 * (n % 5))
    n //= 5

print(*res[::-1], sep='')