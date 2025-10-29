#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n;
  cin >> n;

  vi a(n), cnt(31);

  FOR (i, 0, n) {
    int x;
    cin >> x;
    FOR (k, 0, 31) {
      cnt[k] += (x >> k) & 1;
    }
  }

  FOR (i, 0, n) {
    FOR (k, 0, 31) {
      if (cnt[k] == 0)
        continue;
      a[i] |= 1 << k;
      cnt[k]--;
    }
  }

  FOR (i, 0, n) {
    cout << a[i] << " \n"[i == n - 1];
  }
  
  return 0;
}