
def solve():
  A,B,C,X,Y,D = map(int, input().strip().split())

  # Menos de un taxi completo
  if D<=X:
    print(A)
    return
  if D<=X+Y:
    purosA = D//X * A
    AB = A + (D-X) * B
    print(min(purosA + min(A,(D%X)*B),AB))
    return
  
  oneTaxi = A+B*Y+(D-X-Y)*C

  def usarPuroA():
    vecesA = D//X
    cost = vecesA*A
    falta = D%X
    usarOtraA = cost+A
    if falta >= Y and C<=B:
      cost += Y*B + (falta - Y) * C
    else:
      puedoUsarB = vecesA * Y
      if(puedoUsarB >= falta):
        cost += falta*B
      else:
        cost += puedoUsarB*B + (falta-puedoUsarB) * C
    return min(usarOtraA,cost)
  
  def usarPuroAB():
    vecesAB = D // (X+Y)
    cost = vecesAB * (A+B*Y)
    falta = D % (X+Y)
    usarRestoC = cost+falta*C
    if falta:
      if(falta <= X):
        sobra = X-falta
        cost += A - min(sobra,vecesAB * Y) * B
      else:
        cost += A + (falta-X)*B
    return min(usarRestoC,cost)

  print(min(oneTaxi,usarPuroA(),usarPuroAB()))


t = int(input())
while t:
  solve()
  t-=1