#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define ROF(i, a, b) for(ll i = (ll)a - 1; i >= (ll)b; i--)
#define ENDL '\n'

void solve() {
  ll n;
  cin >> n;

  vi a(n);
  ll sum = 0, total = 0;
  FOR (i, 0, n) {
    cin >> a[i];
    total += a[i];
    if (a[i] == 1) {
      sum += 2;
    } else {
      sum += 1;
    }
  }

  if (n == 1) {
    cout << "NO" << ENDL;
    return;
  }

  if (sum > total) {
    cout << "NO" << ENDL;
    return;
  }

  cout << "YES" << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll tc;
  cin >> tc;
  while(tc--) {
    solve();
  }

  return 0;
}