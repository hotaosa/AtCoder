n, t = map(int, input().split())
score = [0] * n
mp = {0: n}
res = 1

for _ in range(t):
    a, b = map(int, input().split())
    a -= 1
    mp[score[a]] -= 1
    if mp[score[a]] == 0:
        res -= 1
    score[a] += b
    if not score[a] in mp:
        mp[score[a]] = 1
    else:
        mp[score[a]] += 1
    if mp[score[a]] == 1:
        res += 1
    print(res)
