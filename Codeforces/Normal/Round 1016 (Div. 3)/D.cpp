#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((ll)(x).size())

pair<ll, ll> f1(ll x, ll r_lo, ll r_hi, ll c_lo, ll c_hi, ll x_lo, ll x_hi) {
  if (x_lo == x_hi) {
    return {r_lo, c_lo};
  }
  ll blk = (x_hi - x_lo + 1) / 4;
  pair<ll, ll> b1 = {x_lo, x_lo + blk - 1};
  pair<ll, ll> b2 = {x_lo + blk, x_lo + 2 * blk - 1};
  pair<ll, ll> b3 = {x_lo + 2 * blk, x_lo + 3 * blk - 1};
  pair<ll, ll> b4 = {x_lo + 3 * blk, x_lo + 4 * blk - 1};
  if (b1.first <= x && x <= b1.second) {
    return f1(x, r_lo, (r_lo + r_hi) / 2, c_lo, (c_lo + c_hi) / 2, b1.first, b1.second);
  }
  if (b2.first <= x && x <= b2.second) {
    return f1(x, (r_lo + r_hi + 1) / 2, r_hi, (c_lo + c_hi + 1) / 2, c_hi, b2.first, b2.second);
  }
  if (b3.first <= x && x <= b3.second) {
    return f1(x, (r_lo + r_hi + 1) / 2, r_hi, c_lo, (c_lo + c_hi) / 2, b3.first, b3.second);
  }
  return f1(x, r_lo, (r_lo + r_hi) / 2, (c_lo + c_hi + 1) / 2, c_hi, b4.first, b4.second);
}

ll f2(ll r, ll c, ll r_lo, ll r_hi, ll c_lo, ll c_hi, ll x_lo, ll x_hi) {
  if (x_lo == x_hi) {
    return x_lo;
  }
  ll blk = (x_hi - x_lo + 1) / 4;
  pair<ll, ll> b1 = {x_lo, x_lo + blk - 1};
  pair<ll, ll> b2 = {x_lo + blk, x_lo + 2 * blk - 1};
  pair<ll, ll> b3 = {x_lo + 2 * blk, x_lo + 3 * blk - 1};
  pair<ll, ll> b4 = {x_lo + 3 * blk, x_lo + 4 * blk - 1};

  tuple<ll, ll, ll, ll> coords1 = {r_lo, (r_lo + r_hi) / 2, c_lo, (c_lo + c_hi) / 2};
  tuple<ll, ll, ll, ll> coords2 = {(r_lo + r_hi + 1) / 2, r_hi, (c_lo + c_hi + 1) / 2, c_hi};
  tuple<ll, ll, ll, ll> coords3 = {(r_lo + r_hi + 1) / 2, r_hi, c_lo, (c_lo + c_hi) / 2};
  tuple<ll, ll, ll, ll> coords4 = {r_lo, (r_lo + r_hi) / 2, (c_lo + c_hi + 1) / 2, c_hi};

  {
    auto [rlo, rhi, clo, chi] = coords1;
    if (rlo <= r && r <= rhi && clo <= c && c <= chi) {
      return f2(r, c, rlo, rhi, clo, chi, b1.first, b1.second);
    }
  }

  {
    auto [rlo, rhi, clo, chi] = coords2;
    if (rlo <= r && r <= rhi && clo <= c && c <= chi) {
      return f2(r, c, rlo, rhi, clo, chi, b2.first, b2.second);
    }
  }

  {
    auto [rlo, rhi, clo, chi] = coords3;
    if (rlo <= r && r <= rhi && clo <= c && c <= chi) {
      return f2(r, c, rlo, rhi, clo, chi, b3.first, b3.second);
    }
  }

  auto [rlo, rhi, clo, chi] = coords4;
  return f2(r, c, rlo, rhi, clo, chi, b4.first, b4.second);
}

void solve() {
  ll n, q;
  cin >> n >> q;

  ll lo = 1, hi = 1ll << (n << 1);

  while (q--) {
    string op;
    cin >> op;
    if (op == "->") {
      ll r, c;
      cin >> r >> c;
      cout << f2(r, c, 1, 1ll << n, 1, 1ll << n, lo, hi) << '\n';
    }
    else {
      ll x;
      cin >> x;
      auto [r, c] = f1(x, 1, 1ll << n, 1, 1ll << n, lo, hi);
      cout << r << ' ' << c << '\n';
    }
  }
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