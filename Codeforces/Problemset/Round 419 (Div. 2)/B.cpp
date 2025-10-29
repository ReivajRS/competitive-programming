#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  constexpr int maxn = 2e5 + 5;

  int n, k, q;
  cin >> n >> k >> q;

  vector<int> pref(maxn);
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    pref[l]++;
    pref[r + 1]--;
  }
  
  vector<int> pref2(maxn);
  for (int i = 1; i < maxn; i++) {
    pref[i] += pref[i - 1];
    int x = pref[i];
    pref2[i] = pref2[i - 1] + (x >= k);
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << pref2[r] - pref2[l - 1] << '\n';
  }
}