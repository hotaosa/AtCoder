import string

n = int(input())
s = input()
q = int(input())

mp = {c: c for c in string.ascii_lowercase}
for _ in range(q):
    c, d = input().split()
    for k, v in mp.items():
        if v == c:
            mp[k] = d

print("".join(mp[c] for c in s))
