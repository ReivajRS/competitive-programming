#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((ll)x.size())
#define FOR(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define ENDL '\n'

vector<ll> scc(vector<vector<ll>>& g) {
  ll n = SZ(g), t = 0, ncomps = 0;
  vector<ll> tin(n), scc(n, -1), z;
  auto dfs = [&](auto&& self, ll u) -> ll {
    ll low = tin[u] = ++t, x; z.push_back(u);
    for (auto v : g[u]) if (scc[v] < 0)
      low = min(low, tin[v] ?: self(self, v));
    if (low == tin[u]) {
      do {
        x = z.back(); z.pop_back();
        scc[x] = ncomps;
      } while (x != u);
      ncomps++;
    }
    return tin[u] = low;
  };
  FOR (i, 0, n) if (scc[i] == -1) dfs(dfs, i);
  return scc;
}

void solve() {
  ll n, k, q;
  cin >> n >> k >> q;

  vector<vector<ll>> g(n);
  vector<vector<ll>> a(k, vector<ll>(n));
  set<pair<ll, ll>> edges;
  for (ll i = 0; i < k; i++) {
    for (ll j = 0; j < n; j++) {
      cin >> a[i][j];
      a[i][j]--;
      if (j > 0) {
        ll u = a[i][j - 1], v = a[i][j];
        if (edges.count({u, v})) continue;
        g[u].push_back(v);
        edges.insert({u, v});
      }
    }
  }

  auto nc2 = [&](ll x) -> ll {
    return x*(x-1)/2;
  };

  vector<ll> comp = scc(g);

  vector<vector<pair<ll,ll>>> posB(k);
  vector<vector<ll>> b(k);
  FOR(i,0,k){
    b[i].push_back(0);
    FOR(l,0,n){
      ll r = l;
      while(r<n && comp[a[i][l]] == comp[a[i][r]]) r++;
      r--;
      posB[i].push_back({r,l});
      //cout << i << ENDL;
      //cout << l << " " << r << ENDL;
      b[i].push_back(b[i].back()+nc2(r-l+1));
      l = r;
    }
  }
  ll ant = 0;
  const ll INF = 1e15;
  while (q--) {
    ll id, l, r;
    cin >> id >> l >> r;
    id = (id+ant)%k + 1;
    l = (l+ant)%n + 1;
    r = (r+ant)%n + 1;
    l--,r--,id--;
    ll L = lower_bound(posB[id].begin(),posB[id].end(),make_pair(l,-INF)) - posB[id].begin();
    ll R = lower_bound(posB[id].begin(),posB[id].end(),make_pair(r,-INF)) - posB[id].begin();

    ll currAns = 0;
    if(L==R){
      currAns = nc2(r-l+1);
    }else{
      currAns = b[id][R]-b[id][L+1];
      currAns += nc2(posB[id][L+1].second-l);
      currAns += nc2(r-posB[id][R-1].first);
    }

    cout << currAns << ENDL;
    ant = currAns;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}