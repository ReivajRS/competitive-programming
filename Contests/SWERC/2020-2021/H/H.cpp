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

#define oper(a,b) (a + b)
#define NEUT 0
struct STree {
  vector<int> st, L, R; int n, rt, sz;
  STree(int n) : st(1, NEUT), L(1, 0), R(1, 0), n(n), rt(0), sz(1) {}
  int new_node(int v, int l = 0, int r = 0) {
    int ks = SZ(st);
    st.pb(v);L.pb(l);R.pb(r);
    return ks;
  }
  int init(int s, int e, vi a) {
    if (s + 1 == e)return new_node(a[s]);
    int m = (s + e) / 2, l = init(s, m, a), r = init(m, e, a);
    return new_node(oper(st[l], st[r]), l, r);
  }
  int upd(int k, int s, int e, int p, int v) {
    int ks = new_node(st[k], L[k], R[k]);
    if (s + 1 == e) { st[ks] = v; return ks; }
    int m = (s + e) / 2, ps;
    if (p < m) ps = upd(L[ks], s, m, p, v), L[ks] = ps;
    else ps = upd(R[ks], m, e, p, v), R[ks] = ps;
    st[ks] = oper(st[L[ks]], st[R[ks]]);
    return ks;
  }
  int query(int k, int s, int e, int a, int b) {
    if (e <= a || b <= s)return NEUT;
    if (a <= s && e <= b)return st[k];
    int m = (s + e) / 2;
    return oper(query(L[k], s, m, a, b), query(R[k], m, e, a, b));
  }
  int init(vi a) { return init(0, n, a); }
  int upd(int k, int p, int v) { return rt = upd(k, 0, n, p, v); }
  int upd(int p, int v) { return upd(rt, p, v); }
  int query(int k, int a, int b) { return query(k, 0, n, a, b); }; // [a, b)
};

signed main() { __
  int n, cnt = 0;

  cin >> n;
  cin.ignore();
  
  STree st(n + 1);
  vi version(n + 1, 0);
  
  FOR (i, 1, n + 1) {
    string s, w;
    getline(cin, s);
    stringstream ss(s);
    while (ss >> w)
      cnt = st.upd(stoi(w.substr(1)), w[0] == '+' ? 1 : 0);
    version[i] = cnt;
  }
  
  int x = 0;
  
  FOR (i, 0, n) {
    int d;
    cin >> d;
    if (d == 0 || d == n)
      continue;
    x = (x + st.query(version[d], x, n + 1)) % n;
  }

  cout << x << ENDL;
  
  return 0;
}