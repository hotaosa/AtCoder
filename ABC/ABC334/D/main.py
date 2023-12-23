import bisect

def main():
    n, q = map(int, input().split())
    r = sorted(list(map(int, input().split())))
    for i in range(1, n):
        r[i] += r[i - 1]
    for _ in range(q):
        x = int(input())
        print(bisect.bisect_right(r, x))

if __name__ == '__main__':
    main()