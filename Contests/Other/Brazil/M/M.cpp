#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int q;
  cin >> q;

  vector<bool> alive = {true};
  vector<vector<int>> g(1);
  stack<pair<int, int>> st;
  st.emplace(0, 0);
  while (q--) {
    int t, x;
    cin >> t >> x;
    --x;
    if (t == 1) {
      g[x].push_back(int(g.size()));
      g.emplace_back();
      alive.push_back(true);
      continue;
    }
    alive[x] = false;
    while (!alive[st.top().first]) {
      auto [u, c] = st.top();
      st.pop();
      if (c != int(g[u].size())) {
        st.emplace(u, c + 1);
        st.emplace(g[u][c], 0);
      }
    }
    cout << st.top().first + 1 << '\n';
  }

  return 0;
}