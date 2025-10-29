#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

using i64 = long long;

i64 f(i64 n) {
  if (!n) {
    return 0;
  }
  i64 ret = 0;
  for (i64 i = 1; i <= n; ++i) {
    i64 j = n / (n / i);
    ret += n / i * (j - i + 1);
    i = j;
  }
  return ret;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  i64 n, m;
  cin >> n >> m;

  cout << f(m) - f(n - 1) << '\n';

  return 0;
}