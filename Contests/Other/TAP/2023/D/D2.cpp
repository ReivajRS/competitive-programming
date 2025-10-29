#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define ROF(i, a, b) for (ll i = (ll)b - 1; i >= (ll)a; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  ll n;
  cin >> n;

  vi a(n), b(n), alc(n);
  
  for (auto &x : a)
    cin >> x;
  for (auto &x : b)
    cin >> x;
  
  ll sumA = 0, sumB = 0, mn = 1e18;
  FOR (i, 0, n) {
    sumA += a[i];
    sumB += b[i];
    mn = min(mn, sumB / sumA);
  }

  cout << mn << ENDL;

  return 0;
}