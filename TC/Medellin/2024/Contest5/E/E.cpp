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

constexpr int maxn = 1e5 + 5;

int n, q;
vi g[maxn];
vector<pi> anc[maxn];
int is_removed[maxn];
int subtree_size[maxn];
int closest[maxn];

int valid(int v, int parent) {
  return v != parent && !is_removed[v];
}

int get_subtree_size(int u, int parent = -1) {
  subtree_size[u] = 1;
  for (int v : g[u]) if (valid(v, parent)){
    subtree_size[u] += get_subtree_size(v, u);
  }
  return subtree_size[u];
}

int get_centroid(int u, int tree_size, int parent = -1) {
  for (int v : g[u]) if (valid(v, parent) && subtree_size[v] * 2 > tree_size) {
    return get_centroid(v, tree_size, u);
  }
  return u;
}

void add_ancestor(int u, int d, int centroid, int parent = -1) {
  anc[u].pb({centroid, d});
  for (int v : g[u]) if (valid(v, parent)) {
    add_ancestor(v, d + 1, centroid, u);
  }
}

void build_centroid_decomposition(int u = 0) {
  int centroid = get_centroid(u, get_subtree_size(u));

  add_ancestor(centroid, 0, centroid);

  is_removed[centroid] = true;

  for (int v : g[centroid]) if (!is_removed[v]) {
    build_centroid_decomposition(v);
  }
}

void update_ancestors(int u) {
  for (auto &[p, d] : anc[u]) {
    closest[p] = min(closest[p], d);
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> q;
  FOR (i, 1, n) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  FOR (i, 1, n) {
    closest[i] = 1e7;
  }

  build_centroid_decomposition(0);
  update_ancestors(0);

  while (q--) {
    int t, u;
    cin >> t >> u;
    --u;
    if (t == 1) {
      closest[u] = 0;
      update_ancestors(u);
      continue;
    }
    int mn = closest[u];
    for (auto &[v, d] : anc[u]) {
      mn = min(mn, d + closest[v]);
    }
    cout << mn << ENDL;
  }
  
  return 0;
}