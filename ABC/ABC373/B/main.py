s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
t = input()
print(sum([abs(t.index(s[i]) - t.index(s[i + 1])) for i in range(25)]))
