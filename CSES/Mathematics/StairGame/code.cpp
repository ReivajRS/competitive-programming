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
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    int x = 0;
    FOR (i, 0, n) {
      int v;
      cin >> v;
      if (i & 1)
        x ^= v;
    }
    cout << (x != 0 ? "first" : "second") << ENDL;
  }
  return 0;
}