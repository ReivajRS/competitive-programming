#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

constexpr int MOD = int(1e9) + 7;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> ways(3);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    
    if (x == 1) {
      ways[0] = (ways[0] + 1) % MOD;
    } else if (x == 2) {
      ways[1] = ((ways[1] + ways[1]) % MOD + ways[0]) % MOD;
    } else {
      ways[2] = (ways[2] + ways[1]) % MOD;
    }
  }
  cout << ways[2] << '\n';
  
  return 0;
}