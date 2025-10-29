#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
#define SZ(x) ((int)(x).size())

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int G = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    G = gcd(G, a[i]);
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += a[i] == G;
  }
  if (cnt > 0) {
    cout << n - cnt << '\n';
    return;
  }
  int mxa = *max_element(a.begin(), a.end());
  const int INF = 1e6;
  vector<int> curr(mxa + 1, INF), prev(mxa + 1, INF);
  for (int i = 0; i < n; i++) {
    curr[a[i]] = 0;
    for (int x = 1; x <= mxa; x++) {
      if (prev[x] != INF) {
        int g = gcd(x, a[i]);
        curr[g] = min(curr[g], prev[x] + 1);
      }
    }
    prev = curr;
  }
  int mn = prev[G];
  cout << mn + n - 1 << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}