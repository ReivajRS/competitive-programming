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
  int n, m;
  cin >> n >> m;
  
  if (m < n - 1 || m > 2*n + 2) {
    cout << -1 << ENDL;
    return 0;
  }

  int cnt1 = 0;
  while (n || m) {
    if (n > m || cnt1 == 2) {
      cout << 0;
      cnt1 = 0;
      n--;
    }
    else {
      cout << 1;
      cnt1++;
      m--;
    }
  }

  cout << ENDL;

  return 0;
}