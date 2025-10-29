#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
// using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/**
 * Descripcion: maximo flujo de coste minimo. Se permite que cap[i][j] != cap[j][i], pero
 * las aristas dobles no lo estan, si los costos pueden ser negativos, llamar a setpi antes
 * que calc, los ciclos con costos negativos no son soportados.
 * Tiempo: aproximadamente O(E^2)
 */

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

signed main() { __
  int n;
  cin >> n;

  vector<vi> a(n + 1, vi(2 * n)), s(n, vi(2 * n));
  FOR (i, 0, n) {
    FOR (j, 0, n) {
      cin >> a[i][j * 2] >> a[i][j * 2 + 1];
    }
  }
  FOR (i, 0, n) {
    FOR (j, 0, n) {
      cin >> s[i][j * 2] >> s[i][j * 2 + 1];
    }
  }

  const int cntA = n, cntG = n * 2, cntI = n * 2, cntS = n;
  const int offG = cntA, offI = offG + cntG, offS = offI + cntI;
  const int S = cntA + cntG + cntI + cntS, T = S + 1;
  ll mn = 1e18;
  int mnIdx = 0;

  auto getMF = [&](int i) -> MCMF {
    MCMF mf(T + 1);
    FOR (k, 0, n) {
      mf.addEdge(S, k, 1, 0);
      mf.addEdge(offS + k, T, 1, 0);
      mf.addEdge(offG + k * 2, offI + k * 2, 1, 0);
      mf.addEdge(offG + k * 2 + 1, offI + k * 2 + 1, 1, 0);
    }
    FOR (j, 0, i + 1) {
      FOR (k, 0, n) {
        mf.addEdge(k, offG + j * 2, 1, a[k][j * 2]);
        mf.addEdge(offI + j * 2, offS + k, 1, s[k][j * 2]);
      }
    }
    FOR (j, i + 1, n) {
      FOR (k, 0, n) {
        mf.addEdge(k, offG + j * 2 + 1, 1, a[k][j * 2 + 1]);
        mf.addEdge(offI + j * 2 + 1, offS + k, 1, s[k][j * 2 + 1]);
      }
    }
    return mf;
  };

  FOR(i, -1, n) {
    ll flow = getMF(i).calc(S, T).second;
    if (flow < mn) {
      mn = flow;
      mnIdx = i;
    }
  }

  cout << mn << ENDL;

  MCMF mf = getMF(mnIdx);
  mf.calc(S, T);

  FOR (i, 0, n) {
    int g = 0;
    char c = 'A';
    FOR (j, offG, offG + cntG) {
      if (mf.flow[i][j] > 0) {
        g = j;
        c = (g - offG) & 1 ? 'B' : 'A';
        break;
      }
    }
    g += cntI;
    FOR (j, offS, offS + cntS) {
      if (mf.flow[g][j] > 0) {
        cout << i + 1 << ' ' << (g - offI) / 2 + 1 << c << ' ' << j - offS + 1 << ENDL;
        break;
      }
    }
  }

  return 0;
}