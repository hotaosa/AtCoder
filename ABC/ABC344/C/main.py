n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))
l = int(input())
c = list(map(int, input().split()))

se = set()
for x in a:
    for y in b:
        for z in c:
            se.add(x + y + z)

q = int(input())
x = list(map(int, input().split()))
res = ['Yes' if y in se else 'No' for y in x]

print(*res, sep='\n')
