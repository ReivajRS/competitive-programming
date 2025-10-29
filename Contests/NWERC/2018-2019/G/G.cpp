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
  string s;
  cin >> s;
  int n = SZ(s);
  if (n >= 3 && (s.substr(n - 3) == "LRL" || s.substr(n - 3) == "RLR" || s.substr(n - 3) == "UDU" || s.substr(n - 3) == "DUD")) {
    cout << "impossible" << ENDL;
    return 0;
  }
  int x = 0, y = 0, v = 1;
  set<pi> ans;
  FOR (i, 0, n) {
    if (s[i] == 'D') {
      y = -v;
      ans.insert({x, y - 1});
      if (i + 1 < n && s[i + 1] != 'U')
        v++;
    }
    if (s[i] == 'R') {
      x = v;
      ans.insert({x + 1, y});
      if (i + 1 < n && s[i + 1] != 'L')
        v++;
    }
    if (s[i] == 'U') {
      y = v;
      ans.insert({x, y + 1});
      if (i + 1 < n && s[i + 1] != 'D')
        v++;
    }
    if (s[i] == 'L') {
      x = -v;
      ans.insert({x - 1, y});
      if (i + 1 < n && s[i + 1] != 'R')
        v++;
    }
  }
  cout << -x << ' ' << -y << ENDL;
  cout << SZ(ans) << ENDL;
  for (auto &[a, b] : ans)
    cout << a - x << ' ' << b - y << ENDL;
  return 0;
}