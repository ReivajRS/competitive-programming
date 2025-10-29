#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define pb push_back
// using pi = pair<int, int>;
using vi = vector<int>;

#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

#include <bits/extc++.h> // importante de incluir

const ll INF = numeric_limits<ll>::max() / 4;
typedef vector<ll> VL;

struct MCMF {
  int N;
  vector<vi> ed, red;
  vector<VL> cap, flow, cost;
  vi seen;
  VL dist, pi;
  vector<pair<ll, ll>> par;

  MCMF(int N) : N(N), ed(N), red(N), cap(N, VL(N)), flow(cap), cost(cap), seen(N), dist(N), pi(N), par(N) {}

  void addEdge(int from, int to, ll cap, ll cost) {
    this->cap[from][to] = cap;
    this->cost[from][to] = cost;
    ed[from].push_back(to);
    red[to].push_back(from);
  }

  void path(int s) {
    fill(ALL(seen), 0);
    fill(ALL(dist), INF);
    dist[s] = 0;
    ll di;

    __gnu_pbds::priority_queue<pair<ll, int>> q;
    vector<decltype(q)::point_iterator> its(N);
    q.push({0, s});

    auto relax = [&](int i, ll cap, ll cost, int dir) {
      ll val = di - pi[i] + cost;
      if (cap && val < dist[i]) {
        dist[i] = val;
        par[i] = {s, dir};
        if (its[i] == q.end())
          its[i] = q.push({-dist[i], i});
        else
          q.modify(its[i], {-dist[i], i});
      }
    };

    while (!q.empty()) {
      s = q.top().second;
      q.pop();
      seen[s] = 1;
      di = dist[s] + pi[s];
      for (int i : ed[s])
        if (!seen[i])
          relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
      for (int i : red[s])
        if (!seen[i])
          relax(i, flow[i][s], -cost[i][s], 0);
    }
    FOR(i, 0, N)
    pi[i] = min(pi[i] + dist[i], INF);
  }

  pair<ll, ll> calc(int s, int t) {
    ll totflow = 0, totcost = 0;
    while (path(s), seen[t]) {
      ll fl = INF;
      for (int p, r, x = t; tie(p, r) = par[x], x != s; x = p)
        fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
      totflow += fl;
      for (int p, r, x = t; tie(p, r) = par[x], x != s; x = p)
        if (r)
          flow[p][x] += fl;
        else
          flow[x][p] -= fl;
    }
    FOR(i, 0, N)
    FOR(j, 0, N) totcost += cost[i][j] * flow[i][j];
    return {totflow, totcost};
  }

  void setpi(int s) {
    fill(ALL(pi), INF);
    pi[s] = 0;
    int it = N, ch = 1;
    ll v;
    while (ch-- && it--)
      FOR(i, 0, N)
      if (pi[i] != INF) for (int to : ed[i]) if (cap[i][to]) if ((v = pi[i] + cost[i][to]) < pi[to])
          pi[to] = v,
          ch = 1;
    assert(it >= 0);
  }
};


signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;
  int n;
  cin >> n;
  MCMF flujo(30+n);
  FOR(i,0,n){
    string t;
    int x;
    cin >> t >> x;
    vi cnt(27,0);
    for(char c:t) cnt[c-'a']++;
    flujo.addEdge(0,i+1,x,0);
    FOR(j,0,26){
      flujo.addEdge(i+1,n+2+j,cnt[j],i+1);
    }
  }
  vi cnt(26,0);
  for(auto c:s) cnt[c-'a']++;
  FOR(i,0,26){
    flujo.addEdge(n+2+i,n+28,cnt[i],0);
  }

  pair<ll, ll> ans = flujo.calc(0,n+28);
  //cout << ans.first << ENDL;
  if(ans.first == SZ(s)){
    cout << ans.second << ENDL;
  }else{
    cout << -1 << ENDL;
  }

  return 0;
}