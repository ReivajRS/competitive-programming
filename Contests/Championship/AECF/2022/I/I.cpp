#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

constexpr ll INF = 1e18;

vector<ll> bfs(vector<vi>& g, int s) {
  vector<ll> D(SZ(g), INF);
  queue<int> q;
  D[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &v : g[u]) if (D[u] + 1 < D[v]) {
      D[v] = D[u] + 1;
      q.push(v);
    }
  }
  return D;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, m, k, d;
  cin >> n >> m >> k >> d;

  --k;

  vector<vi> g(n);
  FOR (i, 0, m) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].pb(v), g[v].pb(u);
  }

  vector<ll> DK = bfs(g, k);
  vector<ll> DE = bfs(g, n - 1);

  auto sum = [&](ll x) -> ll {
    return x*(x+1)/2;
  };

  auto f = [&](ll x) -> ll {
    ll vc = x / d;
    ll sob = d - x % d;
    ll ans = vc * sum(d);
    ans += sum(d) - sum(sob);
    return ans;
  };


  vector<ll> DD(n, INF);
  {
    DD[0] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({-DD[0], 0});
    while (!pq.empty()) {
      auto [du, u] = pq.top();
      du = -du;
      pq.pop();
      if (du > DD[u]) continue;
      for (auto &v : g[u]) if (DK[v] < d && du + (d - DK[v]) < DD[v]) {
        DD[v] = du + (d - DK[v]);
        pq.push({-DD[v], v});
      }
    }
  }

  ll ans = DD[n - 1];
  for(auto v:g[0]){
    if (DK[v] >= d) {
      ans = min(ans,f(DE[0]));
    }
  }

  FOR (i, 0, n) for (auto &v : g[i]) if (DK[v] == d) {
    ans = min(ans, DD[i] + f(DE[v]+1));
  }
  cout << ans << ENDL;

  return 0;
}