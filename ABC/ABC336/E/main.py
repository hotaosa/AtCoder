def solve(s, digit_sum):
    n = len(s)
    dp = [[[[0] * digit_sum for _ in range(digit_sum + 1)] for _ in range(2)] for _ in range(n + 1)]
    dp[0][0][0][0] = 1

    for i in range(n):
        for less_than_s in range(2):
            for cur_sum in range(digit_sum + 1):
                for cur_mod in range(digit_sum):
                    for nx in range(10):
                        nx_less_than_s = less_than_s | (nx < int(s[i]))
                        nx_sum = cur_sum + nx
                        nx_mod = (cur_mod * 10 + nx) % digit_sum
                        if nx_sum > digit_sum: break
                        if not less_than_s and nx > int(s[i]): break
                        dp[i + 1][nx_less_than_s][nx_sum][nx_mod] += dp[i][less_than_s][cur_sum][cur_mod]

    return dp[n][0][digit_sum][0] + dp[n][1][digit_sum][0]

s = input()
res = 0
for digit_sum in range(1, 9 * len(s) + 1):
    res += solve(s, digit_sum)

print(res)
