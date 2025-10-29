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

void solve() {
  int n;
  cin >> n;
  vi a(n);
  for (auto &ai : a) {
    cin >> ai;
  }
  vi L;
  vector<vector<pi>> cards;
  FOR (i, 0, n) {
    int pos = lower_bound(L.begin(), L.end(), a[i]) - L.begin();
    if (pos == SZ(L)) {
      cards.pb({});
      L.pb(0);
    }
    L[pos] = a[i]; 
    pi p = {i, -1};
    if (pos) {
      p.second = SZ(cards[pos - 1]);
    }
    cards[pos].pb(p);
  }

  vi good(n, 0), vis(n, 0);
  for (auto &p : cards.back()) {
    good[p.first] = 1;
  }
  vi ans;
  ROF (i, SZ(L), 0) {
    // cout << i << ENDL;
    for (auto &[j, lst] : cards[i]) {
      if (!good[j]) {
        continue;
      }
      // cout << ' ' << j << ' ' << lst << ENDL;
      ans.pb(j + 1);
      if (!i) {
        continue;
      }
      ROF (k, lst, 0) {
        int x = cards[i - 1][k].first;
        if (vis[x] || a[x] >= a[j]) {
          break;
        }
        vis[x] = 1;
        good[x] = 1;
      }
    }
  }
  // cout << ENDL << lis_sz << ENDL;
  sort(ALL(ans));
  cout << SZ(ans) << ENDL;
  for (auto &x : ans) {
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