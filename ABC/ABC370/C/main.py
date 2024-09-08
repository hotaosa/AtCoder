s = input()
t = input()

res = []
while s != t:
    idx = -1
    replaced = False
    for i in range(len(s)):
        if s[i] != t[i]:
            idx = i
            if s[i] > t[i]:
                s = s[:i] + t[i] + s[i + 1 :]
                replaced = True
                break
    if not replaced:
        s = s[:idx] + t[idx] + s[idx + 1 :]
    res.append(s)

print(len(res))
print(*res, sep="\n")
