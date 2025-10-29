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
#define ROF(i, a, b) for (int i = a-1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

template<typename T>
pair<T, vi> hungarian(const vector<vector<T>> &a) {
  #define INF numeric_limits<T>::max()
  if (a.empty()) return {0, {}};
  int n = SZ(a) + 1, m = SZ(a[0]) + 1;
  vi p(m), ans(n - 1);
  vector<T> u(n), v(m);
  FOR(i, 1, n) {
    p[0] = i;
    int j0 = 0;  // agregar trabajador "dummy" 0
    vector<T> dist(m, INF);
    vi pre(m, -1);
    vector<bool> done(m + 1);
    do {  // dijkstra
      done[j0] = true;
      int i0 = p[j0], j1;
      T delta = INF;
      FOR (j, 1, m) if (!done[j]) {
        auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
        if (cur < dist[j]) dist[j] = cur, pre[j] = j0;
        if (dist[j] < delta) delta = dist[j], j1 = j;
      }
      FOR (j, 0, m) {
        if (done[j]) u[p[j]] += delta, v[j] -= delta;
        else dist[j] -= delta;
      }
      j0 = j1;
    } while (p[j0]);
    while (j0) {  // actualizar camino alternativo
      int j1 = pre[j0];
      p[j0] = p[j1], j0 = j1;
    }
  }
  FOR(j, 1, m) if (p[j]) ans[p[j] - 1] = j - 1;
  return {-v[0], ans};
}

inline int dist(pi a, pi b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

signed main() { __
  int n, m;
  cin >> n >> m;
  
  vector<pi> bottles(n), couriers(m);
  pi restaurant;
  FOR (i, 0, n)
    cin >> bottles[i].first >> bottles[i].second;
  FOR (i, 0, m)
    cin >> couriers[i].first >> couriers[i].second;
  cin >> restaurant.first >> restaurant.second;

  vector<vi> costs(n, vi(m + n - 1));

  FOR(i, 0, n) {
    FOR(j, 0, m)
      costs[i][j] = dist(bottles[i], couriers[j]) + dist(bottles[i], restaurant);
    FOR(j, m, m + n - 1)
      costs[i][j] = dist(bottles[i], restaurant) * 2;
  }

  cout << hungarian(costs).first << ENDL;

  return 0;
}