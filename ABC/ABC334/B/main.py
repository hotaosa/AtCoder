def floor(x, y):
    z = (x % y + y) % y
    return (x - z) // y

def main():
    a, m, l, r = map(int ,input().split())
    print(floor(r - a, m) - floor(l - a - 1, m))

if __name__ == '__main__':
    main()
