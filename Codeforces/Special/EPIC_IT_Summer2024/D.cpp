#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
  int n;
  cin >> n;
  vi a(n), c(n + 1, 0);
  map<int, set<int>> mp;
  set<int> st;
  for (auto &x : a) {
    cin >> x;
    c[x]++;
    st.insert(x);
  }
  FOR (i, 0, n + 1) {
    if (c[i] > 0)
      mp[c[i]].insert(i);
  }
  int cnt = n / 2;
  sort(ALL(a));
  int ia = 0, ib = n - 1;
  int cb = 1;
  int ans = 0;
  while (!st.empty()) {
    ia = *st.lower_bound(ia + 1);
    ans++;
    st.erase(ia);
    while (mp[cb].empty())
      cb++;
    // if (cb > n)
    //   break;
    if (!mp[cb].empty()) {
      ib = *prev(mp[cb].end());
      st.erase(ib);
      mp[cb].erase(ib);
    }
  }
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}