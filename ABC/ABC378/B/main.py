n = int(input())

q = [0] * n
r = [0] * n
for i in range(n):
    q[i], r[i] = map(int, input().split())

qn = int(input())
for _ in range(qn):
    t, d = map(int, input().split())
    t -= 1

    add = (r[t] - d % q[t] + q[t]) % q[t]
    print(d + add)
