def solve(n):
    if not n in dic:
        dic[n] = n + solve(n // 2) + solve((n + 1) // 2)
    return dic[n]

n = int(input())
dic = {1:0}
print(solve(n))