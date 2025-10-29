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
  int n, m;
  cin >> n >> m;
  
  string s;
  cin >> s;
  
  vi ind;
  set<int> st;
  FOR (i, 0, m) {
    int x;
    cin >> x;
    st.insert(x);
  }

  string c;
  cin >> c;

  for (auto &x : st)
    ind.pb(x);
  sort(ALL(c));

  FOR (i, 0, SZ(ind)) {
    s[ind[i] - 1] = c[i];
  }

  cout << s << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}