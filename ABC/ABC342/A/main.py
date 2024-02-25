s = input()
for c in s:
    if s.count(c) == 1:
        print(s.index(c) + 1)