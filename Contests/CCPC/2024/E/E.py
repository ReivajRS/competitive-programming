
def solve():
  A,B,C,X,Y,D = map(int,input().strip().split())

  if D<=X:
    print(A)
    return
  if D <= X+Y:
    sobra = D % X 
    print(min(D//X*A + min(A,sobra*B), A + (D-X) * B))
    return


  opc1 = A + B*Y + (D-X-Y)*C
  sobra = D%X
  opc2 = D//X*A
  opc22 = opc2+A
  if sobra: 
    if sobra <= Y:
      opc2 += sobra * B
    else:
      if C < B:
          opc2 += Y * B + (sobra - Y) * C
      else:
        if sobra <= D//X * Y:
          opc2 += sobra * B
        else:
          opc2 += D//X*Y*B + (sobra - D//X*Y) * C
  opc2 = min(opc2,opc22)


  sobra = D % (X+Y)
  opc3 = D // (X+Y) * (A + B*Y)
  if sobra:
    if sobra <= X:
      opc3 += min(sobra * C,A - min(D//(X+Y)*Y,X-sobra) * B)
    else:
      opc3 += min(sobra*C,A+(sobra-X)*B)

  print(min(opc1,opc2,opc3))


t = int(input())
while t:
  t-=1
  solve()