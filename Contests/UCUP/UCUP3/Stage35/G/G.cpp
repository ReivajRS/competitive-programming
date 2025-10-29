#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

constexpr int LOG = 25;

struct BinaryLifting {
  int n;
  vector<vector<pair<int, ll>>> g;
  vector<vector<int>> jmp;
  vector<vector<ll>> sum;
  vector<int> d;

  BinaryLifting(int n) : n(n), g(n), jmp(n, vector<int>(LOG, -1)), sum(n, vector<ll>(LOG)), d(n) {}

  void addEdge(int u, int v, ll w) {
    g[u].emplace_back(v, w), g[v].emplace_back(u, w);
  }

  void build(){
    auto dfs = [&](auto&& dfs, int u, int p = -1) -> void {
      jmp[u][0] = p;
      for(auto &[v, w]:g[u])if(v!=p) {
        sum[v][0] = w;
        d[v]=d[u]+1,dfs(dfs, v, u);
      }
    };
    
    dfs(dfs, 0);
    for(int i=1;i<LOG;i++)for(int u=0;u<n;u++) if (jmp[u][i - 1] != -1) {
      jmp[u][i]=jmp[jmp[u][i-1]][i-1];
      sum[u][i]=sum[u][i - 1] + sum[jmp[u][i - 1]][i - 1];
    }
  }

  pair<int, ll> LCA(int u,int v){
    if(d[u]<d[v]) swap(u,v);
    int dist = d[u] - d[v];
    ll sumPath = 0;
    for(int i=LOG-1;i>=0;i--)if((dist>>i)&1) {
      sumPath += sum[u][i];
      u = jmp[u][i];
    }
    if(u==v) return {u, sumPath};
    for(int i=LOG-1;i>=0;i--)if(jmp[u][i]!=jmp[v][i]) {
      sumPath += sum[u][i] + sum[v][i];
      u = jmp[u][i],v=jmp[v][i];
    }
    sumPath += sum[u][0] + sum[v][0];
    return {jmp[u][0], sumPath};
  }
};

int getEdge(BinaryLifting& bl, int u, int c) {
  ll sumPath = 0;
  for (int i = LOG - 1; i >= 0; --i) {
    int v = bl.jmp[u][i];
    if (v != -1 && sumPath + bl.sum[u][i] <= c) {
      sumPath += bl.sum[u][i];
      u = v;
    }
  }
  return u;
}

pair<int, int> goUp(BinaryLifting& bl, BinaryLifting& bl2, int u, int lca) {
  int d = 0;
  for (int i = LOG - 1; i >= 0; --i) {
    int v = bl2.jmp[u][i];
    if (v != -1 && bl.d[v] > bl.d[lca]) {
      d += 1 << i;
      u = v;
    }
  }
  return {u, d};
}

void solve() {
  int n, q, c;
  cin >> n >> q >> c;

  BinaryLifting bl(n);
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    bl.addEdge(u, v, w);
  }
  bl.build();

  BinaryLifting bl2(n);
  for (int i = 0; i < n; ++i) {
    int j = getEdge(bl, i, c);
    if (i != j) {
      bl2.addEdge(i, j, 1);
    }
  }
  bl2.build();

  while (q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;

    if (bl.d[u] < bl.d[v]) {
      swap(u, v);
    }

    int lca = bl.LCA(u, v).first;
    auto [a, da] = goUp(bl, bl2, u, lca);
    da -= a == lca;

    if (lca == v) {
      cout << da << '\n';
      continue;
    }

    auto [b, db] = goUp(bl, bl2, v, lca);
    db -= b == lca;

    ll dAtoB = bl.LCA(a, b).second;
    cout << da + db + (dAtoB > c) << '\n';
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int Z;
  cin >> Z;

  while (Z--) {
    solve();
  }

  return 0;
}

/*
x < aj
 aj < x < 2*aj
 2*aj < x < 3*<aj

(ai mod aj)^2

MAX 1e12
E MAX/aj

sum prob*y
prob 1/MAX
y MAX/aj

suma(1/MAX * MAX/aj)
suma(1...MAX)(1/aj)
1/1 + 1/2 + 1/3 ... 1/MAX
E = log2(MAX)

(ai - x*aj)2
ai2 - (2ai*x)*rango(aj) - x^2 * rango(aj^2)

O(n * log2(MAX) * log2(n))
*/