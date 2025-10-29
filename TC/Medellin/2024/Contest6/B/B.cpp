#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define ROF(i, a, b) for(ll i = (ll)a - 1; i >= (ll)b; i--)
#define ENDL '\n'

template<typename T>
struct PushRelabel {
  struct Edge {
    ll dest, back;
    T f, c;
  };
  vector<vector<Edge>> g;
  vector<T> ec;
  vector<Edge*> cur;
  vector<vi> hs;
  vi H;
  PushRelabel(ll n) : g(n), ec(n), cur(n), hs(2 * n), H(n) {}
  void addEdge(ll s, ll t, T cap, T rcap = 0) {
    if (s == t) return;
    g[s].push_back({t, SZ(g[t]), 0, cap});
    g[t].push_back({s, SZ(g[s]) - 1, 0, rcap});
  }
  void addFlow(Edge& e, T f) {
    Edge& back = g[e.dest][e.back];
    if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
    e.f += f;
    e.c -= f;
    ec[e.dest] += f;
    back.f -= f;
    back.c += f;
    ec[back.dest] -= f;
  }
  T calc(ll s, ll t) {
    ll v = SZ(g);
    H[s] = v;
    ec[t] = 1;
    vi co(2 * v);
    co[0] = v - 1;
    FOR (i, 0, v) cur[i] = g[i].data();
    for (Edge& e : g[s]) addFlow(e, e.c);
    for (ll hi = 0;;) {
      while (hs[hi].empty()) if (!hi--) return -ec[s];
      ll u = hs[hi].back();
      hs[hi].pop_back();
      while (ec[u] > 0) if (cur[u] == g[u].data() + SZ(g[u])) { // discharge u
        H[u] = 1e9;
        for (Edge& e : g[u]) if (e.c && H[u] > H[e.dest] + 1) H[u] = H[e.dest] + 1, cur[u] = &e;
        if (++co[H[u]], !--co[hi] && hi < v) FOR (i, 0, v) if (hi < H[i] && H[i] < v)-- co[H[i]], H[i] = v + 1;
        hi = H[u];
      } 
      else if (cur[u]->c && H[u] == H[cur[u]->dest] + 1) addFlow(*cur[u], min(ec[u], cur[u]->c));
      else ++cur[u];
    }
  }
  bool leftOfMinCut(ll a) { return H[a] >= SZ(g); }
};
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  ll n, m;
  cin >> n >> m;
  vi a(n);
  for (auto &ai : a) {
    cin >> ai;
  }

  vector<vector<pi>> pf(n);
  FOR (i, 0, n) {
    ll x = a[i];
    for (ll j = 2; j * j <= x; j++) if (x % j == 0) {
      ll cnt = 0;
      while (x % j == 0) {
        cnt++;
        x /= j;
      }
      pf[i].pb({j, cnt});
    }
    if (x != 1) pf[i].pb({x, 1});
    sort(ALL(pf[i]));
    // for (auto &[p, e] : pf[i]) {
    //   cout << p << ' ' << e << ", ";
    // }
    // cout << ENDL;
  }

  vi tam(2, 0);
  for (ll i = 0; i < n; i++) {
    tam[i & 1] += SZ(pf[i]);
  }

  // cout << "-" << tam[0] << ' ' << tam[1] << ENDL;
  PushRelabel<ll> mf(tam[0] + tam[1] + 2);

  vector<vi> id(n);
  {
    ll j = 0;
    for (ll i = 0; i < n; i += 2) {
      id[i].resize(SZ(pf[i]));
      FOR (k, 0, SZ(pf[i])) {
        mf.addEdge(tam[0] + tam[1], j, pf[i][k].second);
        id[i][k] = j++;
      }
    }

    for (ll i = 1; i < n; i += 2) {
      id[i].resize(SZ(pf[i]));
      FOR (k, 0, SZ(pf[i])) {
        // cout << j << ' ' << tam[0] + tam[1] + 1 << ' ' << pf[i][k].second << ENDL;
        mf.addEdge(j, tam[0] + tam[1] + 1, pf[i][k].second);
        id[i][k] = j++;
      }
    }
  }

  while (m--) {
    ll i, j;
    cin >> i >> j;
    i--, j--;
    if (i & 1) swap(i, j);
    ll ptr1 = 0, ptr2 = 0;
    while (ptr1 < SZ(pf[i]) && ptr2 < SZ(pf[j])) {
      auto [p1, e1] = pf[i][ptr1];
      auto [p2, e2] = pf[j][ptr2];
      if (p1 != p2) {
        if (p1 < p2) ptr1++;
        else ptr2++;
        continue;
      }
      // cout << i << ' ' << j << ' ' << p1 << ' ' << min(e1, e2) << ' ' << id[i][ptr1] << ' ' << id[j][ptr2] << ENDL;
      mf.addEdge(id[i][ptr1], id[j][ptr2], min(e1, e2));
      ptr1++;
      ptr2++;
    }
  }
  cout << mf.calc(tam[0] + tam[1], tam[0] + tam[1] + 1) << ENDL;

  return 0;
}