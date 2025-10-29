#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
#define SZ(x) ((ll)(x).size())

const ll MOD = 998244353;
vector<ll> pows2;

void solve() {
  ll n;
  cin >> n;
  vector<ll> p(n), q(n);
  for (ll i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (ll i = 0; i < n; i++) {
    cin >> q[i];
  }
  vector<ll> ans(n);
  pair<ll, ll> mxp = {p[0], 0}, mxq = {q[0], 0};
  ans[0] = (pows2[p[0]] + pows2[q[0]]) % MOD;
  for (ll i = 1; i < n; i++) {
    mxp = max(mxp, {p[i], i});
    mxq = max(mxq, {q[i], i});
    pair<ll, ll> op1, op2;
    op1 = {mxp.first, q[i - mxp.second]};
    if (op1.first < op1.second) {
      swap(op1.first, op1.second);
    }
    op2 = {mxq.first, p[i - mxq.second]};
    if (op2.first < op2.second) {
      swap(op2.first, op2.second);
    }
    if (op1 >= op2) {
      ans[i] = (pows2[op1.first] + pows2[op1.second]) % MOD;
    }
    else {
      ans[i] = (pows2[op2.first] + pows2[op2.second]) % MOD;
    }
  }

  for (auto x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  const ll maxn = 1e5 + 10;
  pows2.resize(maxn);
  pows2[0] = 1;
  for (ll i = 1; i < maxn; i++) {
    pows2[i] = (ll)pows2[i - 1] * 2 % MOD;
  }
  
  ll tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}