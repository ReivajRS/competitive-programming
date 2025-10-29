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
  int n;
  cin >> n;
  string s;
  cin >> s;

  int idx = n;
  FOR (i, 0, n - 1) {
    if (s[i + 1] > s[i]) {
      idx = i + 1;
      break;
    }
  }

  string sub = s.substr(0, idx);
  string rsub = sub;
  reverse(ALL(rsub));
  sub += rsub;
  string sub2 = "";
  sub2 += s[0];
  sub2 += s[0];
  cout << min(sub, sub2) << ENDL;
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