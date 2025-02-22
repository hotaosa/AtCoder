op = {")": "(", "]": "[", ">": "<"}
s = []

for c in input():
    if c in op and s and s[-1] == op[c]:
        s.pop()
    else:
        s.append(c)

print("Yes" if not s else "No")
