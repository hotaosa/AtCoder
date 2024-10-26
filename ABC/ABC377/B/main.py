sr = set()
sc = set()

for r in range(8):
    s = input()
    for c in range(8):
        if s[c] == "#":
            sr.add(r)
            sc.add(c)

res = (8 - len(sr)) * (8 - len(sc))
print(res)
