q = int(input())
l = []
for _ in range(q):
    t, x = map(int, input().split())
    if t == 1:
        l.append(x)
    else:
        print(l[-x])