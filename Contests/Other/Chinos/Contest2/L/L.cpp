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

template <class T>
struct SegTree {
  #define NEUT 0

  inline int oper(int a, int b) { return max(a, b); }

  int n;
  vector<T> A, st;

  inline int lc(int p) { return (p << 1) + 1; }
  inline int rc(int p) { return (p << 1) + 2; }

  void init(vector<T> v) {
    A = v;
    n = SZ(A);
    st.resize(n * 4);
    build(0, 0, n - 1);
  }

  void build(int p, int L, int R) {
    if (L == R) {
      st[p] = A[L];
      return;
    }
    int m = (L + R) >> 1;
    build(lc(p), L, m);
    build(rc(p), m + 1, R);
    st[p] = oper(st[lc(p)], st[rc(p)]);
  }

  T query(int l, int r, int p, int L, int R) {
    if (l <= L && r >= R) return st[p];
    if (l > R || r < L) return NEUT;
    int m = (L + R) >> 1;
    return oper(query(l, r, lc(p), L, m), query(l, r, rc(p), m + 1, R));
  }
  T query(int l, int r) { return query(l, r, 0, 0, n - 1); }

  void update(int i, T val, int p, int L, int R) {
    if (L > i || R < i) return;
    if (L == R) {
      st[p] = val;
      return;
    }
    int m = (L + R) >> 1;
    update(i, val, lc(p), L, m);
    update(i, val, rc(p), m + 1, R);
    st[p] = oper(st[lc(p)], st[rc(p)]);
  }
  void update(int i, T val) { update(i, val, 0, 0, n - 1); }
};

template <class T>
struct SegTree2 {
  inline int oper(int a, int b) { return a + b; }
  
  int n;
  vector<T> A, st;

  inline int lc(int p) { return (p << 1) + 1; }
  inline int rc(int p) { return (p << 1) + 2; }

  void init(vector<T> v) {
    A = v;
    n = SZ(A);
    st.resize(n * 4);
    build(0, 0, n - 1);
  }

  void build(int p, int L, int R) {
    if (L == R) {
      st[p] = A[L];
      return;
    }
    int m = (L + R) >> 1;
    build(lc(p), L, m);
    build(rc(p), m + 1, R);
    st[p] = oper(st[lc(p)], st[rc(p)]);
  }

  T query(int l, int r, int p, int L, int R) {
    if (l <= L && r >= R) return st[p];
    if (l > R || r < L) return NEUT;
    int m = (L + R) >> 1;
    return oper(query(l, r, lc(p), L, m), query(l, r, rc(p), m + 1, R));
  }
  T query(int l, int r) { return query(l, r, 0, 0, n - 1); }

  void update(int i, T val, int p, int L, int R) {
    if (L > i || R < i) return;
    if (L == R) {
      st[p] = val;
      return;
    }
    int m = (L + R) >> 1;
    update(i, val, lc(p), L, m);
    update(i, val, rc(p), m + 1, R);
    st[p] = oper(st[lc(p)], st[rc(p)]);
  }
  void update(int i, T val) { update(i, val, 0, 0, n - 1); }
};

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  SegTree<int> st;
  SegTree2<int> st2;
  st.init(vi(n+1,0));
  st2.init(vi(n+1,0));
  vi a(n), b(m);
  vi in(n + 1, 0), pos(n + 1);
  FOR (i, 0, n) {
    cin >> a[i];
    in[a[i]]++;
    pos[a[i]] = i;
    st.update(i, a[i]);
  }
  FOR (i, 0, m) {
    cin >> b[i];
    in[b[i]]++;
  }
  map<int, int> mp;
  FOR (i, 0, k) {
    int x;
    cin >> x;
    mp[x]++;
  }
  vi erased;
  FOR (i, 0, n + 1) {
    if (in[i] == 1) {
      erased.pb(i);
    }
  }

  auto get_l = [&](int p) -> int {
    int l = 0, r = p;
    while (l < r) {
      int m = (l + r + 1) / 2;
      if (st.query(p - m, p) > a[p]) {
        r = m - 1;
      } else {
        l = m;
      }
    }
    return l;
  };

  auto get_r = [&](int p) -> int {
    int l = 0, r = n - p - 1;
    while (l < r) {
      int m = (l + r + 1) / 2;
      if (st.query(p, p + m) > a[p]) {
        r = m - 1;
      } else {
        l = m;
      }
    }
    return l;
  };

  sort(erased.rbegin(), erased.rend());
  for (auto &x : erased) {
    int le = get_l(pos[x]), ri = get_r(pos[x]);
    le -= st2.query(pos[x] - le, pos[x]);
    ri -= st2.query(pos[x], pos[x] + ri);
    int len = le + ri + 1;
    // cout << x << ' ' << le << ' ' << ri <<  " len " << len << ENDL;
    auto it = mp.upper_bound(len);
    if (it == mp.begin()) {
      cout << "NO" << ENDL;
      return;
    it--;
    st.update(pos[x], 0);
    st2.update(pos[x], 1);
    }
    // cout << "uso " << it->first << ENDL;
    it->second--;
    if (it->second == 0) {
      mp.erase(it);
    }
  }

  cout << "YES" << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}