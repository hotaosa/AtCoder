n = int(input())
print(''.join(['o' if (i + 1) % 3 else 'x' for i in range(n)]))