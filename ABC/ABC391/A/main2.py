d = "NESW"
print("".join([d[(d.index(c) + 2) % 4] for c in input()]))
