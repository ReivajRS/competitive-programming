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

void solve() {
  int n;
  cin >> n;
  set<int> st;
  FOR(i, 0, n) {
    int x;
    cin >> x;
    st.insert(x);
  }
  int mex = 1;
  for (auto &x : st)
    if (x == mex)
      mex++;
  if (mex > *st.rbegin())
    cout << (*st.rbegin() % 2 == 0 ? "Bob" : "Alice") << ENDL;
  else
    cout << (mex % 2 == 0 ? "Bob" : "Alice") << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}