#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
  int n, k;
  cin >> n >> k;
  
  map<int, map<int, int>> mp;
  map<int, int> cnt;
  FOR (i, 0, n) {
    int x;
    cin >> x;
    mp[x % k][x]++;
    cnt[x % k]++;
  }

  ll ans = 0;
  bool flag = 0;

  for (auto &[key, m] : mp) {
    if (cnt[key] & 1) {
      if (!(n & 1) || flag) {
        cout << -1 << ENDL;
        return;
      }
      flag = 1;
    }

    vi b;
    for (auto &[v, c] : m) {
      if (c & 1)
        b.pb(v);
    }
    if (b.empty())
      continue;
    sort(ALL(b));

    if (SZ(b) & 1) {
      vector<ll> dPar, dImpar, psPar, psImpar;
      for (int i = 0; i < SZ(b); i += 2) {
        if (i + 1 < SZ(b))
          dPar.pb((b[i + 1] - b[i]) / k);
      }
      psPar.pb(0);
      FOR (i, 0, SZ(dPar)) {
        psPar.pb(psPar.back() + dPar[i]);
      }

      for (int i = 1; i < SZ(b); i += 2) {
        if (i + 1 < SZ(b))
          dImpar.pb((b[i + 1] - b[i]) / k);
      }
      psImpar.pb(0);
      FOR (i, 0, SZ(dImpar)) {
        psImpar.pb(psImpar.back() + dImpar[i]);
      }

      ll op1 = psPar.back();
      ll op2 = psImpar.back();

      ll op3 = LLONG_MAX;
      for (int i = 1; i < SZ(b) - 1; i++) {
        if (i % 2 == 0 && (n - i - 1) % 2 == 0)
          op3 = min(op3, psPar[i / 2] + (psImpar.back() - psImpar[i / 2]));
      }
      
      ans += min({op1, op2, op3});
      continue;
    }

    for (int i = 0; i < SZ(b); i += 2) {
      if (i + 1 < SZ(b))
        ans += (b[i + 1] - b[i]) / k;
    }
  }

  cout << ans << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}