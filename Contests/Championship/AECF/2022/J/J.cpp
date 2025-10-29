#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

void solve() {
  int n;
  cin >> n;
  vector<vi> g(n + 1);
  FOR (i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
    if (SZ(g[u]) == n - 1 || SZ(g[v]) == n - 1) {
      cout << -1 << ENDL;
      return;
    }
  }
  vi leafs(n + 1, 0);
  FOR (i, 0, n) {
    for (auto v : g[i]) {
      if (SZ(g[v]) == 1) leafs[i]++;
    }
  }
  int ans = 0;
  priority_queue<int> pq;
  FOR (i, 0, n) {
    if (leafs[i]) {
      pq.push(leafs[i]);
    }
  }

  /*
    3 3 3
    0 0 3
    0 0 0

    3 3 3
    2 2 3
    1 2 2
    1 1 1
    0 0 1
    0 0 0
  */
  while (!pq.empty()) {
    int sz1 = pq.top();
    pq.pop();
    if (pq.empty()) {
      ans += sz1;
      break;
    }
    int sz2 = pq.top();
    pq.pop();
    ans++;
    sz1--;
    sz2--;
    if (sz1 > 0) pq.push(sz1);
    if (sz2 > 0) pq.push(sz2);
  }
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}