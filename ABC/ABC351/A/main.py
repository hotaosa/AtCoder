a = list(map(int, input().split()))
b = list(map(int, input().split()))
print(max(0, sum(a) - sum(b) + 1))
