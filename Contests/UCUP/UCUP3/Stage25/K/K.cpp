#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

void solve(){
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> row(n);
  for (int i = 0; i < n * m; ++i) {
    int x;
    cin >> x;
    row[(x - 1) / m].push_back(i);
  }

  if (k >= m) {
    cout << m << '\n';
    return;
  }

  int ans = 1e9;
  for (int i = 0; i < n; ++i) {
    ans = min(ans, row[i][m - k - 1] + 1); 
  }
  ans = max(ans, m);
  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while(t--) solve();
  
  return 0;
}