from collections import Counter
s = input()
cnt = [0] * (len(s) + 1)
for k, v in Counter(s).items():
    cnt[v] += 1

print('Yes' if sum(map(lambda x: x == 1 or x > 2, cnt)) == 0 else 'No')