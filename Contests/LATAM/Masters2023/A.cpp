#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = unsigned long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll sum(int x) { return 1ll * x * (x + 1); }

signed main() { __
  ll n;
  cin >> n;
  ll x = 1;
  while (sum(x) < n)
    x++;
  if (n > sum(x - 1) && n <= sum(x - 1) + x)
    cout << x * 2 - 1 << ENDL;
  else
    cout << x * 2 << ENDL;
  return 0;
}