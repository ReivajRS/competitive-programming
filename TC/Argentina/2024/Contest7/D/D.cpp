#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

struct FT {
  vector<ll> s;
  FT(int n) : s(n) {}
  void update(int pos, ll dif) { // a[pos] += dif 
    for (; pos < SZ(s); pos |= pos + 1) s[pos] += dif;
  }
  ll query(int pos) { // [0, pos)
    ll res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
    return res;
  }
  int lower_bound(ll sum) {
    if (sum <= 0) return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1)
      if (pos + pw <= SZ(s) && s[pos + pw - 1] < sum)
        pos += pw, sum -= s[pos - 1];
    return pos;
  }
};

constexpr ll INF = 1e18;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, q;
  cin >> n >> m >> q;

  vi b(m);
  FOR (i, 0, n) {
    int x;
    cin >> x;
    b[x - 1]++;
  }

  vi p(m);
  iota(ALL(p), 0);
  sort(ALL(p), [&](int i, int j) { return b[i] < b[j]; });

  vector<pair<ll, int>> qr(q);
  FOR (i, 0, q) {
    cin >> qr[i].first;
    qr[i].second = i; 
  }

  sort(ALL(qr));

  vi ans(q);
  FT ft(m + 5);
  ll ptr = 0, time = n;
  FOR (i, 0, m) {
    ft.update(p[i], 1);
    while (i + 1 < m && b[p[i]] == b[p[i + 1]]) {
      ft.update(p[++i], 1);
    }
    ll delta_time = (i == m - 1 ? INF : 1ll * (b[p[i + 1]] - b[p[i]]) * (i + 1));
    // cout << "checando " << i << ' ' << p[i] << ' ' << b[p[i]] << " delta " << delta_time << ENDL;
    while (ptr < q && qr[ptr].first - time <= delta_time) {
      ans[qr[ptr].second] = ft.lower_bound((qr[ptr].first - time - 1) % (i + 1) + 1);
      // cout << "respuesta " << qr[ptr].second << ' ' << ans[qr[ptr].second] << ENDL;
      ptr++;
    }
    time += delta_time;
  }

  for (auto &x : ans) cout << x + 1 << ENDL;  

  return 0;
}