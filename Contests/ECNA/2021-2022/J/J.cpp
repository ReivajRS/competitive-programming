#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
// #define FOR()

signed main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vi lg(n), rg(n);
  stack<int> st;
  for (int i = 0; i < n; i++) {
    while (!st.empty() && a[st.top()] >= a[i]) {
      st.pop();
    }
    lg[i] = (st.empty() ? -1 : st.top());
    st.push(i);
  }

  while (!st.empty()) {
    st.pop();
  }

  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && a[st.top()] >= a[i]) {
      st.pop();
    }
    rg[i] = (st.empty() ? n : st.top());
    st.push(i);
  }

  ll ans = 0, ans_l, ans_r;
  for (int i = 0; i < n; i++) {
    ll val = (rg[i] - lg[i] - 1) * 1ll * a[i];
    if (val > ans || (val == ans && lg[i] + 2 < ans_l)) {
      ans = val;
      ans_l = lg[i] + 2;
      ans_r = rg[i];
    }
  }
  cout << ans_l << ' ' << ans_r << ' ' << ans << '\n';


  return 0;
}