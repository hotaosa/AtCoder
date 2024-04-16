import re

s = input()
t = input().lower()

fmt = rf'.*{t[0]}.*{t[1]}.*' if t.endswith('x') else rf'.*{t[0]}.*{t[1]}.*{t[2]}.*'
print('Yes' if re.fullmatch(fmt, s) else 'No')