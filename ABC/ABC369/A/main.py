a, b = map(int, input().split())
if a == b:
    print(1)
else:
    print(2 if abs(a - b) % 2 else 3)
