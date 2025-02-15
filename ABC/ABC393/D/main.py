n = int(input())
s = input()

cl = [0] * n
cr = [0] * n

for i in range(n):
    if i > 0:
        cl[i] = cl[i - 1]
    if s[i] == "1":
        cl[i] += 1

for i in reversed(range(n)):
    if i < n - 1:
        cr[i] = cr[i + 1]
    if s[i] == "1":
        cr[i] += 1

res = 0
for i in range(n):
    if s[i] == "0":
        res += min(cl[i], cr[i])
print(res)
