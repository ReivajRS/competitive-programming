#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> g(n);
  for (int& x : g) {
    cin >> x;
    --x;
  }

  vector<bool> vis(n);
  int x = 0;
  while (!vis[x]) {
    vis[x] = true;
    x = g[x];
  }
  cout << int(accumulate(vis.begin(), vis.end(), 0)) << '\n';

  return 0;
}