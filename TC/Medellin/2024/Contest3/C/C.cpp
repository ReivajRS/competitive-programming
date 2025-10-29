#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= b; i--)
#define ENDL '\n'

constexpr int maxn = 1e5 + 5;

int timer = 0;
int alive[maxn];
vi g[maxn];

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  stack<pi> st;
  st.push({0, 0});

  alive[0] = 1;

  int q;
  cin >> q;
  while (q--) {
    int t, x;
    cin >> t >> x;
    --x;
    if (t == 1) {
      g[x].pb(++timer);
      alive[timer] = 1;
      continue;
    }
    alive[x] = 0;
    // muere
    //cout << "hola" << ENDL;
    while (!st.empty()) {
      auto [u, i] = st.top();
      //cout << u << ' ' << i << ENDL;
      if (alive[u]) {
        break;
      }
      st.pop();
      if (i == SZ(g[u])) {
        continue;
      }
      st.push({u, i + 1});
      st.push({g[u][i], 0});
    }
    if (st.empty()) {
      continue;
    }
    cout << st.top().first + 1 << ENDL;
  }

  return 0;
}