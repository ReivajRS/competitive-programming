#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i,a,b) for (ll i = (ll)a;i<(ll)b;++i)

signed main() {
  ll n, m;
  cin >> n >> m;

  map<string, ll> nametoid;
  string names[n];
  ll salary[n];
  set<pair<ll, string>> st;
  FOR (i, 0, n) {
    cin >> names[i] >> salary[i];
    nametoid[names[i]] = i;
    st.insert({-salary[i], names[i]});
  }

  while (m--) {
    ll op;
    cin >> op;
    if (op == 1) {
      string s;
      ll inc;
      cin >> s >> inc;
      ll i = nametoid[s];
      st.erase({-salary[i], s});
      salary[i] += inc;
      st.insert({-salary[i], s});
      continue;
    }
    auto [val, s] = *st.begin();
    st.erase(st.begin());
    cout << s << ' ' << -val << '\n';
  }

  return 0;
}