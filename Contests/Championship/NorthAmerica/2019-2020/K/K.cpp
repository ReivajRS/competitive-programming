#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

const int maxn = 2e5 + 5;
const int maxlog = 25;
int n;
vi g[maxn];
int jmp[maxn][maxlog], d[maxn];
void dfs(int u, int p = -1) {
  jmp[u][0] = p;
  for (auto &v : g[u]) if(v != p) d[v] = d[u] + 1, dfs(v, u);
}
void build() {
  dfs(0);
  for(int i = 1; i < maxlog; i++) for(int u = 0; u < n; u++) if (jmp[u][i - 1] != -1)
    jmp[u][i] = jmp[jmp[u][i - 1]][i - 1];
}
int LCA(int u, int v) {
  if (d[u] < d[v]) swap(u, v);
  int dist = d[u] - d[v];
  for (int i = maxlog - 1; i >= 0; i--) if((dist >> i) & 1) u = jmp[u][i];
  if (u == v) return u;
  for (int i = maxlog - 1; i >= 0; i--) if(jmp[u][i] != jmp[v][i]) u = jmp[u][i], v = jmp[v][i];
  return jmp[u][0];
}
int dist(int u, int v) { return d[u] + d[v] - 2 * d[LCA(u, v)]; }
//PPBCSMCSMALVC
signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int q;
  cin >> n >> q;
  FOR (i, 0, n-1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  build();

  while (q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    int d = dist(u,v)+1;
    cout << (ll)d*(d-1)/2 + n << ENDL;

  }

  return 0;
}