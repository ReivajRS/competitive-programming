#include <bits/stdc++.h>
using namespace std;
// ? BRO... CSM AC2# AC2++ Hijos de Honor Hackers United
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

constexpr ll di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};

constexpr ll INF = 1e18;

ll N, M, D, GR, GC;

vector<vi> dijkstra_dist(vector<vi> a, ll k) {
  vector<vi> d(N, vi(M, INF));
  priority_queue<array<ll, 3>> pq;
  pq.push({0, GR, GC});
  d[GR][GC] = 0;
  while (!pq.empty()) {
    auto [dst, i, j] = pq.top();
    pq.pop();
    dst = -dst;
    if (dst > d[i][j]) continue;
    FOR (dir, 0, 4) {
      ll ii = i + di[dir], jj = j + dj[dir];
      if (ii == -1 || ii == N || jj == -1 || jj == M) continue;
      ll diff = abs(a[i][j] - a[ii][jj]);
      if (diff > k || dst + diff >= d[ii][jj]) continue;
      d[ii][jj] = dst + diff;
      pq.push({-d[ii][jj], ii, jj});
    }
  }
  return d;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  cin >> N  >> M >> D >> GR >> GC;

  --GR, --GC;

  vector<vi> a(N, vi(M));
  FOR (i, 0, N) FOR (j, 0, M) cin >> a[i][j];

  ll l = 0, r = 1e9+5;
  while (l < r) {
    ll m = (l + r) >> 1;
    vector<vi> d = dijkstra_dist(a, m);
    bool todo_bien = 1;
    FOR (i, 0, N) FOR (j, 0, M) todo_bien &= d[i][j] <= D;
    if (todo_bien) r = m;
    else l = m + 1;
  }
  vector<vi> d = dijkstra_dist(a, l);
  bool todo_bien = 1;
  FOR (i, 0, N) FOR (j, 0, M) todo_bien &= d[i][j] <= D;
  if (todo_bien) {
    cout << l << ENDL;
    return 0;
  }
  d = dijkstra_dist(a, INF);
  ll mx_dist = 0;
  FOR (i, 0, N) FOR (j, 0, M) mx_dist = max(mx_dist, d[i][j]);
  l = 0, r = 1e9+5;
  while (l < r) {
    ll m = (l + r) >> 1;
    d = dijkstra_dist(a, m);
    bool todo_bien = 1;
    FOR (i, 0, N) FOR (j, 0, M) todo_bien &= d[i][j] <= mx_dist;
    if (todo_bien) r = m;
    else l = m + 1;
  }
  cout << "No puedo, jefe: " << mx_dist << ' ' << l << ENDL;
  return 0;
}