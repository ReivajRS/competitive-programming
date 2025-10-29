#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  int n, t;
  cin >> n >> t;
  vi degree(n, 0);
  FOR (i, 1, n) {
    int u,v;
    cin >> u >> v;
    degree[u]++;
    degree[v]++;
  }

  int hojas = 0;
  FOR (i, 0, n) hojas += degree[i] == 1;

  cout << t / hojas * 2 + min(2, t % hojas) << ENDL;

  return 0;
}