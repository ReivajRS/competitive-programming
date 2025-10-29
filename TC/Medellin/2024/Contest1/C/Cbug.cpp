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
  int n, b, x;
  cin >> n >> b >> x;

  vi a(n);
  FOR (i, 0, n) {
    cin >> a[i];
  }

  auto sum = [](int x) -> ll {
    return 1ll * x * (x + 1) / 2;
  };

  auto f = [&](int k) -> ll {
    ll val = 0;
    FOR (i, 0, n) {
      // cout << val << ENDL;
      if (a[i] <= k) {
        cout << "menor " << val << ' ' << sum(a[i] - 1) * b << ENDL;
        val += sum(a[i] - 1) * b;
        continue;
      }
      int v = a[i] / k;
      int agg = (v * sum(k - 1) * v) * b; 
      
      if (a[i] % k != 0) {
        int d = a[i] % k;
        // cout << d << ENDL;
        agg += (d * k * v) * b;
        
      }
      cout << "mayor " << val << ' ' << (v * sum(k - 1) * v) * b << ' ' << (( a[i] % k) * k * v) * b << ENDL;
      val += agg;
    }
    val -= (k - 1) * x;
    cout << val << ENDL;
    return val;
  };
  
  int l = 1, r = n;


  f(2);
  f(3);
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