#include <stdio.h>

int main() {
  double x;
  scanf("%f", &x);
  int n;
  scanf("%d", &n);
  double ans = -1e18, l = 1e18;
  scanf("%f", &l);
  n--;
  for (int i = 0; i < n; i++) {
    double v;
    scanf("%f", &v);
    double val = (x / l) * v - x;
    if (val > ans)
      ans = val;
    if (v < l)
      l = v;
  }
  printf("%.2f", ans);
  return 0;
}