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

struct STree {
  #define ls 2 * v + 1
  #define rs 2 * v + 2
  #define lp ls, tl, tm
  #define rp rs, tm, tr
  #define NEUT 0

  int n;
  vector<int> st;

  STree(int n) : n(n), st(4 * n) {}

  int query(int v, int tl, int tr, int l, int r) {
    if (tr <= l || r <= tl) return NEUT;
    if (l <= tl && tr <= r) return st[v];
    int tm = (tl + tr) / 2;
    return query(lp, l, r) + query(rp, l, r);
  }
  
  void upd(int v, int tl, int tr, int i, int val) {
    if (tl + 1 == tr) { st[v] = val; return; }
    int tm = (tl + tr) / 2;
    if (i < tm) upd(lp, i, val);
    else upd(rp, i, val);
    st[v] = st[ls] + st[rs];
  }
 
  int query(int l, int r) {
    return query(0, 0, n, l, r);
  }
  void upd(int i, int val) {
    upd(0, 0, n, i, val);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, q;
  cin >> n >> q;

  string s;
  cin >> s;

  STree st(n + 1);

  for (int i = 1; i < n; i++) {
    if (s[i - 1] != s[i]) {
      st.upd(i, 1);
    }
  }

  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r;
      cin >> l >> r;
      int ans = st.query(l, r);
      cout << ans + 1 << '\n';
    }
    else {
      int i;
      cin >> i;
      i--;
      char c;
      cin >> c;
      s[i] = c;
      if (i > 0) {
        st.upd(i, s[i - 1] != s[i]);
      }
      if (i + 1 < n) {
        st.upd(i + 1, s[i] != s[i + 1]);
      }
    }
  }
  
  return 0;
}