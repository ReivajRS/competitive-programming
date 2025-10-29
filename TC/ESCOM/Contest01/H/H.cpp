#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

bool alive[4001];
int sz[4001];
ll dist[4001][4001];

struct Frac {
  ll num, den;
  Frac(ll num, ll den) {
    ll g = gcd(num, den);
    this->num = num / g;
    this->den = den / g;
  }
  bool operator<(Frac other) const {
    return (ll)num * other.den < (ll)other.num * den;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n;
  cin >> n;
  
  set<tuple<Frac, int, int>> st;
  
  vector<pair<int, int>> pts(n);
  for (auto &[x, y] : pts) {
    cin >> x >> y;
  }

  for (int i = 0; i < n; i++) {
    sz[i] = 1;
    alive[i] = 1;
    for (int j = i + 1; j < n; j++) {
      ll distIJ = (ll)(pts[i].first - pts[j].first) * (pts[i].first - pts[j].first);
      distIJ += (ll)(pts[i].second - pts[j].second) * (pts[i].second - pts[j].second);
      dist[i][j] = dist[j][i] = distIJ;
      st.insert({Frac(dist[i][j], 1), min(i, j), max(i, j)});
    }
  }
  
  int cntAlive = n;
  int id = n - 1;

  while (cntAlive > 1) {
    int idA = get<1>(*st.begin());
    int idB = get<2>(*st.begin());
    st.erase(st.begin());
    if (!alive[idA] || !alive[idB]) {
      continue;
    }
    int idC = ++id;
    sz[idC] = sz[idA] + sz[idB];
    cout << sz[idC] << '\n';
    for (int idX = 0; idX < id; idX++) {
      if (!alive[idX] || idX == idA || idX == idB) {
        continue;
      }
      dist[idC][idX] = dist[idX][idC] = dist[idA][idX] + dist[idB][idX];
      st.insert({Frac(dist[idC][idX], (ll)sz[idC] * sz[idX]), min(idC, idX), max(idC, idX)});
    }
    alive[idA] = alive[idB] = 0;
    alive[idC] = 1;
    cntAlive--;
  }
  
  return 0;
}