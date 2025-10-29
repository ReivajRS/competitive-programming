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
  string n1, n2;
  cin >> n1 >> n2;
  int n = SZ(n1);

  string ans1(n, '$'), ans2(n, '$');

  int flag = 0;
  FOR (i, 0, n) {
    if (n1[i] == n2[i]) {
      ans1[i] = ans2[i] = n1[i];
      continue;
    }
    if (flag) {
      if (flag == 1)
        ans1[i] = min(n1[i], n2[i]), ans2[i] = max(n1[i], n2[i]);
      else
        ans1[i] = max(n1[i], n2[i]), ans2[i] = min(n1[i], n2[i]);
      continue;
    }
    ans1[i] = n1[i];
    ans2[i] = n2[i];
    if (n1[i] > n2[i])
      flag = 1;
    else
      flag = 2;
  }

  cout << ans1 << ENDL << ans2 << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}