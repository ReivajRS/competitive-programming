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

const int MOD = 998244353;
const int MAXN = 3001;
int c[MAXN], cnt[MAXN];
vi g[MAXN];
int dp[MAXN][MAXN];
int color = -1;

int dfs(int u, int p, bool f) {
  int val = f * (c[u] == color ? 1 : -1);
  for (auto &v : g[u]) if (v != p) {
    val += dfs(v, u, 1);
    if (f) {
      val = (val + dfs(v, u, 1)) % MOD;
    }
    val = val + 
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n;
  cin >> n;

  FOR (i, 0, n) {
    cin >> c[i];
    cnt[c[i]]++;
  }

  FOR (i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  
  return 0;
}