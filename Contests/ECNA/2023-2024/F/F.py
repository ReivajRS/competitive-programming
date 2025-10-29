n = int(input())
a = list(map(int,input().strip().split()))

while len(a)>1:
  mn = a[0]
  mnidx = 0
  for i in range(len(a)):
    if a[i] < mn:
      mn = a[i]
      mnidx = i
  if mnidx > 0 and a[mnidx] == a[mnidx-1]:
    a[mnidx] = a[mnidx]*2
    del a[mnidx-1]
  elif mnidx < len(a)-1 and a[mnidx] == a[mnidx+1]:
    a[mnidx] = a[mnidx]*2
    del a[mnidx+1]
  else:
    del a[mnidx]

print(a[0])