def dist(s):
    d = abs(ord(s[0]) - ord(s[1]))
    return min(d, 5 - d)

def main():
    s = input()
    t = input()
    print('Yes' if dist(s) == dist(t) else 'No')

if __name__ == '__main__':
    main()