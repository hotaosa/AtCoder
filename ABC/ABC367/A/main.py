a, b, c = map(int, input().split())

if a < b:
    a += 24
if c < b:
    c += 24

print("Yes" if (a - b) * (c - a) < 0 else "No")
