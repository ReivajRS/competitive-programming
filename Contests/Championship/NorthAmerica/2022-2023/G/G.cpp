#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
// BRO... CSM AC2# AC2++ HIJOS DE HONOR 
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define ROF(i,a,b) for(ll i = (ll)a-1; i >= (ll)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, m, k;
  cin >> n >> m >> k;

  vi a(n + m - 1);
  FOR (i, 0, n) {
    cin >> a[i];
  }
  n += m - 1;

  stack<ll> st;
  vi paid(n);
  ll ans = 0;
  ll to_pay = k;
  FOR (i, 0, n) {
    if (i - m >= 0) to_pay += paid[i - m];
    st.push(i);
    while (!st.empty() && to_pay) {
      ll j = st.top();
      st.pop();
      if (j <= i - m) continue;
      ll add = min(to_pay, a[j] - paid[j]);
      ans += add, to_pay -= add, paid[j] += add;
      if (paid[j] != a[j]) st.push(j);
    }
  }
  cout << ans << ENDL;

  return 0;
}