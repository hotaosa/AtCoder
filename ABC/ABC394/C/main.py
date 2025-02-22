s = []
for c in input():
    if c == "A":
        add = ["A"]
        while s and s[-1] == "W":
            s.pop()
            add.append("C")
        s.extend(add)
    else:
        s.append(c)
print("".join(s))
