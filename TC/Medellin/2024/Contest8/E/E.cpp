#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  set<ll> st;

  FOR (i, 0, n) {
    ll x;
    cin >> x;
    st.insert(x);
  }

  for (auto &x : st) {
    FOR (j, 0, 33) {
      ll l = x - (1ll << j), r = x + (1ll << j);
      if (st.count(l) && st.count(r)) {
        cout << "3" << ENDL;
        cout << l << ' ' << x << ' ' << r << ENDL;
        return 0;
      }
    }
  }

  for (auto &x : st) {
    FOR (j, 0, 33) {
      ll r = x + (1ll << j);
      if (st.count(r)) {
        cout << "2" << ENDL;
        cout << x << ' ' << r << ENDL;
        return 0;
      }
    }
  }

  cout << "1" << ENDL;
  cout << *st.begin() << ENDL;

  return 0;
}