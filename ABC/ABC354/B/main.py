n = int(input())
s = []
c = 0

for _ in range(n):
    ss, cc = input().split()
    s.append(ss)
    c += int(cc)

print(sorted(s)[c % n])
