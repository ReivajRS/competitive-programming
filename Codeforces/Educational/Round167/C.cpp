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

  vi a(n), b(n);
  for (auto &x : a)
    cin >> x;
  for (auto &x : b)
    cin >> x;

  int pos = 0, neg = 0, val1 = 0, val2 = 0;

  FOR (i, 0, n) {
    if (a[i] == 0 && b[i] == 0)
      continue;
    if (a[i] == 1 && b[i] == 1) {
      pos++;
      continue;
    }
    if (a[i] == -1 && b[i] == -1) {
      neg++;
      continue;
    }
    if (a[i] > b[i])
      val1 += a[i];
    else
      val2 += b[i];
  }

  while (pos--) {
    if (val1 < val2)
      val1++;
    else
      val2++;
  }
  
  while (neg--) {
    if (val1 > val2)
      val1--;
    else
      val2--;
  }
  
  cout << min(val1, val2) << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}