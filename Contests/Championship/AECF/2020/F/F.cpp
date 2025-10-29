#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  map<int, vector<pi>> mpx, mpy;
  vector<pi> a(n), b(m);

  FOR(i, 0, n) {
    int x, y;
    cin >> x >> y;
    a[i] = {x, y};
    mpx[x].pb({y, 0});
    mpy[y].pb({x, 0});
  }

  FOR(i, 0, m) {
    int x, y;
    cin >> x >> y;
    b[i] = {x, y};
    mpx[x].pb({y, 1});
    mpy[y].pb({x, 1});
  }

  for (auto &[pos, x] : mpx) {
    x.pb({-1e9 - 5, -1});
    x.pb({1e9 + 5, -1});
    sort(ALL(x));
  }
  for (auto &[pos, x] : mpy) {
    x.pb({-1e9 - 5, -1});
    x.pb({1e9 + 5, -1});
    sort(ALL(x));
  }
  string ans(n, '1');
  FOR(i, 0, n) {
    auto it = lower_bound(ALL(mpx[a[i].first]), make_pair(a[i].second,-2));
    int yo = it->second;
    it = prev(it);
    if (it->second != -1 && yo != it->second) {
      continue;
    }
    it = next(it);
    it = next(it);
    if (it->second != -1 && yo != it->second) {
      continue;
    }

    it = lower_bound(ALL(mpy[a[i].second]), make_pair(a[i].first,-2));
    yo = it->second;
    it = prev(it);
    if (it->second != -1 && yo != it->second) {
      continue;
    }
    it = next(it);
    it = next(it);
    if (it->second != -1 && yo != it->second) {
      continue;
    }
    ans[i] = '0';
  }

  string ans2(m, '1');
  FOR(i, 0, m) {
    auto it = lower_bound(ALL(mpx[b[i].first]), make_pair(b[i].second,-2));
    int yo = it->second;
    it = prev(it);
    if (it->second != -1 && yo != it->second) {
      continue;
    }
    it = next(it);
    it = next(it);
    if (it->second != -1 && yo != it->second) {
      continue;
    }

    it = lower_bound(ALL(mpy[b[i].second]), make_pair(b[i].first,-2));
    yo = it->second;
    it = prev(it);
    if (it->second != -1 && yo != it->second) {
      continue;
    }
    it = next(it);
    it = next(it);
    if (it->second != -1 && yo != it->second) {
      continue;
    }
    ans2[i] = '0';
  }
  cout << ans << ENDL;
  cout << ans2 << ENDL;

  return 0;
}