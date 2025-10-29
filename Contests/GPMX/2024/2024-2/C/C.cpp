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

signed main() { __
  int q;
  cin >> q;

  while (q--) {
    ll n, t;
    cin >> n >> t;

    if (t == 1) {
      cout << n << ENDL;
      continue;
    }
    
    t--;

    set<ll> st;

    for (ll i = 2; i * i <= t && i <= n; i++) {
      if (t % i == 0) {
        st.insert(i);
        if (t / i != i && t / i <= n)
          st.insert(t / i);
      }
    }

    if (!st.count(1))
      st.insert(1);
    if (t <= n && !st.count(t))
      st.insert(t);

    cout << st.size() << ENDL;
  }
  
  return 0;
}