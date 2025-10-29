#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve() {
  int a1, a2, b1, b2;
  cin >> a1 >> a2 >> b1 >> b2;
  vector<pi> v_a = {{a1, a2}, {a1, a2}, {a2, a1}, {a2, a1}};
  vector<pi> v_b = {{b1, b2}, {b2, b1}, {b1, b2}, {b2, b1}};
  int cnt = 0;
  FOR (i, 0, 4) {
    int c_a = 0, c_b = 0;
    if (v_a[i].first > v_b[i].first) {
      c_a++;
    }
    if (v_a[i].first < v_b[i].first) {
      c_b++;
    }
    if (v_a[i].second > v_b[i].second) {
      c_a++;
    }
    if (v_a[i].second < v_b[i].second) {
      c_b++;
    }
    if (c_a > c_b) {
      cnt++;
    }
  }
  cout << cnt << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}