#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vi a(n), b(m);
  unordered_map<int, int> umap, umap2, umap3;
  for (auto &x : a)
    cin >> x;
  for (auto &x : b) {
    cin >> x;
    umap[x]++;
  }
  int cnt = 0;
  FOR (i, 0, m) {
    umap2[a[i]]++;
    if (umap[a[i]] > umap3[a[i]])
      cnt++, umap3[a[i]]++;
  }

  int ans = 0;
  if (cnt >= k)
    ans++;
  
  FOR (i, m, n) {
    umap2[a[i]]++;
    umap2[a[i - m]]--;
    if (umap3[a[i - m]]) {
      if (umap2[a[i - m]] < umap[a[i - m]]) {
        umap3[a[i - m]]--;
        cnt--;
      }
    }
    if (umap[a[i]] > umap3[a[i]])
      cnt++, umap3[a[i]]++;
    if (cnt >= k)
      ans++;
  }
  cout << ans << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}