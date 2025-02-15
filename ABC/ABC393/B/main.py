s = input()
res = 0
for l in range(1, len(s)):
    for i in range(len(s)):
        if s[i::l][:3] == "ABC":
            res += 1
print(res)
