def overlap(l1, r1, l2, r2):
    if l1 >= r2:
        return False
    if l2 >= r1:
        return False
    return True


a = list(map(int, input().split()))
b = list(map(int, input().split()))

ol = True
for i in range(3):
    ol &= overlap(a[i], a[i + 3], b[i], b[i + 3])

print("Yes" if ol else "No")
