#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, k;
  cin >> n >> m >> k;

  map<string, int> mp;
  vector<string> s(n);
  FOR (i, 0, n) {
    cin >> s[i];
    mp[s[i]] = i;
  }
  
  vi v(n);
  for (auto &vi : v) {
    cin >> vi;
  }

  while (m--) {
    int c;
    cin >> c;
    vi g(c);
    int mn = 1e9;
    for (auto &ci : g) {
      cin >> ci;
      mn = min(mn, v[--ci]);
    }
    for (auto &ci : g) {
      v[ci] = mn;
    }
  }

  ll ans = 0;
  while (k--) {
    string t;
    cin >> t;
    ans += v[mp[t]];
  }
  cout << ans << ENDL;

  return 0;
}