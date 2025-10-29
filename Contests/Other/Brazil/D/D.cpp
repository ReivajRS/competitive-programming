#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

struct DSU {
  vector<int> e;
  bool bip = true;
  void init(int n) { e = vi(n, -1); }
  int get(int x) { return e[x] < 0 ? x : get(e[x]); }
  int color(int x) { return e[x] < 0 ? 0 : color(e[x]) ^ 1; };
  bool join(int a, int b) {
    int A = a, B = b;
    a = get(a), b = get(b);
    if (a == b) {
      if (color(A) == color(B)) {
        bip = false;
      }
      return false;
    }
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  map<int, vector<pair<int, int>>> e;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    e[-w].emplace_back(u, v);
  }

  DSU dsu;
  dsu.init(n);
  vector<int> ans;
  for (auto& [w, edges] : e) {
    int cnt = 0;
    for (auto [u, v] : edges) {
      if (dsu.get(u) != dsu.get(v) || dsu.color(u) == dsu.color(v)) {
        ++cnt;
      }
    }
    cout << -w << ' ' << cnt << '\n';
    if (cnt >= 2) {
      ans.push_back(-w);
    }
    for (auto [u, v] : edges) {
      dsu.join(u, v);
    }
    if (!dsu.bip) {
      cout << "adios " << -w << '\n';
      break;
    }
  }

  for (int x : ans) {
    cout << x << '\n';
  }
  
  return 0;
}