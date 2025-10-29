#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, a, b;
  cin >> n >> a >> b;

  vector<ll> pref(n + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pref[i + 1] = pref[i] + x;
  }

  multiset<ll> st;

  ll ans = -1e18;
  for (int i = a; i <= n; i++) {
    st.insert(pref[i - a]);
    if (i - b - 1 >= 0) {
      st.extract(pref[i - b - 1]);
    }
    ans = max(ans, pref[i] - *st.begin());
  }

  cout << ans << '\n';

  return 0;
}