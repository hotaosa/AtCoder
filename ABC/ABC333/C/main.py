def main():
    n = int(input())
    repunit = []
    cur = 1
    for i in range(13):
        repunit.append(cur)
        cur = cur * 10 + 1

    sum_repunit = set()
    for r1 in repunit:
        for r2 in repunit:
            for r3 in repunit:
                sum_repunit.add(r1 + r2 + r3)
    print(sorted(sum_repunit)[n - 1])

if __name__ == '__main__':
    main()