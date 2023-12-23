def solve_odd(k, a):
    sum_d_left = [0 for i in range(k)]
    for i in range(1, k):
        sum_d_left[i] = sum_d_left[i - 1]
        if i & 1:
            sum_d_left[i] += a[i] - a[i - 1]

    sum_d_right = [0 for i in range(k)]
    for i in range(k - 2, -1, -1):
        sum_d_right[i] = sum_d_right[i + 1]
        if (k - 1 - i) & 1:
            sum_d_right[i] += a[i + 1] - a[i]

    res = 1 << 30
    for i in range(k):
        cur = 0
        if i > 0: cur += sum_d_left[i - 1]
        if i < k - 1: cur += sum_d_right[i + 1]
        if i & 1: cur += a[i + 1] - a[i - 1]
        res = min(res, cur)

    return res

def solve_even(k, a):
    res = 0
    for i in range(1, k, 2):
        res += a[i] - a[i - 1]
    return res

def main():
    n, k = map(int, input().split())
    a = sorted(list(map(int, input().split())))
    if k & 1:
        print(solve_odd(k, a))
    else:
        print(solve_even(k, a))


if __name__ == '__main__':
    main()
