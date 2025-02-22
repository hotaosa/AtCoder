n = int(input())
s = [input() for _ in range(n)]
print("".join(sorted(s, key=lambda x: len(x))))
