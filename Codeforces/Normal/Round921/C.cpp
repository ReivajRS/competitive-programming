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
  int n, k, m;
  cin >> n >> k >> m;
  string s;
  cin >> s;

  int mask = 0;
  string s2 = "";
  
  FOR (i, 0, m) {
    mask |= (1 << (s[i] - 'a'));
    if (__builtin_popcount(mask) == k)
      s2 += s[i], mask = 0;
    if (s2.length() == n)
      break;
  }

  if (s2.length() == n) {
    cout << "YES" << ENDL;
    return;
  }

  FOR (i, 0, k) {
    if (!(mask & (1 << i))) {
      while (s2.length() < n)
        s2 += i + 'a';
      break;
    }
  }

  cout << "NO" << ENDL;
  cout << s2 << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}