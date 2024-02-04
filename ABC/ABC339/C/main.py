n = int(input())
a = list(map(int, input().split()))

s = 0
sum = 0
for ai in a:
    sum += ai
    s = max(s, -sum)

print(s + sum)
