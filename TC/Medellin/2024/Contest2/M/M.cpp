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

  int n, q;
  cin >> n >> q;

  string s;
  cin >> s;

  vi pref_x(n + 1, 0), pref_y(n + 1, 0);

  FOR (i, 0, n) {
    pref_x[i + 1] = pref_x[i];
    pref_y[i + 1] = pref_y[i];
    pref_x[i + 1] += (s[i] == 'R');
    pref_x[i + 1] -= (s[i] == 'L');
    pref_y[i + 1] += (s[i] == 'U');
    pref_y[i + 1] -= (s[i] == 'D');
  }

  // abcdefghij
  // defgh

  map<pi, vi> idxs;
  FOR (i, 0, n + 1) {
    // cout << pref_x[i] << ' ' << pref_y[i] << ENDL;
    idxs[{pref_x[i], pref_y[i]}].pb(i);
  }

  while (q--) {
    int x, y, l, r;
    cin >> x >> y >> l >> r;
    auto it = lower_bound(idxs[{x, y}].begin(), idxs[{x, y}].end(), 0);
    if (it != idxs[{x, y}].end() && *it <= l - 1) {
      cout << "YES" << ENDL;
      continue;
    }
    int dx = pref_x[l - 1] + pref_x[r] - x;
    int dy = pref_y[l - 1] + pref_y[r] - y;
    it = lower_bound(idxs[{dx, dy}].begin(), idxs[{dx, dy}].end(), l);
    if (it != idxs[{dx, dy}].end() && *it <= r - 1) {
      cout << "YES" << ENDL;
      continue;
    }
    it = lower_bound(idxs[{x, y}].begin(), idxs[{x, y}].end(), r);
    if (it != idxs[{x, y}].end() && *it <= n) {
      cout << "YES" << ENDL;
      continue;
    }
    cout << "NO" << ENDL;
  }

  return 0;
}