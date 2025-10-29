#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll r;
  int n;
  cin >> r >> n;

  ll a = 0, b = r;
  for (int i = 0; i < n; ++i) {
    ll d;
    cin >> d;
    a = max(0ll, min(r, a + d));
    b = max(0ll, min(r, b + d));
  }
  if (a == b) {
    cout << a << '\n';
  } else {
    cout << "uncertain\n";
  }

  return 0;
}