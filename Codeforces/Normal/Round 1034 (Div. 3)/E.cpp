#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n), cnt(n + 1);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  ll mex = 0;
  while (mex < n && cnt[mex]) {
    mex++;
  }
  vector<ll> pref(n + 5);
  for (ll i = 0; i <= mex; i++) {
    ll mn_erases = cnt[i];
    ll mx_erases = n - i;
    if (mn_erases <= mx_erases) {
      pref[mn_erases]++;
      pref[mx_erases + 1]--;
    }
  }
  for (ll i = 0; i <= n; i++) {
    cout << pref[i] << ' ';
    pref[i + 1] += pref[i];
  }
  cout << '\n';
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