#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

struct DSU {
  vector<int> e;
  void init(int n) { e = vector<int>(n, -1); }
  int size(int x) { return -e[get(x)]; }
  int get(int x) { return e[x]<0?x:e[x]=get(e[x]);}
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

void dfs(int u, int& ndfs, vector<vector<int>>& g, vector<int>& comp) {
  comp[u] = ndfs;
  for (int v : g[u]){
    if (comp[v] != -1) continue;
    dfs(v, ndfs, g, comp);
  }
}

void solve() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  vector<set<int>> gf(n);
  vector<vector<int>> gg(n);
  for (int i = 0; i < m1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    gf[u].insert(v);
    gf[v].insert(u);
  }
  for (int i = 0; i < m2; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    gg[u].push_back(v);
    gg[v].push_back(u);
  }
  int ndfs = 0;
  vector<int> comp(n, -1);
  for (int u = 0; u < n; u++) {
    if (comp[u] != -1) continue;
    dfs(u, ndfs, gg, comp);
    ndfs++;
  }
  vector<vector<int>> nodes(ndfs);
  vector<map<int, int>> id(ndfs);
  for (int u = 0; u < n; u++) {
    id[comp[u]][u] = SZ(nodes[comp[u]]);
    nodes[comp[u]].push_back(u);
  }
  int remove = 0, add = 0;
  for (int c = 0; c < ndfs; c++) {
    DSU dsuf;
    dsuf.init(SZ(nodes[c]));
    for (int i = 0; i < SZ(nodes[c]); i++) {
      int u = nodes[c][i];
      for (set<int>::iterator it = gf[u].begin(); it != gf[u].end();) {
        int v = *it;
        if (comp[u] == comp[v]) {
          dsuf.join(id[c][u], id[c][v]);
          it++;
          continue;
        }
        it = gf[u].erase(it);
        gf[v].erase(u);
        remove++;
      }
    }
    for (int i = 1; i < SZ(nodes[c]); i++) {
      int u = nodes[c][i - 1], v = nodes[c][i];
      add += dsuf.join(id[c][u], id[c][v]);
    }
  }
  cout << remove + add << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}