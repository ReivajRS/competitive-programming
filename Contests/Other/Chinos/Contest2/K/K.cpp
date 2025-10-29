#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vi a(n);
  int mn = 1e9;
  FOR (i, 0, n) {
    cin >> a[i];
    mn = min(mn, a[i]);
  }

  auto f = [&](int x) {
    FOR (i, 0, n) if (a[i] % x && (a[i] - 1) < x * 2) return false;
    return true;
  };

  int ans = (mn - 1) / 2;
  for (int i = 1; i * i <= mn; i++) if (mn % i == 0) {
    if (f(i)) ans = max(ans, i);
    if (f(mn / i)) ans = max(ans, mn / i);
  }
  cout << ans << ENDL;

  return 0;
}