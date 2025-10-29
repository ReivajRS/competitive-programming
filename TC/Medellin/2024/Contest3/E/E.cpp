#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define ROF(i, a, b) for(ll i = (ll)a - 1; i >= b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  ll n;
  cin >> n;
  vector<pair<ll, ll>> div;
  ll aux_n = n;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i != 0) continue;
    int cnt = 0;
    while (n % i == 0) {
      cnt++;
      n /= i;
    }
    div.pb({i, cnt});
  }
  if (n != 1) {
    div.pb({n, 1});
  }

  n = aux_n;
  map<ll, ll> m;  
  ll val = 3;
  for (ll i = 1; i * i <= n; i++) {
    m[i * i] = val;
    val += 2;
  }

  if (m.count(n)) {
    cout << m[n] << ENDL;
    return 0;
  }

  // p2
  bool flag = 0;
  ll pw = 1;
  for (auto &[d, e] : div) {
    if (e >= 2) {
      pw *= pow(d, e - (e & 1));
      flag = 1;
    }
  }

  if (!flag) {
    cout << n * 3 << ENDL;
    return 0;
  }

  cout << m[pw] * n / pw  << ENDL;
  return 0;
}