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
  vi a(n);
  for (auto &x : a)
    cin >> x;
  sort(ALL(a));
  int cnt = 0;
  int m = (n + 1) / 2 - 1;
  bool flag = false;
  FOR (i, m, n) {
    if (a[i] != a[m])
      flag = true;
    else
      cnt++;
    if (flag)
      break;
  }
  cout << cnt << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}