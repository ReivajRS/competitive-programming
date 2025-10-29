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
  vector<string> a(n);
  for (auto &x : a)
    cin >> x;

  ROF (i, n, 0) {
    if (i -  1 >= 0) {
      if (stoi(a[i]) >= stoi(a[i - 1]))
        continue;
      if ((a[i - 1].back()-'0') <= stoi(a[i]) && a[i - 1][0] <= a[i - 1].back()) {
        a[i - 1] = a[i - 1][0];
        continue;
      }
      cout << "NO" << ENDL;
      return;
    }
  }

  cout << "YES" << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}