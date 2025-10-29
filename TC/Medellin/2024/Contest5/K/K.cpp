#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

void solve() {
  int n, k;
  cin >> n >> k;

  multiset<pi> st;
  FOR (i, 0, n) {
    int x;
    cin >> x;
    st.insert({x % k, x});
  }

  ll ans = 0;
  while (!st.empty()) {
    // cerr << SZ(st) << ENDL;
    pi p = *st.begin();
    // cerr << p.first << ' ' << p.second << ENDL;
    st.erase(st.begin());
    if (p.first == 0) {
      ans += (p.second + st.begin()->second) / k;
      st.erase(st.begin());
      continue;
    }
    auto it = st.lower_bound({k - p.first, 0});
    if (it == st.end()) {
      it = st.begin();
    }
    ans += (p.second + it->second) / k;
    st.erase(it);
  }

  cout << ans << ENDL;
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