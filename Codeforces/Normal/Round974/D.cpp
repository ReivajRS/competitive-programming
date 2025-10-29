#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
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
  int n, d, k;
  cin >> n >> d >> k;

  vector<pi> a(k);
  FOR (i, 0, k) {
    cin >> a[i].first >> a[i].second;
  }

  vector<vi> in_ev(n + 5);
  vector<vi> out_ev(n + 5);
  FOR (i, 0, k) {
    auto [x, y] = a[i];
    in_ev[x].pb(i);
    out_ev[y + 1].pb(i);
  }

  int cnt = 0;

  pi bro = {-1e8, -1e8}, mom = {1e8, 1e8};

  int xw = 1, yw = d;
  int act = 1;

  while (act <= yw) {
    FOR (j, 0, SZ(in_ev[act])) {
      cnt++;
    }
    act++;
  }

  FOR (i, 0, n + 3) {
    FOR (j, 0, SZ(in_ev[yw])) {
      cnt++;
    }
    FOR (j, 0, SZ(out_ev[xw])) {
      cnt--;
    }
    if (yw <= n) {
      bro = max(bro, {cnt, -i});
      mom = min(mom, {cnt, i});
      xw++, yw++;
    }
  }
  cout << -bro.second + 1 << ' ' << mom.second + 1 << ENDL;
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