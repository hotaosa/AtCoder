n = int(input())
st = sa = 0
for _ in range(n):
    x, y = map(int, input().split())
    st += x
    sa += y

res = 'Draw'
if st != sa:
    res = 'Takahashi' if st > sa else 'Aoki'
print(res)