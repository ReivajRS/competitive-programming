#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  ll s;
  cin >> n >> s;

  vector<int> a(n);
  vector<ll> pref(2 * n + 1);
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i % n];
    pref[i + 1] = pref[i] + a[i % n];
  }

  ll sum = pref[n];
  s %= sum;
  if (s == 0) {
    cout << "Yes" << '\n';
    return 0;
  }
  // cout << s << ' ' << sum << '\n';
  unordered_set<ll> st;
  
  for (int i = 0; i <= 2 * n; i++) {
    if (st.count(pref[i] - s)) {
      cout << "Yes" << '\n';
      return 0;
    }
    if (i <= n) {
      st.insert(pref[i]);
    }
  }

  cout << "No" << '\n';

  return 0;
}