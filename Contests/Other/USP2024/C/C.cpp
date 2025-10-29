#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

struct Data {
  ll s, mn;

  Data() : s(0), mn(0) {}
  Data(ll s, ll mn) : s(s), mn(mn) {}

  Data operator+(Data other) {
    return Data(s + other.s, min(mn, other.mn));
  }
};

constexpr int INF = 1e9;

#define QUERY_NEUT INF
struct STree {
  #define ls 2 * v + 1
  #define rs 2 * v + 2
  #define lp ls, tl, tm
  #define rp rs, tm, tr

  int n;
  vector<Data> st;
  vector<ll> lazy;

  STree(int n) : n(n), st(4 * n), lazy(4 * n) {}

  void apply(int v, int tl, int tr, ll val) {
    st[v].s += val * (tr - tl);
    st[v].mn += val;
    lazy[v] += val;
  }

  void push(int v, int tl, int tr) {
    if (lazy[v]) {
      int tm = (tl + tr) / 2;
      apply(lp, lazy[v]), apply(rp, lazy[v]);
      lazy[v] = 0;
    }
  }

  void upd(int v, int tl, int tr, int l, int r, ll val) {
    if (tr <= l || r <= tl) return;
    if (l <= tl && tr <= r) { apply(v, tl, tr, val); return; }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    upd(lp, l, r, val), upd(rp, l, r, val),
    st[v] = st[ls] + st[rs];
  }
  void upd(int l, int r, ll val) { upd(0, 0, n, l, r, val); }

  ll sum(int v, int tl, int tr, int l, int r) {
    if (tr <= l || r <= tl) return 0;
    if (l <= tl && tr <= r) return st[v].s;
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return sum(lp, l, r) + sum(rp, l, r);
  }
  ll sum(int l, int r) { return sum(0, 0, n, l, r); }

  int find(int v, int tl, int tr, int l, int r, ll x) {
    // cout << "  " << tl << ' ' << tr << ' ' << st[v].mn << '\n';
    if (tr <= l || r <= tl || st[v].mn >= x) return QUERY_NEUT;
    if (tl + 1 == tr) return tl;
    push(v, tl, tr);
    int tm = (tl + tr) / 2, left = find(lp, l, r, x);
    if (left != QUERY_NEUT) return left;
    return find(rp, l, r, x);
  }
  int find(int l, int r, ll x) {
    // cout << ' ' << l << ' ' << r << ' ' << x << '\n';
    return find(0, 0, n, l, r, x);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  vector<int> b(n), c(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  STree st(2 * n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
    st.upd(i, 2 * n, b[i] - c[i]);
    st.upd(n + i, 2 * n, b[i] - c[i]);
  }

  while (q--) {
    int t;
    cin >> t;

    if (t == 1) {
      int i;
      cin >> i;
      --i;
      ll s = !i ? 0 : st.sum(i - 1, i);
      st.upd(i, 2 * n, -s);
      int ans = st.find(i, i + n, 0);
      if (ans == QUERY_NEUT) {
        cout << "-1\n";
      } else {
        cout << ans % n + 1 << '\n';
      }
      st.upd(i, 2 * n, s);
    } else if (t == 2) {
      int i, x;
      cin >> i >> x;
      --i;
      st.upd(i, 2 * n, -b[i]);
      st.upd(n + i, 2 * n, -b[i]);
      b[i] = x;
      st.upd(i, 2 * n, b[i]);
      st.upd(n + i, 2 * n, b[i]);
    } else {
      int i, x;
      cin >> i >> x;
      --i;
      st.upd(i, 2 * n, c[i]);
      st.upd(n + i, 2 * n, c[i]);
      c[i] = x;
      st.upd(i, 2 * n, -c[i]);
      st.upd(n + i, 2 * n, -c[i]);
    }
  }

  return 0;
}