n, x, y, z = map(int, input().split())
print('Yes' if (x - z) * (z - y) > 0 else 'No')
