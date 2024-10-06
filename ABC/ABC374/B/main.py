s = input()
t = input()

if len(s) > len(t):
    t += "0" * (len(s) - len(t))
else:
    s += "0" * (len(t) - len(s))

res = -1
for i in reversed(range(len(s))):
    if s[i] != t[i]:
        res = i

print(res + 1)
