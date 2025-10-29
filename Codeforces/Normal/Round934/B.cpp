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
  int n, k;
  cin >> n >> k;
  vi a(n), b(n);
  unordered_map<int, int> umap1, umap2;
  FOR (i, 0, n) {
    cin >> a[i];
    umap1[a[i]]++;
  }
  FOR (i, 0, n) {
    cin >> b[i];
    umap2[b[i]]++;
  }

  vi ans1, ans2;

  int cnt = 0, pairs = 0;

  FOR (i, 0, n) {
    if (umap1[a[i]] == 2 && cnt <= 2 * k - 2) {
      ans1.pb(a[i]);
      ans1.pb(a[i]);
      umap1[a[i]] -= 2;
      cnt += 2;
      pairs++;
      continue;
    }
    if (cnt == 2*k)
      break;
  }

  int cntPairs = 0;
  FOR (i, 0, n) {
    if (umap2[b[i]] == 2 && cntPairs < pairs) {
      ans2.pb(b[i]);
      ans2.pb(b[i]);
      umap2[b[i]] -= 2;
      cntPairs++;
      continue;
    }
    if (cntPairs == pairs)
      break;
  }

  FOR (i, 0, n) {
    if (umap1[a[i]] == 1 && cnt <= 2 * k - 1) {
      ans1.pb(a[i]);
      ans2.pb(a[i]);
      umap1[a[i]]--, umap2[b[i]]--;
      cnt++;
      continue;
    }
    if (cnt == 2*k)
      break;
  }

  for (auto &x : ans1)
    cout << x << ' ';
  cout << ENDL;
  for (auto &x : ans2)
    cout << x << ' ';
  cout << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}