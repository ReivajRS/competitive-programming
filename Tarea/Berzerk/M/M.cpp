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

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m, h;
  cin >> n >> m >> h;

  int sum = 0;
  vi s(m);
  for (auto &x : s) {
    cin >> x;
    sum += x;
  }

  if (sum < n) {
    cout << -1 << ENDL;
    return 0;
  }

  double p = 1.0;

  FOR (i, 1, n) {
    p *= 1.0 * (sum - (s[h - 1] - 1) - i) / (sum - i);
  }

  cout << setprecision(9) << fixed;
  cout << 1.0 - p << ENDL;
  
  return 0;
}