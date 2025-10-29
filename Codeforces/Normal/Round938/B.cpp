#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define ROF(i, a, b) for (ll i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
  ll n, c, d;
  cin >> n >> c >> d;
  vector<vi> mat(n, vi(n, -1));
  map<ll, ll> umap;
  ll mn = 1e15 + 5;
  FOR (i, 0, n) {
    FOR (j, 0, n) {
      ll x;
      cin >> x;
      umap[x]++;
      mn = min(mn, x);
    }
  }
  mat[0][0] = mn;
  umap[mn]--;
  FOR (i, 0, n) {
    if (i == n - 1)
      break;
    FOR (j, 0, n) {
      if (umap[mat[i][j] + c]) {
        mat[i + 1][j] = mat[i][j] + c;
        umap[mat[i][j] + c]--;
      }
      else {
        cout << "NO" << ENDL;
        return;
      }
      if (j == n - 1 || mat[i][j + 1] != -1)
        continue;
      if (umap[mat[i][j] + d]) {
        mat[i][j + 1] = mat[i][j] + d;
        umap[mat[i][j] + d]--;
      }
      else {
        cout << "NO" << ENDL;
        return;
      }
    }
  }

  // FOR (i, 0, n) {
  //   FOR (j, 0, n) {
  //     cout << mat[i][j] << ' ';
  //   }
  //   cout << ENDL;
  // }

  cout << "YES" << ENDL;
}

signed main() { __
  ll tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}