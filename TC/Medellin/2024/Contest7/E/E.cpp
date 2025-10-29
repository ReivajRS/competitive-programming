#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

constexpr int maxn = 1e5 + 5;

struct Point {
  ll x, y;
  
  Point operator-(Point p) const { return { x - p.x, y - p.y }; }

  bool operator<(Point p) const { return tie(x, y) < tie(p.x, p.y); }

  ll cross(Point p) const { return x * p.y - y * p.x; }
};

ll areaTriangle(Point a, Point b, Point c) {
  return abs((b - a).cross(c - a));
}

int n;
vi g[maxn];

ll area[maxn];
ll memo[maxn][2];

ll dp(int u, int parent_taken, int p = -1) {
  ll &ans = memo[u][parent_taken];
  if (~ans) {
    return ans;
  }
  ans = 0;
  for (auto &v : g[u]) if (v != p) {
    ans += dp(v, 0, u);
  }
  if (SZ(g[u]) != 3 || parent_taken) return ans;
  ll aux = area[u];
  for (auto &v : g[u]) if (v != p) {
    aux += dp(v, 1, u);
  }
  return ans = max(ans, aux);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;
  
  map<pair<Point, Point>, int> m;

  auto agregar_lado = [&](Point p1, Point p2, int i) -> void {
    if (p2 < p1) swap(p1, p2);
    pair<Point, Point> p = {p1, p2};
    m[p] = i;
  };

  auto checar_lado = [&](Point p1, Point p2) -> int {
    if (p2 < p1) swap(p1, p2);
    pair<Point, Point> p = {p1, p2};
    if (m.count(p)) return m[p];
    return -1;
  };

  ll areaTotal = 0;
  FOR (i, 0, n) {
    Point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    // cout << a.x << ' ' << a.y << ' ' << b.x << ' ' << b.y << ' ' << c.x << ' ' << c.y << ENDL;
    if (int j = checar_lado(a, b); j != -1) {
      // cout << "arista " << i << ' ' << j << " " << checar_lado(a, b) << ENDL;
      g[i].pb(j);
      g[j].pb(i);
    }
    if (int j = checar_lado(a, c); j != -1) {
      // cout << "arista " << i << ' ' << j  << " " << checar_lado(a, b) << ENDL;
      g[i].pb(j);
      g[j].pb(i);
    }
    if (int j = checar_lado(b, c); j != -1) {
      // cout << "arista " << i << ' ' << j  << " " << checar_lado(a, b) <<  ENDL;
      g[i].pb(j);
      g[j].pb(i);
    }
    agregar_lado(a, b, i);
    agregar_lado(a, c, i);
    agregar_lado(b, c, i);
    area[i] = areaTriangle(a, b, c);
    areaTotal += area[i];
  }

  memset(memo, -1, sizeof memo);
  ll mx = dp(0, 0);
  cout << setprecision(1) << fixed << (areaTotal - mx) / 2.0 << ENDL;

  return 0;
}