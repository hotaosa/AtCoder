n, k = map(int, input().split())
a = list(map(int, input().split()))

res = 1
cnt = 0
for b in a:
    if cnt + b > k:
        res += 1
        cnt = b
    else:
        cnt += b

print(res)