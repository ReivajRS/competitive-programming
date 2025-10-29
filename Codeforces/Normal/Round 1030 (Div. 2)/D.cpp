#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
#define SZ(x) ((int)(x).size())

void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> p(n + 2);
  p[0] = 0;
  p[n + 1] = 1e15 + 1;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  vector<int> d(n + 2);
  for (int i = 1; i <= n; i++){ 
    cin >> d[i];
  }
  int q;
  cin >> q;
  vector<ll> a(q);
  for (int i = 0; i < q; i++) {
    cin >> a[i];
  }

  using state = tuple<int, int, int>;
  vector<vector<vector<state>>> nxt(n + 2, vector<vector<state>>(2, vector<state>(k + 1)));
  vector<vector<vector<int>>> vis(n + 2, vector<vector<int>>(2, vector<int>(k + 1)));
  for (int i = 0; i <= n + 1; i++) {
    for (int dir = 0; dir < 2; dir++) {
      for (int t = 0; t < k; t++) {
        if (i == 0 || i == n + 1) {
          nxt[i][dir][t] = {i, dir, t};
          continue;
        }
        bool is_red = t == d[i];
        int ndir = dir ^ is_red;
        int move = (ndir == 1 ? 1 : -1);
        int j = i + move;
        ll dist  = abs(p[j] - p[i]);
        int nt = (t + (dist % k)) % k;
        nxt[i][dir][t] = {j, ndir, nt};
      }
    }
  }

  auto dfs = [&](auto& dfs, int i, int dir, int t) {
    if (vis[i][dir][t] == 1) {
      vis[i][dir][t] = 3;
      return;
    }
    if (vis[i][dir][t] != 0) {
      return;
    }
    vis[i][dir][t] = 1;
    auto [j, ndir, nt] = nxt[i][dir][t];
    dfs(dfs, j, ndir, nt);
    if (vis[j][ndir][nt] == 2) {
      vis[i][dir][t] = 2;
    }
    else if (make_tuple(i, dir, t) == make_tuple(j, ndir, nt)) {
      vis[i][dir][t] = 2;
    }
    else {
      vis[i][dir][t] = 3;
    }
  };

  for (int i = 0; i <= n + 1; i++) {
    for (int dir = 0; dir < 2; dir++) {
      for (int t = 0; t < k; t++) {
        if (vis[i][dir][t] == 0) {
          dfs(dfs, i, dir, t);
        }
      }
    }
  }

  for (auto x : a) {
    int i = int(lower_bound(p.begin(), p.end(), x) - p.begin());
    if (i == n + 1) {
      cout << "YES" << '\n';
      continue;
    }
    ll dist = p[i] - x;
    int t = dist % k;
    if (vis[i][1][t] == 2) {
      cout << "YES" << '\n';
    }
    else {
      cout << "NO" << '\n';
    }
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