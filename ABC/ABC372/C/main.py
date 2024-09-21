n, q = map(int, input().split())
s = list(input())

cur = 0
for i in range(n - 2):
    if "".join(s[i : i + 3]) == "ABC":
        cur += 1

while q:
    q -= 1
    x, c = input().split()
    idx = int(x) - 1

    diff = 0
    for i in range(max(0, idx - 2), min(n - 2, idx + 1)):
        if "".join(s[i : i + 3]) == "ABC":
            diff -= 1

    s[idx] = c
    for i in range(max(0, idx - 2), min(n - 2, idx + 1)):
        if "".join(s[i : i + 3]) == "ABC":
            diff += 1

    cur += diff
    print(cur)
