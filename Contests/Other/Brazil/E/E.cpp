#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

constexpr int N = 1e5 + 50;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<vector<bool>> vis(2, vector<bool>(N));
  for (int i = 0; i < n; i++) {
    int t, d;
    cin >> t >> d;
    vis[d][t] = true;
  }
  
  bool pending = false;
  int dir = 0, T = -1;
  for (int i = 0; i < N; ++i) {
    if (i == T) {
      if (pending) {
        T += 10;
        dir ^= 1;
        pending = false; 
      }
    } else if (i > T) {
      if (vis[0][i]) {
        dir = 0;
        T = i + 10;
      } else if (vis[1][i]) {
        dir = 1;
        T = i + 10;
      }
    } else {
      if (vis[dir][i]) {
        T = i + 10;
      }
      if (vis[dir ^ 1][i]) {
        pending = true;
      }
    }
  }
  cout << T << '\n';

  return 0;
}

// 3
// acmxacmacmxacm
// acm#icpc#maratona