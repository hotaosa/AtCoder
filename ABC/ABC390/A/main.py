a = list(map(int, input().split()))
for i in range(4):
    b = a.copy()
    b[i], b[i + 1] = b[i + 1], b[i]
    if b == [1, 2, 3, 4, 5]:
        print("Yes")
        exit()
print("No")
