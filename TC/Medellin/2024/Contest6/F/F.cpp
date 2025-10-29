#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  vi pot10(10, 0);
  pot10[0] = 1;
  FOR (i, 0, 10) {
    pot10[i] = pot10[i - 1] * 10;
  }

  int n;
  cin >> n;
  while (n--) {
    vector<pi> r(2);
    cin >> r[0].first >> r[0].second >> r[1].first >> r[2].second;
    FOR (i, 0, 10) {
      FOR (j, 0, ) {
        
      }
    }
  }

  return 0;
}