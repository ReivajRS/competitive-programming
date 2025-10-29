#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll a, b, m, r0;
  cin >> a >> b >> m >> r0;

  vector<int> vis(m + 1, -1);
  int cnt = 0;
  ll r = r0;
  while (vis[r] == -1) {
    vis[r] = cnt;
    r = (a * r + b) % m;
    cnt++;
  }

  cout << cnt - vis[r] << '\n';

  return 0;
}