#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

constexpr int MOD = 98765431;

int add(int a, int b) {
  return a + b >= MOD ? a + b - MOD : a + b;
}

int mul(int a, int b) {
  return (ll)a * b % MOD;
}

int binpow(int a, int b) {
  int res = 1;
  a %= MOD;
  while (b) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

int f(vector<int> a, int m, vector<int>& p, vector<int>& q, set<vector<int>>& st) {
  if (st.count(a)) {
    return 0;
  }
  st.insert(a);
  int n = SZ(a);

  int ans = 0, cycles = 0, vis = 0;
  for (int i = 0; i < n; i++) {
    int now = i;
    if (vis & (1 << now)) {
      continue;
    }
    while (!(vis & (1 << now))) {
      vis |= 1 << now;
      now = a[now];
    }
    cycles++;
  }

  ans = add(ans, binpow(m, cycles));

  vector<int> op1(n), op2(n);
  for (int i = 0; i < n; i++) {
    op1[p[i]] = a[i];
  }
  for (int i = 0; i < n; i++) {
    op2[q[i]] = a[i];
  }
  ans = add(ans, f(op1, m, p, q, st));
  ans = add(ans, f(op2, m, p, q, st));
  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> p(n), q(n);
  for (auto &x : p) {
    cin >> x;
    x--;
  }
  for (auto &x : q) {
    cin >> x;
    x--;
  }

  vector<int> a(n);
  iota(a.begin(), a.end(), 0);
  set<vector<int>> st;
  int ans = f(a, m, p, q, st);
  ans = mul(ans, binpow(SZ(st), MOD - 2));
  cout << ans << '\n';
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