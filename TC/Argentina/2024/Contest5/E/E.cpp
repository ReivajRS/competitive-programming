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

  int n, m;
  cin >> n >> m;
  vector<set<int>> g(n);
  FOR (i, 0, m) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].insert(v), g[v].insert(u);
  }

  set<int> left;
  FOR (i, 0, n) left.insert(i);
  int ans = 0;
  FOR (i, 0, n) {
    if (!left.count(i)) continue;
    ans++;
    queue<int> q;
    q.push(i);
    left.erase(i);
    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      vi out;
      for (auto &v : left) if (!g[u].count(v)) {
        out.pb(v);
        q.push(v);
      }
      for (auto &v : out) {
        left.erase(v);
      }
    }
  }
  ans--;
  cout << ans << ENDL;

  return 0;
}