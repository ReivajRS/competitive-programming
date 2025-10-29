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
char letra[maxn];
int is_removed[maxn];
int subtree_size[maxn];

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

void build_centroid_decomposition(int u, char c) {
  if (c == 'Z' + 1) {
    cout << "Impossible!" << ENDL;
    exit(0);
  }
  
  int centroid = get_centroid(u, get_subtree_size(u));
  letra[centroid] = c;

  is_removed[centroid] = true;

  for (int v : g[centroid]) if (!is_removed[v]) {
    build_centroid_decomposition(v, c + 1);
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;
  FOR (i, 1, n) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  build_centroid_decomposition(0, 'A');

  FOR (i, 0, n) {
    cout << letra[i] << " \n"[i == n - 1];
  }
  
  return 0;
}