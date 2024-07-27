n = int(input())

b = ""
for _ in range(n - 1):
    s = input()
    if b == "sweet" and s == "sweet":
        print("No")
        exit()
    b = s
print("Yes")
