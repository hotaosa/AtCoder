sx, sy = map(int, input().split())
tx, ty = map(int, input().split())

if (sx + sy) & 1:
    sx -= 1
if (tx + ty) & 1:
    tx -= 1

dx = abs(sx - tx)
dy = abs(sy - ty)

print((dy + max(dx, dy)) // 2)
