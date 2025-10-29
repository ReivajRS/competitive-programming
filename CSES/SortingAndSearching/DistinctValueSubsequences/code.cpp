#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = int(1e9) + 7;

ll binpow(ll x, ll p) {
  if (p == 0) return 1;
  ll res = binpow(x, p / 2);
  return res * res % MOD * (p & 1 ? x : 1) % MOD;
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  ll product = 1, ans = 0;
  map<int, int> cnt;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (cnt.count(x)) {
      (product *= binpow(cnt[x] + 1, MOD - 2)) %= MOD;
    }
    (ans += product) %= MOD;
    cnt[x]++;
    (product *= cnt[x] + 1) %= MOD;
  }

  cout << ans << '\n';
}