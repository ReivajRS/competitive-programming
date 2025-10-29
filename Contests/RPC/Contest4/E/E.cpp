#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i,a,b) for (ll i = (ll)a;i<(ll)b;++i)

signed main() {
  int n, k;
  cin >> n >> k;
  int a[n + 1];
  FOR(i, 1, n + 1) {
    cin >> a[i];
  }

  ll p[n + 1];
  p[0] = 0;
  FOR (i, 1, n + 1) {
    p[i] = p[i - 1] + a[i];
  }

  ll s = 0;
  FOR (i, n - k + 1, n + 1) {
    s += 1ll * a[i] * (i - (n - k));
  }

  s -= a[n - k + 1];
  set<pair<ll, int>> st;
  for (int i = n - k + 1; i >= 1; i--) {
    s += a[i];
    st.insert({s, i});
    s -= 1ll * k * a[i + k - 1];
    s += p[i + k - 2] - p[i - 1];
  }
  for (auto &[v, i] : st) {
    cout << i << ' ' << v << '\n';
  }


  return 0;
}