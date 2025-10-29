#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> p, sz;
  DSU(int n) : p(n, -1), sz(n, 1) {}
  int get(int x) {
    return p[x] == -1 ? x : p[x] = get(p[x]);
  }
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) {
      return false;
    }
    if (sz[a] < sz[b]) {
      swap(a, b);
    }
    p[b] = a;
    sz[a] += sz[b];
    return true;
  }
};

void add(int a, int b, DSU& dsu, vector<pair<int, int>>& edges) {
  while (true) {
    cout << "? " << a << ' ' << b << endl;
    int x;
    cin >> x;
    if (a == x) {
      edges.push_back({a, b});
      dsu.join(a, b);
      return;
    }
    if (dsu.get(a) == dsu.get(x)) {
      a = x;
    }
    else {
      b = x;
    }
  }
};

void solve() {
  int n;
  cin >> n;

  DSU dsu(n + 1);
  vector<pair<int, int>> edges;

  while (int(edges.size()) < n - 1) {
    for (int i = 2; i <= n; i++) {
      if (dsu.get(1) != dsu.get(i)) {
        add(1, i, dsu, edges);
      }
    }
  }

  cout << '!';
  for (auto [a, b] : edges) {
    cout << ' ' << a << ' ' << b;
  }
  cout << endl;
}

signed main() {
  // cin.tie(0)->sync_with_stdio(0);
  
  int tc;
  cin >> tc;

  while (tc--) {
    solve();
  }
  
  return 0;
}