#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int lb = 0;
  vector<list<int>> mp(200001);
  mp[a[0]].push_back(0);
  int curr = 0, mx = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] != a[i - 1] && SZ(mp[a[i - 1]]) != 2) {
      curr = 0;
      for (int j = lb; j < i; j++) {
        mp[a[j]].pop_front();
      }
      lb = i;
      mp[a[i]].push_back(i);
      continue;
    }
    if (SZ(mp[a[i]]) == 2) {
      int rb = a[i] == a[i - 1] ? mp[a[i]].front() : mp[a[i]].back();
      for (int j = lb; j <= rb; j++) {
        mp[a[j]].pop_front();
        if (SZ(mp[a[j]]) == 1) curr--;
      }
      lb = rb + 1;
    }
    mp[a[i]].push_back(i);
    if (SZ(mp[a[i]]) == 1) continue;
    if (SZ(mp[a[i]]) == 2) {
      curr++;
      mx = max(mx, curr);
      continue;
    }
  }

  cout << mx * 2 << '\n';

  return 0;
}