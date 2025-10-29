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
  string s(m, 'B');
  FOR (i, 0, n) {
    int x;
    cin >> x;
    int op1 = min(x, m + 1 - x), op2 = max(x, m + 1 - x);
    op1--, op2--;
    if (s[op1] == 'B')
      s[op1] = 'A';
    else
      s[op2] = 'A';
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