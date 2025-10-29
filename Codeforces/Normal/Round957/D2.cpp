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
  string s;
  cin >> s;
  s = 'L' + s + 'L';
  ll w_cnt = 0, pos = 0;
  while (pos < SZ(s)) {
    if (s[pos] == 'W') {
      w_cnt++;
      if (w_cnt > k) {
        cout << "NO" << ENDL;
        return;
      }
      pos++;
      if (pos == SZ(s)) {
        cout << "YES" << ENDL;
      }
      if (s[pos] == 'C') {
        cout << "NO" << ENDL;
        return;
      }
      continue;
    }
    ll best_jump = 0;
    ROF (jump, m + 1, 1) {
      if (pos + jump >= SZ(s)) {
        cout << "YES" << ENDL;
        return;
      }
      if (s[pos + jump] == 'L') {
        best_jump = jump;
        break;
      }
      if (!best_jump) {
        if (s[pos + jump] == 'W')
          best_jump = jump;
      }
    }
    if (!best_jump) {
      cout << "NO" << ENDL;
      return;
    }
    pos += best_jump;
  }
  cout << "YES" << ENDL;
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