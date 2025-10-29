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
  
  int n, x;
  cin >> n >> x;

  unordered_set<int> us;
  FOR (i, 0, n) {
    int y;
    cin >> y;
    for (int j = y; j <= x; j += y) us.insert(j);
  }
  cout << SZ(us) << ENDL;

  return 0;
}