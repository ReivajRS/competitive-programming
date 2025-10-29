#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

bool isSquare(int x) {
  int sq = sqrt(x);
  while (sq * sq < x) {
    ++sq;
  }
  while (sq * sq > x) {
    --sq;
  }
  return sq * sq == x;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int a, b;
  cin >> a >> b;

  int ans = 0;
  for (int i = a; i <= b; ++i) {
    if (isSquare(i)) {
      ans += 15;
    }
  }
  cout << ans << '\n';

  return 0;
}