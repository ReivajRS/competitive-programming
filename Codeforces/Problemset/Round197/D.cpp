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

#define NEUT 0
struct STree {
  int n, depth; vi st;
  STree(int n) : st(4 * n, NEUT), n(n), depth(get_depth()) {}
  int comb(int x, int y, int op) { return op ? x ^ y : x | y; }
  int query(int k, int s, int e, int a, int b, int op) {
    if (a <= s && e <= b) return st[k];
    if (e <= a || s >= b) return NEUT;
    int m = (s+e)/2;
    return comb(query(2*k+1,s,m,a,b,op^1),query(2*k+2,m,e,a,b,op^1),op);
  }
  void upd(int k, int s, int e, int i, int v, int op) {
    if (e <= i || s > i) return;
    if (s+1 == e) { st[k] = v; return; }
    int m = (s+e)/2;
    upd(2*k+1,s,m,i,v,op^1); upd(2*k+2,m,e,i,v,op^1);
    st[k] = comb(st[2*k+1], st[2*k+2], op);
  }
  int get_depth(int k, int s, int e, int a, int b, int level) {
    if (a <= s && e <= b) return level;
    if (e <= a || s >= b) return -1;
    int m = (s+e)/2;
    return max(get_depth(2*k+1,s,m,a,b, level + 1), get_depth(2*k+2,m,e,a,b, level + 1));
  }
  int query(int a, int b) { return query(0, 0, n, a, b, depth & 1); }
  void upd(int i, int v) { upd(0, 0, n, i, v, depth & 1); }
  int get_depth() { return get_depth(0, 0, n , 0, 1, 1); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m;
  cin >> n >> m;

  STree st(1 << n);

  FOR (i, 0, 1 << n) {
    int x;
    cin >> x;
    st.upd(i, x);
  }

  while (m--) {
    int x, y;
    cin >> x >> y;
    st.upd(x - 1, y);
    cout << st.query(0, 1 << n) << ENDL;
  }
  
  return 0;
}