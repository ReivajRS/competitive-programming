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
  
  int n;
  cin >> n;

  vi a(n);
  for (auto &x : a) {
    cin >> x;
  }

  int total = 0;
  vi difs(5001, 0);
  FOR (i, 0, n) {
    FOR (j, i + 1, n) {
      difs[abs(a[i] - a[j])]++;
      total++;
    }
  }

  vector<ll> difs2(10001, 0);
  FOR (i, 0, SZ(difs)) {
    if (difs[i] == 0)
      continue;
    FOR (j, 0, SZ(difs)) {
      difs2[i + j] += 1ll * difs[i] * difs[j];
    }
  }

  ll num = 0;

  FOR (i, 0, SZ(difs2)) {
    if (difs2[i] == 0)
      continue;
    int cnt = 0;
    FOR (j, i + 1, SZ(difs)) {
      cnt += difs[j];
    }
    num += difs2[i] * cnt;
  }

  cout << setprecision(12) << fixed;
  cout << 1.0 * num / (1ll * total * total * total);
  
  return 0;
}