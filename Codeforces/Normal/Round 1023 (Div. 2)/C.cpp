#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

const ll INF = 1e18;
void solve() {
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
    if (s[i] == '0') {
      b[i] = -INF;
    }
  }
  auto print = [](vector<ll>& a) -> void {
    for (int i = 0; i < SZ(a); i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  };
  auto fill = [](vector<ll>& a, string& s) -> void {
    for (int i = 0; i < SZ(a); i++) {
      if (s[i] == '0') {
        a[i] = -INF;
      }
    }
  };
  auto get_max = [](vector<ll>& a) -> ll {
    ll sum = 0, mx = 0;
    for (int i = 0; i < SZ(a); i++) {
      sum += a[i];
      sum = max(0ll, sum);
      mx = max(mx, sum);
    }
    return mx;
  };
  if (get_max(b) > k) {
    cout << "No" << '\n';
    return;
  }
  if (get_max(a) == k) {
    cout << "Yes" << '\n';
    print(a);
    return;
  }
  fill(a, s);
  vector<ll> pref_mx_sub(n), suff_mx_sub(n);
  ll sum = 0, mx = 0;
  for (int i = 0; i < n; i++) {
    pref_mx_sub[i] = sum;
    sum += a[i];
    sum = max(0ll, sum);
    mx = max(mx, sum);
  }
  sum = 0;
  for (int i = n - 1; i >= 0; i--) {
    suff_mx_sub[i] = sum;
    sum += a[i];
    sum = max(0ll, sum);
  }
  // print(pref_mx_sub);
  // print(suff_mx_sub);
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      continue;
    }
    bool ok = 0;
    ll pref = pref_mx_sub[i];
    ll suff = suff_mx_sub[i];
    if (pref >= 0 && suff >= 0) {
      sum = pref + suff;
      a[i] = k - sum;
      s[i] = '1';
      ok = 1;
    }
    else if (pref >= 0 && suff < 0) {
      a[i] = k - pref;
      s[i] = '1';
      ok = 1;
    }
    else if (pref < 0 && suff >= 0) {
      a[i] = k - suff;
      s[i] = '1';
      ok = 1;
    }
    else if (pref < 0 && suff < 0) {
      a[i] = k - max(pref, suff);
      s[i] = '1';
      ok = 1;
    }
    if (ok) {
      // if (get_max(a) != k) {  
      //  cout << "ERROR" << '\n'; 
      // }
      cout << "Yes" << '\n';
      print(a);
      return;
    }
  }
  cout << "No" << '\n';
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