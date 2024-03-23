w, b = map(int, input().split())
s = 'wbwbwwbwbwbw' * 20
for i in range(12):
    t = s[i: i + w + b]
    if t.count('w') == w and t.count('b') == b:
        print('Yes')
        exit()
print('No')
