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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;

  vector<ll> a(n);
  FOR (i, 0, n) {
    cin >> a[i];
  }

  sort(a.rbegin(), a.rend());

  ll ans = 0;
  ll sum = 0;
  ll p = 1;

  FOR (i, 0, n) {
    if (i == p) {
      ans += sum;
      p *= 4;
    }
    sum += a[i];
  }

  ans += sum;

  cout << ans << ENDL;

  return 0;
}