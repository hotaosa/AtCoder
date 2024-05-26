n, t = map(int, input().split())
a = list(map(int, input().split()))

sr = [set() for _ in range(n)]
sc = [set() for _ in range(n)]
sd1 = set()
sd2 = set()

for i, x in enumerate(a):
    r = (x - 1) // n
    c = (x - 1) % n
    sr[r].add(c)
    sc[c].add(r)
    if r == c:
        sd1.add(r)
    if r == n - 1 - c:
        sd2.add(r)

    if max(len(sr[r]), len(sc[c]), len(sd1), len(sd2)) == n:
        print(i + 1)
        exit()

print('-1')
