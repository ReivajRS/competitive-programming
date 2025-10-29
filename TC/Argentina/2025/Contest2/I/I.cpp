#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<set<int>> g(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].insert(v), g[v].insert(u);
  }

  vector<int> order(n);
  for (int& x : order) {
    cin >> x;
    --x;
  }

  if (order[0]) {
    cout << "No\n";
    return 0;
  }

  queue<int> q;
  q.push(0);
  for (int i = 1; i < n; ++i) {
    int p = q.front();
    q.pop();
    for (int j = i; j < i + int(g[p].size()); ++j) {
      int u = order[j];
      if (!g[p].count(u)) {
        cout << "No\n";
        return 0;
      }
      g[u].erase(p);
      q.push(u);
    }
    i = i + int(g[p].size()) - 1;
  }
  cout << "Yes\n";

  return 0;
}