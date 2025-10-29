#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m;
  cin >> n >> m;

  vi a(n);
  for (auto &x : a)
    cin >> x;

  auto check = [&](int k) {
    int act = 0;
    FOR (i, 0, n) {
      if (a[i] <= act) {
        act++;
        continue;
      }
      if (k > 0) {
        act++;
        k--;
      }
    }
    return act >= m;
  };

  int l = 0, r = 200001;

  while (l < r) {
    int m = (l + r) / 2;
    if (check(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }

  cout << r << ENDL;

  return 0;
}