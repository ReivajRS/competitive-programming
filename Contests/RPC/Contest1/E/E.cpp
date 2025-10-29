#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = a - 1; i >= b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  double x, y;
  cin >> x >> y;

  cout << setprecision(10) << fixed;
  if(x == y){
    cout << 1.0 << ENDL;
    return 0;
  }

  double ans = x/y;
  double aux = (100-x)/(100-y);
  cout << ans/aux << ENDL;

  return 0;
}