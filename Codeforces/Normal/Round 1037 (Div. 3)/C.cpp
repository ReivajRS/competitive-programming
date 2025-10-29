#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  
  vector<ll> h(n);
  set<ll> st;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    st.insert(h[i]);
  }

  ll water = 1;
  auto it_now = st.find(h[k - 1]);
  for (auto next_it = next(it_now); next_it != st.end(); next_it++, it_now++) {
    ll next_h = *next_it;
    ll curr_h = *it_now;
    if (next_h - curr_h - 1 + water > curr_h) {
      cout << "NO" << '\n';
      return;
    }
    water += next_h - curr_h;
  }
  cout << "YES" << '\n';
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