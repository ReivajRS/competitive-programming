#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

const ll SZ = 1e10;
template <class T>
struct node {
  T val = 0;
  node<T>* c[2];
  node() { c[0] = c[1] = NULL; }
  void upd(ll ind, T v, ll L = 0, ll R = SZ - 1) {
    if (L == ind && R == ind) {
      val = v;
      return;
    }
    ll M = (L + R) / 2;
    if (ind <= M) {
      if (!c[0])
        c[0] = new node();
      c[0]->upd(ind, v, L, M);
    } else {
      if (!c[1])
        c[1] = new node();
      c[1]->upd(ind, v, M + 1, R);
    }
    val = 0;
    for (ll i = 0; i < 2; i++)
      if (c[i])
        val = max(val, c[i]->val);
  }
  T query(ll lo, ll hi, ll L = 0, ll R = SZ - 1) {  // [l, r]
    if (hi < L || R < lo) return 0;
    if (lo <= L && R <= hi) return val;
    ll M = (L + R) / 2;
    T res = 0;
    if (c[0]) res = c[0]->query(lo, hi, L, M);
    if (c[1]) res = max(res, c[1]->query(lo, hi, M + 1, R));
    return res;
  }
};
signed main() { __
  ll n;
  cin >> n;

  vi x(n), y(n);
  FOR (i, 0, n) {
    cin >> x[i] >> y[i];
    y[i] += x[i];
  }

  vi p(n);
  iota(ALL(p), 0);
  sort(ALL(p), [&](ll i, ll j) {
    return (x[i] < x[j]) || (x[i] == x[j] && y[i] > y[j]);
  });

  node<ll> raiz;
  vi ans(n);
  FOR (i, 0, n) {
    ll yy = y[p[i]];
    ans[p[i]] = raiz.query(yy, SZ) + 1;
    raiz.upd(yy, ans[p[i]]);
  }

  for (auto &x : ans) {
    cout << x - 1 << " ";
  }
  cout << ENDL;

  return 0;
}