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

constexpr int maxn = 1e5 + 1;
vi g[maxn];
int depth[maxn];
double prob[maxn];
bool out_d[maxn];

void dfs(int u, int p = -1) {
  for (auto &v : g[u]) {
    if (v == p) {
      continue;
    }
    depth[v] = depth[u] + 1;
    prob[v] = prob[u] / (SZ(g[u]) - (p != -1));
    dfs(v, u);
    out_d[u] = 1;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n;
  cin >> n;

  FOR (i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  fill(prob, prob + maxn, 1.0);

  dfs(0);

  double ans = 0;
  FOR (i, 0, n) {
    if (!out_d[i]) {
      ans += depth[i] * prob[i];
    }
  }

  cout << setprecision(15) << fixed;
  cout << ans << ENDL;
  
  return 0;
}