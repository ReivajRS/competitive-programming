from math import comb

a, b, c, n = map(int, input().split())

x = 1
if a != b and b != c:
  x = 6
elif a != b or a != c or b != c:
  x = 3

print(x * (comb(n, 3) - n * comb((n - 1) // 2, 2)) % (1 << 64))