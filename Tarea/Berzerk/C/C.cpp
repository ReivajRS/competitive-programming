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
#define deb(x)      cerr << #x << " = " << x << '\n';
#define deb2(x, y)  cerr << #x << " = " << x << ", " << #y << " = " << y << '\n';

struct DSU {
  vi e;
  int sets;
  void init(int n) { e = vi(n, -1); sets = n; }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b)
      return false;
    if (e[a] > e[b])
      swap(a, b);
    e[a] += e[b];
    e[b] = a;
    sets--;
    return true;
  }
};

struct Point {
  int x, y, id;
  bool operator<(const Point o) const {
    if (x == o.x)
      return y > o.y;
    return x < o.x;
  }
};

void solve() {
  int n;
  cin >> n;
  
  vector<Point> pts(n);
  FOR (i, 0, n) {
    cin >> pts[i].x >> pts[i].y;
    pts[i].id = i;
  }

  sort(ALL(pts), [](const Point p1, const Point p2) {
    if (p1.y == p2.y)
      return p1.x < p2.x;
    return p1.y > p2.y;
  });

  multiset<Point> st;
  DSU dsu;
  dsu.init(n);

  FOR (i, 0, n) {
    auto it = st.upper_bound({pts[i].x, pts[i].y});
    if (it == st.end()) {
      st.insert(pts[i]);
      continue;
    }
    dsu.join(pts[i].id, it->id);
    st.erase(it);
    st.insert(pts[i]);
  }

  cout << dsu.sets << ENDL;
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