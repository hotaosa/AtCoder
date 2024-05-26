n, m = map(int, input().split())
a = list(map(int, input().split()))
b = sorted(a + list(map(int, input().split())))

for x, y in zip(b[:-1], b[1:]):
    if x in a and y in a:
        print('Yes')
        exit()

print('No')