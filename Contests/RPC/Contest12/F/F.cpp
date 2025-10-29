#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<string> a1(n), a2(n);
  map<string, int> mp1, mp2;

  for (int i = 0; i < n; i++) {
    cin >> a1[i];
    mp1[a1[i]] = i;
  }

  for (int i = 0; i < n; i++) {
    cin >> a2[i];
    mp2[a2[i]] = i;
  }

  bool flag = 0;
  int mn = 1e8;
  string ans = "";

  for (int i = 0; i < n; i++) {
    int dif = mp2[a2[i]] - mp1[a2[i]];
    // cout << dif << '\n';
    if (dif < mn) {
      mn = dif;
      ans = a2[i];
    }
    if (dif != 0) {
      flag = 1;
    }
  }

  if (!flag) {
    cout << "suspicious" << '\n';
    return 0;
  }

  cout << ans << '\n';

  return 0;
}