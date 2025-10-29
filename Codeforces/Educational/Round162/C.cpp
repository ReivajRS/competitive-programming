#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
  int n, q;
  cin >> n >> q;
  
  vi c(n);
  vector<ll> pref1(n + 1, 0), pref(n + 1, 0);
  FOR (i, 0, n) {
    cin >> c[i];
    pref1[i + 1] = (c[i] == 1) + pref1[i];
    pref[i + 1] = c[i] + pref[i] - 1;
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
      cout << "NO" << ENDL;
      continue;
    }
    if (pref1[r] - pref1[l - 1] <= pref[r] - pref[l - 1])
      cout << "YES" << ENDL;
    else
      cout << "NO" << ENDL;
  }
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}