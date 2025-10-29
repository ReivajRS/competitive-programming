n1 = input()
n2 = input()

if len(n1) > len(n2):
  n1, n2 = n2, n1

n1 = '0' * (len(n2) - len(n1)) + n1

def get(x):
  return ord(x) - ord('0')

def f(n1, n2):
  idx = -1
  num = [c for c in n1]

  for i in range(len(n1)):
    if (get(n1[i]) + get(n2[i]) >= 10):
      idx = i
      break

  if idx == -1:
    return 0

  for i in range(idx, len(n1)):
    num[i] = '0'

  idx -= 1
  carry = True

  for i in range(idx, -1, -1):
    sum = get(n1[i]) + get(n2[i])
    if carry:
      if (sum == 9):
        num[i] = '0'
      else:
        num[i] = str(get(n1[i]) + 1)
        carry = False
    else:
      break

  if carry:
    num.insert(0, '1')
    n1 = '0' + n1

  print(num)

  num = list(reversed(num))
  n1 = list(reversed(n1))

  ret, pot10 = 0, 1
  for i in range(len(num)):
    ret += (ord(num[i]) - ord(n1[i])) * pot10
    pot10 *= 10

  return ret

print(min(f(n1, n2), f(n2, n1)))
