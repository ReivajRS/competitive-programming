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

  map<int, ll> mr, mc;
  map<int, vector<pi>> in_row;
  FOR (i, 0, n) {
    int r, c, x;
    cin >> r >> c >> x;
    mr[r] += x;
    mc[c] += x;
    in_row[r].pb({c, x});
  }

  set<pair<ll, int>> mx;
  for (auto &[c, sc] : mc) {
    mx.insert({-sc, c});
  }

  ll ans = 0;
  for (auto &[r, sr] : mr) {
    for (auto &[c, x] : in_row[r]) {
      mx.erase({-mc[c], c});
      mx.insert({-(mc[c] - x), c});
    }

    ll top = -mx.begin()->first;
    ans = max(ans, sr + top);

    for (auto &[c, x] : in_row[r]) {
      mx.erase({-(mc[c] - x), c});
      mx.insert({-mc[c], c});
    }
  }
  cout << ans << ENDL;

  return 0;
}