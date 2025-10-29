#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
#define SZ(x) ((ll)(x).size())

ll log_2(ll x) {
  if (x <= 1) {
    return 0;
  }
  ll p = 1;
  ll cnt = 0;
  while(p < x) {
    p <<= 1;
    cnt++;
  }
  return cnt;
}

void solve() {
  ll n, m, a, b;
  cin >> n >> m >> a >> b;
  ll n_rem = min(a, n - a + 1);
  ll m_rem = min(b, m - b + 1);
  ll mn = 1 + min(log_2(n_rem) + log_2(m), log_2(m_rem) + log_2(n));
  cout << mn << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}