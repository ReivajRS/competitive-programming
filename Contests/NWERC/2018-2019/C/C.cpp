#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const double PI = acos(-1.0);

struct Point {
  double x, y;
};

struct Node {
  Point p;
  double l, r;
  Node() { p = {0.0, 0.0}, l = 0.0, r = 2*PI; }
};

Point circlePoint(Point c, double r, double ang) {
  return {c.x + cos(ang) * r, c.y + sin(ang) * r};
}

vector<vi> g;
vi sz;
vector<Node> nodes;

void dfs(int u, int p = -1) {
  sz[u] = 1;
  for (auto &v : g[u]) {
    if (v == p)
      continue;
    dfs(v, u);
    sz[u] += sz[v];
  }
}

void dfs2(int u, int p = -1) {
  double ang = (nodes[u].r - nodes[u].l) / sz[u];
  double last = nodes[u].l;
  FOR (i, 0, SZ(g[u])) {
    if (g[u][i] == p)
      continue;
    int v = g[u][i];
    nodes[v].p = circlePoint(nodes[u].p, 1, last + ang * sz[v] / 2);
    nodes[v].l = last;
    nodes[v].r = last + ang * sz[v];
    last = nodes[v].r;
    dfs2(v, u);
  }
}

signed main() { __
  int n;
  cin >> n;

  g.assign(n, vi());
  sz.assign(n, 0);
  nodes.resize(n);

  FOR (i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  dfs(0);
  dfs2(0);

  cout << setprecision(10) << fixed;
  for (Node &node : nodes)
    cout << node.p.x << ' ' << node.p.y << ENDL;

  return 0;
}