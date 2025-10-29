#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  sort(ALL(a));
  ll val = 0;
  while (SZ(a) >= 2) {
    ll v1 = a.back();
    a.pop_back();
    ll v2 = a.back();
    a.pop_back();
    ll aux = v2;
    v2 = min(v1, v2 + k);
    k -= v2 - aux;
    val += v1 - v2;
  }
  if (SZ(a) == 1) {
    val += a.back();
  }
  cout << val << ENDL;
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