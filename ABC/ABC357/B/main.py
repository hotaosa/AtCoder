s = input()
c1 = 0
c2 = 0

for c in s:
    if c.islower():
        c1 += 1
    else:
        c2 += 1

print(s.lower() if c1 > c2 else s.upper())
