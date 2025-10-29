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
  string s;
  cin >> s;
  int cnt = 0;
  char c = s[0];
  FOR (i, 0, s.length())
    if (c == s[i])
      cnt++;
  if (cnt == s.length())
    cout << -1 << ENDL;
  else
    cout << s.length() - 1 << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
      solve();
  }
  return 0;
}