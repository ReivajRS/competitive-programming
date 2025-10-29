#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

inline int sz(pair<int, int> p) {
  return p.second - p.first;
}

void solve() {
  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> chains(k);
  for (auto &[a, b] : chains) {
    cin >> a >> b;
  }

  sort(chains.begin(), chains.end(), [&](pair<int, int> a, pair<int, int> b) -> bool {
    return sz(a) > sz(b);
  });

  if (k == 1) {
    for (int i = 0; i < n; ++i) {
      cout << i << " \n"[i == n - 1];
    }
    return;
  }

  if (sz(chains[0]) == sz(chains[1]) && sz(chains.back()) > sz(chains[0]) - 2) {
    cout << "IMPOSSIBLE\n";
    return;
  }

  vector<int> p(n + 1);
  const int root = chains[0].first;
  for (auto [l, r] : chains) {
    p[l] = root;
    for (int i = l + 1; i <= r; ++i) {
      p[i] = i - 1;
    }
  }
  p[root] = 0;

  if (sz(chains[0]) == sz(chains[1])) {
    p[chains.back().first] = chains[0].first + 1;
  }

  for (int i = 1; i <= n; ++i) {
    cout << p[i] << " \n"[i == n];
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}