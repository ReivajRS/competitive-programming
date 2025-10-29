a = []
b = set()
for n in range(1,65):
    for m in range(65):
        s = ""
        while len(s) <= 65:
            s += '0'*m
            if len(s) > 0:
                a.append(s)
            s += '1'*n
            if len(s) > 0:
                a.append(s)
for x in a:
    b.add(int(x,2))

x,y = map(int,input().split())
ans = 0
if x == 0 or y == 0:
    ans-=1
for num in b:
    if num >= x and num <= y:
        ans+=1 

print(ans)