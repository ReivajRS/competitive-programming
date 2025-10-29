#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  int n;
  cin >> n;

  vector<vi> g;
  g.pb(vi());

  vi val;
  val.pb(0);
  vector<unordered_map<string, int>> m;
  m.pb(unordered_map<string,int>());
  FOR (i, 0, n) {
    string s;
    cin >> s;
    s += '/';
    int u = 0;
    string aux = "";
    FOR (j, 1, SZ(s)) {
      if (s[j] != '/') {
        aux += s[j];
        continue;
      }
      if (!m[u].count(aux)) { 
        m[u][aux] = SZ(g);
        g.pb(vi());
        val.pb(0);
        m.pb(unordered_map<string,int>());
        g[u].pb(m[u][aux]);
      }
      u = m[u][aux];
      if (j == SZ(s) - 1) val[u]++;
      aux = "";
    }
  }

  auto calc = [&](auto self, int u) -> void {
    if (g[u].empty()) return;
    for (auto &v : g[u]) {
      self(self, v);
      val[u] += val[v];
    }
  };
  calc(calc, 0);

  auto get_sum = [&](auto self, int u) -> ll {
    if (g[u].empty()) return 0;
    ll ans = val[u];
    for (auto &v : g[u])
      ans += self(self, v);
    return ans;
  };

  vi ans(SZ(g), 1e9);
  ans[0] = get_sum(get_sum, 0);
  auto dfs = [&](auto self, int u) -> void {
    for (int v : g[u]) {
      if (g[v].empty()) continue;
      ans[v] = ans[u] + val[0] - val[v] - val[v];
      self(self, v);
    }
  };
  dfs(dfs, 0);
  cout << *min_element(ALL(ans)) << ENDL;

  return 0;
}