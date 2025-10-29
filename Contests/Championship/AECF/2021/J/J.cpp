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

constexpr int INF = 1e9;
int n, A, B;
vector<vi> g;
vi l;

void case1(){
  queue<int> q;
  vi dist(n, INF);
  dist[0] = 0;
  q.push(0);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(auto v : g[u]) {
      if(l[v] + B * dist[u] < l[0] + A * dist[u] && dist[v] > dist[u] + 1){
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  if (dist.back() == INF) {
    dist.back() = -1;
  }
  cout << dist.back() << ENDL;
}

void case2(){
  int D = A - B;
  vector<bool> vis(n, 0);
  priority_queue<pi> pq;
  pq.push({0, 0});
  int d = -1;
  while (!pq.empty()) {
    auto [x, u] = pq.top();
    pq.pop();
    x *= -1;
    if (vis[u]) {
      continue;
    }
    if (d >= 0 && x >= l[0] + 1ll * d * D) {
      break;
    }
    for (auto &v : g[u]) if (!vis[v]) {
      pq.push({-l[v], v});
    }
    vis[u] = 1;
    d++;
  }

  while (!pq.empty()) pq.pop();

  vi dist(n, INF);
  dist[0] = 0;
  pq.push({0, 0});
  while (!pq.empty()) {
    auto [x, u] = pq.top();
    pq.pop();
    x *= -1;
    if (x > dist[u]) {
      continue;
    }
    for (auto &v : g[u]) if (vis[v]) {
      if (l[v] < l[0] && dist[u] + 1 < dist[v]) {
        dist[v] = dist[u] + 1;
        pq.push({-dist[v], v});
      }
      int xx = max(x + 1, (l[v] - l[0]) / D + 2);
      if (xx < dist[v]) {
        dist[v] = xx;
        pq.push({-dist[v], v});
      }
    }
  }
  if (dist.back() == INF) {
    dist.back() = -1;
  }
  cout << dist.back() << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  
  while(tc--) {
    int m;
    cin >> n >> m >> A >> B;
    g.assign(n, vi());
    FOR(i, 0, m){
      int u, v;
      cin >> u >>v;
      u--, v--;
      g[u].pb(v);
      g[v].pb(u);
    }
    l.assign(n, 0);
    FOR(i, 0, n) {
      cin >> l[i];
    }
    FOR(i, 1, n) {
      l[i] += B;
    }
    if(A <= B) {
      case1();
    }
    else {
      case2();
    }
  }

  return 0;
}