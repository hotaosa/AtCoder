res = []
while True:
    a = int(input())
    res.append(a)
    if not a:
        break
print(*reversed(res), sep='\n')