#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  ll l = 1, r = n;
  ll li = 0, ri = n - m;
  vi ans(n);
  while (r >= k) {
    ans[li++] = r--;
  }
  while (l <= m) {
    ans[ri++] = l++;
  }
  while (l <= r) {
    ans[li++] = l++;
  }
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  ll tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}