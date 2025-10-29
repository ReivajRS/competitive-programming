
r,s,m,d,n = map(int,input().strip().split())
b = list(map(int, input().strip().split()))

ing = [[] for _ in range(s+m+d)]

for i in range(s+m+d):
    k = list(map(int, input().strip().split()))
    for idx,x in enumerate(k):
        if idx == 0:
            continue
        ing[i].append(x-1)

ban = set()


while n > 0:
    u,v = map(int,input().strip().split())
    u-=1
    v-=1
    mn =int(min(u,v))
    mx =int (max(u,v))
    ban.add((mn,mx))
    n-=1

ans = 0
for i in range(s):
    for j in range(s,s+m):
        for k in range(s+m,s+m+d):
            if ((i,j) in ban) or ((i,k) in ban) or ((j,k) in ban):
                continue
            cnt = [0 for _ in range(1001)]
            for x in ing[i]:
                cnt[x]+=1
            for x in ing[j]:
                cnt[x]+=1
            for x in ing[k]:
                cnt[x]+=1
            prod = 1
            for l in range(r):
                if cnt[l] == 0:
                    continue
                prod *= b[l]
            ans+=prod
            if ans > 1e18:
                print("too many")
                exit()


print(ans)