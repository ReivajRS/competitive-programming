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
  int n;
  cin >> n;
  vi a;
  set<int> st;
  FOR (i, 0, n) {
    int x;
    cin >> x;
    st.insert(x);
  }
  a.pb(0);
  for (auto &x : st)
    a.pb(x);
  bool flag = 0;
  FOR (i, 1, SZ(a)) {
    if (a[i] - a[i - 1] == 1)
      flag ^= 1;
    else {
      flag ^= 1;
      break;
    }
  }
  cout << (flag ? "Alicius" : "Bobius") << ENDL;
  return 0;
}