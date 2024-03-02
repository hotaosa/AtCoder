def is_palindrome(s):
    s = str(s)
    l = 0
    r = len(s) - 1
    while (l < r):
        if s[l] != s[r]:
            return False
        l += 1
        r -= 1
    return True

n = int(input())
res = 1
x = 1
while x * x * x <= n:
    if is_palindrome(x * x * x):
        res = x * x * x
    x += 1

print(res)
