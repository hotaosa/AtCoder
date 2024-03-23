n = int(input())
b = [int(x) for x in input()]
c = list(map(int, input().split()))

INF = 1 << 60
dp = [[INF] * 2 for _ in range(2)]
dp[b[0]][0] = 0
dp[b[0] ^ 1][0] = c[0]

for i in range(1, n):
    d = dp
    dp = [[INF] * 2 for _ in range(2)]
    for j in range(2):
        for k in range(2):
            if d[j][k] == INF:
                continue
            for nj in range(2):
                if k and nj == j:
                    continue
                nk = k | (1 - (nj ^ j))
                cost = 0 if nj == b[i] else c[i]
                dp[nj][nk] = min(dp[nj][nk], d[j][k] + cost)

print(min(dp[0][1], dp[1][1]))