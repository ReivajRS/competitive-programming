#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= b; i--)
#define ENDL '\n'

template <typename T>
pair<T, vi> hungarian(const vector<vector<T>> &a) {
#define INF numeric_limits<T>::max()
  if (a.empty()) return {0, {}};
  int n = SZ(a) + 1, m = SZ(a[0]) + 1;
  vi p(m), ans(n - 1);
  vector<T> u(n), v(m);
  FOR (i, 1, n) {
    p[0] = i;
    int j0 = 0;
    vector<T> dist(m, INF);
    vi pre(m, -1);
    vector<bool> done(m + 1);
    do {
      done[j0] = true;
      int i0 = p[j0], j1;
      T delta = INF;
      FOR (j, 1, m) {
        if (!done[j]) {
          auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
          if (cur < dist[j]) dist[j] = cur, pre[j] = j0;
          if (dist[j] < delta) delta = dist[j], j1 = j;
        }
      }
      FOR (j, 0, m) {
        if (done[j]) {
          u[p[j]] += delta, v[j] -= delta;
        } else {
          dist[j] -= delta;
        }
      }
      j0 = j1;
    } while (p[j0]);
    while (j0) {
      int j1 = pre[j0];
      p[j0] = p[j1], j0 = j1;
    }
  }
  FOR (j, 1, m) {
    if (p[j]) {
      ans[p[j] - 1] = j - 1;
    }
  }
  return {-v[0], ans};
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  
  vector<pi> bottles(n);
  for (auto &[x, y] : bottles) {
    cin >> x >> y;
  }

  vector<pi> courier(m);
  for (auto &[x, y] : courier) {
    cin >> x >> y;
  }

  int xr, yr;
  cin >> xr >> yr;

  auto dist = [&](int x0, int y0, int x1, int y1) -> ll {
    return abs(x0 - x1) + abs(y0 - y1);
  };

  vector<vector<ll>> a(n, vector<ll>(m + n - 1));
  
  FOR (i, 0, n) {
    auto [xb, yb] = bottles[i];
    FOR (j, 0, m) {
      auto [xc, yc] = courier[j];
      a[i][j] = dist(xc, yc, xb, yb) + dist(xb, yb, xr, yr);
    }
    FOR (j, 0, n - 1) {
      a[i][m + j] = dist(xb, yb, xr, yr) * 2;
    }
  }
  cout << hungarian<ll>(a).first << ENDL;

  return 0;
}