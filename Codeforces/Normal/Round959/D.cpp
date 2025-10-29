#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

struct DSU {
  vi e;
  void init(int n) { e = vi(n, -1); }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b)
      return false;
    if (e[a] > e[b])
      swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

void solve() {
  int n;
  cin >> n;
  vi a(n);
  for (auto &x : a)
    cin >> x;
  DSU dsu;
  dsu.init(n);
  vector<pi> edges;
  ROF (x, n, 1) {
    vector<vi> mods(x);
    FOR (i, 0, n) {
      int mod = a[i] % x;
      mods[mod].pb(i);
    }
    for (auto &v : mods) {
      bool flag = 0;
      int c1 = -1, c2 = -1;
      int v1 = -1, v2 = -1;
      for (auto &i : v) {
        int c = dsu.get(i);
        if (c1 == -1) {
          c1 = c, v1 = i;
        }
        else if (c1 != c) {
          c2 = c, v2 = i;
          flag = 1;
          break;
        }
      }
      if (flag) {
        dsu.join(v1, v2);
        edges.pb({v1, v2});
        break;
      }
    }
  }
  if (SZ(edges) != n - 1) {
    cout << "NO" << ENDL;
    return;
  }
  cout << "YES" << ENDL;
  reverse(ALL(edges));
  for (auto &[x, y] : edges) {
    cout << x + 1 << ' ' << y + 1 << ENDL;
  }
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