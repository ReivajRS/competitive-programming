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

struct FT {
  vector<ll> s;
  FT(int n) : s(n) {}
  void update(int pos, ll dif) {
    for (; pos < SZ(s); pos |= pos + 1) s[pos] += dif;
  }
  ll query(int pos) {
    ll res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
    return res;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n;
  cin >> n;
  
  vector<vi> a(3, vi(n));
  FOR (i, 0, 3) {
    FOR (j, 0, n) {
      cin >> a[i][j];
    }
  }

  auto get_inv = [&](int x, int y) {
    FT ft(n + 1);
    vi idx(n + 1);
    FOR (i, 0, n) {
      idx[a[x][i]] = i;
    }
    ll inv = 0;
    ROF (i, n, 0) {
      inv += ft.query(idx[a[y][i]]);
      ft.update(idx[a[y][i]], 1);
    }
    return inv;
  };

  ll inv = get_inv(0, 1) + get_inv(0, 2) + get_inv(1, 2);
  inv /= 2;
  cout << 1ll * n * (n - 1) / 2 - inv << ENDL;

  return 0;
}