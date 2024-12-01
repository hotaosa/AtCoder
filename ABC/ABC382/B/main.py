n, d = map(int, input().split())
s = input()

i = n - 1
while s[i:].count("@") < d:
    i -= 1

print(s[:i] + "." * (n - i))
