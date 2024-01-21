n = int(input())

m = 0
while 1 << m < n:
    m += 1

print(m)
for i in range(m):
    l = []
    for j in range(n):
        if j >> i & 1:
            l.append(j + 1)
    print(len(l), *l)

print(int(input()[::-1], 2) + 1)