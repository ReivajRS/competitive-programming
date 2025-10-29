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

  ll n, m, k;
  cin >> n >> m >> k;

  ll l = 1, r = n * m;

  auto get_cnt = [&](ll x) -> ll {
    ll cnt = 0;
    FOR (i, 1, n + 1) {
      cnt += min(m, (x - 1) / i);
    }
    return cnt;
  };

  while (l < r) {
    ll m = (l + r + 1) >> 1;
    if (get_cnt(m) >= k) {
      r = m - 1;
    }
    else {
      l = m;
    }
  }

  cout << l << ENDL;
  
  return 0;
}