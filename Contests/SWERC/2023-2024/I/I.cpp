#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  ll m, n;
  cin >> m >> n;
  ll s1 = m, s2 = n;
  FOR (i, 0, m) {
    ll x;
    cin >> x;
    s1 += x;
  }
  FOR (i, 0, n) {
    ll x;
    cin >> x;
    s2 += x;
  }
  if (s1 == s2) {
    cout << "TIED" << ENDL;
    return 0;
  }
  cout << (s1 > s2 ? "ALICE" : "BOB") << ENDL;

  return 0;
}