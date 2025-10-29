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
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
  int n;
  cin >> n;
  vector<ll> h(n);
  for (auto &x : h)
    cin >> x;
  vector<ll> dtime(n);
  dtime[n - 1] = h[n - 1];
  ROF (i, n - 1, 0) {
    dtime[i] = max(1ll, h[i] - dtime[i + 1]) + dtime[i + 1];
  }
  cout << dtime[0] << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}