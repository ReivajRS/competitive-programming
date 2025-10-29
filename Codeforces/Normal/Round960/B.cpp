#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve() {
  int n, x, y;
  cin >> n >> x >> y;

  vi a(n, 1);
  for (int i = y - 2; i >= 0; i -= 2)
    a[i] = -1;
  for (int i = x; i < n; i += 2)
    a[i] = -1;

  // auto lck = [&]() -> bool {
  //   int sum = 0, mx = -1;
  //   FOR (i, 0, n) {
  //     sum += a[i];
  //     mx = max(mx, sum);
  //   }
  //   sum = 0;
  //   FOR (i, 0, x) {
  //     sum += a[i];
  //   }
  //   cout << "Left " << sum << ' ' << mx << ENDL;
  //   return sum == mx;
  // };

  // auto rck = [&]() -> bool {
  //   int sum = 0, mx = -1;
  //   ROF (i, n, 0) {
  //     sum += a[i];
  //     mx = max(mx, sum);
  //   }
  //   sum = 0;
  //   FOR (i, y - 1, n) {
  //     sum += a[i];
  //   }
  //   cout << "Right " << sum << ' ' << mx << ENDL;
  //   return sum == mx;
  // };

  // lck();
  // rck();

  for (auto &x : a) {
    cout << x << ' ';
  }
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}