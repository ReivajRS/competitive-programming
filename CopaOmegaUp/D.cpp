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
  int n;

  vector<ll> a(101), b(101);
  FOR (i, 0, 101) {
    a[i] = 1ll * i * (i + 1) * (2*i + 1) / 6;
    b[i] = 1ll * (i * (i + 1) / 2) * (i * (i + 1) / 2);
  }

  while (cin >> n) {
    cout << a[n] << ' ' << b[n] << ENDL; 
  }

  return 0;
}