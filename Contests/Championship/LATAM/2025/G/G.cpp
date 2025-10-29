#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((ll)x.size())
#define FOR(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)


constexpr ll INF = 1e18;
struct Data {
  ll mn, mx;

  Data(ll mn, ll mx) : mn(mn), mx(mx) {}

  bool operator==(Data o) const{
    return tie(mn,mx) ==tie(o.mn,o.mx);
  }

  void apply(ll x) {
    mn += x;
    mx += x;
  }
};
const Data NEUT = Data(INF, -INF);

struct STree {
  #define ls st[k].l
  #define rs st[k].r
  #define lp ls, s, m
  #define rp rs, m, e

  struct Node {
    int l, r;
    ll lazy;
    Data data;

    Node() : l(-1), r(-1), lazy(0), data(Data(0, 0)) {}
  };

  ll n;
  vector<Node> st;

  STree(ll n) : n(n), st(1) {}

  Data merge(Data a, Data b) {
    return Data(min(a.mn, b.mn), max(a.mx, b.mx));
  }

  Data getData(int k) {
    return k == -1 ? Data(0, 0) : st[k].data;
  }

  void pull(int k) {
    st[k].data = merge(getData(ls), getData(rs));
  }

  void apply(int k, ll x) {
    st[k].data.apply(x);
    st[k].lazy += x;
  }

  void push(int k) {
    if (st[k].lazy) {
      if (ls == -1) {
        ls = addNode();
      }
      if (rs == -1) {
        rs = addNode();
      }
      apply(ls, st[k].lazy);
      apply(rs, st[k].lazy);
      st[k].lazy = 0;
    }
  }

  int addNode() {
    st.emplace_back();
    return (int)st.size() - 1;
  }

  Data query(int k, ll s, ll e, ll a, ll b) {
    if (e <= a || s >= b) {
      return NEUT;
    }
    if (k == -1) {
      return Data(0, 0);
    }
    if (a <= s && e <= b) {
      return st[k].data;
    }
    push(k);
    ll m = (s + e) >> 1;
    return merge(query(lp, a, b), query(rp, a, b));
  }

  int upd(int k, ll s, ll e, ll a, ll b, int x) {
    if (e <= a || s >= b) {
      return k;
    }
    if (k == -1) {
      k = addNode();
    }
    if (a <= s && e <= b) {
      apply(k, x);
      return k;
    }
    push(k);
    ll m = (s + e) >> 1;
    ls = upd(lp, a, b, x);
    rs = upd(rp, a, b, x);
    pull(k);
    return k;
  }

  Data query(ll a, ll b) {
    return query(0, 0, n, a, b);
  }
  
  void upd(ll a, ll b, int x) {
    upd(0, 0, n, a, b, x);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;
  STree st(INF*2);
  FOR(i,0,n){
    char c;
    int len;
    ll col;
    cin >> c >> len >> col;
    if(c == '-'){
      ll l = col,r = col+len;
      Data dato = st.query(l,r);
      if(dato.mn == dato.mx){
        cout << 'S';
        st.upd(l,r,1);
      }else{
        cout << 'U';
      }
    }else{
      cout << 'S';
      st.upd(col,col+1,len);
    }
  }
  cout << '\n';

  return 0;
}